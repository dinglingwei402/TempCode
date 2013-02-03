#include "StdAfx.h"
#include "MultiControler.h"
#include "QueryNode.h"
#include <math.h>
#include "MatrixCalc.h"
#include <d3d9types.h>
#include "XnUSB.h"
#include "tchar.h"


MultiControler::MultiControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step,int valid_dev_num):KinectControler(v_data,k_data,x_step,y_step),validDevNum(valid_dev_num),blockSize(0),sub_x(0),sub_y(0)
{
	init();
}

MultiControler::~MultiControler(void)
{
	if(vrmlData)delete[] vrmlData;
}

initStatus MultiControler::init(){
	HRESULT hr;	
	int num=this->getDevData().getDevNum();
	this->vrmlData=new Vrml_PROTO_KinectData[validDevNum];
	for (int i=0;i<validDevNum;i++)
	{
		Node* child;
		this->getVrmlData().getChildren()->get1Value(i,&child);
		EventInMFVec3f* crd;
		hr=DeepQueryNode(child,_T("coord"),IID_EventInMFVec3f,&crd);
		if (!SUCCEEDED(hr))
		{
			this->_ini_stus=initStatus::fail;
		}
		vrmlData[i].coord=crd;
		EventInMFColor* clr;
		hr=DeepQueryNode(child,_T("color"),IID_EventInMFColor,&clr);
		vrmlData[i].color=clr;
		EventOutSFNode* snpMsh;
		hr=DeepQueryNode(child,_T("snapMesh"),IID_EventOutSFNode,&snpMsh);
		vrmlData[i].snapMesh=snpMsh;
		EventOutSFMatrix* devProjMtrx;
		hr=DeepQueryNode(child,_T("devProjMtrx"),IID_EventOutSFMatrix,&devProjMtrx);
		vrmlData[i].devProjMtrx=devProjMtrx;
		float mxtr_view[16]={};
		float mtrx_prj[16];
		memset(mtrx_prj,16*sizeof(float),0);
		devProjMtrx->getValue(mtrx_prj);
		XnFieldOfView fov;
		getDevData().getData()[0].depGen.GetFieldOfView(fov);
		float far_clip=10;
		float near_clip=2;
		float zoomx=cos(0.5*fov.fHFOV)/sin(0.5*fov.fHFOV);
		float zoomy=cos(0.5*fov.fVFOV)/sin(0.5*fov.fVFOV);
		mtrx_prj[0]=-zoomx;
		mtrx_prj[5]=zoomy;
		mtrx_prj[10]=(far_clip)/(far_clip-near_clip);
		mtrx_prj[11]=1;
		mtrx_prj[14]=(near_clip*far_clip)/(near_clip-far_clip);
		mtrx_prj[15]=0;
		int xres=getDevData().getData()[i].xres;
		int yres=getDevData().getData()[i].yres;
		float mtrx_scrn[16]={0.5,0,0,0,0,0.5,0,0,0,0,1,0,0.5+0.5/xres,0.5+0.5/yres,0,1};
		float new_mtrx[16];
		mul4X4(mtrx_prj,mtrx_scrn,new_mtrx);
		EventInSFMatrix* devProjMtrx_In;
		devProjMtrx->QueryInterface(IID_EventInSFMatrix,(void**)&devProjMtrx_In);
		devProjMtrx_In->setValue(new_mtrx);
		EventOutSFNode* imageBuffer;
		DeepQueryNode(child,_T("imgBuf"),IID_EventOutSFNode,&imageBuffer);
		vrmlData[i].imgBuf=imageBuffer;
		Node* node;
		imageBuffer->getValue(&node);
		CComQIPtr<IBufferTexture> imgBufVlu=node;
		imgBufVlu->setFormat(xres,yres,0,D3DFMT_R8G8B8,0);
		BYTE* buf=(BYTE*)(getDevData().getData()[i].pImageData);
		imgBufVlu->setTextureEx(xres,yres,0,D3DFMT_R8G8B8,640*480*3,buf,xres*3);
		node->Release();
	}
	return this->_ini_stus;
}
void MultiControler::start(){

	XnStatus rc;
	for(int i=0;i<this->validDevNum;i++){
		rc=getDevData().getData()[i].depGen.StartGenerating();
		rc=getDevData().getData()[i].imgGen.StartGenerating();
	}
}
void MultiControler::update(){
	XnStatus rc;
	for(int i=0;i<this->validDevNum;i++){
		rc=getDevData().getData()[i].depGen.WaitAndUpdateData();
		int xres=getDevData().getData()[i].xres;
		int yres=getDevData().getData()[i].yres;
		Node* node;
		vrmlData[i].imgBuf->getValue(&node);
		CComQIPtr<IBufferTexture> imgBufVlu=node;
		imgBufVlu->setFormat(xres,yres,0,D3DFMT_R8G8B8,0);
		BYTE* buf=(BYTE*)(getDevData().getData()[i].pImageData);
		imgBufVlu->setTextureEx(xres,yres,0,D3DFMT_R8G8B8,640*480*3,buf,xres*3);
		node->Release();
	}
}
void MultiControler::close(){}
void MultiControler::createMesh(int dev_no){
	
}
void MultiControler::trigger(){
//	createMesh();
	int devNum=getDevData().getDevNum();
	std::vector<std::vector<XnPointXYZRGB>>vec;
	for(int i=0;i<devNum;i++){
		const XnUInt8* imgPix=getDevData().getData()[i].pImageData;
		int xres=getDevData().getData()[i].xres;
		int yres=getDevData().getData()[i].yres;
		std::string  fileName_p="c:\\img_";
		std::stringstream num;
		num<<i;
		std::string fileName=fileName_p+num.str()+".bmp";
		saveRGBImage(xres,yres,(XnUInt8*)imgPix, CA2T(fileName.c_str()));

	}
	for(int i=1;i<devNum;i++)
	{
		getDevData().getData()[i].depGen.StopGenerating();
	}
	for(int i=0;i<devNum;i++)
	{
		std::vector<XnPointXYZRGB> vec_crd;
		getNonZeroPt(i,vec_crd);
		vec.push_back(vec_crd);
		if (i+1<devNum)
		{
			getDevData().getData()[i+1].depGen.StartGenerating();
		}
		
		getDevData().getData()[i].depGen.StopGenerating();

	}
	for(int i=0;i<devNum;i++)
	{
		std::string  fileName_p="c:\\cloud_";
		std::stringstream num;
		num<<i;
		std::string fileName=fileName_p+num.str()+".pcd";
		savePCDRGB(vec.at(i),fileName);	
		getDevData().getData()[i].depGen.StartGenerating();
	}
}



void MultiControler::trigger1(){
	XnStatus res;
	XN_USB_DEV_HANDLE m_dev; 
	const XnUSBConnectionString *paths; 
	XnUInt32 count; 
	res = xnUSBEnumerateDevices(0x045E /* VendorID */, 0x02B0 /*ProductID */, &paths, &count); 
	for (int i=0;i<this->validDevNum;i++)
	{	
		res = xnUSBOpenDeviceByPath(paths[i], &m_dev);
		res = xnUSBSendControl(m_dev,XN_USB_CONTROL_TYPE_VENDOR,/* 0x31*/0x06, /* angle*/2, 0x00, NULL, 0, 0);
		TCHAR idx_c[4];
		_itot(i+1,idx_c,10);
		MessageBox(NULL,idx_c,_T(" "),0);
		res = xnUSBSendControl(m_dev,XN_USB_CONTROL_TYPE_VENDOR,/* 0x31*/0x06, /* angle*/5, 0x00, NULL, 0, 0);
	}

}



                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
#include "StdAfx.h"
#include "MultiControler.h"
#include "QueryNode.h"
#include <string>
#include <math.h>
#include "MatrixCalc.h"
#include <d3d9types.h>

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
		node->Release();
	}
	return this->_ini_stus;
}
void MultiControler::start(){}
void MultiControler::update(){}
void MultiControler::close(){}
void MultiControler::createMesh(int dev_no){
	
}
void MultiControler::trigger(){
//	createMesh();
}


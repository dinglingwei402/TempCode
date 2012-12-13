#include "StdAfx.h"
#include "MultiControler.h"
#include "QueryNode.h"
#include <string>
#include <math.h>
#include "MatrixCalc.h"
#include <d3d9types.h>
const int maxDev=10;
MultiControler::MultiControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step):KinectControler(v_data,k_data,x_step,y_step),blockSize(0),sub_x(0),sub_y(0)
{
	init();
}

MultiControler::~MultiControler(void)
{
INT ENMPTY=0;
}

//const KinectData& MultiControler::getDevData()const{}
//const Vrml_PROTO_KinectDev& MultiControler::getVrmlData()const{}
initStatus MultiControler::init(){
	HRESULT hr;	
	int num=this->getDevData().getDevNum();
	Node* child[maxDev];
	this->validDevNum=num;
	for (int i=0;i<num;i++)
	{	
		child[i]=NULL;
		hr=this->getVrmlData().getChildren()->get1Value(i,&child[i]);
		if(!child[i]){
			this->validDevNum=i;
			num=i;
			break;
		}
	}
	this->vrmlData=new Vrml_PROTO_KinectData[validDevNum];
	for (int i=0;i<validDevNum;i++)
	{
		EventInMFVec3f* crd;
		hr=DeepQueryNode(child[i],_T("coord"),IID_EventInMFVec3f,&crd);
		vrmlData[i].coord=crd;
		EventInMFColor* clr;
		hr=DeepQueryNode(child[i],_T("color"),IID_EventInMFColor,&clr);
		vrmlData[i].color=clr;
		EventOutSFNode* snpMsh;
		hr=DeepQueryNode(child[i],_T("snapMesh"),IID_EventOutSFNode,&snpMsh);
		vrmlData[i].snapMesh=snpMsh;
		EventOutSFMatrix* devProjMtrx;
		hr=DeepQueryNode(child[i],_T("devProjMtrx"),IID_EventOutSFMatrix,&devProjMtrx);
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
		int xres=getDevData().getData()[0].xres;
		int yres=getDevData().getData()[0].yres;
		float mtrx_scrn[16]={0.5,0,0,0,0,0.5,0,0,0,0,1,0,0.5+0.5/xres,0.5+0.5/yres,0,1};
		float new_mtrx[16];
		mul4X4(mtrx_prj,mtrx_scrn,new_mtrx);
		EventInSFMatrix* devProjMtrx_In;
		devProjMtrx->QueryInterface(IID_EventInSFMatrix,(void**)&devProjMtrx_In);
		devProjMtrx_In->setValue(new_mtrx);
		EventOutSFNode* imageBuffer;
		DeepQueryNode(child,_T("imgBuf"),IID_EventOutSFNode,&imageBuffer);
		vrmlData->imgBuf=imageBuffer;
		Node* node;
		imageBuffer->getValue(&node);
		CComQIPtr<IBufferTexture> imgBufVlu=node;
		imgBufVlu->setFormat(xres,yres,0,D3DFMT_R8G8B8,0);
		node->Release();



	}
/*	

	sub_x=(int)(getDevData().getData()[0].xres/getXStep());
	sub_y=(int)(getDevData().getData()[0].yres/getYStep());
	blockSize=sub_x*sub_y;
	if (blockSize==0)
	{
		this->_ini_stus=fail;
		return this->_ini_stus;
	}
	lp_crd=new XnPoint3D[blockSize];
	lp_clr=new XnPoint3D[blockSize];
	drawPointSet(lp_crd,lp_clr);
	this->_ini_stus=FAILED(hr)?fail:success;*/
	depPix=getDevData().getData()[0].pDepthData;
	return this->_ini_stus;
}
void MultiControler::start(){}
void MultiControler::update(){}
void MultiControler::close(){

}

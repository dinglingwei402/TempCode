#include "StdAfx.h"
#include "SingleControler.h"
#include "QueryNode.h"

//######## ######## ######## ######## ######## 
SingleControler::SingleControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step):KinectControler(v_data,k_data,x_step,y_step),blockSize(0),sub_x(0),sub_y(0)
{
	init();	
}
SingleControler::~SingleControler(){if(this->data1)delete data1;}

void SingleControler::start(){
	getDevData().getData()[0].depGen.StartGenerating();
	getDevData().getData()[0].imgGen.StartGenerating();
}

void SingleControler::close(){
 int i=0;
}

initStatus SingleControler::init(){
	HRESULT hr;	
	this->data1=new Vrml_PROTO_KinectData();
	Node* child;
	hr=this->getVrmlData().getChildren()->get1Value(0,&child);
	EventInMFVec3f* crd;
	hr=DeepQueryNode(child,_T("coord"),IID_EventInMFVec3f,&crd);
	data1->coord=crd;
	EventInMFColor* clr;
	hr=DeepQueryNode(child,_T("color"),IID_EventInMFColor,&clr);
	data1->color=clr;
	depPix=getDevData().getData()[0].pDepthData;
	imgPix=getDevData().getData()[0].pImageData;
	sub_x=(int)(getDevData().getData()[0].xres/getXStep());
	sub_y=(int)(getDevData().getData()[0].yres/getYStep());
	blockSize=sub_x*sub_y;
	if (blockSize==0)
	{
		this->ini_stus=fail;
		return this->ini_stus;
	}
	LPVOID lp_clr=VirtualAlloc(NULL,blockSize*sizeof(XnPoint3D),MEM_COMMIT,PAGE_READWRITE);
	LPVOID lp_crd=VirtualAlloc(NULL,blockSize*sizeof(XnPoint3D),MEM_COMMIT,PAGE_READWRITE);
	XnPoint3D* crdPts=(XnPoint3D*)lp_crd;
	XnPoint3D* clrPts=(XnPoint3D*)lp_clr;
	int len=0;
	for(int i=0;i<sub_y;i++){
		for(int j=0;j<sub_x;j++){
			int bigX=j*getXStep();
			int bigY=i*getYStep();
			int idx=bigY*(getDevData().getData()[0].xres)+bigX;
			int base=len*3;
			int base1=base+1;
			int base2=base+2;
			crdPts[len].X=bigX;
			crdPts[len].Y=bigY;
			crdPts[len].Z=depPix[idx];
			clrPts[len].X=(XnFloat)(imgPix[idx*3]/255.0);
			clrPts[len].Y=(XnFloat)(imgPix[idx*3+1]/255.0);
			clrPts[len].Z=(XnFloat)(imgPix[idx*3+2]/255.0);
		//	clrPts=(XnFloat)(imgPix[idx*3]/255.0);
			/*depthPts[base]=bigX;
			depthPts[base1]=bigY;
			depthPts[base2]=depPix[idx];
			clorPts[base]= ;
			clorPts[base1]=(XnFloat)(imgPix[idx*3+1]/255.0);
			clorPts[base2]=(XnFloat)(imgPix[idx*3+2]/255.0);*/
			len++;
		}
	}
	XnPoint3D* aRealWorld=new XnPoint3D[len];
	getDevData().getData()[0].depGen.ConvertProjectiveToRealWorld(len,crdPts,aRealWorld);
	data1->coord->setValue(blockSize*3,(float*)aRealWorld);
	data1->color->setValue(blockSize*3,(float*)clrPts);
	delete[] aRealWorld;
	VirtualFree(lp_crd,0,MEM_RELEASE);
	VirtualFree(lp_clr,0,MEM_RELEASE);
	this->ini_stus=FAILED(hr)?fail:success;
	return this->ini_stus;
}


int SingleControler::update(){
	getDevData().getData()[0].depGen.WaitAndUpdateData();
	getDevData().getData()[0].imgGen.WaitAndUpdateData();
	/*int len=0;
	for(int i=0;i<sub_y;i++){
		for(int j=0;j<sub_x;j++){
			int bigX=j*getXStep();
			int bigY=i*getYStep();
			int idx=bigY*(getDevData().getData()[0].xres)+bigX;
			int base=len*3;
			int base1=base+1;
			int base2=base+2;
			depthPts[base]=(XnFloat)bigX;
			depthPts[base1]=(XnFloat)bigY;
			depthPts[base2]=(XnFloat)depPix[idx];
			clorPts[base]= (XnFloat)(imgPix[idx*3]/255.0);
			clorPts[base1]=(XnFloat)(imgPix[idx*3+1]/255.0);
			clorPts[base2]=(XnFloat)(imgPix[idx*3+2]/255.0);
			len++;
		}
	}
	XnPoint3D* aRealWorld=new XnPoint3D[len];
	getDevData().getData()[0].depGen.ConvertProjectiveToRealWorld(len,depthPts,aRealWorld);
	data1->coord->setValue(blockSize,(float*)aRealWorld);
	data1->color->setValue(blockSize,(float*)clorPts);
	delete[] aRealWorld;*/
	LPVOID lp_clr=VirtualAlloc(NULL,blockSize*sizeof(XnPoint3D),MEM_COMMIT,PAGE_READWRITE);
	LPVOID lp_crd=VirtualAlloc(NULL,blockSize*sizeof(XnPoint3D),MEM_COMMIT,PAGE_READWRITE);
	XnPoint3D* crdPts=(XnPoint3D*)lp_crd;
	XnPoint3D* clrPts=(XnPoint3D*)lp_clr;
	int len=0;
	for(int i=0;i<sub_y;i++){
		for(int j=0;j<sub_x;j++){
			int bigX=j*getXStep();
			int bigY=i*getYStep();
			int idx=bigY*(getDevData().getData()[0].xres)+bigX;
			int base=len*3;
			int base1=base+1;
			int base2=base+2;
			crdPts[len].X=bigX;
			crdPts[len].Y=bigY;
			crdPts[len].Z=depPix[idx];
			clrPts[len].X=(XnFloat)(imgPix[idx*3]/255.0);
			clrPts[len].Y=(XnFloat)(imgPix[idx*3+1]/255.0);
			clrPts[len].Z=(XnFloat)(imgPix[idx*3+2]/255.0);
		//	clrPts=(XnFloat)(imgPix[idx*3]/255.0);
			/*depthPts[base]=bigX;
			depthPts[base1]=bigY;
			depthPts[base2]=depPix[idx];
			clorPts[base]= ;
			clorPts[base1]=(XnFloat)(imgPix[idx*3+1]/255.0);
			clorPts[base2]=(XnFloat)(imgPix[idx*3+2]/255.0);*/
			len++;
		}
	}
	XnPoint3D* aRealWorld=new XnPoint3D[len];
	getDevData().getData()[0].depGen.ConvertProjectiveToRealWorld(len,crdPts,aRealWorld);
	data1->coord->setValue(blockSize*3,(float*)aRealWorld);
	data1->color->setValue(blockSize*3,(float*)clrPts);
	delete[] aRealWorld;
	VirtualFree(lp_crd,0,MEM_RELEASE);
	VirtualFree(lp_clr,0,MEM_RELEASE);
	return 0;
}

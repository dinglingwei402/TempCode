#include "StdAfx.h"
#include "SingleControler.h"

//######## ######## ######## ######## ######## 
SingleControler::SingleControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step):KinectControler(v_data,k_data,x_step,y_step),blockSize(0),sub_x(0),sub_y(0)
{
	init();	
}
SingleControler::~SingleControler(){}

void SingleControler::start(){
	getDevData().getData()[0].depGen.StartGenerating();
	getDevData().getData()[0].imgGen.StartGenerating();
}

void SingleControler::close(){
 int i=0;
}

initStatus SingleControler::init(){
	if (this->ini_stus==fail)
	{	
	
	}
	return this->ini_stus;
}


int SingleControler::update(){
	//if(this->ini_stus==success){
	//	for(int i=0;i<sub_y;i++){
	//		for(int j=0;j<sub_x;j++){
	//			int idx=bigY*(getDevData().getData()[0].xres)+bigX;
	//			depthPts[len].Z=depPix[idx];
	//			clorPts[len].X=imgPix[idx*3]/255.0;
	//			clorPts[len].Y=imgPix[idx*3+1]/255.0;
	//			clorPts[len].Z=imgPix[idx*3+2]/255.0;
	//			len++;
	//		}
	//	}


	//}
	return 0;
}

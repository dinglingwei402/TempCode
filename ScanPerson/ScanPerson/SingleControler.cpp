#include "StdAfx.h"
#include "SingleControler.h"

//######## ######## ######## ######## ######## 
SingleControler::SingleControler(const VrmlData& v_data,const KinectData& k_data,int x_step,int y_step):KinectControler(v_data,k_data,x_step,y_step),blockSize(0),sub_x(0),sub_y(0)
{
	init();	
}
SingleControler::~SingleControler(){}

void SingleControler::start(){
	getDevData().getData()[0].depGen.StartGenerating();
	getDevData().getData()[0].imgGen.StartGenerating();
}

void SingleControler::close(){

}

initStatus SingleControler::init(){
	if (this->ini_stus==fail)
	{	
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
		depthPts=new XnDepthPixel[blockSize*3];
		clorPts=new XnUInt8[blockSize*3];
		int len=0;
		for(int i=0;i<sub_y;i++){
			for(int j=0;j<sub_x;j++){
				int bigX=j*getXStep();
				int bigY=i*getYStep();
				int idx=bigY*(getDevData().getData()[0].xres)+bigX;
				int base=len*3;
				int base1=base+1;
				int base2=base+2;
				depthPts[base]=(XnDepthPixel)bigX;
				depthPts[base1]=(XnDepthPixel)bigY;
				depthPts[base2]=depPix[idx];
				clorPts[base]= (XnUInt8)150;//imgPix[idx*3];
				clorPts[base1]=(XnUInt8)150;//imgPix[idx*3+1];
				clorPts[base2]=(XnUInt8)1;//imgPix[idx*3+2];
				len++;
			}
		}	
	//getVrmlData().setTexture1(clorPts);
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

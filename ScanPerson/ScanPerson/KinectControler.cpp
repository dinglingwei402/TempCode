#pragma once
#include "StdAfx.h"
#include "KinectControler.h"
using namespace xn;

KinectControler::KinectControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step):_vrmlData(v_data),_devData(k_data),_xStep(x_step),_yStep(y_step),_ini_stus(fail){}

KinectControler::~KinectControler(){}

void KinectControler::start(){}

void KinectControler::close(){}

initStatus KinectControler::init()
{
	this->_ini_stus=success;
	return _ini_stus;
}
void KinectControler::update()
{
//	return;
}

void KinectControler::trigger(){}

const KinectData& KinectControler::getDevData()const
{
	return this->_devData;
}

const Vrml_PROTO_KinectDev& KinectControler::getVrmlData()const
{
	return this->_vrmlData;
}

XnUInt32 KinectControler::getXStep()const
{
	return this->_xStep;
}

XnUInt32 KinectControler::getYStep()const
{
	return this->_yStep;
}



void KinectControler::getNonZeroPt(int dev_no,std::vector<XnPointXYZRGB>& vec_clrPt)
{
	const XnUInt8* imgPix=getDevData().getData()[dev_no].pImageData;
	const XnDepthPixel* depPix=getDevData().getData()[dev_no].pDepthData;
	int width=getDevData().getData()[dev_no].xres;
	int height=getDevData().getData()[dev_no].yres;
	int cnt=width*height;
	GenGrp* devData=getDevData().getData();
	for(int i=1;i<height;i++){
		for(int j=1;j<width;j++){
			int bigX=j;
			int bigY=i;
			int idx=bigY*(devData[dev_no].xres)+bigX;
			if(depPix[idx]>devData[dev_no].depGen.GetDeviceMaxDepth())continue; 
			XnPoint3D PixCrd={bigX,bigY,depPix[idx]};
			devData[0].depGen.ConvertProjectiveToRealWorld(1,&PixCrd,&PixCrd);
			float allZero=std::abs(PixCrd.X)+std::abs(PixCrd.Y)+std::abs(PixCrd.Z);
			if(allZero>0.01&&(PixCrd.Z>200&&PixCrd.Z<3000)){
				XnPointXYZRGB pt;
				pt.X=PixCrd.X;
				pt.Y=PixCrd.Y;
				pt.Z=PixCrd.Z;
				pt.nRed=imgPix[idx*3];
				pt.nGreen=imgPix[idx*3+1];
				pt.nBlue=imgPix[idx*3+2];
				vec_clrPt.push_back(pt);	
			}
		}
	}
}

void KinectControler::getNonZeroPt(int dev_no,std::vector<XnPoint3D>& vec_crd)
{
	const XnDepthPixel* depPix=getDevData().getData()[dev_no].pDepthData;
	int width=getDevData().getData()[dev_no].xres;
	int height=getDevData().getData()[dev_no].yres;
	int cnt=width*height;
	GenGrp* devData=getDevData().getData();
	for(int i=1;i<height;i++){
		for(int j=1;j<width;j++){
			int bigX=j;
			int bigY=i;
			int idx=bigY*(devData[dev_no].xres)+bigX;
			if(depPix[idx]>devData[dev_no].depGen.GetDeviceMaxDepth())continue; 
			XnPoint3D PixCrd={bigX,bigY,depPix[idx]};
			devData[0].depGen.ConvertProjectiveToRealWorld(1,&PixCrd,&PixCrd);
			float allZero=std::abs(PixCrd.X)+std::abs(PixCrd.Y)+std::abs(PixCrd.Z);
			if(allZero>0.01&&(PixCrd.Z>200&&PixCrd.Z<3000)){
				vec_crd.push_back(PixCrd);
			}
		}
	}
}


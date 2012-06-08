#pragma once
#include "StdAfx.h"
#include "KinectControler.h"
using namespace xn;

KinectControler::KinectControler():_devData(NULL),_xStep(1),_yStep(1){

}
KinectControler::~KinectControler(){

}


KinectControler::update(){}

void KinectControler::setDevData(GenGrp* data){
	this->_devData=data;
}

void KinectControler::setVrmlData(VrmlData* data){
	this->_vrmlData=data;
}


SingleControler::SingleControler(){}
SingleControler::~SingleControler(){}


//
//SingleControler::update(){
//		XnBool hasUsrPix=false;
//		XnStatus rc=XN_STATUS_OK;
//		const XnDepthPixel* depPix=_devData[0].pDepthData;
//		const XnUInt8* imgPix=_devData[0].pImageData;
//		const XnChar* rslt=xnGetStatusString(rc);
//		int small_x=(int)(_devData[0].xres/_xStep);
//		int small_y=(int)(_devData[0].yres/_yStep);
//		XnUInt32 ptSize=(small_x*small_y);
//		bool flag=false;
//		std::vector<XnUInt32> idxList;
////		pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
//		if(rc==XN_STATUS_OK){
//			if(!depthPts){
//				depthPts=new XnPoint3D[ptSize];
//				clorPts=new XnPoint3D[ptSize];
//			}else{
//				memset(depthPts,0,sizeof(XnPoint3D)*ptSize);
//			}
//			XnUInt32 squence[4];
//			int len=0;
//			//compress mesh grid
//			for(int i=0;i<small_y;i++){
//				for(int j=0;j<small_x;j++){
//					int bigX=j*_xStep;
//					int bigY=i*_yStep;
//					depthPts[len].X=bigX;
//					depthPts[len].Y=bigY;
//					int idx=bigY*xres+bigX;
//					depthPts[len].Z=depPix[idx];
//					clorPts[len].X=imgPix[idx*3]/255.0;
//					clorPts[len].Y=imgPix[idx*3+1]/255.0;
//					clorPts[len].Z=imgPix[idx*3+2]/255.0;
//					len++;
//				}
//			}
//			//find  valid pts then put their indices to the vector
//			//******
//			if(len>0){
//				pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
//				cloud->width=small_x;
//				cloud->height=small_y;
//				cloud->points.resize (cloud->width * cloud->height);
//				XnPoint3D* aRealWorld=new XnPoint3D[len];
//				_devData[0].depGen.ConvertProjectiveToRealWorld(len,depthPts,aRealWorld);
//				g_point[0]->setValue(len*3,(float*)aRealWorld);
//				g_color[0]->setValue(len*3,(float*)clorPts);
//				int i_tmp=0;
//				int* ids=new int[len];
//				for(int i=0;i<len;i++){
//					if(aRealWorld[i].X==0&&aRealWorld[i].Y==0&&aRealWorld[i].Z==0){
//						continue;
//					}
//					ids[i_tmp]=i;
//					++i_tmp;	
//				}
//				cloud->width=i_tmp;
//				cloud->height=1;
//				cloud->resize(cloud->width);
//				for(int i=0;i<i_tmp;i++){
//					cloud->points[i].x=aRealWorld[ids[i]].X/1000;
//					cloud->points[i].y=aRealWorld[ids[i]].Y/1000;
//					cloud->points[i].z=aRealWorld[ids[i]].Z/1000;
//					//UINT8 r = 255, g = 0, b = 0;    // Example: Red color
//					//UINT32 rgb = ((UINT32)r << 16 | (UINT32)g << 8 | (UINT32)b);
//					//float rgb_f = *reinterpret_cast<float*>(&rgb);
//					//UINT32 rgb_i = *reinterpret_cast<int*>(&rgb_f);
//					cloud->points[i].r=(UINT8)(clorPts[i].X*255.0);
//					cloud->points[i].g=(UINT8)(clorPts[i].Y*255.0);
//					cloud->points[i].b=(UINT8)(clorPts[i].Z*255.0);
//				}
//				std::stringstream name_str;
//				name_str<<"c:\\table_kin_"<<0<<".pcd";
//			//	pcl::io::savePCDFileASCII(name_str.str(),*cloud);
//				pcl::io::savePCDFile(name_str.str(),*cloud);
//			}
//			
//		}	
//
//}
// use three kinect with 120 deg's interval

ThreeDevControler::ThreeDevControler(){}
ThreeDevControler::~ThreeDevControler(){}


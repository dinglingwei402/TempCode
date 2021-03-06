#pragma once
#include <XnStatus.h>
#include <XnCppWrapper.h>
#include "blaxxunVRML.h"
#include "KinectData.h"
#include "VrmlData.h"
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace xn;

typedef struct IndxSequence{
	size_t indx_1;
	size_t indx_2;
	size_t indx_3;
}IdxSeq;

typedef struct XnPointXYZRGB
{
	XnFloat X;
	XnFloat Y;
	XnFloat Z;
	XnUInt8 nRed;
	XnUInt8 nGreen;
	XnUInt8 nBlue;
} XnPointXYZRGB;

class KinectControler{
public:
	KinectControler::KinectControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step);
	~KinectControler();
	inline void clearNullPoints(XnPoint3D* points,int cnt,std::vector<XnPoint3D>& vec){
		for (int i=0;i<cnt;i++)
		{ 
			float allZero=std::abs(points[i].X)+std::abs(points[i].Y)+std::abs(points[i].Z);
			if(allZero>0.05){
				vec.push_back(points[i]);
			}	
		}
	};

	const KinectData& getDevData()const;
	const Vrml_PROTO_KinectDev& getVrmlData()const;
	XnUInt32 getXStep()const;
	XnUInt32 getYStep()const;
	virtual void  start();
	virtual void update();
	virtual initStatus init();
	virtual void  close();	
	virtual void trigger();
	virtual void trigger1();
	void getNonZeroPt(int dev_no,std::vector<XnPointXYZRGB>& vec_clrPt);
	void getNonZeroPt(int dev_no,std::vector<XnPoint3D>& vec_crd);

protected:
	initStatus _ini_stus;	
	const KinectData& _devData;
	const Vrml_PROTO_KinectDev& _vrmlData;
private:	
	XnUInt32 _xStep;
	XnUInt32 _yStep;
};



#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
inline void savePCDRGB(std::vector<XnPointXYZRGB>& vec_crd,std::string filename){
	pcl::PointCloud<pcl::PointXYZRGB> cloud;
	cloud.is_dense=true;
	if (vec_crd.empty())return;
	cloud.width=vec_crd.size();
	cloud.height=1;
	cloud.resize(vec_crd.size());
	std::vector<XnPointXYZRGB>::iterator it=vec_crd.begin();
	int i=0;
	while (it!=vec_crd.end())
	{
		cloud.points[i].x=it->X/1000;
		cloud.points[i].y=it->Y/1000;
		cloud.points[i].z=it->Z/1000;
		cloud.points[i].r=it->nRed;
		cloud.points[i].g=it->nGreen;
		cloud.points[i].b=it->nBlue;
		i++;
		it++;
	}
	pcl::PCDWriter	wtr;
	wtr.writeBinary(filename,cloud);
//	pcl::io::savePCDFileASCII(filename,cloud);
};



inline void saveRGBImage(int xres,int yres,XnUInt8* ptPixel,LPCTSTR filename){
	HDC directdc=CreateCompatibleDC(NULL);
	int pixSize=xres*yres*3;
	if(directdc){
		HANDLE hFile=CreateFile(filename,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);
		BITMAP bm;
		BITMAPINFO bmpInfoHeader;
		ZeroMemory(&bmpInfoHeader,sizeof(BITMAPINFO));
		bmpInfoHeader.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
		bmpInfoHeader.bmiHeader.biWidth=xres;
		bmpInfoHeader.bmiHeader.biHeight=yres;
		bmpInfoHeader.bmiHeader.biBitCount=24;
		bmpInfoHeader.bmiHeader.biPlanes=1;
		BITMAPFILEHEADER bmpFileHeader;
		ZeroMemory(&bmpFileHeader,sizeof(bmpFileHeader));
		bmpFileHeader.bfType=0x4D42;
		DWORD lBufferLen=pixSize;
		bmpFileHeader.bfSize=sizeof(bmpFileHeader)+lBufferLen+sizeof(BITMAPINFOHEADER);
		bmpFileHeader.bfOffBits=sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
		DWORD dwWritten=0;
		bool bWrite=WriteFile(hFile,&bmpFileHeader,sizeof(bmpFileHeader),&dwWritten,NULL);
		if(!bWrite)
		{
			MessageBox(0,TEXT("fail to write"),TEXT("Error"),MB_OK);
		}
		dwWritten=0;
		bWrite=WriteFile(hFile,&bmpInfoHeader,sizeof(bmpInfoHeader),&dwWritten,NULL);
		if(!bWrite)
		{
			MessageBox(0,TEXT("fail to write"),TEXT("Error"),MB_OK);
		}
		dwWritten=0;
		XnUInt8* ptPixel_mirror=new XnUInt8[pixSize];
		int stride=xres*3;
	/*	for(int i=0;i<yres;i++){
			memcpy(&ptPixel_mirror[i*stride],&ptPixel[pixSize-(i+1)*stride],stride*sizeof(XnUInt8));
		}*///因为位图默认不是rgb貌似是grb，这样存颜色不正确
		int l_uit8=sizeof(XnUInt8);
		for(int i=0;i<yres;i++){
			for(int j=0;j<xres;j++){
				memcpy(&ptPixel_mirror[i*stride+j*3],&ptPixel[pixSize-(i+1)*stride+j*3+1],l_uit8);
				memcpy(&ptPixel_mirror[i*stride+j*3+1],&ptPixel[pixSize-(i+1)*stride+j*3],l_uit8);
				memcpy(&ptPixel_mirror[i*stride+j*3+2],&ptPixel[pixSize-(i+1)*stride+j*3+2],l_uit8);
			}
		}
		bWrite=WriteFile(hFile,(UINT*)ptPixel_mirror,lBufferLen,&dwWritten,NULL);
		if(!bWrite)
		{
			MessageBox(0,TEXT("fail to write"),TEXT("Error"),MB_OK);
		}
		CloseHandle(hFile);
		delete[] ptPixel_mirror;
	}
};






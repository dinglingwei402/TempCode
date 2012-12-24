#pragma once
#include <XnStatus.h>
#include <XnCppWrapper.h>
#include "blaxxunVRML.h"
#include "KinectData.h"
#include "VrmlData.h"
#include <vector>
#include <stdio.h>
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
	pcl::io::savePCDFile(filename,cloud);
};



inline void saveRGBImage(int xres,int yres,UINT* ptPixel,LPCTSTR filename){
	HDC directdc=CreateCompatibleDC(NULL);
	if(directdc){
		HANDLE hFile=CreateFile(filename,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);
		BITMAP bm;
		BITMAPINFO bmpInfoHeader;
		ZeroMemory(&bmpInfoHeader,sizeof(BITMAPINFO));
		bmpInfoHeader.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
		bmpInfoHeader.bmiHeader.biWidth=xres;
		bmpInfoHeader.bmiHeader.biHeight=-yres;
		bmpInfoHeader.bmiHeader.biBitCount=24;
		bmpInfoHeader.bmiHeader.biCompression=BI_RGB;
		bmpInfoHeader.bmiHeader.biSizeImage=xres*yres;
		BITMAPFILEHEADER bmpFileHeader;
		ZeroMemory(&bmpFileHeader,sizeof(bmpFileHeader));
		bmpFileHeader.bfType=0x4D42;
		DWORD lBufferLen=xres*yres*3;
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
		bWrite=WriteFile(hFile,ptPixel,lBufferLen,&dwWritten,NULL);
		if(!bWrite)
		{
			MessageBox(0,TEXT("fail to write"),TEXT("Error"),MB_OK);
		}
		CloseHandle(hFile);
	}
};

inline void saveGrayImage(int xres,int yres,UINT* ptPixel,LPCTSTR filename){
	HDC directdc=CreateCompatibleDC(NULL);
	if(directdc){
		HANDLE hFile=CreateFile(filename,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);
		const DWORD dwMask[] = { 0xF800, 0x07E0, 0x001F };//RGB 565 mask
		BITMAP bm;
		BITMAPINFO bmpInfoHeader;
		ZeroMemory(&bmpInfoHeader,sizeof(BITMAPINFO));
		bmpInfoHeader.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
	//	bmpInfoHeader.bmiHeader.biCompression=BI_BITFIELDS;
		bmpInfoHeader.bmiHeader.biWidth=xres;
		bmpInfoHeader.bmiHeader.biHeight=-yres;
		bmpInfoHeader.bmiHeader.biBitCount=16;
		BITMAPFILEHEADER bmpFileHeader;
		ZeroMemory(&bmpFileHeader,sizeof(bmpFileHeader));
		bmpFileHeader.bfType=0x4d42;
		DWORD lBufferLen=xres*yres*2;
		bmpFileHeader.bfSize=sizeof(bmpFileHeader)+lBufferLen+sizeof(BITMAPINFOHEADER)+sizeof(dwMask);
		bmpFileHeader.bfOffBits=sizeof(BITMAPFILEHEADER)+sizeof(dwMask)+sizeof(BITMAPINFOHEADER);
		DWORD dwWritten=0;
		bool bWrite=WriteFile(hFile,&bmpFileHeader,sizeof(bmpFileHeader),&dwWritten,NULL);
		if(!bWrite)
		{
			MessageBox(0,TEXT("fail to write0"),TEXT("Error"),MB_OK);
		}
		dwWritten=0;
		bWrite=WriteFile(hFile,&bmpInfoHeader,sizeof(bmpInfoHeader),&dwWritten,NULL);
		if(!bWrite)
		{
			MessageBox(0,TEXT("fail to write1"),TEXT("Error"),MB_OK);
		}
		dwWritten=0;
		bWrite=WriteFile(hFile, dwMask,sizeof(dwMask),&dwWritten,NULL);
		if(!bWrite)
		{
			MessageBox(0,TEXT("fail to write3"),TEXT("Error"),MB_OK);
		}
		dwWritten=0;
		bWrite=WriteFile(hFile,ptPixel,lBufferLen,&dwWritten,NULL);
		if(!bWrite)
		{
			MessageBox(0,TEXT("fail to write4"),TEXT("Error"),MB_OK);
		}
		CloseHandle(hFile);
	}
}




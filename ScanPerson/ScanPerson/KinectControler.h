#pragma once
#include <XnStatus.h>
#include <XnCppWrapper.h>
#include "blaxxunVRML.h"
#include "KinectData.h"
#include "VrmlData.h"
#include <vector>
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

	void getNonZeroPt(int dev_no,std::vector<XnPointXYZRGB>& vec_clrPt);
	void getNonZeroPt(int dev_no,std::vector<XnPoint3D>& vec_crd);

	const KinectData& getDevData()const;
	const Vrml_PROTO_KinectDev& getVrmlData()const;
	XnUInt32 getXStep()const;
	XnUInt32 getYStep()const;

	virtual void  start();
	virtual void update();
	virtual initStatus init();
	virtual void  close();
protected:
	initStatus _ini_stus;	
	const KinectData& _devData;
	const Vrml_PROTO_KinectDev& _vrmlData;
private:	
	XnUInt32 _xStep;
	XnUInt32 _yStep;
};

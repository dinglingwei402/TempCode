#pragma once
#include <XnStatus.h>
#include <XnCppWrapper.h>
#include "blaxxunVRML.h"
#include "KinectData.h"
#include "VrmlData.h"
using namespace xn;

class KinectControler{
public:
	KinectControler();
	~KinectControler();
	KinectControler(int x_step,int y_step);
	KinectControler();

	void setDevData(GenGrp* data);
	void setVrmlData(VrmlData* data);
	XnUInt32 getXStep();
	XnUInt32 getYStep();
	void  start();
	virtual int update();
	HRESULT init();
	void  close();
protected:
	XnUInt32 blockSize;
	XnPoint3D* depthPts;
	XnPoint3D* clorPts;
private:
	GenGrp* _devData;
	VrmlData* _vrmlData;
	XnUInt32 _yStep;
	XnUInt32 _xStep;
};
// use single kinect. 
class SingleControler:public KinectControler{
public:
	SingleControler();
	~SingleControler();
	SingleControler(int x,int y);
	HRESULT init();
	int update();
};
// use three kinect with 120 deg's interval
class ThreeDevControler:public KinectControler{
public:
	ThreeDevControler();
	~ThreeDevControler();

};
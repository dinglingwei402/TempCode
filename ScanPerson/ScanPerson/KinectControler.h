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
	virtual void setDevData(GenGrp* data);
	virtual void setVrmlData(VrmlData* data);
	void  start();
	virtual int update();
	void  close();
	XnUInt32 _yStep;
	XnUInt32 _xStep;
	GenGrp* _devData;
	VrmlData* _vrmlData;
};
// use single kinect. 
class SingleControler:public KinectControler{
public:
	SingleControler();
	~SingleControler();
	int update();
};
// use three kinect with 120 deg's interval
class ThreeDevControler:public KinectControler{
public:
	ThreeDevControler();
	~ThreeDevControler();

};
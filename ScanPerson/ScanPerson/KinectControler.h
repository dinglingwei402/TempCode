#pragma once
#include <XnStatus.h>
#include <XnCppWrapper.h>
#include "blaxxunVRML.h"
#include "KinectData.h"
#include "VrmlData.h"
using namespace xn;

enum initStatus{success=1,fail};
class KinectControler{
public:

	KinectControler();
	~KinectControler();
	KinectControler(int x_step,int y_step);

	void setDevData(const KinectData& data)const;
	void setVrmlData(const VrmlData& data)const;
	XnUInt32 getXStep()const;
	XnUInt32 getYStep()const;
	void  start();
	virtual int update();
	virtual XnStatus init();
	void  close();
protected:
	XnUInt32 blockSize;
	XnPoint3D* depthPts;
	XnPoint3D* clorPts;
	initStatus ini_stus;
private:	
	KinectData* _devData;
	VrmlData* _vrmlData;
	XnUInt32 _yStep;
	XnUInt32 _xStep;
};

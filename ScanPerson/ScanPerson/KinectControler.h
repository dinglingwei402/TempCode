#pragma once
#include <XnStatus.h>
#include <XnCppWrapper.h>
#include "blaxxunVRML.h"
#include "KinectData.h"
#include "VrmlData.h"
using namespace xn;

class KinectControler{
public:
	KinectControler::KinectControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step);
	~KinectControler();
	const KinectData& getDevData()const;
	const Vrml_PROTO_KinectDev& getVrmlData()const;
	XnUInt32 getXStep()const;
	XnUInt32 getYStep()const;
	virtual void  start();
	virtual void update();
	virtual initStatus init();
	virtual void  close();
protected:
	/*XnUInt32 blockSize;
	XnPoint3D* depthPts;
	XnPoint3D* clorPts;*/
	initStatus _ini_stus;	
	const KinectData& _devData;
	const Vrml_PROTO_KinectDev& _vrmlData;
private:	
	XnUInt32 _xStep;
	XnUInt32 _yStep;
};

#pragma once
#include <XnStatus.h>
#include <XnCppWrapper.h>
#include "blaxxunVRML.h"
using namespace xn;

typedef struct GeneratorsGroup
{
	char name[16];
	XnUInt32 xres;
	XnUInt32 yres;
	Context contxt;
	DepthGenerator	depGen;
	ImageGenerator	imgGen;
	UserGenerator	userGen;
	SceneAnalyzer	scenGen;	
	const XnDepthPixel* pDepthData;
	const XnUInt8* pImageData;
}GenGrp;

class KinectData
{
public:
GenGrp* data;
int devNum;
NodeInfoList devicesList;
KinectData();
~KinectData();
XnStatus checkSensors();
void KinectInit();
void checkDev();
};















#pragma once
#include <XnStatus.h>
#include <XnCppWrapper.h>
#include "blaxxunVRML.h"
using namespace xn;

#ifndef tagGenGroup
#define tagGenGroup
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
#endif

class KinectData
{
public:
KinectData();
~KinectData();
XnStatus initData(int num);
GenGrp* getData();
int getDevNum();
//void KinectInit();

private:
	xn::Context _context;
	GenGrp* _data;
	int _devNum;
	int _takeDevNum;
	NodeInfoList* _devicesList;
	XnStatus checkDev();
};


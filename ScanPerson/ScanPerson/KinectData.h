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

#ifndef enum_init_status
#define  enum_init_status
	enum initStatus{success=1,fail};
#endif

#ifndef CHECK_RC(rc, what)
	#define CHECK_RC(rc, what)  \
	if (rc != XN_STATUS_OK)	    \
	{					        \
		printf("%s failed: %s\n", what, xnGetStatusString(rc));	\
		return rc;					\
	}
#endif


class KinectData
{
public:
KinectData();
~KinectData();
initStatus initData();
GenGrp* getData()const{return _data;};
int getDevNum()const{return _devNum;};

private:
	xn::Context _context;
	GenGrp* _data;
	int _devNum;
	NodeInfoList* _devicesList;
	XnStatus checkDev();
	initStatus ini_stus;
};


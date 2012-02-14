#include <XnStatus.h>
#include <XnCppWrapper.h>
#include "blaxxunVRML.h"
using namespace xn;
#define CHECK_RC(rc, what)  \
if (rc != XN_STATUS_OK)	    \
{					        \
	printf("%s failed: %s\n", what, xnGetStatusString(rc));	\
	return rc;					\
}

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
extern Context g_Context;
extern GenGrp* sensors;


 
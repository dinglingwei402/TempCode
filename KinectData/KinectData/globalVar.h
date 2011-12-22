#include <XnStatus.h>
#include <XnCppWrapper.h>
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
		DepthGenerator	g_depGen;
		ImageGenerator	g_imgGen;
		UserGenerator	g_user;
		SceneAnalyzer	g_scen;	
	}GenGrp;
#endif
extern int sensor_count;
extern Context g_context;
extern GenGrp* sensors;

 
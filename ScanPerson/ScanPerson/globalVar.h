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


class KinectDev {
	EventInSFNode*  floor;
	EventInMFNode*	users;
	EventInMFNode*	hands;
	EventInMFInt32*	handsId;
	EventInMFInt32*	usersId;
	EventInSFNode*  colorTexture_dev1; 
	EventInSFNode*  colorTexture_dev2;
	EventInSFNode*  coord_dev1 ;
	EventInSFNode*  coord_dev2 ;
	EventInSFNode*  IndxFaceSet ;
	KinectDev(EventInSFNode* flr,EventInMFNode* usr,EventInMFNode* hnd,EventInMFInt32*	hId,EventInMFInt32* uId,EventInSFNode* clr1,EventInSFNode* clr2,EventInSFNode* crd1,EventInSFNode* crd2);
	~KinectDev();
};
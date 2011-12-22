#include <XnOpenNI.h>
#include <XnCppWrapper.h>
#include <XnHash.h>
#include <XnLog.h>
#include "blaxxunVRML.h"


#ifndef SAMPLE_XML_PATH
#define SAMPLE_XML_PATH "c:\\SamplesConfig.xml"
#endif

#ifndef KNCT_VAR_INIT
#define KNCT_VAR_INIT
#endif
#if _MSC_VER > 1000
	#pragma once
#endif // _MSC_VER

#ifndef CHECK_RC(rc,what)
	#define CHECK_RC(rc, what)	 if(rc != XN_STATUS_OK) {return rc;}
#endif
extern xn::Context g_context;
extern xn::SceneAnalyzer g_scene;
extern xn::DepthGenerator g_depth;
extern xn::ImageGenerator g_image;
extern xn::GestureGenerator g_gesture;
extern xn::HandsGenerator g_hands;
extern xn::UserGenerator g_user;
extern XnUserID g_nPlayer;
extern XnUInt32 g_fps;
extern bool isInit;
XnStatus Init_Kinect(EventOutSFNode* skltn,EventOutSFNode* hnz,EventOutSFNode* flr);
void updateKinect(bool enbld_skltn,bool enbld_hnzTrck);
void writeHandStatusField(int s);
void writeIsTrackingField(XnUserID trckr);
void writeIsCalibratingField(XnBool clbrt);
void writeNeedPoseForCalibrationField(XnBool needPose);
void Close_Kinect();
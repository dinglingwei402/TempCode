#include <XnOpenNI.h>
#include <XnCppWrapper.h>
#include <XnHash.h>
#include <XnLog.h>
#include "blaxxunVRML.h"
#include "KinectDev.h"


#ifndef SAMPLE_XML_PATH
#define SAMPLE_XML_PATH "c:\\SamplesConfig.xml"
#endif

#ifndef CHECK_RC(rc,what)
#define CHECK_RC(rc, what)	 if(rc != XN_STATUS_OK) {return rc;}
#endif

XnStatus Init_Kinect(CKinectDev* dev);
XnStatus updateKinect();
void Close_Kinect();
#include "blaxxunVRML.h"
void KinectInit(CComPtr<Node> node);
void KinectClose();
void GetColorImage();
void UpdateImage();

#define  CHECK_RC(rc,what) {if(rc!=XN_STATUS_OK)  return;}
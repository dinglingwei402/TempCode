#include <XnOS.h>
#include <math.h>
#include <XnCppWrapper.h>

void FindPlayer();
XnUserID getPlayer();
XnBool isUserCalibrate(XnUserID uid);
XnBool IsTracking(XnUserID uid);
XnSkeletonJointPosition GetSkltnJntPos(XnUserID uid, XnSkeletonJoint jnt);
XnSkeletonJointOrientation GetSkltnJntOri(XnUserID uid, XnSkeletonJoint jnt);
XnUserID GetCurUser();
XnStatus GetUserFloor(XnPlane3D& plane);
XnStatus GetUserBBox(XnBoundingBox3D& bbox);
XnStatus GetUserCom(XnUserID uid,XnPoint3D& pt);
void XN_CALLBACK_TYPE NewUser(xn::UserGenerator& generator, XnUserID user, void* pCookie);
void XN_CALLBACK_TYPE LostUser(xn::UserGenerator& generator, XnUserID user, void* pCookie);
XnStatus init_skeleton();
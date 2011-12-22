#include "stdafx.h"
#include "SkltnFrKnct.h"
#include "XnVNite.h"
#include "ControlKinect.h"


using namespace xn;
XnUserID g_nPlayer = 0;
XnBool g_bCalibrated = FALSE;
XnUInt32 g_fps=30; 
//SessionState g_SessionState = NOT_IN_SESSION;

void  Div1000(XnVector3D& vec){
	vec.X*=-(float)0.001;
	vec.Y*=(float)0.001;
	vec.Z*=-(float)0.001;
}

XnUserID getPlayer(){
	return g_nPlayer;
}
XnBool AssignPlayer(XnUserID user)
{
	XnStatus rc=XN_STATUS_OK;
	if (g_nPlayer != 0)
		return FALSE;
	XnPoint3D com;
	g_user.GetCoM(user, com);
	if (com.Z == 0)
		return FALSE;
	rc=g_user.GetSkeletonCap().LoadCalibrationData(user, 0);
	rc=g_user.GetSkeletonCap().StartTracking(user);
	g_nPlayer = user;
	return TRUE;
}
void XN_CALLBACK_TYPE NewUser(xn::UserGenerator& generator, XnUserID user, void* pCookie)
{
	writeNeedPoseForCalibrationField(TRUE);
	if (!g_bCalibrated) // check on player0 is enough
	{
		g_user.GetPoseDetectionCap().StartPoseDetection("Psi", user);
		return;
	}
	AssignPlayer(user);
}
void FindPlayer()
{
	if (g_nPlayer != 0)
	{
		return;
	}
	XnUserID aUsers[20];
	XnUInt16 nUsers = 20;
	g_user.GetUsers(aUsers, nUsers);
	for (int i = 0; i < nUsers; ++i)
	{
		if (AssignPlayer(aUsers[i]))
			return;
	}
}
void LostPlayer()
{
	g_nPlayer = 0;
	writeIsCalibratingField(FALSE);
	writeNeedPoseForCalibrationField(FALSE);
	FindPlayer();
}
void XN_CALLBACK_TYPE LostUser(xn::UserGenerator& generator, XnUserID user, void* pCookie)
{
	if (g_nPlayer == user)
	{
		LostPlayer();
	}
}
void XN_CALLBACK_TYPE PoseDetected(xn::PoseDetectionCapability& pose, const XnChar* strPose, XnUserID user, void* cxt)
{
	g_user.GetSkeletonCap().RequestCalibration(user, TRUE);
	g_user.GetPoseDetectionCap().StopPoseDetection(user);
}

void XN_CALLBACK_TYPE CalibrationStarted(xn::SkeletonCapability& skeleton, XnUserID user, void* cxt)
{
	writeIsCalibratingField(TRUE);
}

void XN_CALLBACK_TYPE CalibrationCompleted(xn::SkeletonCapability& skeleton, XnUserID user, XnCalibrationStatus eStatus, void* cxt)
{
	if (eStatus == XN_CALIBRATION_STATUS_OK)
	{
		if (!g_bCalibrated)
		{
			g_user.GetSkeletonCap().SaveCalibrationData(user, 0);
			g_nPlayer = user;
			XnStatus rc= g_user.GetSkeletonCap().StartTracking(user);
			g_bCalibrated = TRUE;
		}
		XnUserID aUsers[10];
		XnUInt16 nUsers = 10;
		g_user.GetUsers(aUsers, nUsers);
		for (int i = 0; i < nUsers; ++i)
			g_user.GetPoseDetectionCap().StopPoseDetection(aUsers[i]);
		writeNeedPoseForCalibrationField(FALSE);
		writeIsCalibratingField(FALSE);
	}
	
}



XnBool isUserCalibrate(XnUserID uid){
	return g_user.GetSkeletonCap().IsCalibrated(uid);
}

XnBool IsTracking(XnUserID uid){
	return g_user.GetSkeletonCap().IsTracking(uid);
}

XnUserID GetCurUser(){
	return g_nPlayer;
}

XnSkeletonJointPosition GetSkltnJntPos(XnUserID uid, XnSkeletonJoint jnt)
{
	XnSkeletonJointPosition pSklPos;
	g_user.GetSkeletonCap().GetSkeletonJointPosition(uid,jnt,pSklPos);
	Div1000(pSklPos.position);
	return pSklPos;
}

XnSkeletonJointOrientation GetSkltnJntOri(XnUserID uid, XnSkeletonJoint jnt){
	XnSkeletonJointOrientation pSklOri;
	g_user.GetSkeletonCap().GetSkeletonJointOrientation(uid,jnt,pSklOri);
	return pSklOri;
}

XnStatus GetUserFloor(XnPlane3D& plane){
	XnStatus rs=g_scene.GetFloor(plane);
	Div1000(plane.ptPoint);
	return rs;
} 

XnStatus GetUserBBox(XnBoundingBox3D& bbox){
	XnStatus rs=g_depth.GetUserPositionCap().GetUserPosition(1,bbox);
	Div1000(bbox.LeftBottomNear);
	Div1000(bbox.RightTopFar);
	return rs;
}

XnStatus GetUserCom(XnUserID uid,XnPoint3D& pt){
	XnStatus rs = g_user.GetCoM(uid,pt);
	Div1000(pt);
	return rs;
}

XnStatus init_skeleton(){
	XnStatus rc=0;
	if(!g_user.IsCapabilitySupported(XN_CAPABILITY_SKELETON)|| !g_user.IsCapabilitySupported(XN_CAPABILITY_POSE_DETECTION))
	{
		return XN_STATUS_ERROR;
	}
	g_user.GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);
	XnCallbackHandle hUserCBs, hCalibrationStartCB, hCalibrationCompleteCB, hPoseCBs;
	g_user.RegisterUserCallbacks(NewUser, LostUser, NULL, hUserCBs);
	rc = g_user.GetSkeletonCap().RegisterToCalibrationStart(CalibrationStarted, NULL, hCalibrationStartCB);
	CHECK_RC(rc, "Register to calbiration start");
	rc = g_user.GetSkeletonCap().RegisterToCalibrationComplete(CalibrationCompleted, NULL, hCalibrationCompleteCB);
	CHECK_RC(rc, "Register to calibration complete");
	rc = g_user.GetPoseDetectionCap().RegisterToPoseDetected(PoseDetected, NULL, hPoseCBs);
	CHECK_RC(rc, "Register to pose detected");
	return rc;
}


#include "stdafx.h"
#include "NiUserDetector.h"
#include "ControlKinect.h"
#include "Temp4Debug.h"
using namespace xn;
XnList NiUserDetector::sm_Instances;

NiUserDetector::NiUserDetector(Context& context){
	g_context=context;
	playerId=0;
	XnStatus rc = sm_Instances.AddLast(this);
	if (rc != XN_STATUS_OK)
	{
		printf("Unable to add NiHandTracker instance to the list.");
		exit(1);
	}
	XnSkeletonJoint joint_names[]={XN_SKEL_HEAD,XN_SKEL_NECK,XN_SKEL_TORSO,XN_SKEL_WAIST,XN_SKEL_LEFT_COLLAR,XN_SKEL_LEFT_SHOULDER,XN_SKEL_LEFT_ELBOW,XN_SKEL_LEFT_WRIST,XN_SKEL_LEFT_HAND,XN_SKEL_LEFT_FINGERTIP,XN_SKEL_RIGHT_COLLAR,XN_SKEL_RIGHT_SHOULDER,XN_SKEL_RIGHT_ELBOW,XN_SKEL_RIGHT_WRIST,XN_SKEL_RIGHT_HAND,XN_SKEL_RIGHT_FINGERTIP,XN_SKEL_LEFT_HIP,XN_SKEL_LEFT_KNEE,XN_SKEL_LEFT_ANKLE,XN_SKEL_LEFT_FOOT,XN_SKEL_RIGHT_HIP,XN_SKEL_RIGHT_KNEE,XN_SKEL_RIGHT_ANKLE,XN_SKEL_RIGHT_FOOT};
}

NiUserDetector::~NiUserDetector(){
	Stop();
	g_context=NULL;
}
void XN_CALLBACK_TYPE NiUserDetector::UserExit(UserGenerator &generator, XnUserID user, void *pCookie){
//	MessageBox(NULL,L"Exit",L"UserDetec",MB_OK);
}

void XN_CALLBACK_TYPE NiUserDetector::UserReEnter(UserGenerator &generator, XnUserID user, void *pCookie){
	MessageBox(NULL,L"ReEnter",L"UserDetec",MB_OK);
}

void XN_CALLBACK_TYPE NiUserDetector::NewUser(UserGenerator &generator, XnUserID user, void *pCookie){
	assert(pCookie);
	NiUserDetector* pThis=STATIC_CAST(NiUserDetector*)(pCookie);
	if(sm_Instances.Find(pThis)!=sm_Instances.end()){
		pThis->g_usrGen.GetSkeletonCap().RequestCalibration(user,TRUE);
	//	MessageBox(NULL,L"NewUser",L"UserDetec",MB_OK);
		WCHAR wc[]=L"newuser/n";
		wrt_Wchr(wc);
	}
//	MessageBox(NULL,L"NewUser",L"UserDetec",MB_OK);
}

void XN_CALLBACK_TYPE NiUserDetector::LostUser(UserGenerator &generator, XnUserID user, void *pCookie){
//	MessageBox(NULL,L"Lostusr",L"UserDetec",MB_OK);
	assert(pCookie);
	NiUserDetector* pThis=STATIC_CAST(NiUserDetector*)(pCookie);
	MessageBox(NULL,L"Lostusr",L"UserDetec",MB_OK);
	if(pThis->playerId==0)return;
	if(sm_Instances.Find(pThis)!=sm_Instances.end()){
		if(pThis->playerId==user){
			pThis->playerId=0;
		}
	}
}

void XN_CALLBACK_TYPE NiUserDetector::UserCalibrationComplete(SkeletonCapability& capability, XnUserID user, XnCalibrationStatus eStatus, void* pCookie){
	assert(pCookie);
	NiUserDetector* pThis=STATIC_CAST(NiUserDetector*)(pCookie);
	if(sm_Instances.Find(pThis)!=sm_Instances.end()){
		if(eStatus==XN_CALIBRATION_STATUS_OK){
			pThis->g_usrGen.GetSkeletonCap().StartTracking(user);
		}else{
			pThis->g_usrGen.GetSkeletonCap().RequestCalibration(user,TRUE);
		}
		pThis->playerId=user;
		WCHAR pid[10];
		_itow(eStatus,pid,10);
		MessageBox(NULL,pid,L"cali",MB_OK);
	}
}

XnStatus NiUserDetector::Init(){
	XnStatus rc;
	rc=g_usrGen.Create(g_context);
	CHECK_RC(rc,"");
	rc=g_usrGen.GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);
	CHECK_RC(rc,"");
	rc=g_usrGen.RegisterToUserExit(UserExit,this,hUserExit);
	CHECK_RC(rc,"");
	rc=g_usrGen.RegisterToUserReEnter(UserReEnter,this,hUserReEnter);
	CHECK_RC(rc,"");
	rc=g_usrGen.RegisterUserCallbacks(NewUser,LostUser,this,hUserCallbacks);
	CHECK_RC(rc,"");
	rc=g_usrGen.GetSkeletonCap().RegisterToCalibrationComplete(UserCalibrationComplete,this,hCalibration);
	CHECK_RC(rc,"");	
	if(g_usrGen.GetSkeletonCap().NeedPoseForCalibration()){
		MessageBox(NULL,L"ndforpos",L"forcali",MB_OK);
	}
	return rc;
}

XnStatus NiUserDetector::Run(){
	XnStatus rc=g_context.StartGeneratingAll();
	return rc;
}

void NiUserDetector::Stop(){
	g_usrGen.UnregisterFromUserExit(hUserExit);
	g_usrGen.UnregisterFromUserReEnter(hUserReEnter);
	g_usrGen.UnregisterUserCallbacks(hUserCallbacks);
	g_usrGen.GetSkeletonCap().UnregisterFromCalibrationComplete(hCalibration);
	XnList::ConstIterator it = sm_Instances.Find(this);
	assert(it != sm_Instances.end());
	sm_Instances.Remove(it);
}


void NiUserDetector::getUserAllJoint(XnUserID user,XnUserSkeletonSet uss_hash){//
	XnUserSkeleton us_hash;
	for (int i=1;i<=24;i++)
	{
		XnSkeletonJointTransformation trans;
		g_usrGen.GetSkeletonCap().GetSkeletonJoint(user,(XnSkeletonJoint)i,trans);
		us_hash.Set((XnSkeletonJoint)i,trans);	
	}
	uss_hash.Set(user,us_hash);
}

void NiUserDetector::getAllJoint(XnUserID user,XnUserSkeleton us_hash){
	for (int i=1;i<=24;i++)
	{
		XnSkeletonJointTransformation trans;
		g_usrGen.GetSkeletonCap().GetSkeletonJoint(user,(XnSkeletonJoint)i,trans);
		us_hash.Set((XnSkeletonJoint)i,trans);	
	}
}

XnStatus NiUserDetector::getAllUser(XnUserID*  pUsers, XnUInt16&  pnUsers ){
	return g_usrGen.GetUsers(pUsers,pnUsers);
}
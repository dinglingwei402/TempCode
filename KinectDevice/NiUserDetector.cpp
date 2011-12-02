#include "stdafx.h"
#include "NiUserDetector.h"
#include "ControlKinect.h"
using namespace xn;
XnList NiUserDetector::sm_Instances;

NiUserDetector::NiUserDetector(Context& context){
	g_context=context;
	playerId=0;
	cali_flag=false;
	XnStatus rc = sm_Instances.AddLast(this);
	if (rc != XN_STATUS_OK)
	{
		printf("Unable to add NiHandTracker instance to the list.");
		exit(1);
	}
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
		if(!pThis->cali_flag){
		//	g_usrGen.GetPoseDetectionCap().StartPoseDetection("Psi",user);
			return;
		}
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
		pThis->playerId=user;
		WCHAR pid[10];
		_itow(user,pid,10);
		MessageBox(NULL,L"cli",L"cali",MB_OK);
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





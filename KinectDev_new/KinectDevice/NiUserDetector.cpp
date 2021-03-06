#include "stdafx.h"
#include "NiUserDetector.h"
#include "ControlKinect.h"
#include "Temp4Debug.h"
using namespace xn;
XnList UserTracker::sm_Instances;

UserTracker::UserTracker(Context& context){
	g_context=context;
	playerId=0;
	XnStatus rc = sm_Instances.AddLast(this);
	if (rc != XN_STATUS_OK)
	{
		printf("Unable to add NiHandTracker instance to the list.");
		exit(1);
	}
}

UserTracker::~UserTracker(){
	Stop();
	g_context=NULL;
}
void XN_CALLBACK_TYPE UserTracker::UserExit(UserGenerator &generator, XnUserID user, void *pCookie){
	
}

void XN_CALLBACK_TYPE UserTracker::UserReEnter(UserGenerator &generator, XnUserID user, void *pCookie){
//	MessageBox(NULL,L"ReEnter",L"UserDetec",MB_OK);
}

void XN_CALLBACK_TYPE UserTracker::NewUser(UserGenerator &generator, XnUserID user, void *pCookie){
	assert(pCookie);
	UserTracker* pThis=STATIC_CAST(UserTracker*)(pCookie);
	if(sm_Instances.Find(pThis)!=sm_Instances.end()){
		pThis->g_usrGen.GetSkeletonCap().RequestCalibration(user,TRUE);
	}
	if (pThis->m_sync)
	{
		pThis->m_sync->UserNew(user);
	}
}

void XN_CALLBACK_TYPE UserTracker::LostUser(UserGenerator &generator, XnUserID user, void *pCookie){
	assert(pCookie);
	UserTracker* pThis=STATIC_CAST(UserTracker*)(pCookie);	
	if(pThis->m_sync){
		pThis->m_sync->UserLost(user);
	}
	if(pThis->playerId==0)return;
	if(sm_Instances.Find(pThis)!=sm_Instances.end()){
		if(pThis->playerId==user){
			pThis->playerId=0;
		}
	}
}

void XN_CALLBACK_TYPE UserTracker::UserCalibrationComplete(SkeletonCapability &capability, XnUserID user, XnCalibrationStatus eStatus, void* pCookie){
	assert(pCookie);
	UserTracker* pThis=STATIC_CAST(UserTracker*)(pCookie);
	if(sm_Instances.Find(pThis)!=sm_Instances.end()){
		if(eStatus==XN_CALIBRATION_STATUS_OK){
			pThis->g_usrGen.GetSkeletonCap().StartTracking(user);
			if(pThis->m_sync){
				pThis->m_sync->UserNew(user);
			}
		}else{
			pThis->g_usrGen.GetSkeletonCap().RequestCalibration(user,TRUE);
		}
		pThis->playerId=user;
	}
}
void XN_CALLBACK_TYPE UserTracker::UserPositionChanged(ProductionNode &node,void* pCookie){
	assert(pCookie);
	UserTracker* pThis=STATIC_CAST(UserTracker*)(pCookie);
	if(pThis->sm_Instances.Find(pThis)!=sm_Instances.end()){
		if(pThis->m_sync){
			pThis->m_sync->UsersUpdate(pThis->g_usrGen);
		}
	}
}

XnStatus UserTracker::Init(UserSYNC* sync){
	this->m_sync=sync;
	XnStatus rc;
	rc=g_usrGen.Create(g_context);
	CHECK_RC(rc,"");
	rc=g_usrGen.GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);
	CHECK_RC(rc,"");
	rc=g_usrGen.RegisterToUserExit(UserExit,this,hUserExit);
	CHECK_RC(rc,"RegisterToUserExit fail");
	rc=g_usrGen.RegisterToUserReEnter(UserReEnter,this,hUserReEnter);
	CHECK_RC(rc,"");
	rc=g_usrGen.RegisterUserCallbacks(NewUser,LostUser,this,hUserCallbacks);
	CHECK_RC(rc,"");
	rc=g_usrGen.GetSkeletonCap().RegisterToCalibrationComplete(UserCalibrationComplete,this,hCalibration);
	CHECK_RC(rc,"");	
	if(g_usrGen.GetSkeletonCap().NeedPoseForCalibration()){
//		MessageBox(NULL,L"ndforpos",L"forcali",MB_OK);
	}
	return rc;
}

XnStatus UserTracker::Run(){
	XnStatus rc=g_context.StartGeneratingAll();
	return rc;
}

void UserTracker::Stop(){
	g_usrGen.UnregisterFromUserExit(hUserExit);
	g_usrGen.UnregisterFromUserReEnter(hUserReEnter);
	g_usrGen.UnregisterUserCallbacks(hUserCallbacks);
	g_usrGen.GetSkeletonCap().UnregisterFromCalibrationComplete(hCalibration);
	XnList::ConstIterator it = sm_Instances.Find(this);
	assert(it != sm_Instances.end());
	sm_Instances.Remove(it);
}

void UserTracker::Update(){
	if (m_sync)
	{
		m_sync->UsersUpdate(g_usrGen);
	}
}
#include "stdafx.h"
#include "NiUserDetector.h"
#include "ControlKinect.h"
using namespace xn;
XnUserID NiUserDetector::playerId=0;
NiUserDetector::NiUserDetector(Context& context){
	g_context=context;
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
//	MessageBox(NULL,L"NewUser",L"UserDetec",MB_OK);
}

void XN_CALLBACK_TYPE NiUserDetector::LostUser(UserGenerator &generator, XnUserID user, void *pCookie){
//	MessageBox(NULL,L"Lostusr",L"UserDetec",MB_OK);
}

void XN_CALLBACK_TYPE NiUserDetector::UserCalibrationComplete(SkeletonCapability& capability, XnUserID user, XnCalibrationStatus eStatus, void* pCookie){
	NiUserDetector::playerId=user;
	WCHAR pid[10];
	_itow(NiUserDetector::playerId,pid,10);
	MessageBox(NULL,L"cli",L"Calibration",MB_OK);
}

XnStatus NiUserDetector::Init(){
	XnStatus rc;
	rc=g_usrGen.Create(g_context);
	rc=g_usrGen.RegisterToUserExit(UserExit,NULL,hUserExit);
	CHECK_RC(rc,"");
	rc=g_usrGen.RegisterToUserReEnter(UserReEnter,NULL,hUserReEnter);
	CHECK_RC(rc,"");
	rc=g_usrGen.RegisterUserCallbacks(NewUser,LostUser,NULL,hUserCallbacks);
	rc=g_usrGen.GetSkeletonCap().RegisterToCalibrationComplete(UserCalibrationComplete,NULL,hCalibration);
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
}





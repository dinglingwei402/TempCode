// KinectDev.cpp : CKinectDev 的实现

#include "stdafx.h"
#include "ControlKinect.h"
#include "QueryNode.h"
#include "KinectDev.h"
#include "blaxxunVRML.h"
#include <iostream>
#include "Temp4Debug.h"

CKinectDev::CKinectDev():
m_user_com(NULL),
m_status(NULL),
m_users(NULL),
m_floor(NULL),
m_hands(NULL),
m_browser(NULL)
{

}
CKinectDev::~CKinectDev(){
	Close_Kinect();
}

STDMETHODIMP CKinectDev::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IbxxHID
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT STDMETHODCALLTYPE CKinectDev::Init(BSTR Device, int DeviceNo, Browser *pBrowser, int *pDeviceNoUsed)
{	
	DeviceNo=1;
	*pDeviceNoUsed= 1;
	m_browser=pBrowser;
	return  S_OK;
}

HRESULT STDMETHODCALLTYPE CKinectDev::AddDeviceSensor(BSTR eventType, Node *pEventNode, EventInSFBool *pIsActive, BOOL Enabled, int ID, int *pRetVal)
{
	 AllocConsole();
	 HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
	 SetConsoleActiveScreenBuffer(hConsole);
	 SetConsoleTextAttribute(hConsole,
		 FOREGROUND_RED /*字前景红色*/ | BACKGROUND_GREEN/*字背景绿色*/);
	 SetConsoleHandle(hConsole);
	if(Enabled){
		Node *skltn,*hnz,*flr;
		QueryEventOutSFNodeVlu(pEventNode,L"floor",IID_EventOutSFNode,&m_floor,&flr);
		QueryEventInNode(pEventNode,L"users",IID_EventInMFNode,&m_users);
		QueryEventInNode(pEventNode,L"hands",IID_EventInMFNode,&m_hands);
		if (Init_Kinect(this)!=XN_STATUS_OK)
		{
			Close_Kinect();
			return E_FAIL;
		}
	}
	*pRetVal=1;
	return  S_OK;
}

HRESULT STDMETHODCALLTYPE CKinectDev::RemoveDeviceSensor(int ID){
	CloseHandle(GetConsoleHandle());
	FreeConsole();
	return  S_OK;
}


HRESULT STDMETHODCALLTYPE CKinectDev::Tick(double SimTime, double FrameRate){
	updateKinect();
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CKinectDev::EnabledChanged(int ID, BOOL Enabled, BOOL *pSetIsActive){
	*pSetIsActive=true;
	return  S_OK;
}

HRESULT STDMETHODCALLTYPE CKinectDev::FocusChanged(BOOL HasFocusNow, BOOL *pNeedTickCalls){
	*pNeedTickCalls=true;
	return  S_OK;
}

// ScanPerson.cpp : DLL ������ʵ�֡�


#include "stdafx.h"
#include "resource.h"
#include "ScanPerson_i.h"
#include "dllmain.h"
#include "KinectControl.h"
#include "blaxxunVRML.h"

// ����ȷ�� DLL �Ƿ���� OLE ж��
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// ����һ���๤���Դ������������͵Ķ���
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - �������ӵ�ϵͳע���
STDAPI DllRegisterServer(void)
{
    // ע��������Ϳ�����Ϳ��е����нӿ�
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - �����ϵͳע������Ƴ�
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}

// DllInstall - ���û����߰��������ϵͳע���������/ɾ��
//              �	
STDAPI DllInstall(BOOL bInstall, LPCWSTR pszCmdLine)
{
    HRESULT hr = E_FAIL;
    static const wchar_t szUserSwitch[] = _T("user");

    if (pszCmdLine != NULL)
    {
    	if (_wcsnicmp(pszCmdLine, szUserSwitch, _countof(szUserSwitch)) == 0)
    	{
    		AtlSetPerUserRegistration(true);
    	}
    }

    if (bInstall)
    {	
    	hr = DllRegisterServer();
    	if (FAILED(hr))
    	{	
    		DllUnregisterServer();
    	}
    }
    else
    {
    	hr = DllUnregisterServer();
    }

    return hr;
}

// ScanPerson.cpp : CScanPerson ��ʵ��

#include "stdafx.h"
#include "ScanPerson.h"

CScanPerson::CScanPerson():m_ColorImg(NULL)
{

}
CScanPerson::~CScanPerson(){
	KinectClose();
}


STDMETHODIMP CScanPerson::InterfaceSupportsErrorInfo(REFIID riid)
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


HRESULT STDMETHODCALLTYPE CScanPerson::Init( 
							   /* [in] */ BSTR Device,
							   /* [in] */ int DeviceNo,
							   /* [in] */ Browser *pBrowser,
							   /* [retval][out] */ int *pDeviceNoUsed)
{
	int i=1;
	DeviceNo=1;
	*pDeviceNoUsed= 1;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CScanPerson::AddDeviceSensor( 
	/* [in] */ BSTR eventType,
	/* [in] */ Node *pEventNode,
	/* [in] */ EventInSFBool *pIsActive,
	/* [in] */ BOOL Enabled,
	/* [in] */ int ID,
	/* [retval][out] */ int *pRetVal)
{
	Field* fld;

	pEventNode->getField(_T("colorTexture"),&fld);
	assert(fld);
	EventOutSFNode* imgNode;
	CComPtr<Node> imgVlu;
	fld->QueryInterface(IID_EventOutSFNode,(void**)&imgNode);
	imgNode->getValue(&imgVlu);
	fld->Release();
	
	pEventNode->getField(_T("coord"),&fld);
	assert(fld);
	EventOutSFNode* ptsNode;
	CComPtr<Node> pts;
	fld->QueryInterface(IID_EventOutSFNode,(void**)&ptsNode);
	ptsNode->getValue(&pts);
	fld->Release();
	pts->getField(_T("point"),&fld);
	EventInMFVec3f* ptsVlu;
	fld->QueryInterface(IID_EventInMFVec3f,(void**)&ptsVlu);
	fld->Release();

	pEventNode->getField(_T("coord4mesh"),&fld);
	EventOutSFNode* meshNode;
	CComPtr<Node> mesh;
	fld->QueryInterface(IID_EventOutSFNode,(void**)&meshNode);
	meshNode->getValue(&mesh);
	fld->Release();
	mesh->getField(_T("point"),&fld);
	EventInMFVec3f* meshVlu;
	fld->QueryInterface(IID_EventInMFVec3f,(void**)&meshVlu);
	fld->Release();



	imgNode->Release();
	ptsNode->Release();
	meshNode->Release();
	
	KinectInit(imgVlu,ptsVlu,meshVlu);
	*pRetVal=1;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CScanPerson::RemoveDeviceSensor( 
	/* [in] */ int ID)
{
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CScanPerson::Tick( 
							   /* [in] */ double SimTime,
							   /* [in] */ double FrameRate) 
{
	UpdateImage();
	return S_OK;

}

HRESULT STDMETHODCALLTYPE CScanPerson::EnabledChanged( 
	int ID,
	BOOL Enabled,
	/* [retval][out] */ BOOL *pSetIsActive)
{
return S_OK;
}

HRESULT STDMETHODCALLTYPE CScanPerson::FocusChanged( 
									   /* [in] */ BOOL HasFocusNow,
									   /* [retval][out] */ BOOL *pNeedTickCalls)
{
return S_OK;
}

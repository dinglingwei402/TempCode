// ScanPerson.cpp : DLL 导出的实现。


#include "stdafx.h"
#include "resource.h"
#include "ScanPerson_i.h"
#include "dllmain.h"

// 用于确定 DLL 是否可由 OLE 卸载
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// 返回一个类工厂以创建所请求类型的对象
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - 将项添加到系统注册表
STDAPI DllRegisterServer(void)
{
    // 注册对象、类型库和类型库中的所有接口
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - 将项从系统注册表中移除
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}

// DllInstall - 按用户或者按计算机在系统注册表中添加/删除
//              项。	
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

// ScanPerson.cpp : CScanPerson 的实现

#include "stdafx.h"
#include "ScanPerson.h"

CScanPerson::CScanPerson(){}
CScanPerson::~CScanPerson(){}


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
	MessageBox(NULL,L"dsd",L"ddd",MB_OK);
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


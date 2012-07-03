// ScanPerson.cpp : DLL 导出的实现。
#include "stdafx.h"
#include "resource.h"
#include "ScanPerson_i.h"
#include "dllmain.h"
#include "KinectControler.h"
#include "blaxxunVRML.h"
#include "QueryNode.h"
#include "KinectData.h"
#include "VrmlData.h"
#include "SingleControler.h"

/*typedef int tic_fun(void);

tic_fun callback_fun;*/ 
KinectControler* controler=NULL;

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

CScanPerson::CScanPerson()
{

}
CScanPerson::~CScanPerson(){
	//	KinectClose();
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



HRESULT STDMETHODCALLTYPE CScanPerson::RemoveDeviceSensor( 
	/* [in] */ int ID)
{
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CScanPerson::Tick( 
	/* [in] */ double SimTime,
	/* [in] */ double FrameRate) 
{
	if (controler!=NULL)
	{
		controler->update();
	}
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
	*pNeedTickCalls=true;
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
	KinectData* devData=new KinectData();
	Vrml_PROTO_KinectDev* kd=new Vrml_PROTO_KinectDev();
	int num=devData->getDevNum();
	initStatus ini=devData->initData();
	EventOutMFNode* children;
	QueryMFNode(pEventNode,_T("children"),IID_EventOutMFNode,&children);
	EventOutSFBool* useSgl;
	QuerySFNode(pEventNode,_T("useSingleDev"),IID_EventOutSFBool,&useSgl);
	EventOutSFNode* faces;
	QuerySFNode(pEventNode,_T("IndxFaceSet"),IID_EventOutSFNode,&faces);
	kd->setChildren(children);
	kd->setIndxFaceSet(faces);
	kd->setUseSingleDev(useSgl);
	VARIANT_BOOL b;
	useSgl->getValue(&b);
	if(num==1){
		SingleControler* single=new	SingleControler(*kd,*devData);
		controler=single;
		controler->start();
		
	}else if(num>1&&(!b)){
		//TODO:MULTIControler
	}
	/*int chld_cnt;
	children->getSize(&chld_cnt); 
	Node* subNode;
	children->get1Value(0,&subNode);
	EventInMFVec3f* crd;
	QueryMFNode(subNode,_T("coord"),IID_EventInMFVec3f,&crd);
	vrmlData->setCoord(crd);
	EventInMFColor* clr;
	QueryMFNode(subNode,_T("color"),IID_EventInMFColor,&clr);*/
	if(ini!=initStatus::success)
	{
		delete devData;
		return S_FALSE;
	}
	*pRetVal=1;
	return S_OK;
}


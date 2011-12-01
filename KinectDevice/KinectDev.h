// KinectDev.h : CKinectDev 的声明

#pragma once
#include "resource.h"       // 主符号
#include "blaxxunHID.h"
#include "blaxxunVRML.h"
#include "KinectDevice_i.h"
//#include "SkltnFrKnct.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif
class ATL_NO_VTABLE CKinectDev :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CKinectDev, &CLSID_KinectDev>,
	public ISupportErrorInfo,
	public IDispatchImpl<IbxxHID, &IID_IbxxHID, &LIBID_KinectDeviceLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CKinectDev();
	~CKinectDev();

DECLARE_REGISTRY_RESOURCEID(IDR_KINECTDEV)


BEGIN_COM_MAP(CKinectDev)
	COM_INTERFACE_ENTRY(IbxxHID)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	EventInSFVec3f *m_user_com;
	EventInMFString *m_status;
	EventOutSFNode *m_skeletonNode;
	EventOutSFNode *m_handsTrack;
	EventOutSFNode *m_floorNode;
	EventOutSFBool *m_enabledSkltn;
	EventOutSFBool *m_enabledHnz;
	
	HRESULT STDMETHODCALLTYPE Init( 
		/* [in] */ BSTR Device,
		/* [in] */ int DeviceNo,
		/* [in] */ Browser *pBrowser,
		/* [retval][out] */ int *pDeviceNoUsed);

	HRESULT STDMETHODCALLTYPE AddDeviceSensor( 
		/* [in] */ BSTR eventType,
		/* [in] */ Node *pEventNode,
		/* [in] */ EventInSFBool *pIsActive,
		/* [in] */ BOOL Enabled,
		/* [in] */ int ID,
		/* [retval][out] */ int *pRetVal);

	HRESULT STDMETHODCALLTYPE RemoveDeviceSensor( 
		/* [in] */ int ID);

	HRESULT STDMETHODCALLTYPE Tick( 
		/* [in] */ double SimTime,
		/* [in] */ double FrameRate);

	HRESULT STDMETHODCALLTYPE EnabledChanged( 
		int ID,
		BOOL Enabled,
		/* [retval][out] */ BOOL *pSetIsActive);

	HRESULT STDMETHODCALLTYPE FocusChanged( 
		/* [in] */ BOOL HasFocusNow,
		/* [retval][out] */ BOOL *pNeedTickCalls);


//	VOID SetUserData(XnUserID uid);	

};

OBJECT_ENTRY_AUTO(__uuidof(KinectDev), CKinectDev)

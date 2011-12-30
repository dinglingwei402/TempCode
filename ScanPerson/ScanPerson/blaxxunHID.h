

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri Dec 30 18:53:53 2011
 */
/* Compiler settings for .\blaxxunHID.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __blaxxunHID_h__
#define __blaxxunHID_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IbxxHID_FWD_DEFINED__
#define __IbxxHID_FWD_DEFINED__
typedef interface IbxxHID IbxxHID;
#endif 	/* __IbxxHID_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "blaxxunVRML.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __blaxxunHID_Lib_LIBRARY_DEFINED__
#define __blaxxunHID_Lib_LIBRARY_DEFINED__

/* library blaxxunHID_Lib */
/* [uuid] */ 


EXTERN_C const IID LIBID_blaxxunHID_Lib;

#ifndef __IbxxHID_INTERFACE_DEFINED__
#define __IbxxHID_INTERFACE_DEFINED__

/* interface IbxxHID */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IbxxHID;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4256A70F-7DD7-478F-BC2E-1A84D1B68FAC")
    IbxxHID : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ BSTR Device,
            /* [in] */ int DeviceNo,
            /* [in] */ Browser *pBrowser,
            /* [retval][out] */ int *pDeviceNoUsed) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddDeviceSensor( 
            /* [in] */ BSTR eventType,
            /* [in] */ Node *pEventNode,
            /* [in] */ EventInSFBool *pIsActive,
            /* [in] */ BOOL Enabled,
            /* [in] */ int ID,
            /* [retval][out] */ int *pRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveDeviceSensor( 
            /* [in] */ int ID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Tick( 
            /* [in] */ double SimTime,
            /* [in] */ double FrameRate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnabledChanged( 
            int ID,
            BOOL Enabled,
            /* [retval][out] */ BOOL *pSetIsActive) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FocusChanged( 
            /* [in] */ BOOL HasFocusNow,
            /* [retval][out] */ BOOL *pNeedTickCalls) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IbxxHIDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IbxxHID * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IbxxHID * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IbxxHID * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IbxxHID * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IbxxHID * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IbxxHID * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IbxxHID * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IbxxHID * This,
            /* [in] */ BSTR Device,
            /* [in] */ int DeviceNo,
            /* [in] */ Browser *pBrowser,
            /* [retval][out] */ int *pDeviceNoUsed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddDeviceSensor )( 
            IbxxHID * This,
            /* [in] */ BSTR eventType,
            /* [in] */ Node *pEventNode,
            /* [in] */ EventInSFBool *pIsActive,
            /* [in] */ BOOL Enabled,
            /* [in] */ int ID,
            /* [retval][out] */ int *pRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveDeviceSensor )( 
            IbxxHID * This,
            /* [in] */ int ID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Tick )( 
            IbxxHID * This,
            /* [in] */ double SimTime,
            /* [in] */ double FrameRate);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnabledChanged )( 
            IbxxHID * This,
            int ID,
            BOOL Enabled,
            /* [retval][out] */ BOOL *pSetIsActive);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FocusChanged )( 
            IbxxHID * This,
            /* [in] */ BOOL HasFocusNow,
            /* [retval][out] */ BOOL *pNeedTickCalls);
        
        END_INTERFACE
    } IbxxHIDVtbl;

    interface IbxxHID
    {
        CONST_VTBL struct IbxxHIDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IbxxHID_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IbxxHID_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IbxxHID_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IbxxHID_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IbxxHID_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IbxxHID_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IbxxHID_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IbxxHID_Init(This,Device,DeviceNo,pBrowser,pDeviceNoUsed)	\
    ( (This)->lpVtbl -> Init(This,Device,DeviceNo,pBrowser,pDeviceNoUsed) ) 

#define IbxxHID_AddDeviceSensor(This,eventType,pEventNode,pIsActive,Enabled,ID,pRetVal)	\
    ( (This)->lpVtbl -> AddDeviceSensor(This,eventType,pEventNode,pIsActive,Enabled,ID,pRetVal) ) 

#define IbxxHID_RemoveDeviceSensor(This,ID)	\
    ( (This)->lpVtbl -> RemoveDeviceSensor(This,ID) ) 

#define IbxxHID_Tick(This,SimTime,FrameRate)	\
    ( (This)->lpVtbl -> Tick(This,SimTime,FrameRate) ) 

#define IbxxHID_EnabledChanged(This,ID,Enabled,pSetIsActive)	\
    ( (This)->lpVtbl -> EnabledChanged(This,ID,Enabled,pSetIsActive) ) 

#define IbxxHID_FocusChanged(This,HasFocusNow,pNeedTickCalls)	\
    ( (This)->lpVtbl -> FocusChanged(This,HasFocusNow,pNeedTickCalls) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IbxxHID_INTERFACE_DEFINED__ */

#endif /* __blaxxunHID_Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



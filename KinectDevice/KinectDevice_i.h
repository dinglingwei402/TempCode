

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Dec 01 21:22:22 2011
 */
/* Compiler settings for .\KinectDevice.idl:
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

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __KinectDevice_i_h__
#define __KinectDevice_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IKinectDev_FWD_DEFINED__
#define __IKinectDev_FWD_DEFINED__
typedef interface IKinectDev IKinectDev;
#endif 	/* __IKinectDev_FWD_DEFINED__ */


#ifndef __KinectDev_FWD_DEFINED__
#define __KinectDev_FWD_DEFINED__

#ifdef __cplusplus
typedef class KinectDev KinectDev;
#else
typedef struct KinectDev KinectDev;
#endif /* __cplusplus */

#endif 	/* __KinectDev_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IKinectDev_INTERFACE_DEFINED__
#define __IKinectDev_INTERFACE_DEFINED__

/* interface IKinectDev */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IKinectDev;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("879B5ACC-BA2B-4891-9D10-0928E5D632F1")
    IKinectDev : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IKinectDevVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKinectDev * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKinectDev * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKinectDev * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IKinectDev * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IKinectDev * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IKinectDev * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IKinectDev * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IKinectDevVtbl;

    interface IKinectDev
    {
        CONST_VTBL struct IKinectDevVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKinectDev_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IKinectDev_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IKinectDev_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IKinectDev_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IKinectDev_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IKinectDev_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IKinectDev_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IKinectDev_INTERFACE_DEFINED__ */



#ifndef __KinectDeviceLib_LIBRARY_DEFINED__
#define __KinectDeviceLib_LIBRARY_DEFINED__

/* library KinectDeviceLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_KinectDeviceLib;

EXTERN_C const CLSID CLSID_KinectDev;

#ifdef __cplusplus

class DECLSPEC_UUID("F404559E-E7CD-4337-BDDE-9B29545EFEC5")
KinectDev;
#endif
#endif /* __KinectDeviceLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif





/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri Aug 03 17:32:12 2012
 */
/* Compiler settings for .\ScanPerson.idl:
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

#ifndef __ScanPerson_i_h__
#define __ScanPerson_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IScanPerson_FWD_DEFINED__
#define __IScanPerson_FWD_DEFINED__
typedef interface IScanPerson IScanPerson;
#endif 	/* __IScanPerson_FWD_DEFINED__ */


#ifndef __ScanPerson_FWD_DEFINED__
#define __ScanPerson_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScanPerson ScanPerson;
#else
typedef struct ScanPerson ScanPerson;
#endif /* __cplusplus */

#endif 	/* __ScanPerson_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IScanPerson_INTERFACE_DEFINED__
#define __IScanPerson_INTERFACE_DEFINED__

/* interface IScanPerson */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IScanPerson;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("afb35e79-34aa-4cb5-8984-631dcf3ad622")
    IScanPerson : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IScanPersonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScanPerson * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScanPerson * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScanPerson * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScanPerson * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScanPerson * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScanPerson * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScanPerson * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IScanPersonVtbl;

    interface IScanPerson
    {
        CONST_VTBL struct IScanPersonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScanPerson_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScanPerson_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScanPerson_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScanPerson_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IScanPerson_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IScanPerson_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IScanPerson_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScanPerson_INTERFACE_DEFINED__ */



#ifndef __ScanPersonLib_LIBRARY_DEFINED__
#define __ScanPersonLib_LIBRARY_DEFINED__

/* library ScanPersonLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ScanPersonLib;

EXTERN_C const CLSID CLSID_ScanPerson;

#ifdef __cplusplus

class DECLSPEC_UUID("70174573-e3f9-4f69-9467-62afd6544b31")
ScanPerson;
#endif
#endif /* __ScanPersonLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



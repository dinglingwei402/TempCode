

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Nov 30 17:52:04 2011
 */
/* Compiler settings for .\blaxxunVRML.idl:
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


#ifndef __blaxxunVRML_h__
#define __blaxxunVRML_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Node_FWD_DEFINED__
#define __Node_FWD_DEFINED__
typedef interface Node Node;
#endif 	/* __Node_FWD_DEFINED__ */


#ifndef __Browser_FWD_DEFINED__
#define __Browser_FWD_DEFINED__
typedef interface Browser Browser;
#endif 	/* __Browser_FWD_DEFINED__ */


#ifndef __Field_FWD_DEFINED__
#define __Field_FWD_DEFINED__
typedef interface Field Field;
#endif 	/* __Field_FWD_DEFINED__ */


#ifndef __EventIn_FWD_DEFINED__
#define __EventIn_FWD_DEFINED__
typedef interface EventIn EventIn;
#endif 	/* __EventIn_FWD_DEFINED__ */


#ifndef __EventOut_FWD_DEFINED__
#define __EventOut_FWD_DEFINED__
typedef interface EventOut EventOut;
#endif 	/* __EventOut_FWD_DEFINED__ */


#ifndef __EventInSFFloat_FWD_DEFINED__
#define __EventInSFFloat_FWD_DEFINED__
typedef interface EventInSFFloat EventInSFFloat;
#endif 	/* __EventInSFFloat_FWD_DEFINED__ */


#ifndef __EventInSFBool_FWD_DEFINED__
#define __EventInSFBool_FWD_DEFINED__
typedef interface EventInSFBool EventInSFBool;
#endif 	/* __EventInSFBool_FWD_DEFINED__ */


#ifndef __EventOutMField_FWD_DEFINED__
#define __EventOutMField_FWD_DEFINED__
typedef interface EventOutMField EventOutMField;
#endif 	/* __EventOutMField_FWD_DEFINED__ */


#ifndef __EventInMFColor_FWD_DEFINED__
#define __EventInMFColor_FWD_DEFINED__
typedef interface EventInMFColor EventInMFColor;
#endif 	/* __EventInMFColor_FWD_DEFINED__ */


#ifndef __EventInMFFloat_FWD_DEFINED__
#define __EventInMFFloat_FWD_DEFINED__
typedef interface EventInMFFloat EventInMFFloat;
#endif 	/* __EventInMFFloat_FWD_DEFINED__ */


#ifndef __EventInMFTime_FWD_DEFINED__
#define __EventInMFTime_FWD_DEFINED__
typedef interface EventInMFTime EventInMFTime;
#endif 	/* __EventInMFTime_FWD_DEFINED__ */


#ifndef __EventInMFInt32_FWD_DEFINED__
#define __EventInMFInt32_FWD_DEFINED__
typedef interface EventInMFInt32 EventInMFInt32;
#endif 	/* __EventInMFInt32_FWD_DEFINED__ */


#ifndef __EventInMFNode_FWD_DEFINED__
#define __EventInMFNode_FWD_DEFINED__
typedef interface EventInMFNode EventInMFNode;
#endif 	/* __EventInMFNode_FWD_DEFINED__ */


#ifndef __EventInMFRotation_FWD_DEFINED__
#define __EventInMFRotation_FWD_DEFINED__
typedef interface EventInMFRotation EventInMFRotation;
#endif 	/* __EventInMFRotation_FWD_DEFINED__ */


#ifndef __EventInMFString_FWD_DEFINED__
#define __EventInMFString_FWD_DEFINED__
typedef interface EventInMFString EventInMFString;
#endif 	/* __EventInMFString_FWD_DEFINED__ */


#ifndef __EventInMFVec2f_FWD_DEFINED__
#define __EventInMFVec2f_FWD_DEFINED__
typedef interface EventInMFVec2f EventInMFVec2f;
#endif 	/* __EventInMFVec2f_FWD_DEFINED__ */


#ifndef __EventInMFVec3f_FWD_DEFINED__
#define __EventInMFVec3f_FWD_DEFINED__
typedef interface EventInMFVec3f EventInMFVec3f;
#endif 	/* __EventInMFVec3f_FWD_DEFINED__ */


#ifndef __EventInSFColor_FWD_DEFINED__
#define __EventInSFColor_FWD_DEFINED__
typedef interface EventInSFColor EventInSFColor;
#endif 	/* __EventInSFColor_FWD_DEFINED__ */


#ifndef __EventInSFImage_FWD_DEFINED__
#define __EventInSFImage_FWD_DEFINED__
typedef interface EventInSFImage EventInSFImage;
#endif 	/* __EventInSFImage_FWD_DEFINED__ */


#ifndef __EventInSFInt32_FWD_DEFINED__
#define __EventInSFInt32_FWD_DEFINED__
typedef interface EventInSFInt32 EventInSFInt32;
#endif 	/* __EventInSFInt32_FWD_DEFINED__ */


#ifndef __EventInSFNode_FWD_DEFINED__
#define __EventInSFNode_FWD_DEFINED__
typedef interface EventInSFNode EventInSFNode;
#endif 	/* __EventInSFNode_FWD_DEFINED__ */


#ifndef __EventInSFRotation_FWD_DEFINED__
#define __EventInSFRotation_FWD_DEFINED__
typedef interface EventInSFRotation EventInSFRotation;
#endif 	/* __EventInSFRotation_FWD_DEFINED__ */


#ifndef __EventInSFString_FWD_DEFINED__
#define __EventInSFString_FWD_DEFINED__
typedef interface EventInSFString EventInSFString;
#endif 	/* __EventInSFString_FWD_DEFINED__ */


#ifndef __EventInSFTime_FWD_DEFINED__
#define __EventInSFTime_FWD_DEFINED__
typedef interface EventInSFTime EventInSFTime;
#endif 	/* __EventInSFTime_FWD_DEFINED__ */


#ifndef __EventInSFVec2f_FWD_DEFINED__
#define __EventInSFVec2f_FWD_DEFINED__
typedef interface EventInSFVec2f EventInSFVec2f;
#endif 	/* __EventInSFVec2f_FWD_DEFINED__ */


#ifndef __EventInSFVec3f_FWD_DEFINED__
#define __EventInSFVec3f_FWD_DEFINED__
typedef interface EventInSFVec3f EventInSFVec3f;
#endif 	/* __EventInSFVec3f_FWD_DEFINED__ */


#ifndef __EventInSFMatrix_FWD_DEFINED__
#define __EventInSFMatrix_FWD_DEFINED__
typedef interface EventInSFMatrix EventInSFMatrix;
#endif 	/* __EventInSFMatrix_FWD_DEFINED__ */


#ifndef __EventOutObserver_FWD_DEFINED__
#define __EventOutObserver_FWD_DEFINED__
typedef interface EventOutObserver EventOutObserver;
#endif 	/* __EventOutObserver_FWD_DEFINED__ */


#ifndef __EventOutMFColor_FWD_DEFINED__
#define __EventOutMFColor_FWD_DEFINED__
typedef interface EventOutMFColor EventOutMFColor;
#endif 	/* __EventOutMFColor_FWD_DEFINED__ */


#ifndef __EventOutMFFloat_FWD_DEFINED__
#define __EventOutMFFloat_FWD_DEFINED__
typedef interface EventOutMFFloat EventOutMFFloat;
#endif 	/* __EventOutMFFloat_FWD_DEFINED__ */


#ifndef __EventOutMFTime_FWD_DEFINED__
#define __EventOutMFTime_FWD_DEFINED__
typedef interface EventOutMFTime EventOutMFTime;
#endif 	/* __EventOutMFTime_FWD_DEFINED__ */


#ifndef __EventOutMFInt32_FWD_DEFINED__
#define __EventOutMFInt32_FWD_DEFINED__
typedef interface EventOutMFInt32 EventOutMFInt32;
#endif 	/* __EventOutMFInt32_FWD_DEFINED__ */


#ifndef __EventOutMFNode_FWD_DEFINED__
#define __EventOutMFNode_FWD_DEFINED__
typedef interface EventOutMFNode EventOutMFNode;
#endif 	/* __EventOutMFNode_FWD_DEFINED__ */


#ifndef __EventOutMFRotation_FWD_DEFINED__
#define __EventOutMFRotation_FWD_DEFINED__
typedef interface EventOutMFRotation EventOutMFRotation;
#endif 	/* __EventOutMFRotation_FWD_DEFINED__ */


#ifndef __EventOutMFString_FWD_DEFINED__
#define __EventOutMFString_FWD_DEFINED__
typedef interface EventOutMFString EventOutMFString;
#endif 	/* __EventOutMFString_FWD_DEFINED__ */


#ifndef __EventOutMFVec2f_FWD_DEFINED__
#define __EventOutMFVec2f_FWD_DEFINED__
typedef interface EventOutMFVec2f EventOutMFVec2f;
#endif 	/* __EventOutMFVec2f_FWD_DEFINED__ */


#ifndef __EventOutMFVec3f_FWD_DEFINED__
#define __EventOutMFVec3f_FWD_DEFINED__
typedef interface EventOutMFVec3f EventOutMFVec3f;
#endif 	/* __EventOutMFVec3f_FWD_DEFINED__ */


#ifndef __EventOutSFBool_FWD_DEFINED__
#define __EventOutSFBool_FWD_DEFINED__
typedef interface EventOutSFBool EventOutSFBool;
#endif 	/* __EventOutSFBool_FWD_DEFINED__ */


#ifndef __EventOutSFColor_FWD_DEFINED__
#define __EventOutSFColor_FWD_DEFINED__
typedef interface EventOutSFColor EventOutSFColor;
#endif 	/* __EventOutSFColor_FWD_DEFINED__ */


#ifndef __EventOutSFFloat_FWD_DEFINED__
#define __EventOutSFFloat_FWD_DEFINED__
typedef interface EventOutSFFloat EventOutSFFloat;
#endif 	/* __EventOutSFFloat_FWD_DEFINED__ */


#ifndef __EventOutSFImage_FWD_DEFINED__
#define __EventOutSFImage_FWD_DEFINED__
typedef interface EventOutSFImage EventOutSFImage;
#endif 	/* __EventOutSFImage_FWD_DEFINED__ */


#ifndef __EventOutSFInt32_FWD_DEFINED__
#define __EventOutSFInt32_FWD_DEFINED__
typedef interface EventOutSFInt32 EventOutSFInt32;
#endif 	/* __EventOutSFInt32_FWD_DEFINED__ */


#ifndef __EventOutSFNode_FWD_DEFINED__
#define __EventOutSFNode_FWD_DEFINED__
typedef interface EventOutSFNode EventOutSFNode;
#endif 	/* __EventOutSFNode_FWD_DEFINED__ */


#ifndef __EventOutSFRotation_FWD_DEFINED__
#define __EventOutSFRotation_FWD_DEFINED__
typedef interface EventOutSFRotation EventOutSFRotation;
#endif 	/* __EventOutSFRotation_FWD_DEFINED__ */


#ifndef __EventOutSFString_FWD_DEFINED__
#define __EventOutSFString_FWD_DEFINED__
typedef interface EventOutSFString EventOutSFString;
#endif 	/* __EventOutSFString_FWD_DEFINED__ */


#ifndef __EventOutSFTime_FWD_DEFINED__
#define __EventOutSFTime_FWD_DEFINED__
typedef interface EventOutSFTime EventOutSFTime;
#endif 	/* __EventOutSFTime_FWD_DEFINED__ */


#ifndef __EventOutSFVec2f_FWD_DEFINED__
#define __EventOutSFVec2f_FWD_DEFINED__
typedef interface EventOutSFVec2f EventOutSFVec2f;
#endif 	/* __EventOutSFVec2f_FWD_DEFINED__ */


#ifndef __EventOutSFVec3f_FWD_DEFINED__
#define __EventOutSFVec3f_FWD_DEFINED__
typedef interface EventOutSFVec3f EventOutSFVec3f;
#endif 	/* __EventOutSFVec3f_FWD_DEFINED__ */


#ifndef __ScriptContainer_FWD_DEFINED__
#define __ScriptContainer_FWD_DEFINED__
typedef interface ScriptContainer ScriptContainer;
#endif 	/* __ScriptContainer_FWD_DEFINED__ */


#ifndef __Script_FWD_DEFINED__
#define __Script_FWD_DEFINED__
typedef interface Script Script;
#endif 	/* __Script_FWD_DEFINED__ */


#ifndef __BrowserObserver_FWD_DEFINED__
#define __BrowserObserver_FWD_DEFINED__
typedef interface BrowserObserver BrowserObserver;
#endif 	/* __BrowserObserver_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __blaxxunVRMLLib_LIBRARY_DEFINED__
#define __blaxxunVRMLLib_LIBRARY_DEFINED__

/* library blaxxunVRMLLib */
/* [helpstring][version][uuid] */ 









typedef 
enum InterfaceElementTypes
    {	type_unknown	= 0,
	type_field	= ( type_unknown + 1 ) ,
	type_exposedField	= ( type_field + 1 ) ,
	type_eventIn	= ( type_exposedField + 1 ) ,
	type_eventOut	= ( type_eventIn + 1 ) 
    } 	InterfaceElementTypes;

typedef 
enum FieldTypes
    {	UnknownType	= 0,
	SFBOOL	= ( UnknownType + 1 ) ,
	SFIMAGE	= ( SFBOOL + 1 ) ,
	SFTIME	= ( SFIMAGE + 1 ) ,
	SFCOLOR	= ( SFTIME + 1 ) ,
	MFCOLOR	= ( SFCOLOR + 1 ) ,
	SFFLOAT	= ( MFCOLOR + 1 ) ,
	MFFLOAT	= ( SFFLOAT + 1 ) ,
	SFINT32	= ( MFFLOAT + 1 ) ,
	MFINT32	= ( SFINT32 + 1 ) ,
	SFNODE	= ( MFINT32 + 1 ) ,
	MFNODE	= ( SFNODE + 1 ) ,
	SFROTATION	= ( MFNODE + 1 ) ,
	MFROTATION	= ( SFROTATION + 1 ) ,
	SFSTRING	= ( MFROTATION + 1 ) ,
	MFSTRING	= ( SFSTRING + 1 ) ,
	SFVEC2F	= ( MFSTRING + 1 ) ,
	MFVEC2F	= ( SFVEC2F + 1 ) ,
	SFVEC3F	= ( MFVEC2F + 1 ) ,
	MFVEC3F	= ( SFVEC3F + 1 ) ,
	SFENUM	= ( MFVEC3F + 1 ) ,
	SFBITMASK	= ( SFENUM + 1 ) ,
	SFMATRIX	= ( SFBITMASK + 1 ) ,
	SFLONG	= ( SFMATRIX + 1 ) ,
	MFLONG	= ( SFLONG + 1 ) ,
	MFTIME	= ( MFLONG + 1 ) ,
	SFURL	= ( MFTIME + 1 ) ,
	MFURL	= ( SFURL + 1 ) ,
	SFCMD	= ( MFURL + 1 ) ,
	SFDATE	= ( SFCMD + 1 ) ,
	MFVALUE	= ( SFDATE + 1 ) 
    } 	FieldType;



EXTERN_C const IID LIBID_blaxxunVRMLLib;

#ifndef __Node_INTERFACE_DEFINED__
#define __Node_INTERFACE_DEFINED__

/* interface Node */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_Node;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50393-75D9-11D0-9315-0020AFE05CC8")
    Node : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getType( 
            /* [retval][out] */ BSTR *type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getEventIn( 
            /* [in] */ BSTR name,
            /* [retval][out] */ EventIn **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getEventOut( 
            /* [in] */ BSTR name,
            /* [retval][out] */ EventOut **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getField( 
            /* [in] */ BSTR name,
            /* [retval][out] */ Field **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getExposedField( 
            /* [in] */ BSTR name,
            /* [retval][out] */ Field **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getBrowser( 
            /* [retval][out] */ Browser **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getName( 
            /* [retval][out] */ BSTR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setName( 
            /* [in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getNumInterfaceElements( 
            /* [retval][out] */ int *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getInterfaceElement( 
            /* [in] */ int index,
            /* [out] */ int *elementType,
            /* [out] */ int *fieldType,
            /* [out] */ BSTR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getValueNode( 
            /* [retval][out] */ Node **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getNative( 
            /* [retval][out] */ long *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRefCnt( 
            /* [retval][out] */ long *result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct NodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Node * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Node * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Node * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Node * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Node * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Node * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Node * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            Node * This,
            /* [retval][out] */ BSTR *type);
        
        HRESULT ( STDMETHODCALLTYPE *getEventIn )( 
            Node * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ EventIn **result);
        
        HRESULT ( STDMETHODCALLTYPE *getEventOut )( 
            Node * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ EventOut **result);
        
        HRESULT ( STDMETHODCALLTYPE *getField )( 
            Node * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ Field **result);
        
        HRESULT ( STDMETHODCALLTYPE *getExposedField )( 
            Node * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ Field **result);
        
        HRESULT ( STDMETHODCALLTYPE *getBrowser )( 
            Node * This,
            /* [retval][out] */ Browser **result);
        
        HRESULT ( STDMETHODCALLTYPE *getName )( 
            Node * This,
            /* [retval][out] */ BSTR *name);
        
        HRESULT ( STDMETHODCALLTYPE *setName )( 
            Node * This,
            /* [in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *getNumInterfaceElements )( 
            Node * This,
            /* [retval][out] */ int *result);
        
        HRESULT ( STDMETHODCALLTYPE *getInterfaceElement )( 
            Node * This,
            /* [in] */ int index,
            /* [out] */ int *elementType,
            /* [out] */ int *fieldType,
            /* [out] */ BSTR *name);
        
        HRESULT ( STDMETHODCALLTYPE *getValueNode )( 
            Node * This,
            /* [retval][out] */ Node **result);
        
        HRESULT ( STDMETHODCALLTYPE *getNative )( 
            Node * This,
            /* [retval][out] */ long *result);
        
        HRESULT ( STDMETHODCALLTYPE *getRefCnt )( 
            Node * This,
            /* [retval][out] */ long *result);
        
        END_INTERFACE
    } NodeVtbl;

    interface Node
    {
        CONST_VTBL struct NodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Node_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Node_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Node_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Node_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Node_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Node_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Node_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define Node_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define Node_getEventIn(This,name,result)	\
    ( (This)->lpVtbl -> getEventIn(This,name,result) ) 

#define Node_getEventOut(This,name,result)	\
    ( (This)->lpVtbl -> getEventOut(This,name,result) ) 

#define Node_getField(This,name,result)	\
    ( (This)->lpVtbl -> getField(This,name,result) ) 

#define Node_getExposedField(This,name,result)	\
    ( (This)->lpVtbl -> getExposedField(This,name,result) ) 

#define Node_getBrowser(This,result)	\
    ( (This)->lpVtbl -> getBrowser(This,result) ) 

#define Node_getName(This,name)	\
    ( (This)->lpVtbl -> getName(This,name) ) 

#define Node_setName(This,name)	\
    ( (This)->lpVtbl -> setName(This,name) ) 

#define Node_getNumInterfaceElements(This,result)	\
    ( (This)->lpVtbl -> getNumInterfaceElements(This,result) ) 

#define Node_getInterfaceElement(This,index,elementType,fieldType,name)	\
    ( (This)->lpVtbl -> getInterfaceElement(This,index,elementType,fieldType,name) ) 

#define Node_getValueNode(This,result)	\
    ( (This)->lpVtbl -> getValueNode(This,result) ) 

#define Node_getNative(This,result)	\
    ( (This)->lpVtbl -> getNative(This,result) ) 

#define Node_getRefCnt(This,result)	\
    ( (This)->lpVtbl -> getRefCnt(This,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __Node_INTERFACE_DEFINED__ */


#ifndef __Browser_INTERFACE_DEFINED__
#define __Browser_INTERFACE_DEFINED__

/* interface Browser */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_Browser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC5046F-75D9-11D0-9315-0020AFE05CC8")
    Browser : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getName( 
            /* [retval][out] */ BSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getVersion( 
            /* [retval][out] */ BSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getCurrentSpeed( 
            /* [retval][out] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getCurrentFrameRate( 
            /* [retval][out] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getWorldURL( 
            /* [retval][out] */ BSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE replaceWorld( 
            Node *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE loadURL( 
            /* [in] */ int cntUrl,
            /* [size_is][in] */ BSTR *url,
            /* [in] */ int cntParameter,
            /* [size_is][in] */ BSTR *parameter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setDescription( 
            /* [in] */ BSTR description) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE createVrmlFromString( 
            /* [in] */ BSTR vrmlSyntax,
            /* [retval][out] */ Node **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE createVrmlFromURL( 
            /* [in] */ BSTR url,
            /* [in] */ Node *node,
            /* [in] */ BSTR event) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getNode( 
            /* [in] */ BSTR name,
            /* [retval][out] */ Node **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE addRoute( 
            /* [in] */ Node *fromNode,
            /* [in] */ BSTR fromEventOut,
            /* [in] */ Node *toNode,
            /* [in] */ BSTR toEventIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE deleteRoute( 
            /* [in] */ Node *fromNode,
            /* [in] */ BSTR fromEventOut,
            /* [in] */ Node *toNode,
            /* [in] */ BSTR toEventIn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE createNode( 
            /* [in] */ BSTR nodeclass,
            /* [retval][out] */ Node **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getWorld( 
            /* [retval][out] */ Node **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE beginUpdate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE endUpdate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE addNode( 
            /* [in] */ Node *node) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE removeNode( 
            /* [in] */ Node *node,
            /* [retval][out] */ VARIANT_BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setNodeName( 
            /* [in] */ Node *node,
            /* [in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getNodeName( 
            /* [in] */ Node *node,
            /* [retval][out] */ BSTR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getEventOut( 
            BSTR eventOutName,
            /* [retval][out] */ EventOut **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getEventIn( 
            BSTR eventInName,
            /* [retval][out] */ EventIn **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getControlPathname( 
            /* [retval][out] */ BSTR *directoryName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE saveWorld( 
            /* [in] */ BSTR fileName,
            /* [retval][out] */ VARIANT_BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE saveViewpoint( 
            /* [in] */ BSTR viewpointName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setObserver( 
            /* [in] */ IUnknown *observer,
            /* [in] */ int flags,
            /* [retval][out] */ VARIANT_BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setViewpointByValue( 
            /* [size_is][in] */ float *position,
            /* [size_is][in] */ float *orientation,
            /* [in] */ float fov,
            /* [in] */ VARIANT_BOOL animate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setFullscreen( 
            /* [in] */ VARIANT_BOOL mode,
            /* [retval][out] */ VARIANT_BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setCollisionDetection( 
            /* [in] */ VARIANT_BOOL mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setRenderMode( 
            /* [in] */ BSTR mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setNavigationMode( 
            /* [in] */ BSTR mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setViewpoint( 
            /* [in] */ BSTR viewpointName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setHeadlight( 
            /* [in] */ VARIANT_BOOL mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setAvatarHeight( 
            /* [in] */ float value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setCollisionDistance( 
            /* [in] */ float value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setVisibilityLimit( 
            /* [in] */ float value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setWalkSpeed( 
            /* [in] */ float value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setNavigationPanel( 
            /* [in] */ VARIANT_BOOL mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getNavigationPanel( 
            /* [retval][out] */ VARIANT_BOOL *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct BrowserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Browser * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Browser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Browser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Browser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Browser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Browser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Browser * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getName )( 
            Browser * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getVersion )( 
            Browser * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getCurrentSpeed )( 
            Browser * This,
            /* [retval][out] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *getCurrentFrameRate )( 
            Browser * This,
            /* [retval][out] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *getWorldURL )( 
            Browser * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *replaceWorld )( 
            Browser * This,
            Node *value);
        
        HRESULT ( STDMETHODCALLTYPE *loadURL )( 
            Browser * This,
            /* [in] */ int cntUrl,
            /* [size_is][in] */ BSTR *url,
            /* [in] */ int cntParameter,
            /* [size_is][in] */ BSTR *parameter);
        
        HRESULT ( STDMETHODCALLTYPE *setDescription )( 
            Browser * This,
            /* [in] */ BSTR description);
        
        HRESULT ( STDMETHODCALLTYPE *createVrmlFromString )( 
            Browser * This,
            /* [in] */ BSTR vrmlSyntax,
            /* [retval][out] */ Node **value);
        
        HRESULT ( STDMETHODCALLTYPE *createVrmlFromURL )( 
            Browser * This,
            /* [in] */ BSTR url,
            /* [in] */ Node *node,
            /* [in] */ BSTR event);
        
        HRESULT ( STDMETHODCALLTYPE *getNode )( 
            Browser * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ Node **value);
        
        HRESULT ( STDMETHODCALLTYPE *addRoute )( 
            Browser * This,
            /* [in] */ Node *fromNode,
            /* [in] */ BSTR fromEventOut,
            /* [in] */ Node *toNode,
            /* [in] */ BSTR toEventIn);
        
        HRESULT ( STDMETHODCALLTYPE *deleteRoute )( 
            Browser * This,
            /* [in] */ Node *fromNode,
            /* [in] */ BSTR fromEventOut,
            /* [in] */ Node *toNode,
            /* [in] */ BSTR toEventIn);
        
        HRESULT ( STDMETHODCALLTYPE *createNode )( 
            Browser * This,
            /* [in] */ BSTR nodeclass,
            /* [retval][out] */ Node **value);
        
        HRESULT ( STDMETHODCALLTYPE *getWorld )( 
            Browser * This,
            /* [retval][out] */ Node **value);
        
        HRESULT ( STDMETHODCALLTYPE *beginUpdate )( 
            Browser * This);
        
        HRESULT ( STDMETHODCALLTYPE *endUpdate )( 
            Browser * This);
        
        HRESULT ( STDMETHODCALLTYPE *addNode )( 
            Browser * This,
            /* [in] */ Node *node);
        
        HRESULT ( STDMETHODCALLTYPE *removeNode )( 
            Browser * This,
            /* [in] */ Node *node,
            /* [retval][out] */ VARIANT_BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *setNodeName )( 
            Browser * This,
            /* [in] */ Node *node,
            /* [in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *getNodeName )( 
            Browser * This,
            /* [in] */ Node *node,
            /* [retval][out] */ BSTR *name);
        
        HRESULT ( STDMETHODCALLTYPE *getEventOut )( 
            Browser * This,
            BSTR eventOutName,
            /* [retval][out] */ EventOut **value);
        
        HRESULT ( STDMETHODCALLTYPE *getEventIn )( 
            Browser * This,
            BSTR eventInName,
            /* [retval][out] */ EventIn **value);
        
        HRESULT ( STDMETHODCALLTYPE *getControlPathname )( 
            Browser * This,
            /* [retval][out] */ BSTR *directoryName);
        
        HRESULT ( STDMETHODCALLTYPE *saveWorld )( 
            Browser * This,
            /* [in] */ BSTR fileName,
            /* [retval][out] */ VARIANT_BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *saveViewpoint )( 
            Browser * This,
            /* [in] */ BSTR viewpointName);
        
        HRESULT ( STDMETHODCALLTYPE *setObserver )( 
            Browser * This,
            /* [in] */ IUnknown *observer,
            /* [in] */ int flags,
            /* [retval][out] */ VARIANT_BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *setViewpointByValue )( 
            Browser * This,
            /* [size_is][in] */ float *position,
            /* [size_is][in] */ float *orientation,
            /* [in] */ float fov,
            /* [in] */ VARIANT_BOOL animate);
        
        HRESULT ( STDMETHODCALLTYPE *setFullscreen )( 
            Browser * This,
            /* [in] */ VARIANT_BOOL mode,
            /* [retval][out] */ VARIANT_BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *setCollisionDetection )( 
            Browser * This,
            /* [in] */ VARIANT_BOOL mode);
        
        HRESULT ( STDMETHODCALLTYPE *setRenderMode )( 
            Browser * This,
            /* [in] */ BSTR mode);
        
        HRESULT ( STDMETHODCALLTYPE *setNavigationMode )( 
            Browser * This,
            /* [in] */ BSTR mode);
        
        HRESULT ( STDMETHODCALLTYPE *setViewpoint )( 
            Browser * This,
            /* [in] */ BSTR viewpointName);
        
        HRESULT ( STDMETHODCALLTYPE *setHeadlight )( 
            Browser * This,
            /* [in] */ VARIANT_BOOL mode);
        
        HRESULT ( STDMETHODCALLTYPE *setAvatarHeight )( 
            Browser * This,
            /* [in] */ float value);
        
        HRESULT ( STDMETHODCALLTYPE *setCollisionDistance )( 
            Browser * This,
            /* [in] */ float value);
        
        HRESULT ( STDMETHODCALLTYPE *setVisibilityLimit )( 
            Browser * This,
            /* [in] */ float value);
        
        HRESULT ( STDMETHODCALLTYPE *setWalkSpeed )( 
            Browser * This,
            /* [in] */ float value);
        
        HRESULT ( STDMETHODCALLTYPE *setNavigationPanel )( 
            Browser * This,
            /* [in] */ VARIANT_BOOL mode);
        
        HRESULT ( STDMETHODCALLTYPE *getNavigationPanel )( 
            Browser * This,
            /* [retval][out] */ VARIANT_BOOL *value);
        
        END_INTERFACE
    } BrowserVtbl;

    interface Browser
    {
        CONST_VTBL struct BrowserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Browser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Browser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Browser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Browser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Browser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Browser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Browser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define Browser_getName(This,value)	\
    ( (This)->lpVtbl -> getName(This,value) ) 

#define Browser_getVersion(This,value)	\
    ( (This)->lpVtbl -> getVersion(This,value) ) 

#define Browser_getCurrentSpeed(This,value)	\
    ( (This)->lpVtbl -> getCurrentSpeed(This,value) ) 

#define Browser_getCurrentFrameRate(This,value)	\
    ( (This)->lpVtbl -> getCurrentFrameRate(This,value) ) 

#define Browser_getWorldURL(This,value)	\
    ( (This)->lpVtbl -> getWorldURL(This,value) ) 

#define Browser_replaceWorld(This,value)	\
    ( (This)->lpVtbl -> replaceWorld(This,value) ) 

#define Browser_loadURL(This,cntUrl,url,cntParameter,parameter)	\
    ( (This)->lpVtbl -> loadURL(This,cntUrl,url,cntParameter,parameter) ) 

#define Browser_setDescription(This,description)	\
    ( (This)->lpVtbl -> setDescription(This,description) ) 

#define Browser_createVrmlFromString(This,vrmlSyntax,value)	\
    ( (This)->lpVtbl -> createVrmlFromString(This,vrmlSyntax,value) ) 

#define Browser_createVrmlFromURL(This,url,node,event)	\
    ( (This)->lpVtbl -> createVrmlFromURL(This,url,node,event) ) 

#define Browser_getNode(This,name,value)	\
    ( (This)->lpVtbl -> getNode(This,name,value) ) 

#define Browser_addRoute(This,fromNode,fromEventOut,toNode,toEventIn)	\
    ( (This)->lpVtbl -> addRoute(This,fromNode,fromEventOut,toNode,toEventIn) ) 

#define Browser_deleteRoute(This,fromNode,fromEventOut,toNode,toEventIn)	\
    ( (This)->lpVtbl -> deleteRoute(This,fromNode,fromEventOut,toNode,toEventIn) ) 

#define Browser_createNode(This,nodeclass,value)	\
    ( (This)->lpVtbl -> createNode(This,nodeclass,value) ) 

#define Browser_getWorld(This,value)	\
    ( (This)->lpVtbl -> getWorld(This,value) ) 

#define Browser_beginUpdate(This)	\
    ( (This)->lpVtbl -> beginUpdate(This) ) 

#define Browser_endUpdate(This)	\
    ( (This)->lpVtbl -> endUpdate(This) ) 

#define Browser_addNode(This,node)	\
    ( (This)->lpVtbl -> addNode(This,node) ) 

#define Browser_removeNode(This,node,value)	\
    ( (This)->lpVtbl -> removeNode(This,node,value) ) 

#define Browser_setNodeName(This,node,name)	\
    ( (This)->lpVtbl -> setNodeName(This,node,name) ) 

#define Browser_getNodeName(This,node,name)	\
    ( (This)->lpVtbl -> getNodeName(This,node,name) ) 

#define Browser_getEventOut(This,eventOutName,value)	\
    ( (This)->lpVtbl -> getEventOut(This,eventOutName,value) ) 

#define Browser_getEventIn(This,eventInName,value)	\
    ( (This)->lpVtbl -> getEventIn(This,eventInName,value) ) 

#define Browser_getControlPathname(This,directoryName)	\
    ( (This)->lpVtbl -> getControlPathname(This,directoryName) ) 

#define Browser_saveWorld(This,fileName,value)	\
    ( (This)->lpVtbl -> saveWorld(This,fileName,value) ) 

#define Browser_saveViewpoint(This,viewpointName)	\
    ( (This)->lpVtbl -> saveViewpoint(This,viewpointName) ) 

#define Browser_setObserver(This,observer,flags,value)	\
    ( (This)->lpVtbl -> setObserver(This,observer,flags,value) ) 

#define Browser_setViewpointByValue(This,position,orientation,fov,animate)	\
    ( (This)->lpVtbl -> setViewpointByValue(This,position,orientation,fov,animate) ) 

#define Browser_setFullscreen(This,mode,value)	\
    ( (This)->lpVtbl -> setFullscreen(This,mode,value) ) 

#define Browser_setCollisionDetection(This,mode)	\
    ( (This)->lpVtbl -> setCollisionDetection(This,mode) ) 

#define Browser_setRenderMode(This,mode)	\
    ( (This)->lpVtbl -> setRenderMode(This,mode) ) 

#define Browser_setNavigationMode(This,mode)	\
    ( (This)->lpVtbl -> setNavigationMode(This,mode) ) 

#define Browser_setViewpoint(This,viewpointName)	\
    ( (This)->lpVtbl -> setViewpoint(This,viewpointName) ) 

#define Browser_setHeadlight(This,mode)	\
    ( (This)->lpVtbl -> setHeadlight(This,mode) ) 

#define Browser_setAvatarHeight(This,value)	\
    ( (This)->lpVtbl -> setAvatarHeight(This,value) ) 

#define Browser_setCollisionDistance(This,value)	\
    ( (This)->lpVtbl -> setCollisionDistance(This,value) ) 

#define Browser_setVisibilityLimit(This,value)	\
    ( (This)->lpVtbl -> setVisibilityLimit(This,value) ) 

#define Browser_setWalkSpeed(This,value)	\
    ( (This)->lpVtbl -> setWalkSpeed(This,value) ) 

#define Browser_setNavigationPanel(This,mode)	\
    ( (This)->lpVtbl -> setNavigationPanel(This,mode) ) 

#define Browser_getNavigationPanel(This,value)	\
    ( (This)->lpVtbl -> getNavigationPanel(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __Browser_INTERFACE_DEFINED__ */


#ifndef __Field_INTERFACE_DEFINED__
#define __Field_INTERFACE_DEFINED__

/* interface Field */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_Field;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50398-75D9-11D0-9315-0020AFE05CC8")
    Field : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getType( 
            /* [retval][out] */ int *type) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct FieldVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Field * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Field * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Field * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Field * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Field * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Field * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Field * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            Field * This,
            /* [retval][out] */ int *type);
        
        END_INTERFACE
    } FieldVtbl;

    interface Field
    {
        CONST_VTBL struct FieldVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Field_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Field_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Field_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Field_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Field_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Field_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Field_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define Field_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __Field_INTERFACE_DEFINED__ */


#ifndef __EventIn_INTERFACE_DEFINED__
#define __EventIn_INTERFACE_DEFINED__

/* interface EventIn */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventIn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC5039D-75D9-11D0-9315-0020AFE05CC8")
    EventIn : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getType( 
            /* [retval][out] */ int *type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setValueFromString( 
            /* [in] */ BSTR value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventIn * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventIn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventIn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventIn * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventIn * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventIn * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventIn * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventIn * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventIn * This,
            /* [in] */ BSTR value);
        
        END_INTERFACE
    } EventInVtbl;

    interface EventIn
    {
        CONST_VTBL struct EventInVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventIn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventIn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventIn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventIn_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventIn_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventIn_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventIn_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventIn_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventIn_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventIn_INTERFACE_DEFINED__ */


#ifndef __EventOut_INTERFACE_DEFINED__
#define __EventOut_INTERFACE_DEFINED__

/* interface EventOut */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOut;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503F7-75D9-11D0-9315-0020AFE05CC8")
    EventOut : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getType( 
            /* [retval][out] */ int *type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE advise( 
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE unAdvise( 
            /* [in] */ EventOutObserver *observer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE toString( 
            /* [retval][out] */ BSTR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOut * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOut * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOut * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOut * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOut * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOut * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOut * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOut * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOut * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOut * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOut * This,
            /* [retval][out] */ BSTR *value);
        
        END_INTERFACE
    } EventOutVtbl;

    interface EventOut
    {
        CONST_VTBL struct EventOutVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOut_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOut_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOut_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOut_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOut_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOut_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOut_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOut_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOut_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOut_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOut_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOut_INTERFACE_DEFINED__ */


#ifndef __EventInSFFloat_INTERFACE_DEFINED__
#define __EventInSFFloat_INTERFACE_DEFINED__

/* interface EventInSFFloat */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFFloat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503D9-75D9-11D0-9315-0020AFE05CC8")
    EventInSFFloat : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ float value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFFloatVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFFloat * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFFloat * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFFloat * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFFloat * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFFloat * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFFloat * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFFloat * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFFloat * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFFloat * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFFloat * This,
            /* [in] */ float value);
        
        END_INTERFACE
    } EventInSFFloatVtbl;

    interface EventInSFFloat
    {
        CONST_VTBL struct EventInSFFloatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFFloat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFFloat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFFloat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFFloat_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFFloat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFFloat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFFloat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFFloat_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFFloat_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFFloat_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFFloat_INTERFACE_DEFINED__ */


#ifndef __EventInSFBool_INTERFACE_DEFINED__
#define __EventInSFBool_INTERFACE_DEFINED__

/* interface EventInSFBool */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFBool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503CA-75D9-11D0-9315-0020AFE05CC8")
    EventInSFBool : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ VARIANT_BOOL value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFBoolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFBool * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFBool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFBool * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFBool * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFBool * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFBool * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFBool * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFBool * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFBool * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFBool * This,
            /* [in] */ VARIANT_BOOL value);
        
        END_INTERFACE
    } EventInSFBoolVtbl;

    interface EventInSFBool
    {
        CONST_VTBL struct EventInSFBoolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFBool_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFBool_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFBool_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFBool_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFBool_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFBool_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFBool_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFBool_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFBool_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFBool_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFBool_INTERFACE_DEFINED__ */


#ifndef __EventOutMField_INTERFACE_DEFINED__
#define __EventOutMField_INTERFACE_DEFINED__

/* interface EventOutMField */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutMField;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC5040B-75D9-11D0-9315-0020AFE05CC8")
    EventOutMField : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getSize( 
            /* [retval][out] */ int *cnt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutMFieldVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutMField * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutMField * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutMField * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutMField * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutMField * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutMField * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutMField * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutMField * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutMField * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutMField * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutMField * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSize )( 
            EventOutMField * This,
            /* [retval][out] */ int *cnt);
        
        END_INTERFACE
    } EventOutMFieldVtbl;

    interface EventOutMField
    {
        CONST_VTBL struct EventOutMFieldVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutMField_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutMField_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutMField_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutMField_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutMField_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutMField_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutMField_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutMField_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutMField_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutMField_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutMField_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutMField_getSize(This,cnt)	\
    ( (This)->lpVtbl -> getSize(This,cnt) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutMField_INTERFACE_DEFINED__ */


#ifndef __EventInMFColor_INTERFACE_DEFINED__
#define __EventInMFColor_INTERFACE_DEFINED__

/* interface EventInMFColor */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInMFColor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503A2-75D9-11D0-9315-0020AFE05CC8")
    EventInMFColor : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int cnt,
            /* [size_is][in] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set1Value( 
            /* [in] */ int index,
            /* [size_is][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInMFColorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInMFColor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInMFColor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInMFColor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInMFColor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInMFColor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInMFColor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInMFColor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInMFColor * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInMFColor * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInMFColor * This,
            /* [in] */ int cnt,
            /* [size_is][in] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *set1Value )( 
            EventInMFColor * This,
            /* [in] */ int index,
            /* [size_is][in] */ float *value);
        
        END_INTERFACE
    } EventInMFColorVtbl;

    interface EventInMFColor
    {
        CONST_VTBL struct EventInMFColorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInMFColor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInMFColor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInMFColor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInMFColor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInMFColor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInMFColor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInMFColor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInMFColor_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInMFColor_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInMFColor_setValue(This,cnt,value)	\
    ( (This)->lpVtbl -> setValue(This,cnt,value) ) 

#define EventInMFColor_set1Value(This,index,value)	\
    ( (This)->lpVtbl -> set1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInMFColor_INTERFACE_DEFINED__ */


#ifndef __EventInMFFloat_INTERFACE_DEFINED__
#define __EventInMFFloat_INTERFACE_DEFINED__

/* interface EventInMFFloat */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInMFFloat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503A7-75D9-11D0-9315-0020AFE05CC8")
    EventInMFFloat : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int cnt,
            /* [size_is][in] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set1Value( 
            /* [in] */ int index,
            /* [in] */ float value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInMFFloatVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInMFFloat * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInMFFloat * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInMFFloat * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInMFFloat * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInMFFloat * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInMFFloat * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInMFFloat * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInMFFloat * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInMFFloat * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInMFFloat * This,
            /* [in] */ int cnt,
            /* [size_is][in] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *set1Value )( 
            EventInMFFloat * This,
            /* [in] */ int index,
            /* [in] */ float value);
        
        END_INTERFACE
    } EventInMFFloatVtbl;

    interface EventInMFFloat
    {
        CONST_VTBL struct EventInMFFloatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInMFFloat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInMFFloat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInMFFloat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInMFFloat_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInMFFloat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInMFFloat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInMFFloat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInMFFloat_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInMFFloat_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInMFFloat_setValue(This,cnt,value)	\
    ( (This)->lpVtbl -> setValue(This,cnt,value) ) 

#define EventInMFFloat_set1Value(This,index,value)	\
    ( (This)->lpVtbl -> set1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInMFFloat_INTERFACE_DEFINED__ */


#ifndef __EventInMFTime_INTERFACE_DEFINED__
#define __EventInMFTime_INTERFACE_DEFINED__

/* interface EventInMFTime */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInMFTime;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5EEE9A1-6771-11d2-ABB2-00A0C9C7B4A1")
    EventInMFTime : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int cnt,
            /* [size_is][in] */ double *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set1Value( 
            /* [in] */ int index,
            /* [in] */ double value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInMFTimeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInMFTime * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInMFTime * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInMFTime * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInMFTime * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInMFTime * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInMFTime * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInMFTime * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInMFTime * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInMFTime * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInMFTime * This,
            /* [in] */ int cnt,
            /* [size_is][in] */ double *value);
        
        HRESULT ( STDMETHODCALLTYPE *set1Value )( 
            EventInMFTime * This,
            /* [in] */ int index,
            /* [in] */ double value);
        
        END_INTERFACE
    } EventInMFTimeVtbl;

    interface EventInMFTime
    {
        CONST_VTBL struct EventInMFTimeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInMFTime_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInMFTime_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInMFTime_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInMFTime_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInMFTime_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInMFTime_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInMFTime_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInMFTime_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInMFTime_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInMFTime_setValue(This,cnt,value)	\
    ( (This)->lpVtbl -> setValue(This,cnt,value) ) 

#define EventInMFTime_set1Value(This,index,value)	\
    ( (This)->lpVtbl -> set1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInMFTime_INTERFACE_DEFINED__ */


#ifndef __EventInMFInt32_INTERFACE_DEFINED__
#define __EventInMFInt32_INTERFACE_DEFINED__

/* interface EventInMFInt32 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInMFInt32;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503AC-75D9-11D0-9315-0020AFE05CC8")
    EventInMFInt32 : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int cnt,
            /* [size_is][in] */ int *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set1Value( 
            /* [in] */ int index,
            /* [in] */ int value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInMFInt32Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInMFInt32 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInMFInt32 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInMFInt32 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInMFInt32 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInMFInt32 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInMFInt32 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInMFInt32 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInMFInt32 * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInMFInt32 * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInMFInt32 * This,
            /* [in] */ int cnt,
            /* [size_is][in] */ int *value);
        
        HRESULT ( STDMETHODCALLTYPE *set1Value )( 
            EventInMFInt32 * This,
            /* [in] */ int index,
            /* [in] */ int value);
        
        END_INTERFACE
    } EventInMFInt32Vtbl;

    interface EventInMFInt32
    {
        CONST_VTBL struct EventInMFInt32Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInMFInt32_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInMFInt32_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInMFInt32_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInMFInt32_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInMFInt32_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInMFInt32_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInMFInt32_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInMFInt32_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInMFInt32_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInMFInt32_setValue(This,cnt,value)	\
    ( (This)->lpVtbl -> setValue(This,cnt,value) ) 

#define EventInMFInt32_set1Value(This,index,value)	\
    ( (This)->lpVtbl -> set1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInMFInt32_INTERFACE_DEFINED__ */


#ifndef __EventInMFNode_INTERFACE_DEFINED__
#define __EventInMFNode_INTERFACE_DEFINED__

/* interface EventInMFNode */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInMFNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503B1-75D9-11D0-9315-0020AFE05CC8")
    EventInMFNode : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ IDispatch **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set1Value( 
            /* [in] */ int index,
            /* [in] */ Node *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInMFNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInMFNode * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInMFNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInMFNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInMFNode * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInMFNode * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInMFNode * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInMFNode * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInMFNode * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInMFNode * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInMFNode * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ IDispatch **value);
        
        HRESULT ( STDMETHODCALLTYPE *set1Value )( 
            EventInMFNode * This,
            /* [in] */ int index,
            /* [in] */ Node *value);
        
        END_INTERFACE
    } EventInMFNodeVtbl;

    interface EventInMFNode
    {
        CONST_VTBL struct EventInMFNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInMFNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInMFNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInMFNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInMFNode_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInMFNode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInMFNode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInMFNode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInMFNode_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInMFNode_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInMFNode_setValue(This,cnt,value)	\
    ( (This)->lpVtbl -> setValue(This,cnt,value) ) 

#define EventInMFNode_set1Value(This,index,value)	\
    ( (This)->lpVtbl -> set1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInMFNode_INTERFACE_DEFINED__ */


#ifndef __EventInMFRotation_INTERFACE_DEFINED__
#define __EventInMFRotation_INTERFACE_DEFINED__

/* interface EventInMFRotation */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInMFRotation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503B6-75D9-11D0-9315-0020AFE05CC8")
    EventInMFRotation : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int cnt,
            /* [size_is][in] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set1Value( 
            /* [in] */ int index,
            /* [size_is][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInMFRotationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInMFRotation * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInMFRotation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInMFRotation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInMFRotation * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInMFRotation * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInMFRotation * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInMFRotation * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInMFRotation * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInMFRotation * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInMFRotation * This,
            /* [in] */ int cnt,
            /* [size_is][in] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *set1Value )( 
            EventInMFRotation * This,
            /* [in] */ int index,
            /* [size_is][in] */ float *value);
        
        END_INTERFACE
    } EventInMFRotationVtbl;

    interface EventInMFRotation
    {
        CONST_VTBL struct EventInMFRotationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInMFRotation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInMFRotation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInMFRotation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInMFRotation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInMFRotation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInMFRotation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInMFRotation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInMFRotation_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInMFRotation_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInMFRotation_setValue(This,cnt,value)	\
    ( (This)->lpVtbl -> setValue(This,cnt,value) ) 

#define EventInMFRotation_set1Value(This,index,value)	\
    ( (This)->lpVtbl -> set1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInMFRotation_INTERFACE_DEFINED__ */


#ifndef __EventInMFString_INTERFACE_DEFINED__
#define __EventInMFString_INTERFACE_DEFINED__

/* interface EventInMFString */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInMFString;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503BB-75D9-11D0-9315-0020AFE05CC8")
    EventInMFString : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int cnt,
            /* [size_is][in] */ BSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set1Value( 
            /* [in] */ int index,
            /* [in] */ BSTR value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInMFStringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInMFString * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInMFString * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInMFString * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInMFString * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInMFString * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInMFString * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInMFString * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInMFString * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInMFString * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInMFString * This,
            /* [in] */ int cnt,
            /* [size_is][in] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *set1Value )( 
            EventInMFString * This,
            /* [in] */ int index,
            /* [in] */ BSTR value);
        
        END_INTERFACE
    } EventInMFStringVtbl;

    interface EventInMFString
    {
        CONST_VTBL struct EventInMFStringVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInMFString_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInMFString_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInMFString_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInMFString_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInMFString_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInMFString_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInMFString_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInMFString_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInMFString_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInMFString_setValue(This,cnt,value)	\
    ( (This)->lpVtbl -> setValue(This,cnt,value) ) 

#define EventInMFString_set1Value(This,index,value)	\
    ( (This)->lpVtbl -> set1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInMFString_INTERFACE_DEFINED__ */


#ifndef __EventInMFVec2f_INTERFACE_DEFINED__
#define __EventInMFVec2f_INTERFACE_DEFINED__

/* interface EventInMFVec2f */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInMFVec2f;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503C0-75D9-11D0-9315-0020AFE05CC8")
    EventInMFVec2f : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int cnt,
            /* [size_is][in] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set1Value( 
            /* [in] */ int index,
            /* [size_is][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInMFVec2fVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInMFVec2f * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInMFVec2f * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInMFVec2f * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInMFVec2f * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInMFVec2f * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInMFVec2f * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInMFVec2f * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInMFVec2f * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInMFVec2f * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInMFVec2f * This,
            /* [in] */ int cnt,
            /* [size_is][in] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *set1Value )( 
            EventInMFVec2f * This,
            /* [in] */ int index,
            /* [size_is][in] */ float *value);
        
        END_INTERFACE
    } EventInMFVec2fVtbl;

    interface EventInMFVec2f
    {
        CONST_VTBL struct EventInMFVec2fVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInMFVec2f_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInMFVec2f_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInMFVec2f_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInMFVec2f_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInMFVec2f_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInMFVec2f_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInMFVec2f_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInMFVec2f_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInMFVec2f_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInMFVec2f_setValue(This,cnt,value)	\
    ( (This)->lpVtbl -> setValue(This,cnt,value) ) 

#define EventInMFVec2f_set1Value(This,index,value)	\
    ( (This)->lpVtbl -> set1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInMFVec2f_INTERFACE_DEFINED__ */


#ifndef __EventInMFVec3f_INTERFACE_DEFINED__
#define __EventInMFVec3f_INTERFACE_DEFINED__

/* interface EventInMFVec3f */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInMFVec3f;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503C5-75D9-11D0-9315-0020AFE05CC8")
    EventInMFVec3f : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int cnt,
            /* [size_is][in] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE set1Value( 
            /* [in] */ int index,
            /* [size_is][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInMFVec3fVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInMFVec3f * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInMFVec3f * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInMFVec3f * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInMFVec3f * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInMFVec3f * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInMFVec3f * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInMFVec3f * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInMFVec3f * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInMFVec3f * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInMFVec3f * This,
            /* [in] */ int cnt,
            /* [size_is][in] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *set1Value )( 
            EventInMFVec3f * This,
            /* [in] */ int index,
            /* [size_is][in] */ float *value);
        
        END_INTERFACE
    } EventInMFVec3fVtbl;

    interface EventInMFVec3f
    {
        CONST_VTBL struct EventInMFVec3fVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInMFVec3f_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInMFVec3f_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInMFVec3f_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInMFVec3f_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInMFVec3f_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInMFVec3f_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInMFVec3f_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInMFVec3f_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInMFVec3f_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInMFVec3f_setValue(This,cnt,value)	\
    ( (This)->lpVtbl -> setValue(This,cnt,value) ) 

#define EventInMFVec3f_set1Value(This,index,value)	\
    ( (This)->lpVtbl -> set1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInMFVec3f_INTERFACE_DEFINED__ */


#ifndef __EventInSFColor_INTERFACE_DEFINED__
#define __EventInSFColor_INTERFACE_DEFINED__

/* interface EventInSFColor */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFColor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503CF-75D9-11D0-9315-0020AFE05CC8")
    EventInSFColor : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [size_is][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFColorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFColor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFColor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFColor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFColor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFColor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFColor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFColor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFColor * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFColor * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFColor * This,
            /* [size_is][in] */ float *value);
        
        END_INTERFACE
    } EventInSFColorVtbl;

    interface EventInSFColor
    {
        CONST_VTBL struct EventInSFColorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFColor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFColor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFColor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFColor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFColor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFColor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFColor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFColor_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFColor_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFColor_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFColor_INTERFACE_DEFINED__ */


#ifndef __EventInSFImage_INTERFACE_DEFINED__
#define __EventInSFImage_INTERFACE_DEFINED__

/* interface EventInSFImage */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503DE-75D9-11D0-9315-0020AFE05CC8")
    EventInSFImage : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ int numComponents,
            /* [in] */ int cnt,
            /* [size_is][in] */ unsigned small *pixels) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFImage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFImage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFImage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFImage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFImage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFImage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFImage * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFImage * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFImage * This,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ int numComponents,
            /* [in] */ int cnt,
            /* [size_is][in] */ unsigned small *pixels);
        
        END_INTERFACE
    } EventInSFImageVtbl;

    interface EventInSFImage
    {
        CONST_VTBL struct EventInSFImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFImage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFImage_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFImage_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFImage_setValue(This,width,height,numComponents,cnt,pixels)	\
    ( (This)->lpVtbl -> setValue(This,width,height,numComponents,cnt,pixels) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFImage_INTERFACE_DEFINED__ */


#ifndef __EventInSFInt32_INTERFACE_DEFINED__
#define __EventInSFInt32_INTERFACE_DEFINED__

/* interface EventInSFInt32 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFInt32;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503E3-75D9-11D0-9315-0020AFE05CC8")
    EventInSFInt32 : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ int value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFInt32Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFInt32 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFInt32 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFInt32 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFInt32 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFInt32 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFInt32 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFInt32 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFInt32 * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFInt32 * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFInt32 * This,
            /* [in] */ int value);
        
        END_INTERFACE
    } EventInSFInt32Vtbl;

    interface EventInSFInt32
    {
        CONST_VTBL struct EventInSFInt32Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFInt32_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFInt32_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFInt32_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFInt32_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFInt32_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFInt32_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFInt32_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFInt32_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFInt32_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFInt32_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFInt32_INTERFACE_DEFINED__ */


#ifndef __EventInSFNode_INTERFACE_DEFINED__
#define __EventInSFNode_INTERFACE_DEFINED__

/* interface EventInSFNode */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503E8-75D9-11D0-9315-0020AFE05CC8")
    EventInSFNode : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ Node *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFNode * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFNode * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFNode * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFNode * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFNode * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFNode * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFNode * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFNode * This,
            /* [in] */ Node *value);
        
        END_INTERFACE
    } EventInSFNodeVtbl;

    interface EventInSFNode
    {
        CONST_VTBL struct EventInSFNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFNode_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFNode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFNode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFNode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFNode_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFNode_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFNode_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFNode_INTERFACE_DEFINED__ */


#ifndef __EventInSFRotation_INTERFACE_DEFINED__
#define __EventInSFRotation_INTERFACE_DEFINED__

/* interface EventInSFRotation */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFRotation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503ED-75D9-11D0-9315-0020AFE05CC8")
    EventInSFRotation : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [size_is][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFRotationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFRotation * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFRotation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFRotation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFRotation * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFRotation * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFRotation * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFRotation * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFRotation * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFRotation * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFRotation * This,
            /* [size_is][in] */ float *value);
        
        END_INTERFACE
    } EventInSFRotationVtbl;

    interface EventInSFRotation
    {
        CONST_VTBL struct EventInSFRotationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFRotation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFRotation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFRotation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFRotation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFRotation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFRotation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFRotation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFRotation_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFRotation_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFRotation_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFRotation_INTERFACE_DEFINED__ */


#ifndef __EventInSFString_INTERFACE_DEFINED__
#define __EventInSFString_INTERFACE_DEFINED__

/* interface EventInSFString */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFString;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503F2-75D9-11D0-9315-0020AFE05CC8")
    EventInSFString : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ BSTR value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFStringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFString * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFString * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFString * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFString * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFString * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFString * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFString * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFString * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFString * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFString * This,
            /* [in] */ BSTR value);
        
        END_INTERFACE
    } EventInSFStringVtbl;

    interface EventInSFString
    {
        CONST_VTBL struct EventInSFStringVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFString_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFString_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFString_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFString_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFString_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFString_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFString_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFString_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFString_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFString_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFString_INTERFACE_DEFINED__ */


#ifndef __EventInSFTime_INTERFACE_DEFINED__
#define __EventInSFTime_INTERFACE_DEFINED__

/* interface EventInSFTime */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFTime;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503D4-75D9-11D0-9315-0020AFE05CC8")
    EventInSFTime : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [in] */ double value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFTimeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFTime * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFTime * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFTime * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFTime * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFTime * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFTime * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFTime * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFTime * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFTime * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFTime * This,
            /* [in] */ double value);
        
        END_INTERFACE
    } EventInSFTimeVtbl;

    interface EventInSFTime
    {
        CONST_VTBL struct EventInSFTimeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFTime_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFTime_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFTime_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFTime_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFTime_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFTime_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFTime_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFTime_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFTime_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFTime_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFTime_INTERFACE_DEFINED__ */


#ifndef __EventInSFVec2f_INTERFACE_DEFINED__
#define __EventInSFVec2f_INTERFACE_DEFINED__

/* interface EventInSFVec2f */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFVec2f;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC503FC-75D9-11D0-9315-0020AFE05CC8")
    EventInSFVec2f : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [size_is][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFVec2fVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFVec2f * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFVec2f * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFVec2f * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFVec2f * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFVec2f * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFVec2f * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFVec2f * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFVec2f * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFVec2f * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFVec2f * This,
            /* [size_is][in] */ float *value);
        
        END_INTERFACE
    } EventInSFVec2fVtbl;

    interface EventInSFVec2f
    {
        CONST_VTBL struct EventInSFVec2fVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFVec2f_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFVec2f_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFVec2f_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFVec2f_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFVec2f_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFVec2f_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFVec2f_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFVec2f_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFVec2f_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFVec2f_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFVec2f_INTERFACE_DEFINED__ */


#ifndef __EventInSFVec3f_INTERFACE_DEFINED__
#define __EventInSFVec3f_INTERFACE_DEFINED__

/* interface EventInSFVec3f */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFVec3f;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50401-75D9-11D0-9315-0020AFE05CC8")
    EventInSFVec3f : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [size_is][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFVec3fVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFVec3f * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFVec3f * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFVec3f * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFVec3f * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFVec3f * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFVec3f * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFVec3f * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFVec3f * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFVec3f * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFVec3f * This,
            /* [size_is][in] */ float *value);
        
        END_INTERFACE
    } EventInSFVec3fVtbl;

    interface EventInSFVec3f
    {
        CONST_VTBL struct EventInSFVec3fVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFVec3f_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFVec3f_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFVec3f_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFVec3f_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFVec3f_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFVec3f_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFVec3f_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFVec3f_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFVec3f_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFVec3f_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFVec3f_INTERFACE_DEFINED__ */


#ifndef __EventInSFMatrix_INTERFACE_DEFINED__
#define __EventInSFMatrix_INTERFACE_DEFINED__

/* interface EventInSFMatrix */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventInSFMatrix;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9966B8D9-B13D-4461-8617-747B9DB761F5")
    EventInSFMatrix : public EventIn
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setValue( 
            /* [size_is][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventInSFMatrixVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventInSFMatrix * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventInSFMatrix * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventInSFMatrix * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventInSFMatrix * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventInSFMatrix * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventInSFMatrix * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventInSFMatrix * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventInSFMatrix * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *setValueFromString )( 
            EventInSFMatrix * This,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *setValue )( 
            EventInSFMatrix * This,
            /* [size_is][in] */ float *value);
        
        END_INTERFACE
    } EventInSFMatrixVtbl;

    interface EventInSFMatrix
    {
        CONST_VTBL struct EventInSFMatrixVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventInSFMatrix_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventInSFMatrix_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventInSFMatrix_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventInSFMatrix_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventInSFMatrix_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventInSFMatrix_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventInSFMatrix_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventInSFMatrix_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventInSFMatrix_setValueFromString(This,value)	\
    ( (This)->lpVtbl -> setValueFromString(This,value) ) 


#define EventInSFMatrix_setValue(This,value)	\
    ( (This)->lpVtbl -> setValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventInSFMatrix_INTERFACE_DEFINED__ */


#ifndef __EventOutObserver_INTERFACE_DEFINED__
#define __EventOutObserver_INTERFACE_DEFINED__

/* interface EventOutObserver */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutObserver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50406-75D9-11D0-9315-0020AFE05CC8")
    EventOutObserver : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE callback( 
            /* [in] */ EventOut *value,
            /* [in] */ double timeStamp,
            /* [in] */ IDispatch *userData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutObserverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutObserver * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutObserver * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutObserver * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutObserver * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutObserver * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutObserver * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutObserver * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *callback )( 
            EventOutObserver * This,
            /* [in] */ EventOut *value,
            /* [in] */ double timeStamp,
            /* [in] */ IDispatch *userData);
        
        END_INTERFACE
    } EventOutObserverVtbl;

    interface EventOutObserver
    {
        CONST_VTBL struct EventOutObserverVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutObserver_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutObserver_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutObserver_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutObserver_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutObserver_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutObserver_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutObserver_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutObserver_callback(This,value,timeStamp,userData)	\
    ( (This)->lpVtbl -> callback(This,value,timeStamp,userData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutObserver_INTERFACE_DEFINED__ */


#ifndef __EventOutMFColor_INTERFACE_DEFINED__
#define __EventOutMFColor_INTERFACE_DEFINED__

/* interface EventOutMFColor */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutMFColor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50410-75D9-11D0-9315-0020AFE05CC8")
    EventOutMFColor : public EventOutMField
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get1Value( 
            /* [in] */ int index,
            /* [size_is][out][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutMFColorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutMFColor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutMFColor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutMFColor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutMFColor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutMFColor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutMFColor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutMFColor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutMFColor * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutMFColor * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutMFColor * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutMFColor * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSize )( 
            EventOutMFColor * This,
            /* [retval][out] */ int *cnt);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutMFColor * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *get1Value )( 
            EventOutMFColor * This,
            /* [in] */ int index,
            /* [size_is][out][in] */ float *value);
        
        END_INTERFACE
    } EventOutMFColorVtbl;

    interface EventOutMFColor
    {
        CONST_VTBL struct EventOutMFColorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutMFColor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutMFColor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutMFColor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutMFColor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutMFColor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutMFColor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutMFColor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutMFColor_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutMFColor_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutMFColor_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutMFColor_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutMFColor_getSize(This,cnt)	\
    ( (This)->lpVtbl -> getSize(This,cnt) ) 


#define EventOutMFColor_getValue(This,cnt,value)	\
    ( (This)->lpVtbl -> getValue(This,cnt,value) ) 

#define EventOutMFColor_get1Value(This,index,value)	\
    ( (This)->lpVtbl -> get1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutMFColor_INTERFACE_DEFINED__ */


#ifndef __EventOutMFFloat_INTERFACE_DEFINED__
#define __EventOutMFFloat_INTERFACE_DEFINED__

/* interface EventOutMFFloat */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutMFFloat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50415-75D9-11D0-9315-0020AFE05CC8")
    EventOutMFFloat : public EventOutMField
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get1Value( 
            /* [in] */ int index,
            /* [retval][out] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutMFFloatVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutMFFloat * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutMFFloat * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutMFFloat * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutMFFloat * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutMFFloat * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutMFFloat * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutMFFloat * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutMFFloat * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutMFFloat * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutMFFloat * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutMFFloat * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSize )( 
            EventOutMFFloat * This,
            /* [retval][out] */ int *cnt);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutMFFloat * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *get1Value )( 
            EventOutMFFloat * This,
            /* [in] */ int index,
            /* [retval][out] */ float *value);
        
        END_INTERFACE
    } EventOutMFFloatVtbl;

    interface EventOutMFFloat
    {
        CONST_VTBL struct EventOutMFFloatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutMFFloat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutMFFloat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutMFFloat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutMFFloat_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutMFFloat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutMFFloat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutMFFloat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutMFFloat_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutMFFloat_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutMFFloat_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutMFFloat_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutMFFloat_getSize(This,cnt)	\
    ( (This)->lpVtbl -> getSize(This,cnt) ) 


#define EventOutMFFloat_getValue(This,cnt,value)	\
    ( (This)->lpVtbl -> getValue(This,cnt,value) ) 

#define EventOutMFFloat_get1Value(This,index,value)	\
    ( (This)->lpVtbl -> get1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutMFFloat_INTERFACE_DEFINED__ */


#ifndef __EventOutMFTime_INTERFACE_DEFINED__
#define __EventOutMFTime_INTERFACE_DEFINED__

/* interface EventOutMFTime */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutMFTime;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5EEE9A0-6771-11d2-ABB2-00A0C9C7B4A1")
    EventOutMFTime : public EventOutMField
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ double *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get1Value( 
            /* [in] */ int index,
            /* [retval][out] */ double *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutMFTimeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutMFTime * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutMFTime * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutMFTime * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutMFTime * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutMFTime * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutMFTime * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutMFTime * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutMFTime * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutMFTime * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutMFTime * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutMFTime * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSize )( 
            EventOutMFTime * This,
            /* [retval][out] */ int *cnt);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutMFTime * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ double *value);
        
        HRESULT ( STDMETHODCALLTYPE *get1Value )( 
            EventOutMFTime * This,
            /* [in] */ int index,
            /* [retval][out] */ double *value);
        
        END_INTERFACE
    } EventOutMFTimeVtbl;

    interface EventOutMFTime
    {
        CONST_VTBL struct EventOutMFTimeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutMFTime_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutMFTime_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutMFTime_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutMFTime_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutMFTime_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutMFTime_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutMFTime_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutMFTime_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutMFTime_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutMFTime_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutMFTime_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutMFTime_getSize(This,cnt)	\
    ( (This)->lpVtbl -> getSize(This,cnt) ) 


#define EventOutMFTime_getValue(This,cnt,value)	\
    ( (This)->lpVtbl -> getValue(This,cnt,value) ) 

#define EventOutMFTime_get1Value(This,index,value)	\
    ( (This)->lpVtbl -> get1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutMFTime_INTERFACE_DEFINED__ */


#ifndef __EventOutMFInt32_INTERFACE_DEFINED__
#define __EventOutMFInt32_INTERFACE_DEFINED__

/* interface EventOutMFInt32 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutMFInt32;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC5041A-75D9-11D0-9315-0020AFE05CC8")
    EventOutMFInt32 : public EventOutMField
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ int *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get1Value( 
            /* [in] */ int index,
            /* [retval][out] */ int *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutMFInt32Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutMFInt32 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutMFInt32 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutMFInt32 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutMFInt32 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutMFInt32 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutMFInt32 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutMFInt32 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutMFInt32 * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutMFInt32 * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutMFInt32 * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutMFInt32 * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSize )( 
            EventOutMFInt32 * This,
            /* [retval][out] */ int *cnt);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutMFInt32 * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ int *value);
        
        HRESULT ( STDMETHODCALLTYPE *get1Value )( 
            EventOutMFInt32 * This,
            /* [in] */ int index,
            /* [retval][out] */ int *value);
        
        END_INTERFACE
    } EventOutMFInt32Vtbl;

    interface EventOutMFInt32
    {
        CONST_VTBL struct EventOutMFInt32Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutMFInt32_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutMFInt32_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutMFInt32_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutMFInt32_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutMFInt32_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutMFInt32_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutMFInt32_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutMFInt32_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutMFInt32_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutMFInt32_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutMFInt32_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutMFInt32_getSize(This,cnt)	\
    ( (This)->lpVtbl -> getSize(This,cnt) ) 


#define EventOutMFInt32_getValue(This,cnt,value)	\
    ( (This)->lpVtbl -> getValue(This,cnt,value) ) 

#define EventOutMFInt32_get1Value(This,index,value)	\
    ( (This)->lpVtbl -> get1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutMFInt32_INTERFACE_DEFINED__ */


#ifndef __EventOutMFNode_INTERFACE_DEFINED__
#define __EventOutMFNode_INTERFACE_DEFINED__

/* interface EventOutMFNode */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutMFNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC5041F-75D9-11D0-9315-0020AFE05CC8")
    EventOutMFNode : public EventOutMField
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ IDispatch **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get1Value( 
            /* [in] */ int index,
            /* [retval][out] */ Node **value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutMFNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutMFNode * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutMFNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutMFNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutMFNode * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutMFNode * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutMFNode * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutMFNode * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutMFNode * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutMFNode * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutMFNode * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutMFNode * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSize )( 
            EventOutMFNode * This,
            /* [retval][out] */ int *cnt);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutMFNode * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ IDispatch **value);
        
        HRESULT ( STDMETHODCALLTYPE *get1Value )( 
            EventOutMFNode * This,
            /* [in] */ int index,
            /* [retval][out] */ Node **value);
        
        END_INTERFACE
    } EventOutMFNodeVtbl;

    interface EventOutMFNode
    {
        CONST_VTBL struct EventOutMFNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutMFNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutMFNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutMFNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutMFNode_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutMFNode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutMFNode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutMFNode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutMFNode_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutMFNode_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutMFNode_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutMFNode_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutMFNode_getSize(This,cnt)	\
    ( (This)->lpVtbl -> getSize(This,cnt) ) 


#define EventOutMFNode_getValue(This,cnt,value)	\
    ( (This)->lpVtbl -> getValue(This,cnt,value) ) 

#define EventOutMFNode_get1Value(This,index,value)	\
    ( (This)->lpVtbl -> get1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutMFNode_INTERFACE_DEFINED__ */


#ifndef __EventOutMFRotation_INTERFACE_DEFINED__
#define __EventOutMFRotation_INTERFACE_DEFINED__

/* interface EventOutMFRotation */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutMFRotation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50424-75D9-11D0-9315-0020AFE05CC8")
    EventOutMFRotation : public EventOutMField
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get1Value( 
            /* [in] */ int index,
            /* [size_is][out][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutMFRotationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutMFRotation * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutMFRotation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutMFRotation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutMFRotation * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutMFRotation * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutMFRotation * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutMFRotation * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutMFRotation * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutMFRotation * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutMFRotation * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutMFRotation * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSize )( 
            EventOutMFRotation * This,
            /* [retval][out] */ int *cnt);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutMFRotation * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *get1Value )( 
            EventOutMFRotation * This,
            /* [in] */ int index,
            /* [size_is][out][in] */ float *value);
        
        END_INTERFACE
    } EventOutMFRotationVtbl;

    interface EventOutMFRotation
    {
        CONST_VTBL struct EventOutMFRotationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutMFRotation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutMFRotation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutMFRotation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutMFRotation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutMFRotation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutMFRotation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutMFRotation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutMFRotation_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutMFRotation_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutMFRotation_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutMFRotation_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutMFRotation_getSize(This,cnt)	\
    ( (This)->lpVtbl -> getSize(This,cnt) ) 


#define EventOutMFRotation_getValue(This,cnt,value)	\
    ( (This)->lpVtbl -> getValue(This,cnt,value) ) 

#define EventOutMFRotation_get1Value(This,index,value)	\
    ( (This)->lpVtbl -> get1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutMFRotation_INTERFACE_DEFINED__ */


#ifndef __EventOutMFString_INTERFACE_DEFINED__
#define __EventOutMFString_INTERFACE_DEFINED__

/* interface EventOutMFString */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutMFString;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50429-75D9-11D0-9315-0020AFE05CC8")
    EventOutMFString : public EventOutMField
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ BSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get1Value( 
            /* [in] */ int index,
            /* [retval][out] */ BSTR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutMFStringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutMFString * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutMFString * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutMFString * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutMFString * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutMFString * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutMFString * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutMFString * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutMFString * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutMFString * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutMFString * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutMFString * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSize )( 
            EventOutMFString * This,
            /* [retval][out] */ int *cnt);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutMFString * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *get1Value )( 
            EventOutMFString * This,
            /* [in] */ int index,
            /* [retval][out] */ BSTR *value);
        
        END_INTERFACE
    } EventOutMFStringVtbl;

    interface EventOutMFString
    {
        CONST_VTBL struct EventOutMFStringVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutMFString_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutMFString_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutMFString_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutMFString_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutMFString_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutMFString_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutMFString_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutMFString_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutMFString_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutMFString_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutMFString_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutMFString_getSize(This,cnt)	\
    ( (This)->lpVtbl -> getSize(This,cnt) ) 


#define EventOutMFString_getValue(This,cnt,value)	\
    ( (This)->lpVtbl -> getValue(This,cnt,value) ) 

#define EventOutMFString_get1Value(This,index,value)	\
    ( (This)->lpVtbl -> get1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutMFString_INTERFACE_DEFINED__ */


#ifndef __EventOutMFVec2f_INTERFACE_DEFINED__
#define __EventOutMFVec2f_INTERFACE_DEFINED__

/* interface EventOutMFVec2f */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutMFVec2f;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC5042E-75D9-11D0-9315-0020AFE05CC8")
    EventOutMFVec2f : public EventOutMField
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get1Value( 
            /* [in] */ int index,
            /* [size_is][out][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutMFVec2fVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutMFVec2f * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutMFVec2f * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutMFVec2f * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutMFVec2f * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutMFVec2f * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutMFVec2f * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutMFVec2f * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutMFVec2f * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutMFVec2f * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutMFVec2f * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutMFVec2f * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSize )( 
            EventOutMFVec2f * This,
            /* [retval][out] */ int *cnt);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutMFVec2f * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *get1Value )( 
            EventOutMFVec2f * This,
            /* [in] */ int index,
            /* [size_is][out][in] */ float *value);
        
        END_INTERFACE
    } EventOutMFVec2fVtbl;

    interface EventOutMFVec2f
    {
        CONST_VTBL struct EventOutMFVec2fVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutMFVec2f_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutMFVec2f_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutMFVec2f_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutMFVec2f_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutMFVec2f_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutMFVec2f_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutMFVec2f_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutMFVec2f_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutMFVec2f_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutMFVec2f_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutMFVec2f_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutMFVec2f_getSize(This,cnt)	\
    ( (This)->lpVtbl -> getSize(This,cnt) ) 


#define EventOutMFVec2f_getValue(This,cnt,value)	\
    ( (This)->lpVtbl -> getValue(This,cnt,value) ) 

#define EventOutMFVec2f_get1Value(This,index,value)	\
    ( (This)->lpVtbl -> get1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutMFVec2f_INTERFACE_DEFINED__ */


#ifndef __EventOutMFVec3f_INTERFACE_DEFINED__
#define __EventOutMFVec3f_INTERFACE_DEFINED__

/* interface EventOutMFVec3f */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutMFVec3f;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50433-75D9-11D0-9315-0020AFE05CC8")
    EventOutMFVec3f : public EventOutMField
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ float *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get1Value( 
            /* [in] */ int index,
            /* [size_is][out][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutMFVec3fVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutMFVec3f * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutMFVec3f * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutMFVec3f * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutMFVec3f * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutMFVec3f * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutMFVec3f * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutMFVec3f * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutMFVec3f * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutMFVec3f * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutMFVec3f * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutMFVec3f * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSize )( 
            EventOutMFVec3f * This,
            /* [retval][out] */ int *cnt);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutMFVec3f * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ float *value);
        
        HRESULT ( STDMETHODCALLTYPE *get1Value )( 
            EventOutMFVec3f * This,
            /* [in] */ int index,
            /* [size_is][out][in] */ float *value);
        
        END_INTERFACE
    } EventOutMFVec3fVtbl;

    interface EventOutMFVec3f
    {
        CONST_VTBL struct EventOutMFVec3fVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutMFVec3f_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutMFVec3f_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutMFVec3f_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutMFVec3f_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutMFVec3f_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutMFVec3f_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutMFVec3f_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutMFVec3f_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutMFVec3f_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutMFVec3f_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutMFVec3f_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutMFVec3f_getSize(This,cnt)	\
    ( (This)->lpVtbl -> getSize(This,cnt) ) 


#define EventOutMFVec3f_getValue(This,cnt,value)	\
    ( (This)->lpVtbl -> getValue(This,cnt,value) ) 

#define EventOutMFVec3f_get1Value(This,index,value)	\
    ( (This)->lpVtbl -> get1Value(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutMFVec3f_INTERFACE_DEFINED__ */


#ifndef __EventOutSFBool_INTERFACE_DEFINED__
#define __EventOutSFBool_INTERFACE_DEFINED__

/* interface EventOutSFBool */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFBool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50438-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFBool : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [retval][out] */ VARIANT_BOOL *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFBoolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFBool * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFBool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFBool * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFBool * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFBool * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFBool * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFBool * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFBool * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFBool * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFBool * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFBool * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutSFBool * This,
            /* [retval][out] */ VARIANT_BOOL *value);
        
        END_INTERFACE
    } EventOutSFBoolVtbl;

    interface EventOutSFBool
    {
        CONST_VTBL struct EventOutSFBoolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFBool_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFBool_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFBool_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFBool_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFBool_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFBool_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFBool_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFBool_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFBool_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFBool_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFBool_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFBool_getValue(This,value)	\
    ( (This)->lpVtbl -> getValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFBool_INTERFACE_DEFINED__ */


#ifndef __EventOutSFColor_INTERFACE_DEFINED__
#define __EventOutSFColor_INTERFACE_DEFINED__

/* interface EventOutSFColor */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFColor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC5043D-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFColor : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [size_is][out][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFColorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFColor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFColor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFColor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFColor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFColor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFColor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFColor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFColor * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFColor * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFColor * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFColor * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutSFColor * This,
            /* [size_is][out][in] */ float *value);
        
        END_INTERFACE
    } EventOutSFColorVtbl;

    interface EventOutSFColor
    {
        CONST_VTBL struct EventOutSFColorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFColor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFColor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFColor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFColor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFColor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFColor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFColor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFColor_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFColor_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFColor_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFColor_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFColor_getValue(This,value)	\
    ( (This)->lpVtbl -> getValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFColor_INTERFACE_DEFINED__ */


#ifndef __EventOutSFFloat_INTERFACE_DEFINED__
#define __EventOutSFFloat_INTERFACE_DEFINED__

/* interface EventOutSFFloat */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFFloat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50442-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFFloat : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [retval][out] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFFloatVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFFloat * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFFloat * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFFloat * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFFloat * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFFloat * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFFloat * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFFloat * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFFloat * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFFloat * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFFloat * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFFloat * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutSFFloat * This,
            /* [retval][out] */ float *value);
        
        END_INTERFACE
    } EventOutSFFloatVtbl;

    interface EventOutSFFloat
    {
        CONST_VTBL struct EventOutSFFloatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFFloat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFFloat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFFloat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFFloat_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFFloat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFFloat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFFloat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFFloat_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFFloat_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFFloat_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFFloat_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFFloat_getValue(This,value)	\
    ( (This)->lpVtbl -> getValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFFloat_INTERFACE_DEFINED__ */


#ifndef __EventOutSFImage_INTERFACE_DEFINED__
#define __EventOutSFImage_INTERFACE_DEFINED__

/* interface EventOutSFImage */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50447-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFImage : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getWidth( 
            /* [retval][out] */ int *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getHeight( 
            /* [retval][out] */ int *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getNumComponents( 
            /* [retval][out] */ int *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getPixels( 
            /* [in] */ int cnt,
            /* [size_is][out][in] */ unsigned small *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFImage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFImage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFImage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFImage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFImage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFImage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFImage * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFImage * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFImage * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFImage * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getWidth )( 
            EventOutSFImage * This,
            /* [retval][out] */ int *value);
        
        HRESULT ( STDMETHODCALLTYPE *getHeight )( 
            EventOutSFImage * This,
            /* [retval][out] */ int *value);
        
        HRESULT ( STDMETHODCALLTYPE *getNumComponents )( 
            EventOutSFImage * This,
            /* [retval][out] */ int *value);
        
        HRESULT ( STDMETHODCALLTYPE *getPixels )( 
            EventOutSFImage * This,
            /* [in] */ int cnt,
            /* [size_is][out][in] */ unsigned small *value);
        
        END_INTERFACE
    } EventOutSFImageVtbl;

    interface EventOutSFImage
    {
        CONST_VTBL struct EventOutSFImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFImage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFImage_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFImage_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFImage_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFImage_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFImage_getWidth(This,value)	\
    ( (This)->lpVtbl -> getWidth(This,value) ) 

#define EventOutSFImage_getHeight(This,value)	\
    ( (This)->lpVtbl -> getHeight(This,value) ) 

#define EventOutSFImage_getNumComponents(This,value)	\
    ( (This)->lpVtbl -> getNumComponents(This,value) ) 

#define EventOutSFImage_getPixels(This,cnt,value)	\
    ( (This)->lpVtbl -> getPixels(This,cnt,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFImage_INTERFACE_DEFINED__ */


#ifndef __EventOutSFInt32_INTERFACE_DEFINED__
#define __EventOutSFInt32_INTERFACE_DEFINED__

/* interface EventOutSFInt32 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFInt32;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC5044C-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFInt32 : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [retval][out] */ int *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFInt32Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFInt32 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFInt32 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFInt32 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFInt32 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFInt32 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFInt32 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFInt32 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFInt32 * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFInt32 * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFInt32 * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFInt32 * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutSFInt32 * This,
            /* [retval][out] */ int *value);
        
        END_INTERFACE
    } EventOutSFInt32Vtbl;

    interface EventOutSFInt32
    {
        CONST_VTBL struct EventOutSFInt32Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFInt32_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFInt32_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFInt32_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFInt32_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFInt32_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFInt32_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFInt32_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFInt32_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFInt32_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFInt32_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFInt32_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFInt32_getValue(This,value)	\
    ( (This)->lpVtbl -> getValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFInt32_INTERFACE_DEFINED__ */


#ifndef __EventOutSFNode_INTERFACE_DEFINED__
#define __EventOutSFNode_INTERFACE_DEFINED__

/* interface EventOutSFNode */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50451-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFNode : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [retval][out] */ Node **value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFNode * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFNode * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFNode * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFNode * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFNode * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFNode * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFNode * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFNode * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFNode * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutSFNode * This,
            /* [retval][out] */ Node **value);
        
        END_INTERFACE
    } EventOutSFNodeVtbl;

    interface EventOutSFNode
    {
        CONST_VTBL struct EventOutSFNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFNode_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFNode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFNode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFNode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFNode_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFNode_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFNode_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFNode_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFNode_getValue(This,value)	\
    ( (This)->lpVtbl -> getValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFNode_INTERFACE_DEFINED__ */


#ifndef __EventOutSFRotation_INTERFACE_DEFINED__
#define __EventOutSFRotation_INTERFACE_DEFINED__

/* interface EventOutSFRotation */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFRotation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50456-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFRotation : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [size_is][out][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFRotationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFRotation * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFRotation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFRotation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFRotation * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFRotation * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFRotation * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFRotation * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFRotation * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFRotation * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFRotation * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFRotation * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutSFRotation * This,
            /* [size_is][out][in] */ float *value);
        
        END_INTERFACE
    } EventOutSFRotationVtbl;

    interface EventOutSFRotation
    {
        CONST_VTBL struct EventOutSFRotationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFRotation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFRotation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFRotation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFRotation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFRotation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFRotation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFRotation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFRotation_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFRotation_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFRotation_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFRotation_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFRotation_getValue(This,value)	\
    ( (This)->lpVtbl -> getValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFRotation_INTERFACE_DEFINED__ */


#ifndef __EventOutSFString_INTERFACE_DEFINED__
#define __EventOutSFString_INTERFACE_DEFINED__

/* interface EventOutSFString */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFString;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC5045B-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFString : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [retval][out] */ BSTR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFStringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFString * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFString * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFString * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFString * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFString * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFString * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFString * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFString * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFString * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFString * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFString * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutSFString * This,
            /* [retval][out] */ BSTR *value);
        
        END_INTERFACE
    } EventOutSFStringVtbl;

    interface EventOutSFString
    {
        CONST_VTBL struct EventOutSFStringVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFString_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFString_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFString_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFString_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFString_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFString_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFString_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFString_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFString_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFString_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFString_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFString_getValue(This,value)	\
    ( (This)->lpVtbl -> getValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFString_INTERFACE_DEFINED__ */


#ifndef __EventOutSFTime_INTERFACE_DEFINED__
#define __EventOutSFTime_INTERFACE_DEFINED__

/* interface EventOutSFTime */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFTime;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50460-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFTime : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [retval][out] */ double *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFTimeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFTime * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFTime * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFTime * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFTime * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFTime * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFTime * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFTime * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFTime * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFTime * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFTime * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFTime * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutSFTime * This,
            /* [retval][out] */ double *value);
        
        END_INTERFACE
    } EventOutSFTimeVtbl;

    interface EventOutSFTime
    {
        CONST_VTBL struct EventOutSFTimeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFTime_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFTime_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFTime_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFTime_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFTime_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFTime_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFTime_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFTime_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFTime_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFTime_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFTime_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFTime_getValue(This,value)	\
    ( (This)->lpVtbl -> getValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFTime_INTERFACE_DEFINED__ */


#ifndef __EventOutSFVec2f_INTERFACE_DEFINED__
#define __EventOutSFVec2f_INTERFACE_DEFINED__

/* interface EventOutSFVec2f */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFVec2f;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50465-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFVec2f : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [size_is][out][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFVec2fVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFVec2f * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFVec2f * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFVec2f * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFVec2f * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFVec2f * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFVec2f * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFVec2f * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFVec2f * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFVec2f * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFVec2f * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFVec2f * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutSFVec2f * This,
            /* [size_is][out][in] */ float *value);
        
        END_INTERFACE
    } EventOutSFVec2fVtbl;

    interface EventOutSFVec2f
    {
        CONST_VTBL struct EventOutSFVec2fVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFVec2f_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFVec2f_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFVec2f_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFVec2f_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFVec2f_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFVec2f_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFVec2f_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFVec2f_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFVec2f_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFVec2f_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFVec2f_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFVec2f_getValue(This,value)	\
    ( (This)->lpVtbl -> getValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFVec2f_INTERFACE_DEFINED__ */


#ifndef __EventOutSFVec3f_INTERFACE_DEFINED__
#define __EventOutSFVec3f_INTERFACE_DEFINED__

/* interface EventOutSFVec3f */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_EventOutSFVec3f;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC5046A-75D9-11D0-9315-0020AFE05CC8")
    EventOutSFVec3f : public EventOut
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getValue( 
            /* [size_is][out][in] */ float *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct EventOutSFVec3fVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            EventOutSFVec3f * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            EventOutSFVec3f * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            EventOutSFVec3f * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            EventOutSFVec3f * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            EventOutSFVec3f * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            EventOutSFVec3f * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            EventOutSFVec3f * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *getType )( 
            EventOutSFVec3f * This,
            /* [retval][out] */ int *type);
        
        HRESULT ( STDMETHODCALLTYPE *advise )( 
            EventOutSFVec3f * This,
            /* [in] */ EventOutObserver *observer,
            /* [in] */ IDispatch *userData);
        
        HRESULT ( STDMETHODCALLTYPE *unAdvise )( 
            EventOutSFVec3f * This,
            /* [in] */ EventOutObserver *observer);
        
        HRESULT ( STDMETHODCALLTYPE *toString )( 
            EventOutSFVec3f * This,
            /* [retval][out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *getValue )( 
            EventOutSFVec3f * This,
            /* [size_is][out][in] */ float *value);
        
        END_INTERFACE
    } EventOutSFVec3fVtbl;

    interface EventOutSFVec3f
    {
        CONST_VTBL struct EventOutSFVec3fVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define EventOutSFVec3f_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define EventOutSFVec3f_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define EventOutSFVec3f_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define EventOutSFVec3f_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define EventOutSFVec3f_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define EventOutSFVec3f_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define EventOutSFVec3f_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define EventOutSFVec3f_getType(This,type)	\
    ( (This)->lpVtbl -> getType(This,type) ) 

#define EventOutSFVec3f_advise(This,observer,userData)	\
    ( (This)->lpVtbl -> advise(This,observer,userData) ) 

#define EventOutSFVec3f_unAdvise(This,observer)	\
    ( (This)->lpVtbl -> unAdvise(This,observer) ) 

#define EventOutSFVec3f_toString(This,value)	\
    ( (This)->lpVtbl -> toString(This,value) ) 


#define EventOutSFVec3f_getValue(This,value)	\
    ( (This)->lpVtbl -> getValue(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __EventOutSFVec3f_INTERFACE_DEFINED__ */


#ifndef __ScriptContainer_INTERFACE_DEFINED__
#define __ScriptContainer_INTERFACE_DEFINED__

/* interface ScriptContainer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ScriptContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50474-75D9-11D0-9315-0020AFE05CC8")
    ScriptContainer : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ScriptContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ScriptContainer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ScriptContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ScriptContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ScriptContainer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ScriptContainer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ScriptContainer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ScriptContainer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ScriptContainerVtbl;

    interface ScriptContainer
    {
        CONST_VTBL struct ScriptContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ScriptContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ScriptContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ScriptContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ScriptContainer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ScriptContainer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ScriptContainer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ScriptContainer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ScriptContainer_INTERFACE_DEFINED__ */


#ifndef __Script_INTERFACE_DEFINED__
#define __Script_INTERFACE_DEFINED__

/* interface Script */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_Script;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAC50479-75D9-11D0-9315-0020AFE05CC8")
    Script : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setContainer( 
            /* [in] */ Node *container) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE loadScriptObject( 
            /* [in] */ BSTR urlData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE initialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE shutdown( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE processEvent( 
            /* [in] */ BSTR name,
            /* [in] */ int eventId,
            /* [in] */ EventOut *value,
            /* [in] */ double timeStamp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE eventsProcessed( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ScriptVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Script * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Script * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Script * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Script * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Script * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Script * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Script * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *setContainer )( 
            Script * This,
            /* [in] */ Node *container);
        
        HRESULT ( STDMETHODCALLTYPE *loadScriptObject )( 
            Script * This,
            /* [in] */ BSTR urlData);
        
        HRESULT ( STDMETHODCALLTYPE *initialize )( 
            Script * This);
        
        HRESULT ( STDMETHODCALLTYPE *shutdown )( 
            Script * This);
        
        HRESULT ( STDMETHODCALLTYPE *processEvent )( 
            Script * This,
            /* [in] */ BSTR name,
            /* [in] */ int eventId,
            /* [in] */ EventOut *value,
            /* [in] */ double timeStamp);
        
        HRESULT ( STDMETHODCALLTYPE *eventsProcessed )( 
            Script * This);
        
        END_INTERFACE
    } ScriptVtbl;

    interface Script
    {
        CONST_VTBL struct ScriptVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Script_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Script_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Script_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Script_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Script_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Script_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Script_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define Script_setContainer(This,container)	\
    ( (This)->lpVtbl -> setContainer(This,container) ) 

#define Script_loadScriptObject(This,urlData)	\
    ( (This)->lpVtbl -> loadScriptObject(This,urlData) ) 

#define Script_initialize(This)	\
    ( (This)->lpVtbl -> initialize(This) ) 

#define Script_shutdown(This)	\
    ( (This)->lpVtbl -> shutdown(This) ) 

#define Script_processEvent(This,name,eventId,value,timeStamp)	\
    ( (This)->lpVtbl -> processEvent(This,name,eventId,value,timeStamp) ) 

#define Script_eventsProcessed(This)	\
    ( (This)->lpVtbl -> eventsProcessed(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __Script_INTERFACE_DEFINED__ */


#ifndef __BrowserObserver_INTERFACE_DEFINED__
#define __BrowserObserver_INTERFACE_DEFINED__

/* interface BrowserObserver */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_BrowserObserver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B8B46AC1-185B-11D1-9447-0020AFE05CC8")
    BrowserObserver : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnStatusMessage( 
            /* [in] */ BSTR message,
            /* [in] */ int messageType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnUrlError( 
            /* [in] */ BSTR url,
            /* [in] */ BSTR message,
            /* [in] */ int errorCode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLoadUrl( 
            /* [in] */ BSTR url,
            /* [in] */ BSTR targetFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLoadAnchor( 
            /* [in] */ BSTR description,
            /* [in] */ int numUrl,
            /* [size_is][in] */ BSTR *url,
            /* [in] */ int numParameter,
            /* [size_is][in] */ BSTR *parameter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnViewpointChanged( 
            /* [size_is][in] */ float *position,
            /* [size_is][in] */ float *orientation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnSceneChanged( 
            /* [in] */ BSTR url) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadUrlToFile( 
            /* [in] */ BSTR url) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct BrowserObserverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            BrowserObserver * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            BrowserObserver * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            BrowserObserver * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            BrowserObserver * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            BrowserObserver * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            BrowserObserver * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            BrowserObserver * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *OnStatusMessage )( 
            BrowserObserver * This,
            /* [in] */ BSTR message,
            /* [in] */ int messageType);
        
        HRESULT ( STDMETHODCALLTYPE *OnUrlError )( 
            BrowserObserver * This,
            /* [in] */ BSTR url,
            /* [in] */ BSTR message,
            /* [in] */ int errorCode);
        
        HRESULT ( STDMETHODCALLTYPE *OnLoadUrl )( 
            BrowserObserver * This,
            /* [in] */ BSTR url,
            /* [in] */ BSTR targetFrame);
        
        HRESULT ( STDMETHODCALLTYPE *OnLoadAnchor )( 
            BrowserObserver * This,
            /* [in] */ BSTR description,
            /* [in] */ int numUrl,
            /* [size_is][in] */ BSTR *url,
            /* [in] */ int numParameter,
            /* [size_is][in] */ BSTR *parameter);
        
        HRESULT ( STDMETHODCALLTYPE *OnViewpointChanged )( 
            BrowserObserver * This,
            /* [size_is][in] */ float *position,
            /* [size_is][in] */ float *orientation);
        
        HRESULT ( STDMETHODCALLTYPE *OnSceneChanged )( 
            BrowserObserver * This,
            /* [in] */ BSTR url);
        
        HRESULT ( STDMETHODCALLTYPE *LoadUrlToFile )( 
            BrowserObserver * This,
            /* [in] */ BSTR url);
        
        END_INTERFACE
    } BrowserObserverVtbl;

    interface BrowserObserver
    {
        CONST_VTBL struct BrowserObserverVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define BrowserObserver_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define BrowserObserver_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define BrowserObserver_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define BrowserObserver_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define BrowserObserver_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define BrowserObserver_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define BrowserObserver_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define BrowserObserver_OnStatusMessage(This,message,messageType)	\
    ( (This)->lpVtbl -> OnStatusMessage(This,message,messageType) ) 

#define BrowserObserver_OnUrlError(This,url,message,errorCode)	\
    ( (This)->lpVtbl -> OnUrlError(This,url,message,errorCode) ) 

#define BrowserObserver_OnLoadUrl(This,url,targetFrame)	\
    ( (This)->lpVtbl -> OnLoadUrl(This,url,targetFrame) ) 

#define BrowserObserver_OnLoadAnchor(This,description,numUrl,url,numParameter,parameter)	\
    ( (This)->lpVtbl -> OnLoadAnchor(This,description,numUrl,url,numParameter,parameter) ) 

#define BrowserObserver_OnViewpointChanged(This,position,orientation)	\
    ( (This)->lpVtbl -> OnViewpointChanged(This,position,orientation) ) 

#define BrowserObserver_OnSceneChanged(This,url)	\
    ( (This)->lpVtbl -> OnSceneChanged(This,url) ) 

#define BrowserObserver_LoadUrlToFile(This,url)	\
    ( (This)->lpVtbl -> LoadUrlToFile(This,url) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __BrowserObserver_INTERFACE_DEFINED__ */

#endif /* __blaxxunVRMLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



#include "stdafx.h"
#include "keyObserver.h"
#include "SingleControler.h"


STDMETHODCALLTYPE KeyObserver::KeyObserver(void){this->controler=NULL;}
STDMETHODCALLTYPE KeyObserver::KeyObserver(KinectControler* ctrl):controler(ctrl){}
STDMETHODCALLTYPE KeyObserver::~KeyObserver(void){}
HRESULT STDMETHODCALLTYPE KeyObserver::QueryInterface( 
	/* [in] */ REFIID riid,
	/* [iid_is][out] */ __RPC__deref_out void __RPC_FAR *__RPC_FAR *ppvObject){
	return S_OK;
}

ULONG STDMETHODCALLTYPE KeyObserver::AddRef( void){
	{return 0;}
}

ULONG STDMETHODCALLTYPE KeyObserver::Release( void){
	{return 0;}
}

HRESULT STDMETHODCALLTYPE KeyObserver::GetTypeInfoCount( 
	/* [out] */ __RPC__out UINT *pctinfo){
	return S_OK;
}

HRESULT STDMETHODCALLTYPE KeyObserver::GetTypeInfo( 
									  /* [in] */ UINT iTInfo,
									  /* [in] */ LCID lcid,
									  /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo){
	return S_OK;
}

HRESULT STDMETHODCALLTYPE KeyObserver::GetIDsOfNames( 
										/* [in] */ __RPC__in REFIID riid,
										/* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
										/* [range][in] */ UINT cNames,
										/* [in] */ LCID lcid,
										/* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId){
	return S_OK;
}


HRESULT STDMETHODCALLTYPE KeyObserver::Invoke( 
								 /* [in] */ DISPID dispIdMember,
								 /* [in] */ REFIID riid,
								 /* [in] */ LCID lcid,
								 /* [in] */ WORD wFlags,
								 /* [out][in] */ DISPPARAMS *pDispParams,
								 /* [out] */ VARIANT *pVarResult,
								 /* [out] */ EXCEPINFO *pExcepInfo,
								 /* [out] */ UINT *puArgErr)
{
									 return S_OK;
}

HRESULT STDMETHODCALLTYPE KeyObserver::callback(EventOut *value,double timeStamp,IDispatch *userData)
{		
	EventOutSFInt32* tmp_vlu;
	value->QueryInterface(IID_EventOutSFInt32,(void**)&tmp_vlu);
	int keyVlu;
	tmp_vlu->getValue(&keyVlu);
	if(keyVlu==65){
		MessageBoxW(NULL,L"trigger",L"in keyobv",0);
		/*SingleControler* ctrl=(SingleControler*)controler;
		ctrl->createMesh();*/
		this->controler->trigger();
	}
	if(keyVlu==66){
		MessageBox(NULL,L"place devices around you According to the order number",L"attention!",0);
		MessageBox(NULL,L"we will tell you the dev-number and refer the dev \r\nby stop blinking the led and turn it red ",L"attention!",0);
		MessageBox(NULL,L"let 1st dev look on you then others by right-handwise",L"attention!",0);
		/*SingleControler* ctrl=(SingleControler*)controler;
		ctrl->createMesh();*/
		this->controler->trigger1();
	}
	tmp_vlu->Release();
	return S_OK;
}

HRESULT STDMETHODCALLTYPE  KeyObserver::setControler(KinectControler* ctrl){
	this->controler=ctrl;
	return S_OK;
}


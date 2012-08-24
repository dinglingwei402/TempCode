#include "blaxxunVRML.h"


class KeyObserver : public EventOutObserver{
public:
	void (*m_func)();
	void (*m_func1)();
	void (*m_func2)();
	void (*m_func3)();
	void (*m_func4)();
	STDMETHODCALLTYPE KeyObserver(void);
	STDMETHODCALLTYPE ~KeyObserver(void);
	HRESULT STDMETHODCALLTYPE QueryInterface( 
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ __RPC__deref_out void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG STDMETHODCALLTYPE AddRef( void);

	ULONG STDMETHODCALLTYPE Release( void);

	HRESULT STDMETHODCALLTYPE GetTypeInfoCount( 
		/* [out] */ __RPC__out UINT *pctinfo);

	HRESULT STDMETHODCALLTYPE GetTypeInfo( 
		/* [in] */ UINT iTInfo,
		/* [in] */ LCID lcid,
		/* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);

	HRESULT STDMETHODCALLTYPE GetIDsOfNames( 
		/* [in] */ __RPC__in REFIID riid,
		/* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
		/* [range][in] */ UINT cNames,
		/* [in] */ LCID lcid,
		/* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);

	HRESULT STDMETHODCALLTYPE Invoke( 
		/* [in] */ DISPID dispIdMember,
		/* [in] */ REFIID riid,
		/* [in] */ LCID lcid,
		/* [in] */ WORD wFlags,
		/* [out][in] */ DISPPARAMS *pDispParams,
		/* [out] */ VARIANT *pVarResult,
		/* [out] */ EXCEPINFO *pExcepInfo,
		/* [out] */ UINT *puArgErr);
	HRESULT STDMETHODCALLTYPE callback(EventOut *value,double timeStamp,IDispatch *userData);
	template<class T>
	HRESULT STDMETHODCALLTYPE setMFunc( void (T::*func)())
	{
		this->m_func=func;
		return S_OK;
	};

	HRESULT STDMETHODCALLTYPE setMFunc1(void (*func)());
	HRESULT STDMETHODCALLTYPE setMFunc2(void (*func)());
	HRESULT STDMETHODCALLTYPE setMFunc3(void (*func)());
	HRESULT STDMETHODCALLTYPE setMFunc4(void (*func)());
};

#include "blaxxunVRML.h"
#include <typeinfo>

template<typename EVT_TYP,typename VLU_TYP>
HRESULT QuerySFNode(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result,/*out*/VLU_TYP* vlu){
	HRESULT hr=S_OK;
	EventOut* out;
	hr=root->getEventOut(name,&out);
	if(!out){
		return E_FAIL;
	}
	if (FAILED(hr)){
		out->Release();
		out=NULL;
		return hr;
	}
	hr=out->QueryInterface(type_ID,(void**)result);
	if (FAILED(hr)){
		out->Release();
		out=NULL;
		return hr;
	}
	if (vlu!=NULL)
	{ 	
		hr=(*result)->getValue(vlu);
	}
	out->Release();
	out=NULL;
	return hr;
}
template<typename EVT_TYP>
HRESULT QuerySFNode(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result){
	HRESULT hr=S_OK;
	EventOut* out;
	hr=root->getEventOut(name,&out);
	if (FAILED(hr))return hr;
	if (FAILED(hr)){
		out->Release();
		out=NULL;
		return hr;
	}
	hr=out->QueryInterface(type_ID,(void**)result);
	if (FAILED(hr)){
		out->Release();
		out=NULL;
		return hr;
	}
	out->Release();
	out=NULL;
	return hr;
}
template<typename EVT_TYP>
HRESULT QuerySFNode(EventOutSFNode* evtout,BSTR name,const IID type_ID,/*out*/EVT_TYP** result){
	HRESULT hr=S_OK;
	Node* root;
	evtout->getValue(&root);
	hr=QuerySFNode(root,name,type_ID,result);
	return hr;
}

//*************************MF*********************************
template < typename EVT_TYP,typename VLU_TYP>
HRESULT QueryMFNode(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result,/*out*/VLU_TYP** vlu){
	HRESULT hr=S_OK;
	EventOut* out;
	hr=root->getEventOut(name,&out);
	if(!out){
		return E_FAIL;
	}
	if (FAILED(hr)){
		out->Release();
		out=NULL;
		return hr;
	}
	hr=out->QueryInterface(type_ID,(void**)result);
	if (FAILED(hr)){
		out->Release();
		out=NULL;
		return hr;
	}
	if(vlu!=NULL){
		int cnt=0;
		(*result)->getSize(&cnt);
		*vlu=new VLU_TYP[cnt];
		hr=(*result)->getValue(cnt,*vlu);
	}
	out->Release();
	out=NULL;
	return hr;
}

template <typename EVT_TYP,typename VLU_TYP>
HRESULT QueryMFNode(EventOut* evtOut,BSTR name,const IID type_ID,/*out*/EVT_TYP** result,/*out*/VLU_TYP** vlu){
	HRESULT hr=S_OK;
	Node* root;
	evtOut->getValue(root);
	QueryMFNode(root,name,type_ID,result,vlu);
	root->Release();
	return hr;
}
template <typename EVT_TYP>
HRESULT QueryMFNode(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result){
	HRESULT hr=S_OK;
	EventOut* out;
	hr=root->getEventOut(name,&out);
	if(!out){
		return E_FAIL;
	}
	if (FAILED(hr)){
		out->Release();
		out=NULL;
		return hr;
	}
	hr=out->QueryInterface(type_ID,(void**)result);
	out->Release();
	out=NULL;
	return hr;
}
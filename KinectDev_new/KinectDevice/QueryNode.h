#include "blaxxunVRML.h"
#include <typeinfo>
template<typename EVT_TYP>
HRESULT QueryEventInNode(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result){
	HRESULT hr=S_OK;
	EventIn* in;
	hr=root->getEventIn(name,&in);
	if(!in){
		return E_FAIL;
	}
	if(FAILED(hr)){
		in->Release();
		in=NULL;
		return hr;
	}
	hr=in->QueryInterface(type_ID,(void**)result);
	in->Release();
	in=NULL;
	return hr;
}


template<typename EVT_TYP>
HRESULT QueryEventOutNode(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result){
	HRESULT hr=S_OK;
	EventOut* out;
	hr=root->getEventOut(name,&out);
	if(!out){
		return E_FAIL;
	}
	if(FAILED(hr)){
		out->Release();
		out=NULL;
		return hr;
	}
	hr=out->QueryInterface(type_ID,(void**)result);
	out->Release();
	out=NULL;
	return hr;
}
template<typename EVT_TYP>
HRESULT QueryEventOutNode(EventOutSFNode* evtout,BSTR name,const IID type_ID,/*out*/EVT_TYP** result){
	HRESULT hr=S_OK;
	Node* root;
	evtout->getValue(&root);
	hr=QueryEventOutNode(root,name,type_ID,result);
	root->Release();
	root=NULL;
	return hr;
}

template<typename EVT_TYP,typename VLU_TYP>
HRESULT QueryEventOutSFNodeVlu(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result,/*out*/VLU_TYP* vlu){
	HRESULT hr=S_OK;
	if(!root){
	//	MessageBox(NULL,L"root null",L"rn",MB_OK);
		return E_POINTER;
	}
	hr=QueryEventOutNode(root,name,type_ID,result);
	if(FAILED(hr))return hr;
	if (vlu!=NULL)
	{ 	
		hr=(*result)->getValue(vlu);
	}
	return hr;
}
template<typename EVT_TYP,typename VLU_TYP>
HRESULT QueryEventOutSFNodeVlu(EventOutSFNode* evtOut,BSTR name,const IID type_ID,/*out*/EVT_TYP** result,/*out*/VLU_TYP* vlu){
	HRESULT hr=S_OK;
	hr=QueryEventOutNode(evtOut,name,type_ID,result);
	if(FAILED(hr))return hr;
	if (vlu!=NULL)
	{ 	
		hr=(*result)->getValue(vlu);
	}
	return hr;
}
//*************************MF*********************************
template < typename EVT_TYP,typename VLU_TYP>
HRESULT QueryEventOutMFNodeVlu(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result,/*out*/VLU_TYP** vlu){
	HRESULT hr=S_OK;
	hr=QueryEventOutNode(root,name,type_ID,result);
	if(FAILED(hr))return hr;
	if(vlu!=NULL){
		int cnt=0;
		(*result)->getSize(&cnt);
		*vlu=new VLU_TYP[cnt];
		hr=(*result)->getValue(cnt,*vlu);
	}
	return hr;
}

template <typename EVT_TYP,typename VLU_TYP>
HRESULT QueryEventOutMFNodeVlu(EventOut* evtOut,BSTR name,const IID type_ID,/*out*/EVT_TYP** result,/*out*/VLU_TYP** vlu){
	HRESULT hr=S_OK;
	Node* root;
	evtOut->getValue(root);
	QueryEventOutMFNodeVlu(root,name,type_ID,result,vlu);
	root->Release();
	root=NULL;
	return hr;
}
/*
template <typename EVT_TYP>
HRESULT QueryMFNode(Node* root,BSTR name,const IID type_ID,EVT_TYP** result){
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
*/
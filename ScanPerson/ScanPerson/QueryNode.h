#include "blaxxunVRML.h"
#include <typeinfo>

template<typename EVT_TYP>
HRESULT QuerySFNode(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result){
	HRESULT hr=S_OK;
	Field* fld;
	hr=root->getField(name,&fld);
	if (FAILED(hr)||fld==NULL)return E_NOINTERFACE;
	hr=fld->QueryInterface(type_ID,(void**)result);
	if (FAILED(hr)){
		fld->Release();
		fld=NULL;
		return hr;
	}
	fld->Release();
	fld=NULL;
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


template<typename EVT_TYP,typename VLU_TYP>
HRESULT QuerySFNode(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result,/*out*/VLU_TYP* vlu){
	HRESULT hr=S_OK;
	hr=QuerySFNode(root,name, type_ID,result);
	if(FAILED(hr))return hr;
	if (vlu!=NULL)
	{ 	
		hr=(*result)->getValue(vlu);
	}
	return hr;
}

template<typename EVT_TYP,typename VLU_TYP>
HRESULT QuerySFNode(EventOutSFNode* evtout,BSTR name,const IID type_ID,/*out*/EVT_TYP** result,/*out*/VLU_TYP* vlu){
	HRESULT hr=S_OK;
	Node* root;
	evtout->getValue(&root);
	hr=QuerySFNode(root,name,type_ID,result,vlu);
	return hr;
}

//*************************MF*********************************
template < typename EVT_TYP,typename VLU_TYP>
HRESULT QueryMFNode(Node* root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result,/*out*/VLU_TYP** vlu){
	HRESULT hr=S_OK;
	EventOut* out;
	hr=root->getEventOut(name,&out);
	if(!out){
		return E_NOINTERFACE;
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
	hr=QueryMFNode(root,name,type_ID,result,vlu);
	root->Release();
	root=NULL;
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
//recurrence 
template<typename EVT_TYP>
HRESULT DeepQueryNode(Node*root,BSTR name,const IID type_ID,/*out*/EVT_TYP** result){
	HRESULT hr=S_OK;
	hr=QuerySFNode(root,name,type_ID,result);	
	if(FAILED(hr)){
		int ele_num=0;
		root->getNumInterfaceElements(&ele_num);
		for (int i=0;i<ele_num;i++)
		{
			int ele_type=0;
			int fld_type=0;
			BSTR ele_name;
			root->getInterfaceElement(i,&ele_type,&fld_type,&ele_name);
			if(fld_type==FieldTypes::SFNODE){
				EventOutSFNode* subEvent=NULL;
				Node* subNode=NULL;
				hr=QuerySFNode(root,ele_name,IID_EventOutSFNode,&subEvent,&subNode);
				if(subEvent!=NULL){
					subEvent->Release();
					subEvent=NULL;
				}
				if(subNode){		
					hr=DeepQueryNode(subNode,name,type_ID,result);
					subNode->Release();
					subNode=NULL;
					if (SUCCEEDED(hr))break;
				}else{
					hr=E_NOINTERFACE;
				}
			}
		}
	}
	return hr;
}
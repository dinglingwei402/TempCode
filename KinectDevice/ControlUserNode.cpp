#include "StdAfx.h"
#include "ControlUserNode.h"
#include "QueryNode.h"
#include "NiUserDetector.h"
#include "XnHash.h"

ControlUserNode::ControlUserNode(CKinectDev* dev)
{
	this->m_dev=dev;
	dev->m_users->QueryInterface(IID_EventInMFNode,(void**)(&this->m_userIn));
	dev->m_users->QueryInterface(IID_EventOutMFNode,(void**)(&this->m_userOut));
}
ControlUserNode::~ControlUserNode(void)
{
}
HRESULT ControlUserNode::UserNew(XnUserID nId){
	if((!m_dev)||(!m_userOut)||(!m_userIn))return E_POINTER;
	int cnt=0;
	HRESULT hr=S_OK;
	hr=m_userOut->getSize(&cnt);
	CString vrmlSyntax;
	vrmlSyntax.Format(_T(" OpenNIUser{playerID %d}"),nId);
	//	vrmlSyntax.Format(_T(" Shape{}"),nId,pPosition->X,pPosition->Y,pPosition->Z);
	Node* node;
	BSTR bstr=vrmlSyntax.AllocSysString();
	hr= m_dev->m_browser->createVrmlFromString(bstr,&node);
	if (SUCCEEDED(hr))
	{
		EventOutMFNode* children;
		Node* subNode;
		QueryEventOutNode(node,_T("children"),IID_EventOutMFNode,&children);
		children->get1Value(0,&subNode);
		hr=m_userIn->set1Value(cnt,subNode);
		MessageBox(NULL,bstr,L"SUCCEEDED",MB_OK);
	}
	VARIANT_BOOL b=false;
	m_dev->m_browser->removeNode(node,&b);
	return hr;
}
HRESULT ControlUserNode::UserLost(XnUserID nId){
	MessageBox(NULL,L"UserLost",L"UserLost",MB_OK);
	if((!m_dev)||(!m_userOut)||(!m_userIn))return E_POINTER;
	int cnt=0;
	HRESULT hr=S_OK;
	hr=m_userOut->getSize(&cnt);
	for (int i=0;i<cnt;i++)
	{
		int vlu=-1;
		Node* tmp_sub;
		hr=m_userOut->get1Value(i,&tmp_sub);
		EventOutSFInt32* idVlu;
		hr=QueryEventOutSFNodeVlu(tmp_sub,_T("playerID"),IID_EventOutSFInt32,&idVlu,&vlu);
		if(nId==vlu){
			m_userIn->set1Value(i,NULL);
			tmp_sub->Release();
			tmp_sub=NULL;
			idVlu->Release();
			idVlu=NULL;
			break;
		}
	}
	return hr;
}


 HRESULT ControlUserNode::UsersUpdate(XnUserSkeletonSet* uss)
 {
	 XnHash* hash=uss;
	 
	 
	 return S_OK;
 
 }

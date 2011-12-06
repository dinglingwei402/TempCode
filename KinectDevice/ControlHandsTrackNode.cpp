#include "StdAfx.h"
#include "ControlHandsTrackNode.h"
#include "QueryNode.h"
#include "XnList.h"

ControlHandsTrackNode::ControlHandsTrackNode(CKinectDev* dev)
{
		m_dev=dev;//Node with proto openiHand
		if (m_dev)
		{
			m_dev->m_hands->QueryInterface(IID_EventOutMFNode,(void**)&m_handOut);
			m_dev->m_hands->QueryInterface(IID_EventInMFNode,(void**)&m_handIn);
		}
}

ControlHandsTrackNode::~ControlHandsTrackNode(void)
{

}
HRESULT ControlHandsTrackNode::HandCreate(XnUserID nId, const XnPoint3D* pPosition){
	if((!m_dev)||(!m_handOut)||(!m_handIn))return E_POINTER;
	int cnt=0;
	HRESULT hr=S_OK;
	hr=m_handOut->getSize(&cnt);
	CString vrmlSyntax;
	vrmlSyntax.Format(_T(" OpenNIHand{nid %d handTrack [%f %f %f] }"),nId,pPosition->X,pPosition->Y,pPosition->Z);
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
		hr=m_handIn->set1Value(cnt,subNode);
		MessageBox(NULL,bstr,L"SUCCEEDED",MB_OK);
	}
	VARIANT_BOOL b=false;
	m_dev->m_browser->removeNode(node,&b);
	return hr;

}

HRESULT ControlHandsTrackNode::HandUpdate(XnUserID nId, const TrailHistory::Trail* trail){
//	MessageBox(NULL,L"update",_T("update"),MB_OK);
	if((!m_dev)||(!m_handOut)||(!m_handIn))return E_POINTER;
	int cnt=0;
	HRESULT hr=S_OK;
	hr=m_handOut->getSize(&cnt);
	//WCHAR bb[100];
	//swprintf_s(bb,100,L"record is %d",cnt);
	//MessageBox(NULL,bb,_T("record"),MB_OK);
	for (int i=0;i<cnt;i++)
	{
		int vlu=-1;
		Node* tmp_sub;
		m_handOut->get1Value(i,&tmp_sub);
		if(!tmp_sub){return E_POINTER;}
		EventOutSFInt32* idVlu;
		EventInMFVec3f* trackVec;
		hr=QueryEventOutSFNodeVlu(tmp_sub,_T("nid"),IID_EventOutSFInt32,&idVlu,&vlu);
	//	if(vlu==-1)return E_FAIL;
		WCHAR chr[80];
		MessageBox(NULL,_itow(vlu,chr,10),_T("findid is"),MB_OK);
		if(nId==vlu){
			WCHAR aa[100];
			swprintf_s(aa,100,L"find usr is %d",nId);
			MessageBox(NULL,aa,_T("find usr"),MB_OK);
			hr=QueryEventOutNode(tmp_sub,_T("handTrack"),IID_EventInMFVec3f,&trackVec);
			TrailHistory::Trail::ConstIterator it=trail->begin();
			CString ptstr(_T("["));
			for(;it!=trail->end();++it){
				XnPoint3D pt=*it;
				ptstr.AppendFormat(L"%f %f %f,",pt.X,pt.Y,pt.Z);
			}
			MessageBox(NULL,ptstr,L"findpt",MB_OK);
			ptstr+=_T("]");
			BSTR b=ptstr.AllocSysString();
			trackVec->setValueFromString(b);
			SysFreeString(b);
			break;
		}
	}
	return hr;
}

HRESULT ControlHandsTrackNode::HandDestroy(XnUserID nId){
	MessageBox(NULL,L"detroy",L"detroy",MB_OK);
	if((!m_dev)||(!m_handOut)||(!m_handIn))return E_POINTER;
	int cnt=0;
	HRESULT hr=S_OK;
	hr=m_handOut->getSize(&cnt);
	for (int i=0;i<cnt;i++)
	{
		int vlu=-1;
		Node* tmp_sub;
		hr=m_handOut->get1Value(i,&tmp_sub);
		EventOutSFInt32* idVlu;
		EventInMFVec3f* trackVec;
		hr=QueryEventOutSFNodeVlu(tmp_sub,_T("nid"),IID_EventOutSFInt32,&idVlu,&vlu);
		if(nId==vlu){
			/*VARIANT_BOOL b=-1;
			m_dev->m_browser->removeNode(tmp_sub,&b);*/
			tmp_sub->Release();
			tmp_sub=NULL;
			m_handIn->set1Value(i,NULL);
			/*WCHAR bb[10];
			MessageBox(NULL,_itow(b,bb,10),_T("delete?"),MB_OK);*/
			break;
		}
	}
	return hr;
}
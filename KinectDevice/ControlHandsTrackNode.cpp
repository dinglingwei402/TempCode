#include "StdAfx.h"
#include "ControlHandsTrackNode.h"
#include "QueryNode.h"

ControlHandsTrackNode::ControlHandsTrackNode(CKinectDev* dev)
{
		m_dev=dev;//Node with proto openiHand
		if (m_dev)
		{
			m_dev->m_handsTrack->QueryInterface(IID_EventOutMFNode,(void**)&m_handOut);
			m_dev->m_handsTrack->QueryInterface(IID_EventInMFNode,(void**)&m_handIn);
		}
}

ControlHandsTrackNode::~ControlHandsTrackNode(void)
{

}
HRESULT ControlHandsTrackNode::HandCreate(XnUserID nId, const XnPoint3D*	pPosition){
	if((!m_dev)||(!m_handOut)||(!m_handIn))return E_POINTER;
	int cnt=0;
	HRESULT hr=S_OK;
	hr=m_handOut->getSize(&cnt);
	CString vrmlSyntax;
	vrmlSyntax.Format(_T(" OpenNIHand{id %d handTrack [%f %f %f] }"),nId,pPosition->X,pPosition->Y,pPosition->Z);
	Node* node;
	BSTR b=vrmlSyntax.AllocSysString();
	hr= m_dev->m_browser->createVrmlFromString(b,&node);
	if (SUCCEEDED(hr))
	{
		hr=m_handIn->set1Value(cnt+1,node);
		MessageBox(NULL,b,L"SUCCEEDED",MB_OK);
	}
	if(node)node->Release();
	node=NULL;
	return hr;

}

HRESULT ControlHandsTrackNode::HandUpdate(XnUserID nId, const XnPoint3D*	pPosition){
	MessageBox(NULL,L"update",_T("update"),MB_OK);
	if((!m_dev)||(!m_handOut)||(!m_handIn))return E_POINTER;
	int cnt=0;
	HRESULT hr=S_OK;
	hr=m_handOut->getSize(&cnt);
	WCHAR chr[80];
	MessageBox(NULL,_itow(cnt,chr,10),_T("cnt is"),MB_OK);
	for (int i=0;i<cnt;i++)
	{
		Node* tmp;
		MessageBox(NULL,L"here1",L"debug",MB_OK);
		hr=m_handOut->get1Value(i,&tmp);
		EventOutSFInt32* idVlu;
		int vlu=0;
		hr=QueryEventOutSFNodeVlu(tmp,_T("id"),IID_EventOutSFInt32,&idVlu,&vlu);
		MessageBox(NULL,L"here3",L"debug",MB_OK);
		if(!idVlu)return E_POINTER;
		if(nId==vlu){
			MessageBox(NULL,L"here4",L"debug",MB_OK);
			MessageBox(NULL,_itow(i,chr,10),_T("find usr"),MB_OK);
			idVlu->Release();
			idVlu=NULL;
			MessageBox(NULL,L"here5",L"debug",MB_OK);
			break;
		
		}
		idVlu->Release();
		idVlu=NULL;
	}
	return hr;
}

HRESULT ControlHandsTrackNode::HandDestroy(XnUserID nId){
	return S_OK;
}
#include "StdAfx.h"
#include "ControlHandsTrackNode.h"
#include "QueryNode.h"
#include "XnList.h"
#include "Temp4Debug.h"

ControlHandsTrackNode::ControlHandsTrackNode(CKinectDev* dev):NULLSTR(_T("[]"))
{
		m_dev=dev;
		g_height=480;
		g_width=640;
		if (m_dev)
		{
			m_dev->m_hands->QueryInterface(IID_EventOutMFNode,(void**)&m_handOut);
			m_dev->m_hands->QueryInterface(IID_EventInMFNode,(void**)&m_handIn);
			m_dev->m_handsId->QueryInterface(IID_EventInMFInt32,(void**)&m_handsIdIn);
			m_dev->m_handsId->QueryInterface(IID_EventOutMFInt32,(void**)&m_handsIdOut);
		}
}

ControlHandsTrackNode::~ControlHandsTrackNode(void)
{

}
VOID  ControlHandsTrackNode::SetScreenSize(XnUInt32 x,XnUInt32 y){
	g_width=x;
	g_height=y;
}


HRESULT ControlHandsTrackNode::HandCreate(XnUserID nId, const XnPoint3D* pPosition){
	if((!m_dev)||(!m_handOut)||(!m_handIn)||!m_handsIdIn||!m_handsIdOut)return E_POINTER;
	wrt_Wchr(L"@ControlHandsTrackNode::HandCreate");
	wrt_i(nId);
	HRESULT hr=S_OK;
	int cnt=0;
	m_handsIdOut->getSize(&cnt);
	int* ids_bf_create=new int[cnt];
	m_handsIdOut->getValue(cnt,ids_bf_create);
	int indx=0;
	bool findit=false;
	for(int i=0;i<cnt;i++){
		if(ids_bf_create[i]==nId){
			indx=i;
			findit=true;
			break;
		}
	}
	if(findit){
		delete[] ids_bf_create;
		return hr;
	}
	m_handsIdIn->set1Value(cnt,nId);
	CString vrmlSyntax;
	XnFloat x=pPosition->X;
	XnFloat y=pPosition->Y;
	XnFloat z=pPosition->Z;
	XnFloat w=(x-g_width)/g_width;
	XnFloat h=(g_height-y)/g_height;
	vrmlSyntax.Format(_T(" OpenNIHand{id %d handTrack [%f %f %f] position %f %f}"),nId,x,y,z,w,h);
	Node* node;
	BSTR createHandStr=vrmlSyntax.AllocSysString();
	hr= m_dev->m_browser->createVrmlFromString(createHandStr,&node);
	wrt_Wchr(createHandStr);
	SysFreeString(createHandStr);
	if (SUCCEEDED(hr))
	{
		EventOutMFNode* children;
		Node* subNode;
		QueryEventOutNode(node,_T("children"),IID_EventOutMFNode,&children);
		children->get1Value(0,&subNode);
		m_handIn->set1Value(cnt,subNode);
		subNode->Release();
		subNode=NULL;
	}
	VARIANT_BOOL b=false;
	m_dev->m_browser->removeNode(node,&b);
	BSTR printidVlu;
	BSTR printhandVlu;
	m_handOut->toString(&printhandVlu);
	m_handsIdOut->toString(&printidVlu);
	wrt_Wchr(L"printidVlu");
	wrt_Wchr(printidVlu);
	wrt_Wchr(L"printhandVlu");
	wrt_Wchr(printhandVlu);
	SysFreeString(printhandVlu);
	SysFreeString(printidVlu);
	return hr;
}

HRESULT ControlHandsTrackNode::HandUpdate(XnUserID nId, const TrailHistory::Trail* trail){
	wrt_Wchr(L"@ControlHandsTrackNode::HandUpdate");
	wrt_i(nId);
	if((!m_dev)||(!m_handOut)||(!m_handIn))return E_POINTER;
	HRESULT hr=S_OK;
	int cnt=0;
	m_handsIdOut->getSize(&cnt);
	if(cnt==0)return hr;
	int* ids=new int[cnt];
	hr=m_handsIdOut->getValue(cnt,ids);
	int indx=0;
	bool findit=false;
	for (int i=0;i<cnt;i++)
	{
		if(ids[i]==nId){
			indx=i;
			findit=true;
			break;
		}
	}	
	if(!findit){	
		delete[] ids;
		return hr;
	}
	Node* tmp_sub;
	EventInMFVec3f* trackVec;
	hr=m_handOut->get1Value(indx,&tmp_sub);
	hr=QueryEventOutNode(tmp_sub,_T("handTrack"),IID_EventInMFVec3f,&trackVec);
	TrailHistory::Trail::ConstIterator it=trail->begin();
	unsigned short len=trail->getLength();
	float* pts=new float[len*3];
	CString ptstr(_T("["));
	int j=0;
	for(;it!=trail->end();++it){
		XnPoint3D pt=*it;
		pts[j*3]=pt.X;
		pts[j*3+1]=pt.Y;
		pts[j*3+2]=pt.Z;
		ptstr.AppendFormat(L"%f %f %f,",pt.X,pt.Y,pt.Z);
		j++;
	}
	assert(j==len);
	ptstr+=_T("]");
	trackVec->setValue(len*3,pts);
	BSTR handsUpdateStr=ptstr.AllocSysString();
	wrt_Wchr(handsUpdateStr);
	SysFreeString(handsUpdateStr);
	EventInSFVec2f* posVec;
	hr=QueryEventOutNode(tmp_sub,_T("position"),IID_EventInSFVec2f,&posVec);
	assert(posVec);
	float* posArr=new float[2];
	XnFloat w=(pts[0]-g_width)/g_width;
	XnFloat h=(g_height-pts[1])/g_height;
	posArr[0]=w;
	posArr[1]=h;
	posVec->setValue(posArr);
	delete[] ids;
	delete[] pts;
	delete[] posArr;
	return hr;
}

HRESULT ControlHandsTrackNode::HandDestroy(XnUserID nId){
	wrt_Wchr(L"@ControlHandsTrackNode::HandDestroy");
	wrt_i(nId);
	HRESULT hr=S_OK;
	if((!m_dev)||(!m_handOut)||(!m_handIn)||!m_handsIdIn||!m_handsIdOut)return E_POINTER;
	int cnt=0;
	m_handsIdOut->getSize(&cnt);
	if(cnt==0){
		return hr;
	}
	int* ids_bf_del=new int[cnt];
	m_handsIdOut->getValue(cnt,ids_bf_del);
	int indx=0;
	bool findit=false;
	for(int i=0;i<cnt;i++){
		if(ids_bf_del[i]==nId){
			indx=i;
			findit=true;
			break;
		}
	}
	
	if(!findit){
		delete[] ids_bf_del;
		return hr;
	}
	if(cnt==1){
		m_handsIdIn->setValueFromString(_T("[]"));
		m_handIn->setValueFromString(_T("[]"));
		delete[] ids_bf_del;
		return hr;
	}
	IDispatch** hand_bf_del=new IDispatch*[cnt];
	m_handOut->getValue(cnt,hand_bf_del);
	
	int* ids_aft_del=new int[cnt-1];
	IDispatch** hand_aft_del=new IDispatch*[cnt-1];

	int j=0;
	for(int i=0;i<cnt;i++){
		if(ids_bf_del[i]==nId){
			continue;
		}
		ids_aft_del[j]=ids_bf_del[i];
		hand_aft_del[j]=hand_bf_del[i];
		j++;
	}
	m_handsIdIn->setValue(cnt-1,ids_aft_del);
	m_handIn->setValue(cnt-1,hand_aft_del);

	delete[] ids_bf_del;
	delete[] ids_aft_del;
	delete[] hand_bf_del;
	delete[] hand_aft_del;
	ids_bf_del=NULL;
	ids_aft_del=NULL;
	hand_aft_del=NULL;
	hand_bf_del=NULL;

	BSTR printidVlu;
	BSTR printhandVlu;
	m_handOut->toString(&printhandVlu);
	m_handsIdOut->toString(&printidVlu);
	wrt_Wchr(L"printidVlu");
	wrt_Wchr(printidVlu);
	wrt_Wchr(L"printhandVlu");
	wrt_Wchr(printhandVlu);
	SysFreeString(printhandVlu);
	SysFreeString(printidVlu);

	return hr;
}
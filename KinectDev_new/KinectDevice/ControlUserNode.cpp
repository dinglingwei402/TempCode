#include "StdAfx.h"
#include "QueryNode.h"
#include "ControlUserNode.h"
#include "NiUserDetector.h"
#include "Temp4Debug.h"

BSTR  ControlUserNode::m_pos_field[]={L"XN_SKEL_POS_HEAD",L"XN_SKEL_POS_NECK",L"XN_SKEL_POS_TORSO",L"XN_SKEL_POS_WAIST",L"XN_SKEL_POS_LEFT_COLLAR",L"XN_SKEL_POS_LEFT_SHOULDER",L"XN_SKEL_POS_LEFT_ELBOW",L"XN_SKEL_POS_LEFT_WRIST",L"XN_SKEL_POS_LEFT_HAND",L"XN_SKEL_POS_LEFT_FINGERTIP",L"XN_SKEL_POS_RIGHT_COLLAR",L"XN_SKEL_POS_RIGHT_SHOULDER",L"XN_SKEL_POS_RIGHT_ELBOW",L"XN_SKEL_POS_RIGHT_WRIST",L"XN_SKEL_POS_RIGHT_HAND",L"XN_SKEL_POS_RIGHT_FINGERTIP",L"XN_SKEL_POS_LEFT_HIP",L"XN_SKEL_POS_LEFT_KNEE",L"XN_SKEL_POS_LEFT_ANKLE",L"XN_SKEL_POS_LEFT_FOOT",L"XN_SKEL_POS_RIGHT_HIP",L"XN_SKEL_POS_RIGHT_KNEE",L"XN_SKEL_POS_RIGHT_ANKLE",L"XN_SKEL_POS_RIGHT_FOOT"};

BSTR ControlUserNode::m_ori_field[]={L"XN_SKEL_ORI_HEAD",L"XN_SKEL_ORI_NECK",L"XN_SKEL_ORI_TORSO",L"XN_SKEL_ORI_WAIST",L"XN_SKEL_ORI_LEFT_COLLAR",L"XN_SKEL_ORI_LEFT_SHOULDER",L"XN_SKEL_ORI_LEFT_ELBOW",L"XN_SKEL_ORI_LEFT_WRIST",L"XN_SKEL_ORI_LEFT_HAND",L"XN_SKEL_ORI_LEFT_FINGERTIP",L"XN_SKEL_ORI_RIGHT_COLLAR",L"XN_SKEL_ORI_RIGHT_SHOULDER",L"XN_SKEL_ORI_RIGHT_ELBOW",L"XN_SKEL_ORI_RIGHT_WRIST",L"XN_SKEL_ORI_RIGHT_HAND",L"XN_SKEL_ORI_RIGHT_FINGERTIP",L"XN_SKEL_ORI_LEFT_HIP",L"XN_SKEL_ORI_LEFT_KNEE",L"XN_SKEL_ORI_LEFT_ANKLE",L"XN_SKEL_ORI_LEFT_FOOT",L"XN_SKEL_ORI_RIGHT_HIP",L"XN_SKEL_ORI_RIGHT_KNEE",L"XN_SKEL_ORI_RIGHT_ANKLE",L"XN_SKEL_ORI_RIGHT_FOOT"};

XnSkeletonJoint ControlUserNode::m_joint_names[]={XN_SKEL_HEAD,XN_SKEL_NECK,XN_SKEL_TORSO,XN_SKEL_WAIST,XN_SKEL_LEFT_COLLAR,XN_SKEL_LEFT_SHOULDER,XN_SKEL_LEFT_ELBOW,XN_SKEL_LEFT_WRIST,XN_SKEL_LEFT_HAND,XN_SKEL_LEFT_FINGERTIP,XN_SKEL_RIGHT_COLLAR,XN_SKEL_RIGHT_SHOULDER,XN_SKEL_RIGHT_ELBOW,XN_SKEL_RIGHT_WRIST,XN_SKEL_RIGHT_HAND,XN_SKEL_RIGHT_FINGERTIP,XN_SKEL_LEFT_HIP,XN_SKEL_LEFT_KNEE,XN_SKEL_LEFT_ANKLE,XN_SKEL_LEFT_FOOT,XN_SKEL_RIGHT_HIP,XN_SKEL_RIGHT_KNEE,XN_SKEL_RIGHT_ANKLE,XN_SKEL_RIGHT_FOOT};

ControlUserNode::ControlUserNode(CKinectDev* dev):NULLSTR(_T("NULL"))
{
	m_lastCom[0]=0;
	m_lastCom[1]=0;
	m_lastCom[2]=0;
	this->m_dev=dev;
	dev->m_users->QueryInterface(IID_EventInMFNode,(void**)(&this->m_userIn));
	dev->m_users->QueryInterface(IID_EventOutMFNode,(void**)(&this->m_userOut));
	dev->m_usersId->QueryInterface(IID_EventOutMFInt32,(void**)(&this->m_usersIdOut));
	dev->m_usersId->QueryInterface(IID_EventInMFInt32,(void**)(&this->m_usersIdIn));
}
ControlUserNode::~ControlUserNode(void)
{
}
void ControlUserNode::Div1000(XnVector3D& vec){
	vec.X*=-(float)0.001;
	vec.Y*=(float)0.001;
	vec.Z*=-(float)0.001;
}

HRESULT ControlUserNode::UserNew(XnUserID nId){
	HRESULT hr=S_OK;
	wrt_Wchr(L"@ControlUserNode::UserNew");
	wrt_i(nId);
	if((!m_dev)||(!m_userOut)||(!m_userIn))return E_POINTER;
	int cnt=0;
	m_usersIdOut->getSize(&cnt);
	int* ids_bf_create=new int[cnt];
	m_usersIdOut->getValue(cnt,ids_bf_create);
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
	m_usersIdIn->set1Value(cnt,nId);
	CString vrmlSyntax;
	vrmlSyntax.Format(_T(" OpenNIUser{id %d\r\n isExit FALSE}"),nId);
	Node* node;
	BSTR createUserStr=vrmlSyntax.AllocSysString();
	hr= m_dev->m_browser->createVrmlFromString(createUserStr,&node);
	wrt_Wchr(createUserStr);
	SysFreeString(createUserStr);
	if (SUCCEEDED(hr))
	{
		EventOutMFNode* children;
		Node* subNode;
		QueryEventOutNode(node,_T("children"),IID_EventOutMFNode,&children);
		children->get1Value(0,&subNode);
		m_userIn->set1Value(cnt,subNode);
		subNode->Release();
		subNode=NULL;
	}
	VARIANT_BOOL b=false;
	m_dev->m_browser->removeNode(node,&b);
	BSTR printidVlu;
	BSTR printuserVlu;
	m_userOut->toString(&printuserVlu);
	m_usersIdOut->toString(&printidVlu);
	wrt_Wchr(L"printidVlu");
	wrt_Wchr(printidVlu);
	wrt_Wchr(L"printuserVlu");
	wrt_Wchr(printuserVlu);
	SysFreeString(printuserVlu);
	SysFreeString(printidVlu);
	return hr;
}
HRESULT ControlUserNode::UserLost(XnUserID nId){
	wrt_Wchr(L"@ControlUserNode::UserLost");
	wrt_i(nId);
	HRESULT hr=S_OK;
	if((!m_dev)||(!m_userOut)||(!m_userIn))return E_POINTER;
	int cnt=0;
	m_usersIdOut->getSize(&cnt);
	if(cnt==0)return hr;
	int* ids_bf_del=new int[cnt];
	m_usersIdOut->getValue(cnt,ids_bf_del);
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
		m_usersIdIn->setValueFromString(_T("[]"));
		m_userIn->setValueFromString(_T("[]"));
		delete[] ids_bf_del;
		return hr;
	}
	IDispatch** user_bf_del=new IDispatch*[cnt];
	m_userOut->getValue(cnt,user_bf_del);

	int* ids_aft_del=new int[cnt-1];
	IDispatch** user_aft_del=new IDispatch*[cnt-1];

	int j=0;
	for(int i=0;i<cnt;i++){
		if(ids_bf_del[i]==nId){
			continue;
		}
		ids_aft_del[j]=ids_bf_del[i];
		user_aft_del[j]=user_bf_del[i];
		j++;
	}
	m_usersIdIn->setValue(cnt-1,ids_aft_del);
	m_userIn->setValue(cnt-1,user_aft_del);

	delete[] ids_bf_del;
	delete[] ids_aft_del;
	delete[] user_aft_del;
	delete[] user_bf_del;
    
	ids_aft_del=ids_bf_del=NULL;
	user_bf_del=user_aft_del=NULL;
	BSTR printidVlu;
	BSTR printuserVlu;
	m_userOut->toString(&printuserVlu);
	m_usersIdOut->toString(&printidVlu);
	wrt_Wchr(L"printidVlu");
	wrt_Wchr(printidVlu);
	wrt_Wchr(L"printuserVlu");
	wrt_Wchr(printuserVlu);
	SysFreeString(printuserVlu);
	SysFreeString(printidVlu);

	return hr;
}

HRESULT ControlUserNode::UsersUpdate(xn::UserGenerator& gen )
{
//	wrt_Wchr(L"@ControlUserNode::UsersUpdate");
	HRESULT hr=S_OK;
	int cnt=0;
	m_usersIdOut->getSize(&cnt);
	if(cnt==0)return hr;
	int* ids=new int[cnt];
	hr=m_usersIdOut->getValue(cnt,ids);
	for(int i=0;i<cnt;i++){
		Node* tmp_sub;
		hr=m_userOut->get1Value(i,&tmp_sub);
//////////////////////////////////////////////////
		XnPoint3D pt;
		gen.GetCoM(ids[i],pt);
		Div1000(pt);
		EventOutSFVec3f* com;
		hr=QueryEventOutNode(tmp_sub,_T("userCoM"),IID_EventOutSFVec3f,&com);
		assert(com);
		float vlu[3];
		com->getValue(vlu);
		if(vlu[0]!=m_lastCom[0]&&vlu[1]!=m_lastCom[1]&&vlu[2]!=m_lastCom[2]){
			((EventInSFVec3f*)com)->setValue((float*)(&pt));
			m_lastCom[0]=vlu[0];
			m_lastCom[1]=vlu[1];
			m_lastCom[2]=vlu[2];
		}
		
/////////////////////////////////////////////////////
		int len=sizeof(m_joint_names)/sizeof(XnUInt32);
		assert(len==24);
		for(int j=0;j<len;j++){
			EventInSFVec3f* pos;
			EventInSFMatrix* ori;
			hr=QueryEventInNode(tmp_sub,m_pos_field[j],IID_EventInSFVec3f,&pos);
			hr=QueryEventInNode(tmp_sub,m_ori_field[j],IID_EventInSFMatrix,&ori);
			XnSkeletonJointTransformation trans;
			gen.GetSkeletonCap().GetSkeletonJoint(ids[i],m_joint_names[j],trans);
			if (pos)
			{
				XnVector3D pst=trans.position.position;
				Div1000(pst);
				pos->setValue((float*)(&pst));
			}
			if (ori)
			{
				float* ori_Matrix=trans.orientation.orientation.elements;
				float save_ori[16]={ori_Matrix[0],-ori_Matrix[3],ori_Matrix[6],0.0, 
					-ori_Matrix[1],ori_Matrix[4],-ori_Matrix[7],0.0, 
					ori_Matrix[2],-ori_Matrix[5],ori_Matrix[8],0.0, 
					0.0,0.0,0.0,1.0};
				ori->setValue(save_ori);
			}
		}
	}
	 return hr;
 }






HRESULT ControlUserNode::UserExit(XnUserID nId){
	HRESULT hr=S_OK;
	int cnt=0;
	m_usersIdOut->getSize(&cnt);
	if(cnt==0)return hr;
	int* ids_bf_create=new int[cnt];
	m_usersIdOut->getValue(cnt,ids_bf_create);
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
		Node* tmp_sub;
		hr=m_userOut->get1Value(indx,&tmp_sub);
		EventInSFBool* isExit;
		hr=QueryEventInNode(tmp_sub,_T("isExit"),IID_EventInSFBool,&isExit);
		isExit->setValue(true);
	}
}

HRESULT ControlUserNode::UserReEnter(XnUserID nId){
	HRESULT hr=S_OK;
	int cnt=0;
	m_usersIdOut->getSize(&cnt);
	if(cnt==0)return hr;
	int* ids_bf_create=new int[cnt];
	m_usersIdOut->getValue(cnt,ids_bf_create);
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
		Node* tmp_sub;
		hr=m_userOut->get1Value(indx,&tmp_sub);
		EventInSFBool* isExit;
		hr=QueryEventInNode(tmp_sub,_T("isExit"),IID_EventInSFBool,&isExit);
		isExit->setValue(false);
	}
	return S_OK;
}


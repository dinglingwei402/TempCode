#include "StdAfx.h"
#include "QueryNode.h"
#include "ControlUserNode.h"
#include "NiUserDetector.h"

BSTR  ControlUserNode::m_pos_field[]={L"XN_SKEL_POS_HEAD",L"XN_SKEL_POS_NECK",L"XN_SKEL_POS_TORSO",L"XN_SKEL_POS_WAIST",L"XN_SKEL_POS_LEFT_COLLAR",L"XN_SKEL_POS_LEFT_SHOULDER",L"XN_SKEL_POS_LEFT_ELBOW",L"XN_SKEL_POS_LEFT_WRIST",L"XN_SKEL_POS_LEFT_HAND",L"XN_SKEL_POS_LEFT_FINGERTIP",L"XN_SKEL_POS_RIGHT_COLLAR",L"XN_SKEL_POS_RIGHT_SHOULDER",L"XN_SKEL_POS_RIGHT_ELBOW",L"XN_SKEL_POS_RIGHT_WRIST",L"XN_SKEL_POS_RIGHT_HAND",L"XN_SKEL_POS_RIGHT_FINGERTIP",L"XN_SKEL_POS_LEFT_HIP",L"XN_SKEL_POS_LEFT_KNEE",L"XN_SKEL_POS_LEFT_ANKLE",L"XN_SKEL_POS_LEFT_FOOT",L"XN_SKEL_POS_RIGHT_HIP",L"XN_SKEL_POS_RIGHT_KNEE",L"XN_SKEL_POS_RIGHT_ANKLE",L"XN_SKEL_POS_RIGHT_FOOT"};

BSTR ControlUserNode::m_ori_field[]={L"XN_SKEL_ORI_HEAD",L"XN_SKEL_ORI_NECK",L"XN_SKEL_ORI_TORSO",L"XN_SKEL_ORI_WAIST",L"XN_SKEL_ORI_LEFT_COLLAR",L"XN_SKEL_ORI_LEFT_SHOULDER",L"XN_SKEL_ORI_LEFT_ELBOW",L"XN_SKEL_ORI_LEFT_WRIST",L"XN_SKEL_ORI_LEFT_HAND",L"XN_SKEL_ORI_LEFT_FINGERTIP",L"XN_SKEL_ORI_RIGHT_COLLAR",L"XN_SKEL_ORI_RIGHT_SHOULDER",L"XN_SKEL_ORI_RIGHT_ELBOW",L"XN_SKEL_ORI_RIGHT_WRIST",L"XN_SKEL_ORI_RIGHT_HAND",L"XN_SKEL_ORI_RIGHT_FINGERTIP",L"XN_SKEL_ORI_LEFT_HIP",L"XN_SKEL_ORI_LEFT_KNEE",L"XN_SKEL_ORI_LEFT_ANKLE",L"XN_SKEL_ORI_LEFT_FOOT",L"XN_SKEL_ORI_RIGHT_HIP",L"XN_SKEL_ORI_RIGHT_KNEE",L"XN_SKEL_ORI_RIGHT_ANKLE",L"XN_SKEL_ORI_RIGHT_FOOT"};

XnSkeletonJoint ControlUserNode::m_joint_names[]={XN_SKEL_HEAD,XN_SKEL_NECK,XN_SKEL_TORSO,XN_SKEL_WAIST,XN_SKEL_LEFT_COLLAR,XN_SKEL_LEFT_SHOULDER,XN_SKEL_LEFT_ELBOW,XN_SKEL_LEFT_WRIST,XN_SKEL_LEFT_HAND,XN_SKEL_LEFT_FINGERTIP,XN_SKEL_RIGHT_COLLAR,XN_SKEL_RIGHT_SHOULDER,XN_SKEL_RIGHT_ELBOW,XN_SKEL_RIGHT_WRIST,XN_SKEL_RIGHT_HAND,XN_SKEL_RIGHT_FINGERTIP,XN_SKEL_LEFT_HIP,XN_SKEL_LEFT_KNEE,XN_SKEL_LEFT_ANKLE,XN_SKEL_LEFT_FOOT,XN_SKEL_RIGHT_HIP,XN_SKEL_RIGHT_KNEE,XN_SKEL_RIGHT_ANKLE,XN_SKEL_RIGHT_FOOT};

ControlUserNode::ControlUserNode(CKinectDev* dev)
{
	this->m_dev=dev;
	dev->m_users->QueryInterface(IID_EventInMFNode,(void**)(&this->m_userIn));
	dev->m_users->QueryInterface(IID_EventOutMFNode,(void**)(&this->m_userOut));
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
	MessageBox(NULL,L"UserNew",L"UserNew",MB_OK);
	if((!m_dev)||(!m_userOut)||(!m_userIn))return E_POINTER;
	int cnt=0;
	HRESULT hr=S_OK;
	hr=m_userOut->getSize(&cnt);
	CString vrmlSyntax;
	vrmlSyntax.Format(_T(" OpenNIUser{playerID %d}"),nId);
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

HRESULT ControlUserNode::UsersUpdate(xn::UserGenerator& gen )
{
//	MessageBox(NULL,L"Inupdate",L"Inupdate",MB_OK);
	XnUInt16 MaxUser=20;
	 XnUserID pUsers[20];
	 gen.GetUsers(pUsers,MaxUser);
	 if(MaxUser==0)return S_FALSE;
	 int cnt=0;
	 HRESULT hr=S_OK;
	 hr=m_userOut->getSize(&cnt);
	 for (int i=0;i<MaxUser;i++)
	 {
		 bool findid=false;
		 for (int j=0;j<cnt;j++){
			 int vlu=-1;
			 Node* tmp_sub;
			 hr=m_userOut->get1Value(i,&tmp_sub);
			 if(!tmp_sub)continue;
			 EventOutSFInt32* idVlu;
			 hr=QueryEventOutSFNodeVlu(tmp_sub,_T("playerID"),IID_EventOutSFInt32,&idVlu,&vlu);
			 if(vlu==pUsers[j]){
					findid=true;
					//!!!!!!!!!!!!!!!!!!!!!!!!
					XnPoint3D pt;
					gen.GetCoM(pUsers[i],pt);
					Div1000(pt);
					EventInSFVec3f* com;
					hr=QueryEventInNode(tmp_sub,_T("userCoM"),IID_EventInSFVec3f,&com);
					if(!com){
						MessageBox(NULL,L"com is null",L"CoM",MB_OK);
					}
					com->setValue((float*)(&pt));
					//#########################
					int len=24;//sizeof(m_joint_names)/sizeof(XnUInt16);
				//	assert(len!=24);
					for(int j=0;j<len;j++){
						EventInSFVec3f* pos;
						EventInSFMatrix* ori;
						hr=QueryEventInNode(tmp_sub,m_pos_field[j],IID_EventInSFVec3f,&pos);
						hr=QueryEventInNode(tmp_sub,m_ori_field[j],IID_EventInSFMatrix,&ori);
						XnSkeletonJointTransformation trans;
						gen.GetSkeletonCap().GetSkeletonJoint(pUsers[i],m_joint_names[j],trans);
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
					//@@@@@@@@@@@@@@@@@@@@@@@@@
					break;
			 }
		 }
	 }
 }





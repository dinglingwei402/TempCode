#pragma once
#include "UserSYNC.h"
#include "KinectDev.h"


class ControlUserNode :public UserSYNC
{
public:
	ControlUserNode(CKinectDev* dev);
	~ControlUserNode(void);
	HRESULT UserNew(XnUserID nId);
	HRESULT UserLost(XnUserID nId);
	HRESULT UsersUpdate(xn::UserGenerator& gen);
private:
	void Div1000(XnVector3D& vec);
private:
	CKinectDev* m_dev;
	EventOutMFNode* m_userOut;
	EventInMFNode* m_userIn;
	EventInMFInt32* m_usersIdIn;
	EventOutMFInt32* m_usersIdOut;
	static BSTR m_pos_field[];
	static BSTR m_ori_field[];
	static XnSkeletonJoint m_joint_names[];
	const BSTR NULLSTR;
};

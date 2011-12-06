#pragma once
#include "usersync.h"
#include "KinectDev.h"

class ControlUserNode :
	public UserSYNC
{
public:
	ControlUserNode(CKinectDev* dev);
	~ControlUserNode(void);
	HRESULT UserNew(XnUserID nId);
	HRESULT UserLost(XnUserID nId);
	HRESULT UsersUpdate(XnHash hash);
private:
	CKinectDev* m_dev;
	EventOutMFNode* m_userOut;
	EventInMFNode* m_userIn;
};

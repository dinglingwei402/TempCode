#pragma once
#include "XnCppWrapper.h"
#include "NiUserDetector.h"

class UserSYNC
{
public:
	UserSYNC(void);
	~UserSYNC(void);
	virtual HRESULT UserNew(XnUserID nId){return S_OK;};
	virtual HRESULT UserLost(XnUserID nId){return S_OK;};
	virtual HRESULT UsersUpdate(XnUserSkeletonSet* uss){return S_OK;};
};

#pragma once
#include "XnCppWrapper.h"

class UserSYNC
{
public:
	UserSYNC();
	~UserSYNC(void);
	virtual HRESULT UserNew(XnUserID nId){return S_OK;};
	virtual HRESULT UserLost(XnUserID nId){return S_OK;};
	virtual HRESULT UsersUpdate(xn::UserGenerator& gen){return S_OK;};
};

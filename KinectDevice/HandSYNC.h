#pragma once
#include "XnCppWrapper.h"
#include "NiTrailHistory.h"

class HandSYNC
{
public:
	HandSYNC();
	~HandSYNC(void);
	virtual HRESULT HandCreate(XnUserID nId, const XnPoint3D*	pPosition){return S_OK;};
	virtual	HRESULT HandUpdate(XnUserID nId, const TrailHistory::Trail* trail){return S_OK;};
	virtual HRESULT HandDestroy(XnUserID nId){return S_OK;};
private:
	void* m_dev;
};

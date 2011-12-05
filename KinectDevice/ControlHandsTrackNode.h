#pragma once
#include "handsync.h"
#include "blaxxunVRML.h"
#include "KinectDev.h"

class ControlHandsTrackNode :
	public HandSYNC
{
public:
	ControlHandsTrackNode(CKinectDev* dev);
	~ControlHandsTrackNode(void);
	HRESULT HandCreate(XnUserID nId, const XnPoint3D*	pPosition);
	HRESULT HandUpdate(XnUserID nId, const XnPoint3D*	pPosition);
	HRESULT HandDestroy(XnUserID nId);
private:
	CKinectDev* m_dev;
	EventOutMFNode* m_handOut;
	EventInMFNode* m_handIn;
};

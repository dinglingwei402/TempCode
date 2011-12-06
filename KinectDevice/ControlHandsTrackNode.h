#pragma once
#include "handsync.h"
#include "blaxxunVRML.h"
#include "KinectDev.h"
#include "NiTrailHistory.h"

class ControlHandsTrackNode :
	public HandSYNC
{
public:
	ControlHandsTrackNode(CKinectDev* dev);
	~ControlHandsTrackNode(void);
	HRESULT HandCreate(XnUserID nId, const XnPoint3D*	pPosition);
	HRESULT HandUpdate(XnUserID nId, const TrailHistory::Trail* trail);
	HRESULT HandDestroy(XnUserID nId);
private:
	CKinectDev* m_dev;
	EventOutMFNode* m_handOut;
	EventInMFNode* m_handIn;
};

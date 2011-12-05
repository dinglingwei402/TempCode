#include "stdafx.h"
#include "ControlKinect.h"
#include "NiHandTracker.h"
#include "NiUserDetector.h"
#include "Temp4Debug.h"
#include "ControlHandsTrackNode.h"

xn::Context g_context;
xn::DepthGenerator depGen;
xn::ImageGenerator imgGen;
UserTracker* ut;
HandTracker* ht;
XnStatus Init_Kinect(CKinectDev* dev){
	XnStatus rc=XN_STATUS_OK;
	#ifdef _DEBUG
		rc=g_context.Init();
		CHECK_RC(rc,"get g_context fail");
		rc=depGen.Create(g_context);
		CHECK_RC(rc,"get depGen fail");
		rc=imgGen.Create(g_context);
		CHECK_RC(rc,"get imgGen fail");
    #else
		rc=g_context.InitFromXmlFile(SAMPLE_XML_PATH,NULL);
		CHECK_RC(rc,"get g_context fail");
	#endif // _DEBUG
		ht=new HandTracker(g_context);
		ut=new UserTracker(g_context);
		ControlHandsTrackNode* chtn=new ControlHandsTrackNode(dev);
		MessageBox(NULL,L"init",L"init",MB_OK);
		rc=ht->Init(chtn);
		rc=ht->Run();
	//	rc=ut->Init();
	//	ut->Run();
		
		
	return rc;
}

void readHandHistory(HandTracker* handtracker,EventInMFNode* m_handsTrack){
	typedef TrailHistory			History;
	typedef History::ConstIterator	HistoryIterator;
	typedef History::Trail			Trail;
	typedef Trail::ConstIterator	TrailIterator;
	const TrailHistory&	history =handtracker->GetHistory();
	// History points coordinates buffer
	XnFloat	coordinates[3 * MAX_HAND_TRAIL_LENGTH];
	const HistoryIterator	hend = history.end();
	HistoryIterator		hit = history.begin();
	if(hit==hend) return;
	CString getPointStr;
	for( ;hit != hend; ++hit)
	{
		int	numpoints = 0;
		const Trail&	trail = hit.GetTrail();
		const TrailIterator	tend = trail.end();
		TrailIterator	tit = trail.begin();
		if (tend==tit){
			continue;
		}
		getPointStr+=_T("OpenNIHandsTrack {id ");
		CString uidstr;
		uidstr.Format(_T("%d"),hit.GetKey());
		getPointStr+=uidstr;
		getPointStr+=_T(" handTrack [");
		for(;tit != tend; ++tit)
		{
			XnPoint3D	point = *tit;
			CString ptstr;
			ptstr.Format(_T(" %f %f %f,"),point.X,point.Y,point.Z);
			getPointStr+=ptstr;
			++numpoints;
		}
		getPointStr+=(_T("]}"));
	}
	MessageBox(NULL,getPointStr,L"cstring",MB_OK);
	BSTR b=getPointStr.AllocSysString();
	m_handsTrack->setValueFromString(b);
//	SysFreeString(b);
}



XnStatus updateKinect(){
	XnStatus rc=g_context.WaitAndUpdateAll();
//	m_handsTrack->setValueFromString(L"Shape{}");
//	readHandHistory(ht,m_handsTrack);
	return 	rc;
}


void Close_Kinect(){
	g_context.Shutdown();
}
#include "stdafx.h"
#include "ControlKinect.h"
#include "NiHandTracker.h"
#include "NiUserDetector.h"
#include "Temp4Debug.h"
#include "ControlHandsTrackNode.h"
#include "ControlUserNode.h"
#include "QueryNode.h"

float lastFloorCtr[3]={0,0,0};
float lastFloorNml[3]={0,0,0};
xn::Context g_context;
xn::DepthGenerator depGen;
xn::ImageGenerator imgGen;
xn::SceneAnalyzer scenAnlyz;
UserTracker* ut;
HandTracker* ht;
EventInSFVec3f* floor_ctr;
EventInSFVec3f* floor_nml;

XnStatus Init_Kinect(CKinectDev* dev){
	XnStatus rc=XN_STATUS_OK;
		rc=g_context.Init();
		rc=depGen.Create(g_context);
		const XnChar* statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"create context");
		rc=imgGen.Create(g_context);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"create img");
		scenAnlyz.Create(g_context);
		QueryEventOutNode(dev->m_floor,_T("point"),IID_EventInSFVec3f,&floor_ctr);
		QueryEventOutNode(dev->m_floor,_T("normal"),IID_EventInSFVec3f,&floor_nml);
		ht=new HandTracker(g_context);
		ut=new UserTracker(g_context);
		ControlHandsTrackNode* chtn=new ControlHandsTrackNode(dev);
		ControlUserNode* cun=new ControlUserNode(dev);
		xn::DepthMetaData depMD;
		depGen.GetMetaData(depMD);
		int width=depMD.XRes();
		int height=depMD.YRes();
		chtn->SetScreenSize(width,height);
		rc=ht->Init(chtn);
		rc=ht->Run();
		rc=ut->Init(cun);
		rc=ut->Run();
	return rc;
}

void  Div1000(XnVector3D& vec){
	vec.X*=-(float)0.001;
	vec.Y*=(float)0.001;
	vec.Z*=-(float)0.001;
}
VOID SetFloorData(){
	XnPlane3D plane;
	XnStatus rs=scenAnlyz.GetFloor(plane);
	XnPoint3D pt=plane.ptPoint;
	Div1000(pt);
	if(pt.X!=lastFloorCtr[0]||pt.Y!=lastFloorCtr[1]||pt.Z!=lastFloorCtr[2]){
		floor_ctr->setValue((float*)(&pt));
		lastFloorCtr[0]=pt.X;
		lastFloorCtr[1]=pt.Y;
		lastFloorCtr[2]=pt.Z;
	}
	if (plane.vNormal.X!=lastFloorNml[0]||plane.vNormal.Y!=lastFloorNml[1]||plane.vNormal.Z!=lastFloorNml[2])
	{
		floor_nml->setValue((float*)(&plane.vNormal));
		lastFloorNml[0]=plane.vNormal.X;
		lastFloorNml[1]=plane.vNormal.Y;
		lastFloorNml[2]=plane.vNormal.Z;
	}
}

XnStatus updateKinect(){
	XnStatus rc=g_context.WaitAndUpdateAll();
	ut->Update();
	SetFloorData();
	return 	rc;
}


void Close_Kinect(){
	if(ut)
	{
		delete ut;
	}
	if (ht)
	{
		delete ht;
	}
	g_context.Shutdown();
}
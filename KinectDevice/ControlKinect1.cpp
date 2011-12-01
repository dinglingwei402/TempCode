#include "stdafx.h"
#include "QueryNode.h"
#include "ControlKinect.h"
#include "SkltnFrKnct.h"
#include "TrackingHands.h"

using namespace xn;
BSTR pos_field[]={L"XN_SKEL_POS_HEAD",L"XN_SKEL_POS_NECK",L"XN_SKEL_POS_TORSO",L"XN_SKEL_POS_WAIST",L"XN_SKEL_POS_LEFT_COLLAR",L"XN_SKEL_POS_LEFT_SHOULDER",L"XN_SKEL_POS_LEFT_ELBOW",L"XN_SKEL_POS_LEFT_WRIST",L"XN_SKEL_POS_LEFT_HAND",L"XN_SKEL_POS_LEFT_FINGERTIP",L"XN_SKEL_POS_RIGHT_COLLAR",L"XN_SKEL_POS_RIGHT_SHOULDER",L"XN_SKEL_POS_RIGHT_ELBOW",L"XN_SKEL_POS_RIGHT_WRIST",L"XN_SKEL_POS_RIGHT_HAND",L"XN_SKEL_POS_RIGHT_FINGERTIP",L"XN_SKEL_POS_LEFT_HIP",L"XN_SKEL_POS_LEFT_KNEE",L"XN_SKEL_POS_LEFT_ANKLE",L"XN_SKEL_POS_LEFT_FOOT",L"XN_SKEL_POS_RIGHT_HIP",L"XN_SKEL_POS_RIGHT_KNEE",L"XN_SKEL_POS_RIGHT_ANKLE",L"XN_SKEL_POS_RIGHT_FOOT"};
BSTR ori_field[]={L"XN_SKEL_ORI_HEAD",L"XN_SKEL_ORI_NECK",L"XN_SKEL_ORI_TORSO",L"XN_SKEL_ORI_WAIST",L"XN_SKEL_ORI_LEFT_COLLAR",L"XN_SKEL_ORI_LEFT_SHOULDER",L"XN_SKEL_ORI_LEFT_ELBOW",L"XN_SKEL_ORI_LEFT_WRIST",L"XN_SKEL_ORI_LEFT_HAND",L"XN_SKEL_ORI_LEFT_FINGERTIP",L"XN_SKEL_ORI_RIGHT_COLLAR",L"XN_SKEL_ORI_RIGHT_SHOULDER",L"XN_SKEL_ORI_RIGHT_ELBOW",L"XN_SKEL_ORI_RIGHT_WRIST",L"XN_SKEL_ORI_RIGHT_HAND",L"XN_SKEL_ORI_RIGHT_FINGERTIP",L"XN_SKEL_ORI_LEFT_HIP",L"XN_SKEL_ORI_LEFT_KNEE",L"XN_SKEL_ORI_LEFT_ANKLE",L"XN_SKEL_ORI_LEFT_FOOT",L"XN_SKEL_ORI_RIGHT_HIP",L"XN_SKEL_ORI_RIGHT_KNEE",L"XN_SKEL_ORI_RIGHT_ANKLE",L"XN_SKEL_ORI_RIGHT_FOOT"};
XnSkeletonJoint joint_names[]={XN_SKEL_HEAD,XN_SKEL_NECK,XN_SKEL_TORSO,XN_SKEL_WAIST,XN_SKEL_LEFT_COLLAR,XN_SKEL_LEFT_SHOULDER,XN_SKEL_LEFT_ELBOW,XN_SKEL_LEFT_WRIST,XN_SKEL_LEFT_HAND,XN_SKEL_LEFT_FINGERTIP,XN_SKEL_RIGHT_COLLAR,XN_SKEL_RIGHT_SHOULDER,XN_SKEL_RIGHT_ELBOW,XN_SKEL_RIGHT_WRIST,XN_SKEL_RIGHT_HAND,XN_SKEL_RIGHT_FINGERTIP,XN_SKEL_LEFT_HIP,XN_SKEL_LEFT_KNEE,XN_SKEL_LEFT_ANKLE,XN_SKEL_LEFT_FOOT,XN_SKEL_RIGHT_HIP,XN_SKEL_RIGHT_KNEE,XN_SKEL_RIGHT_ANKLE,XN_SKEL_RIGHT_FOOT};
Context g_context;
SceneAnalyzer g_scene;
DepthGenerator g_depth;
ImageGenerator g_image;
GestureGenerator g_gesture;
HandsGenerator g_hands;
UserGenerator g_user;
EventOutSFNode* g_skltn,*g_hnz,*g_flr;
bool isInit=false;
int pix_w;
int pix_h;
int lastTrackingStatus=0;
int lastPlayerStatus=0;
float lastFloorCtr[3]={0,0,0};
float lastFloorNml[3]={0,0,0};
XnStatus Init_Kinect(EventOutSFNode* skltn,EventOutSFNode* hnz,EventOutSFNode* flr){
	XnStatus rc=XN_STATUS_OK;
	EnumerationErrors errors;
	DepthMetaData g_depthMD;
	ImageMetaData g_imageMD;
	rc = g_context.InitFromXmlFile(SAMPLE_XML_PATH, &errors);
	CHECK_RC(rc, "InitFromXml");
	rc = g_context.FindExistingNode(XN_NODE_TYPE_DEPTH, g_depth);
	CHECK_RC(rc,"XN_NODE_TYPE_DEPTH");
	rc = g_context.FindExistingNode(XN_NODE_TYPE_IMAGE, g_image);
	CHECK_RC(rc,"XN_NODE_TYPE_IMAGE");
	rc=  g_context.FindExistingNode(XN_NODE_TYPE_USER,g_user); 
	CHECK_RC(rc,"XN_NODE_TYPE_USER");
	rc=g_context.FindExistingNode(XN_NODE_TYPE_SCENE,g_scene);
	CHECK_RC(rc,"XN_NODE_TYPE_SCENE");
	rc=g_context.FindExistingNode(XN_NODE_TYPE_HANDS,g_hands);
	CHECK_RC(rc,"XN_NODE_TYPE_HANDS");
	rc=g_context.FindExistingNode(XN_NODE_TYPE_GESTURE,g_gesture);
	CHECK_RC(rc,"XN_NODE_TYPE_GESTURE");
	g_depth.GetMetaData(g_depthMD);
	g_fps=g_depthMD.FPS();
	g_image.GetMetaData(g_imageMD);
	rc=init_skeleton();
	CHECK_RC(rc,"INIT SKELETON");
	rc=init_hands();
	CHECK_RC(rc,"INIT HANDS");
	pix_w=g_depthMD.FullXRes();
	pix_h=g_depthMD.FullYRes();
	if(pix_h==0||pix_w==0){return XN_STATUS_ERROR;}
	g_skltn=skltn;
	g_hnz=hnz;
	g_flr=flr;
	if(NULL==g_skltn||NULL==g_hands||NULL==g_flr)return XN_STATUS_ERROR;
	isInit=true;
	return rc;
}
VOID SetUserSkeletonData(XnUserID uid){	
	HRESULT hr;
	if(uid!=lastPlayerStatus){
		EventInSFInt32* plyr;
		QuerySFNode(g_skltn,L"playerID",IID_EventInSFInt32,&plyr);
		plyr->setValue(uid);
		plyr->Release();
		lastPlayerStatus=uid;
	}
	if(uid!=0){
		EventInSFVec3f* com;
		QuerySFNode(g_skltn,L"userCoM",IID_EventInSFVec3f,&com);
		XnPoint3D pt;
		GetUserCom(uid,pt);
		com->setValue((float*)&(pt));
		com->Release();
	}
	bool b=IsTracking(uid);
	if(b!=lastTrackingStatus){
		EventInSFBool* trckWho;
		QuerySFNode(g_skltn,L"isTracking",IID_EventInSFBool,&trckWho);
		trckWho->setValue(b);
		trckWho->Release();
		lastTrackingStatus=b;
	}
	if(b){
		int len=(sizeof joint_names)/(sizeof XnSkeletonJoint);
		for(int i=0;i<len;i++){
			EventInSFVec3f* vec;
			hr=QuerySFNode(g_skltn,pos_field[i],IID_EventInSFVec3f,&vec);
			if (!vec)
			{
				continue;
			}
			vec->setValue((float*)&(GetSkltnJntPos(uid,joint_names[i]).position));
			vec->Release();
		}
		for(int i=0;i<len;i++){
			EventInSFMatrix* matrix;
			QuerySFNode(g_skltn,ori_field[i],IID_EventInSFMatrix,&matrix);
			if(!matrix){
				continue;
			}	
			float* ori_Matrix=GetSkltnJntOri(uid,joint_names[i]).orientation.elements;
			float save_ori[16]={ori_Matrix[0],-ori_Matrix[3],ori_Matrix[6],0.0, 
								-ori_Matrix[1],ori_Matrix[4],-ori_Matrix[7],0.0, 
								ori_Matrix[2],-ori_Matrix[5],ori_Matrix[8],0.0, 
								0.0,0.0,0.0,1.0};
			matrix->setValue(save_ori);
			matrix->Release();
		}
	}
}
VOID SetUserHandsData(){	
	SessionState s=GetSessionStatus();
	if(s==SessionState::IN_SESSION){
	EventInMFVec3f* vec,*vec1;
	EventInSFVec2f*vec2,*vec3;
	float* tmp;
	float pos[2];
	//"firstHandTrack"
	QuerySFNode(g_hnz,L"firstHandTrack",IID_EventInMFVec3f,&vec);
	GetHandTrackPoint(1,&tmp);
	vec->setValue(GetBufferSize()*3,tmp);
	QuerySFNode(g_hnz,L"position",IID_EventInSFVec2f,&vec2);
	pos[0]=(tmp[0]*2.0-pix_w)/pix_w;
	pos[1]=(pix_h-tmp[1]*2.0)/pix_h;
	vec2->setValue(pos);
	//"secondHandTrack"
	QuerySFNode(g_hnz,L"secondHandTrack",IID_EventInMFVec3f,&vec1);
	GetHandTrackPoint(2,&tmp);
	vec1->setValue(GetBufferSize()*3,tmp);
	QuerySFNode(g_hnz,L"secondHandposition",IID_EventInSFVec2f,&vec3);
	pos[0]=(tmp[0]-pix_w)/pix_w;
	pos[1]=(pix_h-tmp[1])/pix_h;
	vec3->setValue(pos);
	vec->Release();
	vec1->Release();
	vec2->Release();
	vec3->Release();
	}
}


VOID SetFloorData(){
	XnPlane3D plane;
	XnStatus rc=GetUserFloor(plane);
	if(rc!=XN_STATUS_OK){return;}
	if(plane.ptPoint.X!=lastFloorCtr[0]||plane.ptPoint.Y!=lastFloorCtr[1]||plane.ptPoint.Z!=lastFloorCtr[2]){
		EventInSFVec3f* pt;
		QuerySFNode(g_flr,L"point",IID_EventInSFVec3f,&pt);
		pt->setValue((float*)&(plane.ptPoint));
		pt->Release();
		lastFloorCtr[0]=plane.ptPoint.X;
		lastFloorCtr[1]=plane.ptPoint.Y;
		lastFloorCtr[2]=plane.ptPoint.Z;
	}
	if (plane.vNormal.X!=lastFloorNml[0]||plane.vNormal.Y!=lastFloorNml[1]||plane.vNormal.Z!=lastFloorNml[2])
	{
		EventInSFVec3f*nml;
		QuerySFNode(g_flr,L"normal",IID_EventInSFVec3f,&nml);
		nml->setValue((float*)&(plane.vNormal));
		nml->Release();
		lastFloorNml[0]=plane.vNormal.X;
		lastFloorNml[1]=plane.vNormal.Y;
		lastFloorNml[2]=plane.vNormal.Z;
	}
}
void updateKinect(bool enbld_skltn,bool enbld_hnzTrck){	
	g_context.WaitAndUpdateAll();
	//if (enbld_skltn){
	//	FindPlayer();
	//	SetUserSkeletonData(getPlayer());
	//}
	//if(enbld_hnzTrck){
	//	updateHands();
	//	SetUserHandsData();
	//}
	//SetFloorData();
}

//for callback in hand
void writeHandStatusField(int s){
	EventInSFString* str;
	QuerySFNode(g_hnz,L"status",IID_EventInSFString,&str);
	if(s==SessionState::IN_SESSION){
		str->setValue(L"IN_SESSION");
	}else if(s==SessionState::QUICK_REFOCUS){
		str->setValue(L"QUICK_REFOCUS");
	}else{
		str->setValue(L"NOT_IN_SESSION");
	}
	str->Release();
} 
//for callback in skltnFrKnick
//void writeIsTrackingField(XnUserID trckr){
//	EventInSFInt32* trckWho;
//	QuerySFNode(g_skltn,L"isTracking",IID_EventInSFInt32,&trckWho);
//	trckWho->setValue(trckr);
//	trckWho->Release();
//}
void writeIsCalibratingField(XnBool clbrt){
	EventInSFBool* isClbrt;
	QuerySFNode(g_skltn,L"isCalibrating",IID_EventInSFBool,&isClbrt);
	isClbrt->setValue(clbrt);
	isClbrt->Release();
}
void writeNeedPoseForCalibrationField(XnBool needPose){
	EventInSFBool* isNeedPose;
	QuerySFNode(g_skltn,L"needPoseForCalibration",IID_EventInSFBool,&isNeedPose);
	isNeedPose->setValue(needPose);
	isNeedPose->Release();
}

void Close_Kinect(){
	g_context.Shutdown();
}

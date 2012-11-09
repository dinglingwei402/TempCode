#pragma once
#include "blaxxunVRML.h"

class Vrml_PROTO_KinectDev{
public:
	Vrml_PROTO_KinectDev();
	~Vrml_PROTO_KinectDev();
	void setUseSingleDev(EventOutSFBool* b){this->useSingleDev=b;};
	void setIndxFaceSet(EventOutSFNode* faces){this->IndxFaceSet=faces;};
	void setChildren(EventOutMFNode* chr){
		this->children=chr;
	};
	void setKey(EventOutSFInt32* keyIn){
		this->key=keyIn;
	}
	EventOutSFBool* getUseSingleDev()const{
		return this->useSingleDev;
	};
	EventOutMFNode* getChildren()const{
		return this->children;
	};
	EventOutSFNode* getIndxFaceSet()const{
		return this->IndxFaceSet;
	};
	EventOutSFInt32* getKey()const{
		return this->key;
	};
private:
	EventOutSFBool* useSingleDev;
	EventOutMFNode* children;
	EventOutSFNode* IndxFaceSet;
	EventOutSFInt32* key;

};


class Vrml_PROTO_KinectData
{
public:
	Vrml_PROTO_KinectData(void);
	~Vrml_PROTO_KinectData(void);
//	void setDevId(EventInSFString* id){this->devId=id;};
//	void setHandsId(EventInMFInt32* ids){this->handsId=ids;};
//	void setUsersId(EventInMFInt32* ids){this->usersId=ids;};
//	void setCoord(EventInMFVec3f* crd){this->coord=crd;};
//	void setColor(EventInMFColor* clr){this->color=clr;};
////#### #### #### #### #### #### #### ####
//	void setFloor(EventOutSFNode* flr){this->floor=flr;};
//	void setUser(EventOutMFNode* user){this->users=user;};
//	void setHands(EventOutMFNode* hand){this->hands=hand;};
//	void setImgBuf(EventOutSFNode* tex)
//	{
//		Node* add;
//		this->imgBuf->getValue(&add);
//		this->imgBuf=tex;
//	};
//	void setDptBuf(EventOutSFNode* tex)
//	{
//		Node* add;
//		this->dptBuf->getValue(&add);
//		this->dptBuf=tex;
//	};
//private:
	EventInSFString* devId;
	EventInMFInt32* handsId;
	EventInMFInt32* usersId;
	EventInMFVec3f* coord;
	EventInMFColor* color;
//#### #### #### #### #### #### #### ####
	EventOutSFNode*	imgBuf;
	EventOutSFNode*	dptBuf;
	EventOutSFNode*	floor;
	EventOutMFNode*	users;
	EventOutMFNode*	hands;
	EventOutSFNode* snapMesh;
};



class Vrml_PROTO_OpenNIUser{
public:
		Vrml_PROTO_OpenNIUser();
		~Vrml_PROTO_OpenNIUser();
		EventInSFBool*	enabled;
		EventInSFInt32* id;
		EventInSFBool* isTracking;
		EventInSFBool* isCalibrating;
		EventInSFBool* needPoseForCalibration;
		EventInSFBool* isExit;
		EventInSFVec3f* userCoM;
		EventInSFVec3f* XN_SKEL_POS_HEAD; 
		EventInSFVec3f* XN_SKEL_POS_NECK;  
		EventInSFVec3f* XN_SKEL_POS_TORSO;  
		EventInSFVec3f* XN_SKEL_POS_WAIST;  
		EventInSFVec3f* XN_SKEL_POS_LEFT_COLLAR;  
		EventInSFVec3f* XN_SKEL_POS_LEFT_SHOULDER;  
		EventInSFVec3f* XN_SKEL_POS_LEFT_ELBOW;  
		EventInSFVec3f* XN_SKEL_POS_LEFT_WRIST;  
		EventInSFVec3f* XN_SKEL_POS_LEFT_HAND;  
		EventInSFVec3f* XN_SKEL_POS_LEFT_FINGERTIP;  
		EventInSFVec3f* XN_SKEL_POS_RIGHT_COLLAR;  
		EventInSFVec3f* XN_SKEL_POS_RIGHT_SHOULDER;  
		EventInSFVec3f* XN_SKEL_POS_RIGHT_ELBOW;  
		EventInSFVec3f* XN_SKEL_POS_RIGHT_WRIST;  
		EventInSFVec3f* XN_SKEL_POS_RIGHT_HAND;  
		EventInSFVec3f* XN_SKEL_POS_RIGHT_FINGERTIP;  
		EventInSFVec3f* XN_SKEL_POS_LEFT_HIP;  
		EventInSFVec3f* XN_SKEL_POS_LEFT_KNEE;  
		EventInSFVec3f* XN_SKEL_POS_LEFT_ANKLE;  
		EventInSFVec3f* XN_SKEL_POS_LEFT_FOOT;  
		EventInSFVec3f* XN_SKEL_POS_RIGHT_HIP;  
		EventInSFVec3f* XN_SKEL_POS_RIGHT_KNEE;  
		EventInSFVec3f* XN_SKEL_POS_RIGHT_ANKLE;  
		EventInSFVec3f* XN_SKEL_POS_RIGHT_FOOT; 
		EventInSFMatrix* XN_SKEL_ORI_HEAD;
		EventInSFMatrix* XN_SKEL_ORI_NECK;
		EventInSFMatrix* XN_SKEL_ORI_TORSO;
		EventInSFMatrix* XN_SKEL_ORI_WAIST;
		EventInSFMatrix* XN_SKEL_ORI_LEFT_COLLAR;
		EventInSFMatrix* XN_SKEL_ORI_LEFT_SHOULDER;
		EventInSFMatrix* XN_SKEL_ORI_LEFT_ELBOW;
		EventInSFMatrix* XN_SKEL_ORI_LEFT_WRIST;
		EventInSFMatrix* XN_SKEL_ORI_LEFT_HAND;
		EventInSFMatrix* XN_SKEL_ORI_LEFT_FINGERTIP;
		EventInSFMatrix* XN_SKEL_ORI_RIGHT_COLLAR;
		EventInSFMatrix* XN_SKEL_ORI_RIGHT_SHOULDER;
		EventInSFMatrix* XN_SKEL_ORI_RIGHT_ELBOW;
		EventInSFMatrix* XN_SKEL_ORI_RIGHT_WRIST;
		EventInSFMatrix* XN_SKEL_ORI_RIGHT_HAND;
		EventInSFMatrix* XN_SKEL_ORI_RIGHT_FINGERTIP;
		EventInSFMatrix* XN_SKEL_ORI_LEFT_HIP;
		EventInSFMatrix* XN_SKEL_ORI_LEFT_KNEE;
		EventInSFMatrix* XN_SKEL_ORI_LEFT_ANKLE;
		EventInSFMatrix* XN_SKEL_ORI_LEFT_FOOT;
		EventInSFMatrix* XN_SKEL_ORI_RIGHT_HIP;
		EventInSFMatrix* XN_SKEL_ORI_RIGHT_KNEE;
		EventInSFMatrix* XN_SKEL_ORI_RIGHT_ANKLE;
		EventInSFMatrix* XN_SKEL_ORI_RIGHT_FOOT;
		EventInSFNode* BodyMesh;

		EventInSFMatrix* getXN_SKEL_ORI_RIGHT_FOOT() const { return XN_SKEL_ORI_RIGHT_FOOT; }
		void setXN_SKEL_ORI_RIGHT_FOOT(EventInSFMatrix* val) { XN_SKEL_ORI_RIGHT_FOOT = val; }
		EventInSFNode* getBodyMesh() const { return BodyMesh; }
		void setBodyMesh(EventInSFNode* val) { BodyMesh = val; }
		
};
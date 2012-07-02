#pragma once
#include "blaxxunVRML.h"

class Vrml_PROTO_KinectDev{
	Vrml_PROTO_KinectDev();
	~Vrml_PROTO_KinectDev();
	void setUseSingleDev(EventOutSFBool* b){this->useSingleDev=b;};
	void setIndxFaceSet(EventOutSFNode* faces){this->IndxFaceSet=faces;};
	void setChildren(EventOutMFNode* chr){
		this->children=chr;
	};
	EventOutSFBool* getUseSingleDev(){
		return this->useSingleDev;
	};
	EventOutMFNode* getChildren(){
		return this->children;
	};
	EventOutSFNode* getIndxFaceSet(){
		return this->IndxFaceSet;
	};
private:
	EventOutSFBool* useSingleDev;
	EventOutMFNode* children;
	EventOutSFNode* IndxFaceSet;
};


class Vrml_PROTO_KinectData
{
public:
	Vrml_PROTO_KinectData(void);
	~Vrml_PROTO_KinectData(void);
	void setDevId(EventInSFString* id){this->devId=id;};
	void setHandsId(EventInMFInt32* ids){this->handsId=ids;};
	void setUsersId(EventInMFInt32* ids){this->usersId=ids;};
	void setCoord(EventInMFVec3f* crd){this->coord=crd;};
	void setColor(EventInMFColor* clr){this->color=clr;};
//#### #### #### #### #### #### #### ####
	void setFloor(EventOutSFNode* flr){this->floor=flr;};
	void setUser(EventOutMFNode* user){this->users=user;};
	void setHands(EventOutMFNode* hand){this->hands=hand;};
	void setImgBuf(EventOutSFNode* tex)
	{
		Node* add;
		this->imgBuf->getValue(&add);
		this->imgBuf=tex;
	};
	void setDptBuf(EventOutSFNode* tex)
	{
		Node* add;
		this->dptBuf->getValue(&add);
		this->dptBuf=tex;
	};
private:
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
};

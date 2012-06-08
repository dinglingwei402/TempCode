#pragma once
#include "blaxxunVRML.h"

class VrmlData
{
public:
	VrmlData(void);
	~VrmlData(void);
	void setUseSigleDev(EventOutSFBool* b);
	void setFloor(EventOutSFNode* node);
	void setUser(EventOutMFNode* user);
	void setHands(EventOutMFNode* hand);
	void setTexture1(EventOutSFNode* tex1);
	void setTexture2(EventOutSFNode* tex2);
	void setTexture3(EventOutSFNode* tex3);
	void setCoord1(EventOutSFNode* coord1);
	void setCoord2(EventOutSFNode* coord2);
	void setCoord3(EventOutSFNode* coord3);
private:
	EventOutSFBool*  useSingleDev;
	EventOutSFNode*  floor;
	EventOutMFNode*	users;
	EventOutMFNode*	hands;
	EventOutMFInt32*	handsId;
	EventOutMFInt32*	usersId;
	EventOutSFNode*  colorTexture_dev1;
	EventOutSFNode*  colorTexture_dev2;
	EventOutSFNode*  colorTexture_dev3;
	EventOutSFNode*  coord_dev1;
	EventOutSFNode*  coord_dev2;
	EventOutSFNode*  coord_dev3;
	EventOutSFNode*  IndxFaceSet;
	EventOutSFNode*	extra;

};

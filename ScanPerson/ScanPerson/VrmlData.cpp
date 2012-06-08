#include "StdAfx.h"
#include "VrmlData.h"

VrmlData::VrmlData(void)
{

}

VrmlData::~VrmlData(void)
{

}

void VrmlData::setUseSigleDev(EventOutSFBool* b){this->useSingleDev=b;}
void VrmlData::setFloor(EventOutSFNode* node){this->floor=node;}
void VrmlData::setUser(EventOutMFNode* user){this->users=user;}
void VrmlData::setHands(EventOutMFNode* hand){this->hands=hand;}
void VrmlData::setTexture1(EventOutSFNode* tex1){this->colorTexture_dev1=tex1;}
void VrmlData::setTexture2(EventOutSFNode* tex2){this->colorTexture_dev2=tex2;}
void VrmlData::setTexture3(EventOutSFNode* tex3){this->colorTexture_dev3=tex3;}
void VrmlData::setCoord1(EventOutSFNode* coord1){this->coord_dev1=coord1;}
void VrmlData::setCoord2(EventOutSFNode* coord2){this->coord_dev2=coord2;}
void VrmlData::setCoord3(EventOutSFNode* coord3){this->coord_dev3=coord3;}


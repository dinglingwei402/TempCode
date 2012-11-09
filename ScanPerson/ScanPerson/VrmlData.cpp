#include "StdAfx.h"
#include "VrmlData.h"


Vrml_PROTO_KinectDev::Vrml_PROTO_KinectDev():useSingleDev(NULL),children(NULL),IndxFaceSet(NULL){}
Vrml_PROTO_KinectDev::~Vrml_PROTO_KinectDev(){}
//#### #### #### #### #### #### #### ####
Vrml_PROTO_KinectData::Vrml_PROTO_KinectData(void):floor(NULL),users(NULL),hands(NULL),imgBuf(NULL),snapMesh(NULL){}
Vrml_PROTO_KinectData::~Vrml_PROTO_KinectData(void){}

Vrml_PROTO_OpenNIUser::Vrml_PROTO_OpenNIUser(void){}
Vrml_PROTO_OpenNIUser::~Vrml_PROTO_OpenNIUser(void){}

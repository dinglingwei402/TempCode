#pragma once
#include "StdAfx.h"
#include "KinectControler.h"
using namespace xn;

KinectControler::KinectControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step):_vrmlData(v_data),_devData(k_data),_xStep(x_step),_yStep(y_step),ini_stus(fail){}

KinectControler::~KinectControler(){}

initStatus KinectControler::init()
{
	this->ini_stus=success;
	return ini_stus;
}

int KinectControler::update()
{
	return 0;
}

const KinectData& KinectControler::getDevData()const
{
	return this->_devData;
}

const Vrml_PROTO_KinectDev& KinectControler::getVrmlData()const
{
	return this->_vrmlData;
}

XnUInt32 KinectControler::getXStep()const
{
	return this->_xStep;
}

XnUInt32 KinectControler::getYStep()const
{
	return this->_yStep;
}

void KinectControler::start(){}
void KinectControler::close(){}


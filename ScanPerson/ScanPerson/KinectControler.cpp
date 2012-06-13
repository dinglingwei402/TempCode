#pragma once
#include "StdAfx.h"
#include "KinectControler.h"
using namespace xn;

KinectControler::KinectControler():_xStep(1),_yStep(1),blockSize(0){

}
KinectControler::KinectControler(int x_step,int y_step):_xStep(x_step),_yStep(y_step),blockSize(0){
	if(!_xStep){
		_xStep=1;
	}
	if (_yStep)
	{
		_yStep=1;
	}
}



KinectControler::~KinectControler(){

}

int KinectControler::update(){return 0;}

void KinectControler::setDevData(const KinectData& data)const
{
	this->_devData=&data;
}

void KinectControler::setVrmlData(const VrmlData& data)const
{
	this->_vrmlData=&data;
}
XnUInt32 KinectControler::getXStep()const
{
	return this->_xStep;
}
XnUInt32 KinectControler::getYStep()const
{
	return this->_yStep;
}


#pragma once
#include "kinectcontroler.h"

class SingleControler:public KinectControler{
public:
	SingleControler();
	~SingleControler(void);
	SingleControler(int x,int y);
	XnStatus init();
	int update();
};

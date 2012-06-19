#pragma once
#include "kinectcontroler.h"

class SingleControler:public KinectControler{
public:
	SingleControler(const VrmlData& v_data,const KinectData& k_data,int x_step=1,int y_step=1);
	~SingleControler(void);
	void start();
	int update();
	void close();
private:
	int sub_x;
	int sub_y;
	int blockSize;
	XnDepthPixel* depthPts;
	XnUInt8* clorPts;
	const XnDepthPixel* depPix;
	const XnUInt8* imgPix;	
	initStatus init();
};

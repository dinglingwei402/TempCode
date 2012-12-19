#pragma once
#include "kinectcontroler.h"
class MultiControler :
	public KinectControler
{
public:
	MultiControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step,int valid_dev_num);
	~MultiControler();
	void start();
	void update();
	void close();
	void trigger();
	void trigger1();
	void drawPointSet(XnPoint3D* crdPts,XnPoint3D* clrPts);
	void createMesh(int dev_no);
	int validDevNum;
private:
	int sub_x;
	int sub_y;
	int blockSize;
	Vrml_PROTO_KinectData* vrmlData;
	initStatus init();
};

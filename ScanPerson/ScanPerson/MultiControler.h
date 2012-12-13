#pragma once
#include "kinectcontroler.h"
#include <vector>
class MultiControler :
	public KinectControler
{
public:
	MultiControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step);
	~MultiControler();
	void start();
	void update();
	void close();
	void drawPointSet(XnPoint3D* crdPts,XnPoint3D* clrPts);
	void createMesh();
private:
	int validDevNum;
	int sub_x;
	int sub_y;
	int blockSize;
	Vrml_PROTO_KinectData* vrmlData;
	initStatus init();
};

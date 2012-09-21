#pragma once
#include "kinectcontroler.h"
#include <vector>
class SingleControler:public KinectControler{
public:
	SingleControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step=1,int y_step=1);
	~SingleControler(void);
	void start();
	void update();
	void close();
	void drawPointSet(XnPoint3D* crdPts,XnPoint3D* clrPts);
	void getNonZeroPt(std::vector<XnPoint3D>& vec_crd,std::vector<XnPoint3D>& vec_clr);
	void getNonZeroPt( std::vector<XnPoint3D>& vec_crd);
	void createMesh();
private:
	int sub_x;
	int sub_y;
	int blockSize;
	Vrml_PROTO_KinectData* data1;
	const XnDepthPixel* depPix;
	const XnUInt8* imgPix;
	XnPoint3D* lp_clr;
	XnPoint3D* lp_crd;
private:
	initStatus init();
};

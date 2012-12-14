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
	void trigger();
	void drawPointSet(XnPoint3D* crdPts,XnPoint3D* clrPts);
	void createMesh();
	void PclMesh2VrlMesh(size_t ptsCnt,XnPoint3D* pts,size_t idxCnt,IdxSeq* idx);
	void saveImage();
private:
	int sub_x;
	int sub_y;
	int blockSize;
	Vrml_PROTO_KinectData* vrmlData;
	//const XnDepthPixel* depPix;
	//const XnUInt8* imgPix;
private:
	initStatus init();
};

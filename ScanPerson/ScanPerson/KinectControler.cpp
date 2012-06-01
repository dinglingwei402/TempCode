#include "StdAfx.h"
#include "KinectControler.h"

KinectData::KinectData():devNum(0){
}

KinectData::~KinectData(){

}
void KinectData::checkDev(){
	XnStatus rc;
	rc=g_Context.EnumerateProductionTrees(XN_NODE_TYPE_DEVICE,NULL,devicesList);
	int i=0;
	NodeInfoList::Iterator it=devicesList.Begin();
	for(it;it!=devicesList.End();it++,i++){}
	devNum=i;
	sensors=new GenGrp[0];
	int cnt=0;
}
XnStatus KinectData::checkSensors()
{
	XnStatus rc;
	NodeInfoList::Iterator it=devicesList.Begin();
	const XnChar* statusStr;
	for(;i<devNum;it++,i++){
		NodeInfo devInf=*it;
		rc=g_Context.CreateProductionTree(devInf);
		CHECK_RC(rc,"Create Device");
		const XnChar * devName=devInf.GetInstanceName();
		XnInt32 len =xnOSStrLen(devName); 
		Query query;
		query.AddNeededNode(devName);
		xnOSMemCopy(sensors[i].name,devName,len);
		rc=g_Context.CreateAnyProductionTree(XN_NODE_TYPE_DEPTH,&query,sensors[i].depGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateDepGen");
		bool b=sensors[i].depGen.GetMirrorCap().IsMirrored();
		if(!b)sensors[i].depGen.GetMirrorCap().SetMirror(true);
		rc=g_Context.CreateAnyProductionTree(XN_NODE_TYPE_IMAGE,&query,sensors[i].imgGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateImgGen");
		b=sensors[i].imgGen.GetMirrorCap().IsMirrored();
		if(!b)sensors[i].imgGen.GetMirrorCap().SetMirror(true);
		rc=sensors[i].depGen.GetAlternativeViewPointCap().SetViewPoint(sensors[i].imgGen);
		statusStr=xnGetStatusString(rc);
		DepthMetaData depMD;
		ImageMetaData imgMD;
		sensors[i].depGen.GetMetaData(depMD);
		sensors[i].imgGen.GetMetaData(imgMD);
		XnPixelFormat format=sensors[i].imgGen.GetPixelFormat();
		int byteNum=sensors[i].imgGen.GetBytesPerPixel();
		sensors[i].xres=depMD.XRes();
		sensors[i].yres=depMD.YRes();
		sensors[i].pDepthData=depMD.Data();
		sensors[i].pImageData=imgMD.Data();
		sensors[i].imgGen.StartGenerating();
	}
	//	g_Context.StartGeneratingAll();
	return rc;
}
void KinectData::KinectInit( Node* img1,Node* img2,Node* img3,Node* coord1,Node* coord2, Node* coord3,Node* face,Node* extra,EventOutSFInt32* key)
{
	rc=checkSensors();
	xres=sensors[0].xres;
	yres=sensors[0].yres;
	pixSize = 1;
}



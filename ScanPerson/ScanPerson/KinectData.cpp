#include "StdAfx.h"
#include "KinectData.h"
using namespace xn;
#define CHECK_RC(rc, what)  \
	if (rc != XN_STATUS_OK)	    \
{					        \
	printf("%s failed: %s\n", what, xnGetStatusString(rc));	\
	return rc;					\
}

KinectData::KinectData():_data(NULL){
	XnStatus rc;
	rc=_context.Init();
	_devicesList=new NodeInfoList();
	rc=_context.EnumerateProductionTrees(XN_NODE_TYPE_DEVICE,NULL,(*_devicesList));
	rc=checkDev();
	
}

KinectData::~KinectData(){
	delete _devicesList;
}

XnStatus KinectData::checkDev(){
	XnStatus rc;
	rc=_context.EnumerateProductionTrees(XN_NODE_TYPE_DEVICE,NULL,(*_devicesList));
	int i=0;
	NodeInfoList::Iterator it=(*_devicesList).Begin();
	for(;it!=(*_devicesList).End();it++,i++){}
	_devNum=i;
	return rc;
}
XnStatus KinectData::initData(int takeDevNum){
	XnStatus rc=XN_STATUS_OK;
	const XnChar* statusStr;
	if(_devNum==0)return rc;
	if(!(_data==NULL)){
		delete[] _data;
		_data=NULL;
	}
	int num=0;
	num=takeDevNum<=_devNum?takeDevNum:_devNum;
	_data=new GenGrp[num];
	NodeInfoList::Iterator it=(*_devicesList).Begin();
	for (int i=0;i<num;it++,i++)
	{
		rc=_context.CreateProductionTree(*it);
		const XnChar * devName=(*it).GetInstanceName();
		XnInt32 len =xnOSStrLen(devName); 
		xnOSMemCopy(_data[i].name,devName,len);
		Query query;
		query.AddNeededNode(devName);
		rc=_context.CreateAnyProductionTree(XN_NODE_TYPE_DEPTH,&query,_data[i].depGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateDepGen");
		bool b=_data[i].depGen.GetMirrorCap().IsMirrored();
		if(!b)_data[i].depGen.GetMirrorCap().SetMirror(true);
		rc=_context.CreateAnyProductionTree(XN_NODE_TYPE_IMAGE,&query,_data[i].imgGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateImgGen");
		b=_data[i].imgGen.GetMirrorCap().IsMirrored();
		if(!b)_data[i].imgGen.GetMirrorCap().SetMirror(true);
		rc=_data[i].depGen.GetAlternativeViewPointCap().SetViewPoint(_data[i].imgGen);
		statusStr=xnGetStatusString(rc);
		DepthMetaData depMD;
		ImageMetaData imgMD;
		_data[i].depGen.GetMetaData(depMD);
		_data[i].imgGen.GetMetaData(imgMD);
		XnPixelFormat format=_data[i].imgGen.GetPixelFormat();
		int byteNum=_data[i].imgGen.GetBytesPerPixel();
		_data[i].xres=depMD.XRes();
		_data[i].yres=depMD.YRes();
		_data[i].pDepthData=depMD.Data();
		_data[i].pImageData=imgMD.Data();
//		rc=_data[i].imgGen.StartGenerating();
	}

	return rc;
}

GenGrp* KinectData::getData(){
	return _data;
}
int KinectData::getDevNum(){
	return _devNum;
}

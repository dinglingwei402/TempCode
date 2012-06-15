#include "StdAfx.h"
#include "KinectData.h"
using namespace xn;

#ifndef RC_INI_STATUS(rc)
#define  RC_INI_STATUS(rc) 	\
	if (rc != XN_STATUS_OK)	    \
{					        \
	this->ini_stus=initStatus::fail; \
	return initStatus::fail;\
}
#endif

KinectData::KinectData():_data(NULL),_devNum(0),ini_stus(initStatus::fail){
	XnStatus rc;
	rc=_context.Init();
	if(rc!=XN_STATUS_OK)this->ini_stus=initStatus::fail;
	_devicesList=new NodeInfoList();
	rc=_context.EnumerateProductionTrees(XN_NODE_TYPE_DEVICE,NULL,(*_devicesList));
	if(rc!=XN_STATUS_OK)this->ini_stus=initStatus::fail;
	rc=checkDev();
	if(rc!=XN_STATUS_OK)this->ini_stus=initStatus::fail;
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

initStatus KinectData::initData(){
	XnStatus rc=XN_STATUS_OK;
	if(_devNum==0){
		this->ini_stus=fail;
		return ini_stus;
	}
	if(!(_data==NULL)){
		delete[] _data;
		_data=NULL;
	}
	_data=new GenGrp[_devNum];
	NodeInfoList::Iterator it=(*_devicesList).Begin();
	for (int i=0;i<_devNum;it++,i++)
	{
		rc=_context.CreateProductionTree(*it);
		RC_INI_STATUS(rc);
		const XnChar * devName=(*it).GetInstanceName();
		XnInt32 len =xnOSStrLen(devName); 
		xnOSMemCopy(_data[i].name,devName,len);
		Query query;
		query.AddNeededNode(devName);
		rc=_context.CreateAnyProductionTree(XN_NODE_TYPE_DEPTH,&query,_data[i].depGen);
		RC_INI_STATUS(rc);
		bool b=_data[i].depGen.GetMirrorCap().IsMirrored();
		if(!b)_data[i].depGen.GetMirrorCap().SetMirror(true);
		rc=_context.CreateAnyProductionTree(XN_NODE_TYPE_IMAGE,&query,_data[i].imgGen);
		RC_INI_STATUS(rc);
		b=_data[i].imgGen.GetMirrorCap().IsMirrored();
		if(!b)_data[i].imgGen.GetMirrorCap().SetMirror(true);
		rc=_data[i].depGen.GetAlternativeViewPointCap().SetViewPoint(_data[i].imgGen);
		RC_INI_STATUS(rc);
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
	}
	this->ini_stus=initStatus::success;
	return this->ini_stus;
}



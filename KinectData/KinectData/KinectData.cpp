// KinectData.cpp : 定义 DLL 应用程序的导出函数。
#include "stdafx.h"
#include "globalVar.h"
#define  xmlpath "c:\\SamplesConfig.xml"
#define  KDDLL_API _declspec(dllexport) 
#include "KinectData.h"
//#include "XnOSStrings.h"
//#include "XnOSMemory.h"

Context g_context;
GenGrp* sensors;
int sensor_count=0;
XnStatus checkSensors();
XnUInt32 xres;
XnUInt32 yrex;

void  init(){
	XnStatus rc=XN_STATUS_OK;
	ScriptNode scrptNode;
	EnumerationErrors errs;
//	rc=g_context.InitFromXmlFile(xmlpath,scrptNode,&errs);
	rc=g_context.Init();
	const XnChar* rslt;
	rslt=xnGetStatusString(rc);
	#ifdef   _DEBUG
	printf("size of dep %d",sizeof(DepthGenerator));
	printf("size of img %d",sizeof(ImageGenerator));
	printf("size of usr %d",sizeof(UserGenerator));
	printf("size of sce %d",sizeof(SceneAnalyzer));
	printf("size of name %d",sizeof(sensors[0].name));
	printf("size of size %d",sizeof(sensors[0].xres));
	#endif
	checkSensors();
}
GenGrp  getGrp(){
	GenGrp p;
	DepthGenerator dd=p.g_depGen;
	return p;
}

XnStatus checkSensors(){
	NodeInfoList devicesList;
	XnStatus rc;
	rc=g_context.EnumerateProductionTrees(XN_NODE_TYPE_DEVICE,NULL,devicesList);
	int i=0;
	NodeInfoList::Iterator it=devicesList.Begin();
	for(it;it!=devicesList.End();it++,i++){}
	sensor_count=i;
	sensors=new GenGrp[sensor_count];
	i=0;
	it=devicesList.Begin();
	const XnChar* statusStr;
	for(;it!=devicesList.End();it++,i++){
		NodeInfo devInf=*it;
		rc=g_context.CreateProductionTree(devInf);
		CHECK_RC(rc,"Create Device");
		const XnChar * devName=devInf.GetInstanceName();
		XnInt32 len =xnOSStrLen(devName); 
		Query query;
		query.AddNeededNode(devName);
		xnOSMemCopy(sensors[i].name,devName,len);
		rc=g_context.CreateAnyProductionTree(XN_NODE_TYPE_DEPTH,&query,sensors[i].g_depGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateDepGen");
		rc=g_context.CreateAnyProductionTree(XN_NODE_TYPE_IMAGE,&query,sensors[i].g_imgGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateImgGen");
		rc=g_context.CreateAnyProductionTree(XN_NODE_TYPE_USER,&query,sensors[i].g_user);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateUsrGen");
		rc=g_context.CreateAnyProductionTree(XN_NODE_TYPE_SCENE,&query,sensors[i].g_scen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateScenAnly");
	}
	DepthMetaData depMD;
	sensors[0].g_depGen.GetMetaData(depMD);
	sensors[0].xres=depMD.XRes();
	sensors[0].yres=depMD.YRes();
	sensors[1].xres=depMD.XRes();
	sensors[1].yres=depMD.YRes();
	return rc;
}

bool CheckUser(int devID,int UserID){
	if(devID==0) {return false;}
	else{
		int n=devID-1;
		SceneMetaData data;
		const XnLabel* pLable;
		if(sensors[n].g_user.GetUserPixels(UserID,data)==XN_STATUS_OK){
			pLable=data.Data();
		}
	}

}


void drawPoint(XnUInt32 devId,XnUserID nId){
	XnBool hasUsrPix=false;
	SceneMetaData usrPix;
	DepthMetaData depPix;
	XnStatus rc=XN_STATUS_OK;
	sensors[devId].g_scen.GetMetaData(usrPix);
	sensors[devId].g_depGen.GetMetaData(depPix);
	rc=sensors[devId].g_user.GetUserPixels(nId,usrPix);
	XnUInt32 xres=sensors[devId].xres;
	XnUInt32 yres=sensors[devId].yres;
	XnUInt32 ptSize=xres*yres;
	XnPoint3D* pts=new XnPoint3D[ptSize];
	XnUInt32 len=0;
	const XnLabel* pLab=usrPix.Data();
	if(rc==XN_STATUS_OK){
		hasUsrPix=TRUE;
		for(XnUInt32 i=0;i<yres;i++){
			for(XnUInt32 j=0;j<xres;j++){
				if(usrPix.Data()==0){
					continue;
				}
				len++;
				pts->X=j;
				pts->Y=i;
				pts->Z=depPix[j*i];
				pts++;				
			}
		}
	}
}
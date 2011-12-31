#include "stdafx.h"
#include "KinectControl.h"
#include "XnCppWrapper.h"
#include "D3D9TYPES.h"
#include "blaxxunVRML.h"
#include "D3D9TYPES.h"

using namespace xn;
int xres;
int yres;
const int sensor_count=1;
GenGrp* sensors;
CComQIPtr<IBufferTexture> g_bufTex;
Context g_Context;


void KinectInit(CComPtr<Node> node){
	XnStatus rc=XN_STATUS_OK;
	rc=g_Context.Init();
	rc=xnGetStatusString(rc);
	rc=checkSensors();
	xres=GenGrp[0].xres;
	yres=GenGrp[0].yres;
	const XnDepthPixel* pDepth=sensors[0].depGen.Data();
	g_bufTex->setTexture(0,2*xres*yres,(BYTE*)pDepth,xres*2);
}

void UpdateImage(){	
	g_Context.WaitAndUpdateAll();
	const XnDepthPixel* pDepth=sensors[0].depGen.Data();
	g_bufTex->setTexture(0,2*xres*yres,(BYTE*)pDepth,2*xres);
}
GenGrp  getGrp(){
	GenGrp p;
	DepthGenerator dd=p.depGen;
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
		rc=g_context.CreateAnyProductionTree(XN_NODE_TYPE_DEPTH,&query,sensors[i].depGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateDepGen");
		rc=g_context.CreateAnyProductionTree(XN_NODE_TYPE_IMAGE,&query,sensors[i].imgGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateImgGen");
		rc=g_context.CreateAnyProductionTree(XN_NODE_TYPE_USER,&query,sensors[i].userGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateUsrGen");
		rc=g_context.CreateAnyProductionTree(XN_NODE_TYPE_SCENE,&query,sensors[i].scenGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateScenAnly");
	}
	DepthMetaData depMD;
	sensors[0].depGen.GetMetaData(depMD);
	sensors[0].xres=depMD.XRes();
	sensors[0].yres=depMD.YRes();
	sensors[1].xres=depMD.XRes();
	sensors[1].yres=depMD.YRes();
	g_context.StartGeneratingAll();
	return rc;
}


void getValidUserNum(XnUInt32 devId,XnUserID aUsers[],XnUInt16 aUsersNum){
	sensors[devId].userGen.GetUsers(aUsers,aUsersNum);
}

void drawPoint(XnUInt32 devId,XnUserID nId){
	XnBool hasUsrPix=false;
	SceneMetaData usrPix;
	DepthMetaData depPix;
	XnStatus rc=XN_STATUS_OK;
	sensors[devId].scenGen.GetMetaData(usrPix);
	sensors[devId].depGen.GetMetaData(depPix);
	rc=sensors[devId].userGen.GetUserPixels(0,usrPix);
	const XnChar* rslt=xnGetStatusString(rc);
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
				const XnLabel* p=usrPix.Data();
				if(*p==0){
					continue;
				}
				len++;
				pts[len].X=j;
				pts[len].Y=i;
				pts[len].Z=depPix[j+i*xres];		
			}
		}
	}
	delete[] pts;
}
void KinectClose(){
	g_Context.Shutdown();
}
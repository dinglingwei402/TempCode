#include "stdafx.h"
#include "KinectControl.h"
#include "XnCppWrapper.h"
#include "D3D9TYPES.h"
#include "blaxxunVRML.h"
#include "D3D9TYPES.h"
#include "globalVar.h"
using namespace xn;
const int showStyle=1;
XnUInt32 pixSize;
int xres;
int yres;
int sensor_count;
GenGrp *sensors;
CComQIPtr<IBufferTexture> g_bufTex;

Context g_Context;
XnStatus  checkSensors();

void KinectInit(CComPtr<Node> vlu,CComPtr<Node> pts){
	g_bufTex=vlu;
	XnStatus rc=XN_STATUS_OK;
	rc=g_Context.Init();
	const XnChar* rslt=xnGetStatusString(rc);
	rc=checkSensors();
	xres=sensors[0].xres;
	yres=sensors[0].yres;
	g_bufTex->setFormat(xres,yres,0,D3DFMT_R8G8B8,0);
	pixSize = 3;//imgMD.BytesPerPixel();
	//g_bufTex->setTexture(0,2*xres*yres,(BYTE*)sensors[0].pDepthData,2*xres);
	g_bufTex->setTexture(0,xres*yres*pixSize,(BYTE*)sensors[0].pImageData,xres*pixSize);
}

void UpdateImage(){	
	g_Context.WaitAndUpdateAll();
//	g_bufTex->setTexture(0,2*xres*yres,(BYTE*)sensors[0].pDepthData,2*xres);
	g_bufTex->setTexture(0,xres*yres*pixSize,(BYTE*)sensors[0].pImageData,xres*pixSize);
}
GenGrp  getGrp(){
	GenGrp p;
	DepthGenerator dd=p.depGen;
	return p;
}
XnStatus checkSensors(){
	NodeInfoList devicesList;
	XnStatus rc;
	rc=g_Context.EnumerateProductionTrees(XN_NODE_TYPE_DEVICE,NULL,devicesList);
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
		rc=g_Context.CreateAnyProductionTree(XN_NODE_TYPE_IMAGE,&query,sensors[i].imgGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateImgGen");
		rc=g_Context.CreateAnyProductionTree(XN_NODE_TYPE_USER,&query,sensors[i].userGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateUsrGen");
		rc=g_Context.CreateAnyProductionTree(XN_NODE_TYPE_SCENE,&query,sensors[i].scenGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateScenAnly");
		DepthMetaData depMD;
		ImageMetaData imgMD;
		sensors[i].depGen.GetMetaData(depMD);
		sensors[i].imgGen.GetMetaData(imgMD);
		sensors[i].xres=depMD.XRes();
		sensors[i].yres=depMD.YRes();
		sensors[i].pDepthData=depMD.Data();
		sensors[i].pImageData=imgMD.Data();
	}
	g_Context.StartGeneratingAll();
	return rc;
}


void getValidUserNum(XnUInt32 devId,XnUserID aUsers[],XnUInt16 aUsersNum){
	sensors[devId].userGen.GetUsers(aUsers,aUsersNum);
}

void drawPoint(XnUInt32 devId,XnUserID nId){
	XnBool hasUsrPix=false;
	SceneMetaData usrPix;
	XnStatus rc=XN_STATUS_OK;
	sensors[devId].scenGen.GetMetaData(usrPix);
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
				pts[len].Z=sensors[devId].pDepthData[j+i*xres];		
			}
		}
	}
	delete[] pts;
}
void KinectClose(){
	g_Context.Shutdown();
}
#include "stdafx.h"
#include "KinectControl.h"
#include "XnCppWrapper.h"
#include "D3D9TYPES.h"
#include "blaxxunVRML.h"
#include "globalVar.h"
#include <vector>
using namespace xn;
#define  xmlpath "C:\\SamplesConfig.xml"

const int showStyle=1;
XnUInt16 runOnce=0;
XnUInt32 rows=0;
XnBool findValidCell=0;
XnUInt32 g_YStep=3;
XnUInt32 g_XStep=3;

XnUInt32 pixSize;
int xres;
int yres;
int sensor_count;
GenGrp *sensors;
CComQIPtr<IBufferTexture> g_bufTex;
Node* g_mesh;
EventInMFVec3f* g_point;
EventInMFInt32* g_coordIndx;
Context g_Context;
XnPoint3D* depthPts;

XnStatus  checkSensors();
void drawPoint(XnUInt32 devId,XnUserID nId);
void KinectInit(CComPtr<Node> img,CComPtr<Node> coord,CComPtr<Node> mesh){
	g_bufTex=img;
	g_mesh=mesh;
	g_mesh->getEventIn(_T("index"),(EventIn**)&g_coordIndx);
	coord->getEventIn(_T("point"),(EventIn**)&g_point);
	XnStatus rc=XN_STATUS_OK;
	ScriptNode scriptNode;
	EnumerationErrors errors;
	rc=g_Context.Init();
	rc=checkSensors();
	xres=sensors[0].xres;
	yres=sensors[0].yres;
	g_bufTex->setFormat(xres,yres,0,D3DFMT_R8G8B8,0);
	pixSize = 3;
	g_bufTex->setTexture(0,xres*yres*pixSize,(BYTE*)sensors[0].pImageData,xres*pixSize);
}

void UpdateImage(){	
	g_Context.WaitAndUpdateAll();
//	g_bufTex->setTexture(0,2*xres*yres,(BYTE*)sensors[0].pDepthData,2*xres);
	g_bufTex->setTexture(0,xres*yres*pixSize,(BYTE*)sensors[0].pImageData,xres*pixSize);
	drawPoint(0,1);

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
		SceneMetaData sceMD;
		sensors[i].depGen.GetMetaData(depMD);
		sensors[i].imgGen.GetMetaData(imgMD);
		sensors[i].scenGen.GetMetaData(sceMD);
		XnPixelFormat format=sensors[i].imgGen.GetPixelFormat();
		sensors[i].xres=depMD.XRes();
		sensors[i].yres=depMD.YRes();
		sensors[i].pDepthData=depMD.Data();
		sensors[i].pImageData=imgMD.RGB24Data();
	}
	g_Context.StartGeneratingAll();
	return rc;
}

void drawPoint(XnUInt32 devId,XnUserID nId){
	if(runOnce==0)
	{
		XnBool hasUsrPix=false;
		SceneMetaData usrPix;
		XnStatus rc=XN_STATUS_OK;
		sensors[devId].scenGen.GetMetaData(usrPix);
		rc=sensors[devId].userGen.GetUserPixels(0,usrPix);
		const XnChar* rslt=xnGetStatusString(rc);
		int small_x=(int)(xres/g_XStep);
		int small_y=(int)(yres/g_YStep);
		XnUInt32 ptSize=(small_x*small_y);
		bool flag=false;
		if(rc==XN_STATUS_OK){
			if(!depthPts){
				XnUInt32 curIdx=i*g_YStep*xres+j;
				XnInt32	 nextIdx=curIdx+g_XStep;
				XnInt32  undNextIdx=nextIdx+g_YStep*xres;
				XnUInt32 undCurIdx=curIdx+g_YStep*xres;
				XnUInt32 squence[4]={curIdx,nextIdx,undNextIdx,undCurIdx};
			}else{
				memset(depthPts,0,sizeof(XnPoint3D)*ptSize);
			}
			for(int i=0;i<small_y;i++){
				for(int j=0;j<small_x,j++){
					
					depthPts[i].X=i;



				}

			}
			for(int i=1;i<4;i++){
				if(isValidPt(squence[i],lab,depPix))
				{
					id[tri_num]=i;
					tri_num++;
				}
			}
			if(tri_num<3){
				printf("trinum is less then 3:it is %d",tri_num);
			}else if(tri_num==3){
				idxList.push_back(squence[id[0]]);
				idxList.push_back(squence[id[1]]);
				idxList.push_back(squence[id[2]]);
				printf("trinum == 3:it is %d",tri_num);
			}else{
				idxList.push_back(squence[id[0]]);
				idxList.push_back(squence[id[1]]);
				idxList.push_back(squence[id[2]]);
				idxList.push_back(squence[id[0]]);
				idxList.push_back(squence[id[2]]);
				idxList.push_back(squence[id[3]]);


		}
	}
}

void getValidUserNum(XnUInt32 devId,XnUserID aUsers[],XnUInt16 aUsersNum){
	sensors[devId].userGen.GetUsers(aUsers,aUsersNum);
}

void alertZero(XnPoint3D pt){
	if (pt.X==0&&pt.Y==0&&pt.Z==0)
	{
		MessageBox(NULL,_T("ZERO"),_T("ZERO"),NULL);
	}
}

bool isValidPt(int indx,const XnLabel* lab,const XnDepthPixel* dep){
	return ((lab[indx]>0)&&(dep[indx]!=0));
}




void ReadCell()
{
		
}
void ReadRow()
{

}

void ReadGrid()
{

}


void KinectClose(){
	g_Context.Shutdown();
}
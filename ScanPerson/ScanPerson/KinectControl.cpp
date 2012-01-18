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
XnLabel* labPts;

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

void getValidUserNum(XnUInt32 devId,XnUserID aUsers[],XnUInt16 aUsersNum){
	sensors[devId].userGen.GetUsers(aUsers,aUsersNum);
}
bool isValidPt(int indx,const XnLabel* lab,const XnPoint3D* dep,int i){
	int jj=i;
	return ((lab[indx]>0)&&(dep[indx].Z!=0));
}

void drawPoint(XnUInt32 devId,XnUserID nId){
	if(runOnce==0)
	{
		XnBool hasUsrPix=false;
		SceneMetaData usrPix;
		XnStatus rc=XN_STATUS_OK;
		sensors[devId].scenGen.GetMetaData(usrPix);
		rc=sensors[devId].userGen.GetUserPixels(0,usrPix);
		const XnLabel *lab=usrPix.Data(); 
		const XnDepthPixel* depPix=sensors[devId].pDepthData;
		const XnChar* rslt=xnGetStatusString(rc);
		int small_x=(int)(xres/g_XStep);
		int small_y=(int)(yres/g_YStep);
		XnUInt32 ptSize=(small_x*small_y);
		bool flag=false;
		std::vector<XnUInt32> idxList;
		if(rc==XN_STATUS_OK){
			if(!depthPts){
				depthPts=new XnPoint3D[ptSize];
			}else{
				memset(depthPts,0,sizeof(XnPoint3D)*ptSize);
			}
			if(!labPts){
				labPts=new XnLabel[ptSize];
			}else{
				memset(labPts,0,sizeof(XnLabel)*ptSize);
			}
			XnUInt32 squence[4];
			int len=0;
			//compress mesh grid
			for(int i=0;i<small_y;i++){
				for(int j=0;j<small_x;j++){
					int bigX=j*g_XStep;
					int bigY=i*g_YStep;
					depthPts[len].X=bigX;
					depthPts[len].Y=bigY;
					int idx=bigY*xres+bigX;
					depthPts[len].Z=depPix[idx];
					labPts[len]=lab[idx];
					len++;
				}
			}
			//find  valid pts then put their indices to the vector
			for(int i=0;i<small_y-1;i++){
				for(int j=0;j<small_x-1;j++){
					squence[0]=i*small_x+j;
					squence[1]=squence[0]+1;
					squence[2]=squence[1]+small_x;
					squence[3]=squence[0]+small_x;
					int id[4];
					int tri_num=0;
					for(int k=0;k<4;k++){
						if(squence[k]>34080){
							int sss=squence[k];
						}
						if(isValidPt(squence[k],labPts,depthPts,k))
						{
							id[tri_num]=k;
							tri_num++;
						}
					}
					if(tri_num<3){
						continue;
					}else if(tri_num==3){
						idxList.push_back(squence[id[0]]);
						idxList.push_back(squence[id[1]]);
						idxList.push_back(squence[id[2]]);
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
			//******
			if(len>0){
				//去得在子坐标系中的位置
				int idxListLen=idxList.size();
				int *idxArr=new int[idxListLen];
				for(int k=0;k<idxListLen;k++){
					idxArr[k]=idxList.at(k);
				}
				XnPoint3D* aRealWorld=new XnPoint3D[len];
				sensors[devId].depGen.ConvertProjectiveToRealWorld(len,depthPts,aRealWorld);
				for(int k=0;k<len;k++){
					aRealWorld[k].X*=-1;
					aRealWorld[k].Z*=-1;
				}
				g_point->setValue(1,NULL);
				g_point->setValue(len*3,(float*)aRealWorld);
				g_coordIndx->setValue(1,NULL);
				g_coordIndx->setValue(idxListLen,idxArr);
				delete[] aRealWorld;
				delete[] idxArr;
			}

		}
	
	}

}







void KinectClose(){
	g_Context.Shutdown();
}
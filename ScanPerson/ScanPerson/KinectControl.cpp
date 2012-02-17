#include "stdafx.h"
#include "KinectControl.h"
#include "XnCppWrapper.h"
#include "D3D9TYPES.h"
#include "blaxxunVRML.h"
#include "globalVar.h"
#include "QueryNode.h"
#include "pcl/io/pcd_io.h"
#include "pcl/point_types.h"


#include <vector>
using namespace xn;
#define  xmlpath "C:\\SamplesConfig.xml"

const int showStyle=1;
XnUInt16 runOnce[2]={0,0};
XnUInt32 rows=0;
XnBool findValidCell=0;
XnUInt32 g_YStep=1;
XnUInt32 g_XStep=1;

XnUInt32 pixSize;
int xres;
int yres;
int sensor_count;
GenGrp *sensors;
//////
CComQIPtr<IBufferTexture> g_bufTex_left;
CComQIPtr<IBufferTexture> g_bufTex_right;
Node* g_mesh;
Node* g_coord1;
Node* g_coord2;
EventInMFVec3f* g_point[2];
EventInMFInt32* g_coordIndx1;
EventInMFInt32* g_coordIndx2;
EventInMFColor* g_color[2];
//////
Context g_Context;
XnPoint3D* depthPts;
XnPoint3D* clorPts;
XnLabel* labPts;
XnBool chgVPt=false;
//***************************************



KinectDev::KinectDev(EventInSFNode* flr,EventInMFNode* usr,EventInMFNode* hnd,EventInMFInt32*	hId,EventInMFInt32* uId,EventInSFNode* clr1,EventInSFNode* clr2,EventInSFNode* crd1,EventInSFNode* crd2):floor(flr),users(usr),hands(hnd),handsId(hId),usersId(uId),colorTexture_dev1(clr1),colorTexture_dev2(clr2),coord_dev1(crd1),coord_dev2(crd2){}


XnStatus  checkSensors();
void drawMesh(XnUInt32 devId,XnUserID nId);
void drawPoint(XnUInt32 devId);
void testColor(){
	/*BYTE* tempBuffer = (BYTE*)malloc(xres*yres*pixSize);
	for(int i=0;i<xres*yres;i++){
		tempBuffer[i*pixSize]=200;
		tempBuffer[i*pixSize+1]=0;
		tempBuffer[i*pixSize+2]=55;
	}*/
//	g_bufTex_left->setTextureEx(xres,yres,0,20,xres*yres*pixSize,(BYTE*)sensors[0].pImageData,xres*pixSize);
	HRESULT hr;
	hr = g_bufTex_right->setTextureEx(xres,yres,0,D3DFMT_R8G8B8,xres*yres*pixSize,(BYTE*)sensors[1].pImageData,xres*pixSize);
	hr = g_bufTex_left->setTextureEx(xres,yres,0,D3DFMT_R8G8B8,xres*yres*pixSize,(BYTE*)sensors[0].pImageData,xres*pixSize);

//	g_bufTex_left->setTextureEx(xres,yres,0,20,xres*yres*pixSize,tempBuffer,xres*pixSize);
//	g_bufTex_left->setTexture(0,xres*yres*4,tempBuffer,xres*4);
	/*int w=0;
	int h=0;
	int lev=0;
	int fmt=0;
	g_bufTex_left->getFormat(&w,&h,&lev,&fmt);*/
}
//*************************************************

void KinectInit( Node* img1,Node* img2,Node* coord1,Node* coord2, Node* face,Node* extra )
{
	g_bufTex_left=img1;
	g_bufTex_right=img2;
	g_mesh=face;
	g_coord1=coord1;
	g_coord2=coord2;
	g_mesh->getEventIn(_T("set_index"),(EventIn**)&g_coordIndx1);
	
	Field* fld;
	g_coord1->getField(_T("point"),&fld);
	fld->QueryInterface(IID_EventInMFVec3f,(void**)&g_point[0]);
	g_coord2->getField(_T("point"),&fld);
	fld->QueryInterface(IID_EventInMFVec3f,(void**)&g_point[1]);
	fld->Release();

	EventOutSFNode* clr1,*clr2;
	QuerySFNode(extra,_T("pt_color1"),IID_EventOutSFNode,&clr1);
	QuerySFNode(extra,_T("pt_color2"),IID_EventOutSFNode,&clr2);
	QuerySFNode(clr1,_T("color"),IID_EventInMFColor,&g_color[0]);
	QuerySFNode(clr2,_T("color"),IID_EventInMFColor,&g_color[1]);

	clr1->Release();
	clr2->Release();

	XnStatus rc=XN_STATUS_OK;
	rc=g_Context.Init();
	rc=checkSensors();
	xres=sensors[0].xres;
	yres=sensors[0].yres;
	pixSize = 3;
}

void UpdateImage(){	
	XnStatus rc=g_Context.WaitNoneUpdateAll();
	if (rc!=0)
	{
		int iii=0;
		return;
	}
	testColor();
	drawPoint(0);
	drawPoint(1);
}
GenGrp  getGrp(){
	GenGrp p;
	DepthGenerator dd=p.depGen;
	return p;
}

void getValidUserNum(XnUInt32 devId,XnUserID aUsers[],XnUInt16 aUsersNum){
	sensors[devId].userGen.GetUsers(aUsers,aUsersNum);
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
		bool b=sensors[i].depGen.GetMirrorCap().IsMirrored();
		if(!b)sensors[i].depGen.GetMirrorCap().SetMirror(true);
		rc=g_Context.CreateAnyProductionTree(XN_NODE_TYPE_IMAGE,&query,sensors[i].imgGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateImgGen");
		b=sensors[i].imgGen.GetMirrorCap().IsMirrored();
		if(!b)sensors[i].imgGen.GetMirrorCap().SetMirror(true);

		rc=sensors[i].depGen.GetAlternativeViewPointCap().SetViewPoint(sensors[i].imgGen);
		statusStr=xnGetStatusString(rc);
		/*	rc=g_Context.CreateAnyProductionTree(XN_NODE_TYPE_USER,&query,sensors[i].userGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateUsrGen");
		rc=g_Context.CreateAnyProductionTree(XN_NODE_TYPE_SCENE,&query,sensors[i].scenGen);
		statusStr=xnGetStatusString(rc);
		CHECK_RC(rc,"CreateScenAnly");*/
		DepthMetaData depMD;
		ImageMetaData imgMD;
	//	SceneMetaData sceMD;
		sensors[i].depGen.GetMetaData(depMD);
		sensors[i].imgGen.GetMetaData(imgMD);
	//	sensors[i].scenGen.GetMetaData(sceMD);
		XnPixelFormat format=sensors[i].imgGen.GetPixelFormat();
		int byteNum=sensors[i].imgGen.GetBytesPerPixel();
		sensors[i].xres=depMD.XRes();
		sensors[i].yres=depMD.YRes();
		sensors[i].pDepthData=depMD.Data();
		sensors[i].pImageData=imgMD.Data();
	//	sensors[i].pImageData=imgMD.RGB24Data();
	//	NodeInfoList userList;
	////	g_Context.EnumerateProductionTrees(XN_NODE_TYPE_USER,&query,userList,NULL);
	//	g_Context.EnumerateExistingNodes(userList,XN_NODE_TYPE_USER);
	//	int j=0;
	//	NodeInfoList::Iterator it1=userList.Begin();
	//	while(it1!=userList.End()){
	//		NodeInfo imageInfo = *it1;
	//		//	bool kk=(imageInfo.GetDescription().Type == XN_NODE_TYPE_USER );
	//
	//		it1++;
	//		j++;
	//	}
	//	OutputDebugString(L"is \r\n");
	}
//	EnumerationErrors* pErrors;

	g_Context.StartGeneratingAll();
	return rc;
}
bool isValidPt(int indx,const XnLabel* lab,const XnPoint3D* dep,int i){
	int jj=i;
	return ((lab[indx]>0)&&(dep[indx].Z!=0));
}
void drawPoint(XnUInt32 devId){
	if(runOnce[devId]==0)
	{
		XnBool hasUsrPix=false;
		XnStatus rc=XN_STATUS_OK;
		const XnDepthPixel* depPix=sensors[devId].pDepthData;
		const XnUInt8* imgPix=sensors[devId].pImageData;
		const XnChar* rslt=xnGetStatusString(rc);
		int small_x=(int)(xres/g_XStep);
		int small_y=(int)(yres/g_YStep);
		XnUInt32 ptSize=(small_x*small_y);
		bool flag=false;
		std::vector<XnUInt32> idxList;
		pcl::PointCloud<pcl::PointXYZ> cloud;

		if(rc==XN_STATUS_OK){
			if(!depthPts){
				depthPts=new XnPoint3D[ptSize];
				clorPts=new XnPoint3D[ptSize];
			}else{
				memset(depthPts,0,sizeof(XnPoint3D)*ptSize);
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
					clorPts[len].X=imgPix[idx*3]/255.0;
					clorPts[len].Y=imgPix[idx*3+1]/255.0;
					clorPts[len].Z=imgPix[idx*3+2]/255.0;
					len++;
				}
			}

			//find  valid pts then put their indices to the vector
			//******
			if(len>0){
				cloud.width=small_x;
				cloud.height=small_y;
				cloud.points.resize (cloud.width * cloud.height);
				XnPoint3D* aRealWorld=new XnPoint3D[len];
				sensors[devId].depGen.ConvertProjectiveToRealWorld(len,depthPts,aRealWorld);
				g_point[devId]->setValue(len*3,(float*)aRealWorld);
				g_color[devId]->setValue(len*3,(float*)clorPts);
				for(int i=0;i<len;i++){
					cloud.points[i].x=aRealWorld[i].X;
					cloud.points[i].y=aRealWorld[i].Y;
					cloud.points[i].z=aRealWorld[i].Z;
				}
				pcl::io::savePCDFile ("c:\\test_pcd.pcd", cloud);
				delete[] aRealWorld;
				runOnce[devId]=1;
			}
		}	
	}
}


void KinectClose(){
	g_Context.Shutdown();
}
/*
void drawMesh(XnUInt32 devId,XnUserID nId){
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
			int valPt_len=0;
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
					valPt_len++;
				}
			}
			//******
			if(valPt_len>0){
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
		//		g_point->setValue(1,NULL);
				g_point[0]->setValue(len*3,(float*)aRealWorld);
		//		g_coordIndx->setValue(1,NULL);
				g_coordIndx1->setValue(idxListLen,idxArr);
				delete[] aRealWorld;
				delete[] idxArr;
				runOnce[devId]=1;
			}
		}	                                                                                                     
	}
}*/
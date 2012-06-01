#include "stdafx.h"
#include "KinectControl.h"
#include "XnCppWrapper.h"
#include "D3D9TYPES.h"
#include "blaxxunVRML.h"
#include "globalVar.h"
#include "QueryNode.h"
#include "pcl/io/pcd_io.h"
#include "pcl/point_types.h"
#include <pcl/features/normal_3d.h>
#include <vector>
#include "keyObserver.h"
#include <Windows.h>
using namespace xn;

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
CComQIPtr<IBufferTexture> g_bufTex_middle;

Node* g_mesh;
Node* g_coord1;
Node* g_coord2;
Node* g_coord3;
EventInMFInt32* g_coordIndx1;
EventInMFInt32* g_coordIndx2;
EventInMFInt32* g_coordIndx3;
EventInMFVec3f* g_point[3];
EventInMFColor* g_color[3];

//////

Context g_Context;
XnPoint3D* depthPts;
XnPoint3D* clorPts;
XnLabel* labPts;
XnPoint3D* pointCache[3];
XnPoint3D* colorCache[3];

XnBool chgVPt=false;
int UseDoubleCam=1;
int KeyMode=0;

KeyObserver* obv;

//***************************************



KinectDev::KinectDev(EventInSFNode* flr,EventInMFNode* usr,EventInMFNode* hnd,EventInMFInt32*	hId,EventInMFInt32* uId,EventInSFNode* clr1,EventInSFNode* clr2,EventInSFNode* crd1,EventInSFNode* crd2):floor(flr),users(usr),hands(hnd),handsId(hId),usersId(uId),colorTexture_dev1(clr1),colorTexture_dev2(clr2),coord_dev1(crd1),coord_dev2(crd2){}


XnStatus checkSensors();
void drawMesh(XnUInt32 devId,XnUserID nId);
void drawPoint(XnUInt32 devId);
void drawAll();
void startDepGen(XnUInt32 devId);
void closeDepGen(XnUInt32 devId);

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
	hr = g_bufTex_middle->setTextureEx(xres,yres,0,D3DFMT_R8G8B8,xres*yres*pixSize,(BYTE*)sensors[2].pImageData,xres*pixSize);
//	g_bufTex_left->setTextureEx(xres,yres,0,20,xres*yres*pixSize,tempBuffer,xres*pixSize);
//	g_bufTex_left->setTexture(0,xres*yres*4,tempBuffer,xres*4);
	/*int w=0;
	int h=0;
	int lev=0;
	int fmt=0;
	g_bufTex_left->getFormat(&w,&h,&lev,&fmt);*/
}
//*************************************************

void KinectInit( Node* img1,Node* img2,Node* img3,Node* coord1,Node* coord2, Node* coord3,Node* face,Node* extra,EventOutSFInt32* key)
{
	g_bufTex_left=img1;
	g_bufTex_right=img2;
	g_bufTex_middle=img3;
	g_mesh=face;
	g_coord1=coord1;
	g_coord2=coord2;
	g_coord3=coord3;
	obv=new KeyObserver();
	obv->setMFunc(drawAll);
//	obv->setMFunc1(startDepGen);
//	obv->setMFunc2(closeDepGen);

	key->advise(obv,NULL);
	g_mesh->getEventIn(_T("set_index"),(EventIn**)&g_coordIndx1);	
	Field* fld;
	g_coord1->getField(_T("point"),&fld);
	fld->QueryInterface(IID_EventInMFVec3f,(void**)&g_point[0]);
	g_coord2->getField(_T("point"),&fld);
	fld->QueryInterface(IID_EventInMFVec3f,(void**)&g_point[1]);
	g_coord3->getField(_T("point"),&fld);
	fld->QueryInterface(IID_EventInMFVec3f,(void**)&g_point[2]);
	fld->Release();

	EventOutSFNode* clr1,*clr2,*clr3;
	QuerySFNode(extra,_T("pt_color1"),IID_EventOutSFNode,&clr1);
	QuerySFNode(extra,_T("pt_color2"),IID_EventOutSFNode,&clr2);
	QuerySFNode(extra,_T("pt_color3"),IID_EventOutSFNode,&clr3);
	QuerySFNode(clr1,_T("color"),IID_EventInMFColor,&g_color[0]);
	QuerySFNode(clr2,_T("color"),IID_EventInMFColor,&g_color[1]);
	QuerySFNode(clr3,_T("color"),IID_EventInMFColor,&g_color[2]);
	clr1->Release();
	clr2->Release();
	clr3->Release();
	XnStatus rc=XN_STATUS_OK;
	rc=g_Context.Init();
	rc=checkSensors();
	xres=sensors[0].xres;
	yres=sensors[0].yres;
	pixSize = 1;
}

void UpdateImage(){	
//	XnStatus rc=g_Context.WaitNoneUpdateAll();
	/*if (!rc)
	{
		return;
	}*/
//	testColor();

}

void drawAll(){
//	g_Context.WaitNoneUpdateAll();
	for(int i=0;i<sensor_count;i++){
		startDepGen(i);
		drawPoint(i);
		Beep(50*(i+5),100);
		closeDepGen(i);
	}
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
	if(sensor_count<=1)UseDoubleCam=0;
	if(UseDoubleCam==0)sensor_count=1;
	sensors=new GenGrp[sensor_count];
	i=0;
	it=devicesList.Begin();
	const XnChar* statusStr;
	for(;i<sensor_count;it++,i++){
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
bool isValidPt(int indx,const XnLabel* lab,const XnPoint3D* dep,int i)
{
	return ((lab[indx]>0)&&(dep[indx].Z!=0));
}

void savePoint(XnUInt32 devId){
	/*XnStatus rc=XN_STATUS_OK;
	if (!pointCache[devId])
	{
		pointCache[devId]=new XnPoint3D[]£»
	}
	const XnDepthPixel* depPix=sensors[devId].pDepthData;
	const XnUInt8* imgPix=sensors[devId].pImageData;*/
}
void drawPoint(XnUInt32 devId){
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
//		pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
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
				pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
				cloud->width=small_x;
				cloud->height=small_y;
				cloud->points.resize (cloud->width * cloud->height);
				XnPoint3D* aRealWorld=new XnPoint3D[len];
				sensors[devId].depGen.ConvertProjectiveToRealWorld(len,depthPts,aRealWorld);
				g_point[devId]->setValue(len*3,(float*)aRealWorld);
				g_color[devId]->setValue(len*3,(float*)clorPts);
				int i_tmp=0;
				int* ids=new int[len];
				for(int i=0;i<len;i++){
					if(aRealWorld[i].X==0&&aRealWorld[i].Y==0&&aRealWorld[i].Z==0){
						continue;
					}
					ids[i_tmp]=i;
					++i_tmp;	
				}
				cloud->width=i_tmp;
				cloud->height=1;
				cloud->resize(cloud->width);
				for(int i=0;i<i_tmp;i++){
					cloud->points[i].x=aRealWorld[ids[i]].X/1000;
					cloud->points[i].y=aRealWorld[ids[i]].Y/1000;
					cloud->points[i].z=aRealWorld[ids[i]].Z/1000;
					//UINT8 r = 255, g = 0, b = 0;    // Example: Red color
					//UINT32 rgb = ((UINT32)r << 16 | (UINT32)g << 8 | (UINT32)b);
					//float rgb_f = *reinterpret_cast<float*>(&rgb);
					//UINT32 rgb_i = *reinterpret_cast<int*>(&rgb_f);
					cloud->points[i].r=(UINT8)(clorPts[i].X*255.0);
					cloud->points[i].g=(UINT8)(clorPts[i].Y*255.0);
					cloud->points[i].b=(UINT8)(clorPts[i].Z*255.0);
				}
				std::stringstream name_str;
				name_str<<"c:\\table_kin_"<<devId<<".pcd";
			//	pcl::io::savePCDFileASCII(name_str.str(),*cloud);
				pcl::io::savePCDFile(name_str.str(),*cloud);
			}
			
		}	
}

void convPoint(XnUInt32 devId){}
void startDepGen(XnUInt32 devId){
	sensors[devId].depGen.StartGenerating();
}
void closeDepGen(XnUInt32 devId){
	sensors[devId].depGen.StopGenerating();
}


void KinectClose(){
	if(obv)delete obv;
	g_Context.Shutdown();
}

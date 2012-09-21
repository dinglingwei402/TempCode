#include "StdAfx.h"
#include "SingleControler.h"
#include "QueryNode.h"
#include "pcl_function.h"
#include <string>
//######## ######## ######## ######## ######## 
void clearNullPoints(XnPoint3D* points,int cnt,std::vector<XnPoint3D>& vec){
	for (int i=0;i<cnt;i++)
	{ 
		float allZero=std::abs(points[i].X)+std::abs(points[i].Y)+std::abs(points[i].Z);
		if(allZero>0.05){
			vec.push_back(points[i]);
		}	
	}
}

SingleControler::SingleControler(const Vrml_PROTO_KinectDev& v_data,const KinectData& k_data,int x_step,int y_step):KinectControler(v_data,k_data,x_step,y_step),blockSize(0),sub_x(0),sub_y(0)
{
	init();	
}
SingleControler::~SingleControler()
{
	if(this->data1)delete data1;
	if(this->lp_crd)delete lp_crd;
	if(this->lp_clr)delete lp_clr;
}

void SingleControler::start(){
	getDevData().getData()[0].depGen.StartGenerating();
	getDevData().getData()[0].imgGen.StartGenerating();
}

void SingleControler::close(){
 int i=0;
}

void SingleControler::drawPointSet(XnPoint3D* crdPts,XnPoint3D* clrPts){
	if (ini_stus==success)
	{
		int len=0;
		for(int i=0;i<sub_y;i++){
			for(int j=0;j<sub_x;j++){
				int bigX=j*getXStep();
				int bigY=i*getYStep();
				int idx=bigY*(getDevData().getData()[0].xres)+bigX;
				int base=len*3;
				int base1=base+1;
				int base2=base+2;
				crdPts[len].X=bigX;
				crdPts[len].Y=bigY;
				crdPts[len].Z=depPix[idx];
				clrPts[len].X=(XnFloat)(imgPix[idx*3]/255.0);
				clrPts[len].Y=(XnFloat)(imgPix[idx*3+1]/255.0);
				clrPts[len].Z=(XnFloat)(imgPix[idx*3+2]/255.0);
				len++;
			}
		}
		getDevData().getData()[0].depGen.ConvertProjectiveToRealWorld(len,crdPts,crdPts);
		data1->coord->setValue(blockSize*3,(float*)crdPts);
		data1->color->setValue(blockSize*3,(float*)clrPts);
	}

	//return 0;
}


void SingleControler::getNonZeroPt( std::vector<XnPoint3D>& vec_crd,std::vector<XnPoint3D>& vec_clr)
{
	int width=getDevData().getData()[0].xres;
	int height=getDevData().getData()[0].yres;
	int cnt=width*height;
	GenGrp* devData=getDevData().getData();
	for(int i=1;i<height;i++){
		for(int j=1;j<width;j++){
			int bigX=j;
			int bigY=i;
			int idx=bigY*(devData[0].xres)+bigX;
			if(depPix[idx]>devData[0].depGen.GetDeviceMaxDepth())continue; 
			XnPoint3D PixCrd={bigX,bigY,depPix[idx]};
			devData[0].depGen.ConvertProjectiveToRealWorld(1,&PixCrd,&PixCrd);
			float allZero=std::abs(PixCrd.X)+std::abs(PixCrd.Y)+std::abs(PixCrd.Z);
			if(allZero>0.001){
				vec_crd.push_back(PixCrd);
				int r=(XnFloat)(imgPix[idx*3]);
				int g=(XnFloat)(imgPix[idx*3+1]);
				int b=(XnFloat)(imgPix[idx*3+2]);
				XnPoint3D PixClr={r,g,b};
				vec_clr.push_back(PixClr);
				
			}
		}
	}
}

void SingleControler::getNonZeroPt( std::vector<XnPoint3D>& vec_crd)
{
	int width=getDevData().getData()[0].xres;
	int height=getDevData().getData()[0].yres;
	int cnt=width*height;
	GenGrp* devData=getDevData().getData();
	for(int i=1;i<height;i++){
		for(int j=1;j<width;j++){
			int bigX=j;
			int bigY=i;
			int idx=bigY*(devData[0].xres)+bigX;
			if(depPix[idx]>devData[0].depGen.GetDeviceMaxDepth())continue; 
			XnPoint3D PixCrd={bigX,bigY,depPix[idx]};
			devData[0].depGen.ConvertProjectiveToRealWorld(1,&PixCrd,&PixCrd);
			float allZero=std::abs(PixCrd.X)+std::abs(PixCrd.Y)+std::abs(PixCrd.Z);
			if(allZero>0.001){
				vec_crd.push_back(PixCrd);
			}
		}
	}
}

initStatus SingleControler::init(){
	HRESULT hr;	
	this->data1=new Vrml_PROTO_KinectData();
	Node* child;
	hr=this->getVrmlData().getChildren()->get1Value(0,&child);
	EventInMFVec3f* crd;
	hr=DeepQueryNode(child,_T("coord"),IID_EventInMFVec3f,&crd);
	data1->coord=crd;
	EventInMFColor* clr;
	hr=DeepQueryNode(child,_T("color"),IID_EventInMFColor,&clr);
	data1->color=clr;
	depPix=getDevData().getData()[0].pDepthData;
	imgPix=getDevData().getData()[0].pImageData;
	sub_x=(int)(getDevData().getData()[0].xres/getXStep());
	sub_y=(int)(getDevData().getData()[0].yres/getYStep());
	blockSize=sub_x*sub_y;
	if (blockSize==0)
	{
		this->ini_stus=fail;
		return this->ini_stus;
	}
	lp_crd=new XnPoint3D[blockSize];
	lp_clr=new XnPoint3D[blockSize];
	drawPointSet(lp_crd,lp_clr);
	this->ini_stus=FAILED(hr)?fail:success;
	return this->ini_stus;
}


void SingleControler::update(){
	XnStatus rc;
	rc=getDevData().getData()[0].depGen.WaitAndUpdateData();
	if(rc==XN_STATUS_OK){
	//	drawPointSet(lp_crd,lp_clr); 
	//	createMesh();
	}
//	return 0;
}
void SingleControler::createMesh(){	
	/*int len=sizeof(XnPoint3D);
	int len1=len*blockSize1;*/
	HANDLE hRead;
	HANDLE hWrite;
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle=true;
	sa.lpSecurityDescriptor=NULL;
	sa.nLength=sizeof(SECURITY_ATTRIBUTES);
	std::vector<XnPoint3D> vec_crd;
	std::vector<XnPoint3D> vec_clr;
	getNonZeroPt(vec_crd,vec_clr);
	int vec_sz=vec_crd.size();
	int ptsSize=sizeof(XnPoint3D)*vec_sz*2;
	XnPoint3D* arr=new XnPoint3D[vec_sz*2];
	std::vector<XnPoint3D>::iterator it=vec_crd.begin();
	std::vector<XnPoint3D>::iterator it1=vec_clr.begin();
	int indx=0;
	while (it!=vec_crd.end())
	{
		arr[indx*2]=*it;
		arr[indx*2+1]=*it1;
		indx++;
		it++;
		it1++;
	}
	bool b=CreatePipe(&hRead,&hWrite,&sa,ptsSize);
	DWORD dwWrite;
	if(!WriteFile(hWrite,arr,ptsSize,&dwWrite,NULL)){
		MessageBoxW(NULL,L"写入失败",L"in keyobv",0);
		return;
	}
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si,sizeof(STARTUPINFO));
	si.cb=sizeof(STARTUPINFO);
	si.dwFlags=STARTF_USESTDHANDLES;
	si.hStdInput =hRead;
	si.hStdOutput=hWrite;
	si.hStdError=GetStdHandle(STD_ERROR_HANDLE);
	TCHAR cmdApPath[]=_T("\"E:\\Code\\pclwrite\\build\\Release\\pcd_write_test.exe\" "); 
	TCHAR cmdAppArg[256];
	_itot(ptsSize,cmdAppArg,10);
	int argChrCnt=_tcslen(cmdAppArg);
	int pathChrCnt=_tcslen(cmdApPath);
	int cmdLineLen=argChrCnt+pathChrCnt;
	TCHAR* saveCmd=new TCHAR[cmdLineLen+1];
	int charSz=sizeof(TCHAR)/sizeof(char);
	memcpy(saveCmd,cmdApPath,pathChrCnt*charSz);
	memcpy(&saveCmd[pathChrCnt],cmdAppArg,argChrCnt*charSz);
	saveCmd[cmdLineLen]=_T('\0');
	HRESULT ret=CreateProcess(NULL,saveCmd,NULL,NULL,TRUE,0,NULL,NULL,&si,&pi);
	if(!ret)
	{
		MessageBoxW(NULL,L"没有找到模块 ",L"in keyobv",0);
		return;
	}
	delete[] saveCmd;
	saveCmd=NULL;
	/*char buf1[100];
	DWORD dwRead;
	if (!ReadFile(hRead,buf1,100,&dwRead,NULL))
	{
		int hhh=0;
	}*/
	CloseHandle(hRead);
	CloseHandle(hWrite);
}

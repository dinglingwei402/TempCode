#include "StdAfx.h"
#include "SingleControler.h"
#include "QueryNode.h"
#include <string>

#ifndef FILTER_CONDITION(rc, what)
#define CHECK_RC(rc, what)  \
	if (rc != XN_STATUS_OK)	    \
	{					        \
	printf("%s failed: %s\n", what, xnGetStatusString(rc));	\
	return rc;					\
	}
#endif

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
	if (_ini_stus==success)
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
			if(allZero>0.01&&(PixCrd.Z>200&&PixCrd.Z<3000)){
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
			if(allZero>0.01&&(PixCrd.Z>200&&PixCrd.Z<3000)){
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
	EventOutSFNode* snpMsh;
	hr=DeepQueryNode(child,_T("snapMesh"),IID_EventOutSFNode,&snpMsh);
	data1->snapMesh=snpMsh;
	depPix=getDevData().getData()[0].pDepthData;
	imgPix=getDevData().getData()[0].pImageData;
	sub_x=(int)(getDevData().getData()[0].xres/getXStep());
	sub_y=(int)(getDevData().getData()[0].yres/getYStep());
	blockSize=sub_x*sub_y;
	if (blockSize==0)
	{
		this->_ini_stus=fail;
		return this->_ini_stus;
	}
	lp_crd=new XnPoint3D[blockSize];
	lp_clr=new XnPoint3D[blockSize];
	drawPointSet(lp_crd,lp_clr);
	this->_ini_stus=FAILED(hr)?fail:success;
	return this->_ini_stus;
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


TCHAR* getCmdStr(TCHAR cmdPath[],TCHAR cmdArg[]){
	/*TCHAR* cmdApPath=procPath; 
	TCHAR cmdAppArg[256];
	_itot(ptsBuf,cmdAppArg,10);*/
	int argChrCnt=_tcslen(cmdArg);
	int pathChrCnt=_tcslen(cmdPath);
	int cmdLineLen=argChrCnt+pathChrCnt;
	TCHAR* saveCmd=new TCHAR[cmdLineLen+1];
	int charSz=sizeof(TCHAR)/sizeof(char);
	memcpy(saveCmd,cmdPath,pathChrCnt*charSz);
	memcpy(&saveCmd[pathChrCnt],cmdArg,argChrCnt*charSz);
	saveCmd[cmdLineLen]=_T('\0');
	return saveCmd;
}

void SingleControler::createMesh(){	
//	_asm int 3;
	std::vector<XnPoint3D> vec_crd;
	getNonZeroPt(vec_crd);
//	int vec_sz=vec_crd.size();
	int vec_sz=5000;
	int ptsBuf=sizeof(XnPoint3D)*vec_sz;
	TCHAR cmdAppArg[256];
	_itot(ptsBuf,cmdAppArg,10);
	TCHAR* cmdStr = getCmdStr(_T("\"E:\\Code\\pclwrite\\build\\Debug\\pcd_write_test.exe\" "),cmdAppArg);
	
	HANDLE hReadPipe1,hWritePipe1,hReadPipe2,hWritePipe2;
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle=true;
	sa.lpSecurityDescriptor=NULL;
	sa.nLength=sizeof(SECURITY_ATTRIBUTES);
	std::vector<XnPoint3D>::iterator it=vec_crd.begin();
	if(it==vec_crd.end())return;
	XnPoint3D* wrtBuf=new XnPoint3D[vec_sz];	
	int indx=0;
	while (indx!=vec_sz)
	{
		wrtBuf[indx]=*it;
		indx++;
		it++;
	}
	const size_t pipe2Buf=100;
	BOOL pipe1Success=CreatePipe(&hReadPipe1,&hWritePipe1,&sa,ptsBuf);
	BOOL pipe2Success=CreatePipe(&hReadPipe2,&hWritePipe2,&sa,pipe2Buf);
	DWORD dwWrite;
	if(!WriteFile(hWritePipe1,wrtBuf,ptsBuf,&dwWrite,NULL)){
		MessageBoxW(NULL,L"写入失败",L"in keyobv",0);
		return;
	}
	delete wrtBuf;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si,sizeof(STARTUPINFO));
	si.cb=sizeof(STARTUPINFO);
	si.dwFlags=STARTF_USESTDHANDLES;
	si.hStdInput =hReadPipe1;
	si.hStdOutput=hWritePipe1;
	si.hStdError=hWritePipe2;//notice the error handle
	//childprocess
	BOOL ret=CreateProcess(NULL,cmdStr,NULL,NULL,TRUE,0,NULL,NULL,&si,&pi);
	if(!ret)
	{
		MessageBoxW(NULL,L"没有找到模块 ",L"in keyobv",0);
		return;
	}
//	MessageBoxW(NULL,L"wait",L"in keyobv",0);
	bool flag=false;
	char isFinished=(char)flag;
	DWORD dwReadPipe2;
    char rdBuf[pipe2Buf];//read offset vlu,the offset record the len of points ,and the len of idx
	for(;;){
		if (!ReadFile(hReadPipe2,rdBuf,100,&dwReadPipe2,NULL))
		{
			MessageBoxW(NULL,L"readPipe2Error",L"in keyobv",0);	
			break;
		}else if(dwReadPipe2==0)
		{
			break;
		}
	}

	size_t* offset=(size_t*)rdBuf;//use offset to find where is pts content and where is index
	size_t ptsSetBuf=offset[0]*sizeof(XnPoint3D);
	size_t indxSetBuf=offset[1]*sizeof(IdxSeq);
	size_t totalSize=ptsSetBuf+indxSetBuf;
	char* totalBuf=new char[totalSize];		
	DWORD dwReadPipe1;
	for(;;){
		if(!ReadFile(hReadPipe1,totalBuf,totalSize,&dwReadPipe1,NULL))
		{
			MessageBoxW(NULL,L"readPipe1Error",L"in keyobv",0);	
			break;
		}else if(dwReadPipe1==0){
			break;
		}
	}

//	SetStdHandle(STD_INPUT_HANDLE,hReadPipe2);
	XnPoint3D* pts=(XnPoint3D*)totalBuf;
	IdxSeq* idx=(IdxSeq*)(&totalBuf[ptsSetBuf]);
	PclMesh2VrlMesh(offset[0],pts,offset[1],idx);
	delete[] totalBuf;
	CloseHandle(hReadPipe1);
	CloseHandle(hWritePipe1);
	CloseHandle(hReadPipe2);
	CloseHandle(hWritePipe2);
	delete cmdStr;	
}

void SingleControler::PclMesh2VrlMesh(size_t ptsCnt,XnPoint3D* pts,size_t idxCnt,IdxSeq* idx){
	Node* meshNode;
	this->data1->snapMesh->getValue(&meshNode);
	EventInMFVec3f* points;
	DeepQueryNode(meshNode,L"point",IID_EventInMFVec3f,&points);
	points->setValue(ptsCnt*3,(float*)pts);
	EventInMFInt32* ind;
	DeepQueryNode(meshNode,L"index",IID_EventInMFInt32,&ind);
	ind->setValue(idxCnt*3,(int*)idx);
}


#include "StdAfx.h"
#include "SingleControler.h"
#include "QueryNode.h"
#include "pcl_function.h"
//######## ######## ######## ######## ######## 
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

HRESULT SingleControler::GetKeyEvents(int keyVlu){
	if(keyVlu==65){
		MessageBoxW(NULL,L"at 0 degree ",L"in keyobv",0);
		
	}
	if(keyVlu==66){
		//		MessageBoxW(L"rotate to 120 degree ",);
	}
	if(keyVlu==67){
		//		MessageBoxW(L"rotate t0 240 degree ",);
	}

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
		drawPointSet(lp_crd,lp_clr); 
	//	createMesh();
	}
//	return 0;
}


void SingleControler::createMesh(){
	HANDLE hRead;
	HANDLE hWrite;
	CreatePipe(&hRead,&hWrite,NULL,NULL);
	WCHAR buf[]=L"sdfsdfsdfdsfsdf";
	DWORD dwWrite;
	if(!WriteFile(hWrite,buf,wcslen(buf)+2,&dwWrite,NULL)){
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
	if(!(CreateProcess(L"E:\\pcd_write_test.exe",NULL,NULL,
		NULL,TRUE,0,NULL,NULL,&si,&pi)))
	{
		MessageBoxW(NULL,L"没有找到模块 ",L"in keyobv",0);
		return;
	}
}



	/*void SingleControler::createMesh1(){
		pcl::PointCloud<pcl::PointXYZ> cloud;
		int blockSize1=200;
		cloud.width=blockSize1;
		cloud.height=1;
		cloud.points.resize(blockSize1);
		for(int i=0;i<blockSize1;i++){
			cloud.points[i].x=lp_crd[i].X/1000.0;
			cloud.points[i].y=lp_crd[i].Y/1000.0;
			cloud.points[i].z=lp_crd[i].Z/1000.0;
		}
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloudPtr(&cloud);
		poissonSurface(cloud,("tst_7_7.pcd"));
	}*/

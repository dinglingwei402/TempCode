#include "stdafx.h"
#include "KinectControl.h"
#include "XnCppWrapper.h"

using namespace xn;
int xres;
int yres;
Context g_Context;
ImageGenerator g_imgGen;
DepthGenerator g_depGen;
ImageMetaData g_ImgDat;
DepthMetaData g_DepDat;


void KinectInit(Node* node){
	XnStatus rc=XN_STATUS_OK;
	rc=g_Context.Init();
	if (rc==XN_STATUS_OK)
	{
		rc=g_imgGen.Create(g_Context,NULL,NULL);
		CHECK_RC(rc,"Create ImgGen");
		g_imgGen.GetMetaData(g_ImgDat);
		rc=g_depGen.Create(g_Context,NULL,NULL);
		CHECK_RC(rc,"Create depGen");
		g_depGen.GetMetaData(g_DepDat);		
		xres=g_DepDat.FullXRes();
		yres=g_DepDat.FullYRes();
		EventIn *w,*h,*f;
		node->getEventIn(_T("pixelWidth"),&w);
		EventInSFInt32* wid,*heit;
		w->QueryInterface(IID_EventInSFInt32,(void**)&wid);
		wid->setValue(xres);
		node->getEventIn(_T("pixelHeight"),&h);
		h->QueryInterface(IID_EventInSFInt32,(void**)&heit);
		heit->setValue(yres);
		EventInSFString* fmt;
		node->getEventIn(_T("format"),(EventIn**)&f);
		f->QueryInterface(IID_EventInSFString,(void**)&fmt);
		fmt->setValue(L"L16");
		wid->Release();
		heit->Release();
		fmt->Release();
		w->Release();
		h->Release();
		f->Release();
	}
	
	g_Context.StartGeneratingAll();
}

void UpdateImage(){
	
//	g_Context.WaitAndUpdateAll();
//	const XnDepthPixel* pDepth=g_DepDat.Data();
	
	
}

void KinectClose(){
	g_Context.Shutdown();
}
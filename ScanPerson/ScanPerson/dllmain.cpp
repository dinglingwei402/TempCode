// dllmain.cpp : DllMain 的实现。
#include "stdafx.h"
#include "resource.h"
#include "ScanPerson_i.h"
#include "dllmain.h"

#ifdef _DEBUG

#define DEBUG_CLIENTBLOCK    new( _CLIENT_BLOCK, __FILE__, __LINE__)

#else

#define DEBUG_CLIENTBLOCK

#endif

#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>

#ifdef _DEBUG

#define new DEBUG_CLIENTBLOCK

#endif


CScanPersonModule _AtlModule;


void no_mem(){
	OutputDebugString(L"nnnnomem");
	exit(1);
}



// DLL 入口点
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	//set_new_handler(no_mem);
	/*_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(long(181));
	_CrtSetBreakAlloc(long(180));
	_CrtSetBreakAlloc(long(179));
	_CrtSetBreakAlloc(long(178));
	_CrtSetBreakAlloc(long(177));
	_CrtSetBreakAlloc(long(176));
	_CrtSetBreakAlloc(long(175));
	_CrtSetBreakAlloc(long(174));
	_CrtSetBreakAlloc(long(173));
	_CrtSetBreakAlloc(long(172));
	_CrtSetBreakAlloc(long(171));*/
//	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	hInstance;
	BOOL rslt=_AtlModule.DllMain(dwReason, lpReserved); 
//	_CrtDumpMemoryLeaks();
	return rslt;
}

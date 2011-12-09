#include "stdafx.h"
#include "Temp4Debug.h"
#include <assert.h>
#define  TURNOFF False
#define IS_HANDLE_NULL   assert(hConsole);if(!hConsole||TURNOFF){return;}



HANDLE hConsole=NULL;
void SetConsoleHandle(HANDLE h){
	hConsole=h;
}
HANDLE GetConsoleHandle(){
	return hConsole;
}

void wrt_Wchr(WCHAR wc[]){
	IS_HANDLE_NULL;
	DWORD ws;
	WriteConsoleW(hConsole,wc,wcslen(wc),&ws,NULL);
	WCHAR enter[]=L"\r\n";
	WriteConsoleW(hConsole,enter,wcslen(enter),&ws,NULL);
}
void wrt_i(int i){
	IS_HANDLE_NULL;
	WCHAR wc[50];
	swprintf_s(wc,50,L"%d\r\n",i);
	wrt_Wchr(wc);
}

void wrt_f(float f){
	WCHAR wc[50];
	swprintf_s(wc,50,L"%.8f\r\n",f);
	wrt_Wchr(wc);
}

void wrt_char(char c[]){
	WCHAR wc[1000];
	swprintf_s(wc,1000,L"%s\r\n",c);
	wrt_Wchr(wc);
}

void wrt_spec(WCHAR wc[]){
	DWORD ws;
	WriteConsoleW(hConsole,wc,wcslen(wc),&ws,NULL);
	WCHAR enter[]=L"\r\n";
	WriteConsoleW(hConsole,enter,wcslen(enter),&ws,NULL);
}

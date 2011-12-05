#include "stdafx.h"
#include "Temp4Debug.h"

HANDLE hConsole;
void SetConsoleHandle(HANDLE h){
	hConsole=h;
}
HANDLE GetConsoleHandle(){
	return hConsole;
}

void wrt_Wchr(WCHAR wc[]){
	DWORD ws;
	WriteConsoleW(hConsole,wc,wcslen(wc),&ws,NULL);
}
void wrt_i(int i){
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
	WCHAR wc[100];
	swprintf_s(wc,100,L"%s\r\n",c);
	wrt_Wchr(wc);
}

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
	WCHAR int_wchr[50];
	_itow(i,int_wchr,10);
	DWORD ws;
	WriteConsoleW(hConsole,int_wchr,wcslen(int_wchr),&ws,NULL);

}
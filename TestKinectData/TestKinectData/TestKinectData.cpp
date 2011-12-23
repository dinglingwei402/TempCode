// TestKinectData.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "KinectData.h"
#include <windows.h>


VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD); 
VOID MouseEventProc(MOUSE_EVENT_RECORD); 
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD); 

int main(VOID) 
{ 
	HANDLE hStdin; 
	DWORD cNumRead, fdwMode, fdwSaveOldMode, i; 
	INPUT_RECORD irInBuf[128]; 
	int counter=0;
	init();
	// Get the standard input handle. 

	hStdin = GetStdHandle(STD_INPUT_HANDLE); 
	if (hStdin == INVALID_HANDLE_VALUE) 
		ErrorExit(TEXT("GetStdHandle")); 

	// Save the current input mode, to be restored on exit. 

	if (! GetConsoleMode(hStdin, &fdwSaveOldMode) ) 
		ErrorExit(TEXT("GetConsoleMode")); 

	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; 
	if (! SetConsoleMode(hStdin, fdwMode) ) 
		ErrorExit(TEXT("SetConsoleMode")); 


	// Loop to read and handle the input events. 

	while (true) 
	{ 
			//	KeyEventProc(irInBuf[i].Event.KeyEvent); 
				tick();
				XnUserID aUsers[20];	
				XnUInt16 num=20;
				getValidUserNum(0,aUsers,num);
				for(int i=0;i<20;i++){
					drawPoint(0,aUsers[i]);
				}
					//	break; 
	} 

	return 0; 
}

VOID ErrorExit (LPSTR lpszMessage) 
{ 
	fprintf(stderr, "%s\n", lpszMessage); 
	ExitProcess(0); 
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{
	printf("Key event: ");

	if(ker.bKeyDown)
		printf("key pressed\n");
	else printf("key released\n");
}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	printf("Mouse event: ");

	switch(mer.dwEventFlags)
	{
	case 0:
		printf("button press\n");
		break;
	case DOUBLE_CLICK:
		printf("double click\n");
		break;
	case MOUSE_HWHEELED:
		printf("horizontal mouse wheel\n");
		break;
	case MOUSE_MOVED:
		printf("mouse moved\n");
		break;
	case MOUSE_WHEELED:
		printf("vertical mouse wheel\n");
		break;
	default:
		printf("unknown\n");
		break;
	}
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	printf("Resize event\n");
}
#include"stdio.h" 
#include"malloc.h"
#include"math.h"  //数学函数
int mul4X4(float left[16],float right[16],float out[16]){
	int k=0;
	for(int i=0;i<4;i++){
		int row_Start=i*4;
		for(int j=0;j<4;j++){
			int clmn_Start=j*4;
			out[k]=left[row_Start]*right[clmn_Start]+	\
				left[row_Start+1]*right[clmn_Start+1]+	\
				left[row_Start+2]*right[clmn_Start+2]+	\
				left[row_Start+3]*right[clmn_Start+3];
			k++;
		}
	}
	return 0;
}
int inv(float *p,int n) 
{
	void swap(float *a,float *b);
	int *is,*js,i,j,k,l;
	for(i=0;i<n;i++) {
		putchar('\n');
		for(j=0;j<n;j++) printf("%f  ",*(p+i*n+j));
	}
	puts("\n\n\n\n");
	float temp,fmax;
	is=(int *)malloc(n*sizeof(int));
	js=(int *)malloc(n*sizeof(int));
	for(k=0;k<n;k++) {
		fmax=0.0;
		for(i=k;i<n;i++) for(j=k;j<n;j++) 
		{
			temp=fabs(*(p+i*n+j));//找最大值 
			if(temp>fmax) 
			{
				fmax=temp;
				is[k]=i;
				js[k]=j;
			}

		}
		if((fmax+1.0)==1.0) 
		{
			free(is);
			free(js);
			printf("no inv");
			return(0);
		}
		if((i=is[k])!=k) for(j=0;j<n;j++) swap(&p[k*n+j],&p[i*n+j]);//交换指针 
		if((j=js[k])!=k) for(i=0;i<n;i++) swap(&p[i*n+k],&p[i*n+j]);//交换指针 
		p[k*n+k]=1.0/p[k*n+k];
		for(j=0;j<n;j++) if(j!=k) p[k*n+j]*=p[k*n+k];
		for(i=0;i<n;i++) if(i!=k) 
			for(j=0;j<n;j++) 
				if(j!=k) p[i*n+j]=p[i*n+j]-p[i*n+k]*p[k*n+j];
		for(i=0;i<n;i++) 
			if(i!=k) p[i*n+k]*=-p[k*n+k];
	}
	for(k=n-1;k>=0;k--) 
	{
		if((j=js[k])!=k) for(i=0;i<n;i++) swap((p+j*n+i),(p+k*n+i));
		if((i=is[k])!=k) for(j=0;j<n;j++) swap((p+j*n+i),(p+j*n+k));
	}
	free(is);
	free(js);
	return 1;
}
void swap(float *a,float *b) 
{
	float c;
	c=*a;
	*a=*b;
	*b=c;
}

BOOL SaveBmp(HBITMAP hBitmap, const TCHAR *FileName)       
{       
	HDC     hDC;       
	int     iBits;       
	WORD     wBitCount;       
	DWORD     dwPaletteSize=0,     dwBmBitsSize=0,     dwDIBSize=0,     dwWritten=0;      	BITMAP     Bitmap;               
	BITMAPFILEHEADER     bmfHdr;               
	BITMAPINFOHEADER     bi;               
	LPBITMAPINFOHEADER     lpbi;               
	HANDLE     fh,     hDib,     hPal,hOldPal=NULL;          
	hDC     =     CreateDC(_T("DISPLAY"),     NULL,     NULL,     NULL);       
	iBits     =     GetDeviceCaps(hDC,     BITSPIXEL) *GetDeviceCaps(hDC,     PLANES);       
	DeleteDC(hDC);           
	if (iBits <= 1) 
	{
		wBitCount = 1; 
	}
	else if (iBits <= 4)   
	{
		wBitCount = 4;         
	}
	else if (iBits <= 8)  
	{
		wBitCount = 8;  
	}
	else 
	{
		wBitCount = 24;
	}

	GetObject(hBitmap, sizeof(Bitmap), (LPSTR)&Bitmap);       
	bi.biSize = sizeof(BITMAPINFOHEADER);       
	bi.biWidth =  Bitmap.bmWidth;       
	bi.biHeight = Bitmap.bmHeight;       
	bi.biPlanes = 1;       
	bi.biBitCount = wBitCount;       
	bi.biCompression =  BI_RGB;       
	bi.biSizeImage  =  0;       
	bi.biXPelsPerMeter = 0;       
	bi.biYPelsPerMeter   =   0;       
	bi.biClrImportant = 0;       
	bi.biClrUsed   = 0;      

	dwBmBitsSize  = ((Bitmap.bmWidth     *     wBitCount     +     31)     /     32)     *     4     *     Bitmap.bmHeight;      
	hDib     =     GlobalAlloc(GHND,dwBmBitsSize     +     dwPaletteSize     +     sizeof(BITMAPINFOHEADER));           
	lpbi     =     (LPBITMAPINFOHEADER)GlobalLock(hDib);           
	*lpbi     =     bi;          
	hPal     =     GetStockObject(DEFAULT_PALETTE);           
	if     (hPal)           
	{           
		hDC     =     ::GetDC(NULL);           
		hOldPal     =     ::SelectPalette(hDC,     (HPALETTE)hPal,     FALSE);           
		RealizePalette(hDC);           
	}      
	GetDIBits(hDC, 
		hBitmap, 
		0,   
		(UINT)Bitmap.bmHeight,
		(LPSTR)lpbi+sizeof(BITMAPINFOHEADER)+dwPaletteSize,
		(BITMAPINFO *)lpbi, 
		DIB_RGB_COLORS);          
	if (hOldPal)           
	{           
		::SelectPalette(hDC,     (HPALETTE)hOldPal,     TRUE);           
		RealizePalette(hDC);           
		::ReleaseDC(NULL,     hDC);           
	}          

	fh  =  CreateFile((LPCWSTR)FileName,
		GENERIC_WRITE,
		0,     
		NULL,    
		CREATE_ALWAYS,           
		FILE_ATTRIBUTE_NORMAL,
		NULL);/*     FILE_FLAG_SEQUENTIAL_SCAN,     NULL);  */        

	if     (fh == INVALID_HANDLE_VALUE) 
	{
		return     FALSE;  
	}

	bmfHdr.bfType     =     0x4D42;     //     "BM"           
	dwDIBSize     =     sizeof(BITMAPFILEHEADER)     +     sizeof(BITMAPINFOHEADER)     +     dwPaletteSize     +     dwBmBitsSize;               
	bmfHdr.bfSize     =     dwDIBSize;           
	bmfHdr.bfReserved1     =     0;           
	bmfHdr.bfReserved2     =     0;           
	bmfHdr.bfOffBits     =     (DWORD)sizeof(BITMAPFILEHEADER)     +     (DWORD)sizeof(BITMAPINFOHEADER)     +     dwPaletteSize;           
	WriteFile(fh,     (LPSTR)&bmfHdr,     sizeof(BITMAPFILEHEADER),     &dwWritten,     NULL);           
	WriteFile(fh,     (LPSTR)lpbi,     dwDIBSize,     &dwWritten,     NULL);           
	//清除               
	GlobalUnlock(hDib);           
	GlobalFree(hDib);           
	CloseHandle(fh);          
	return     TRUE;       
}      
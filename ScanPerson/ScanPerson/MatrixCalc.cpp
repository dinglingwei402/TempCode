#include "stdafx.h"
#include "MatrixCalc.h"
#include"stdio.h" 
#include"malloc.h"
#include"math.h"  //数学函数
int mul4X4(float left[16],float right[16],float out[16]){
	int k=0;
	for(int i=0;i<4;i++){
		int row_Start=i*4;
		for(int j=0;j<4;j++){
			int clmn_Start=j;
			out[k]=left[row_Start]*right[clmn_Start]+	\
				left[row_Start+1]*right[clmn_Start+1*4]+	\
				left[row_Start+2]*right[clmn_Start+2*4]+	\
				left[row_Start+3]*right[clmn_Start+3*4];
			k++;
		}
	}
	return 0;
}

void vecMulMatrx(float vec[4],float right[16],float out[3] ){
	float out_temp[4]={0,0,0,0};
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			out_temp[i]+=vec[j]*right[i+j*4];
		}
	}
	out[0]=out_temp[0]/out_temp[3];
	out[1]=out_temp[1]/out_temp[3];
	out[2]=out_temp[2]/out_temp[3];
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

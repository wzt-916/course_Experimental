#include "stdafx.h"
#include <complex>
using namespace std;
#define PI 3.1415926535

BITMAPINFO * lpBitsInfo = NULL;
BOOL LoadBmpFile(char *BmpFileName)
{
	FILE *fp;
	if(NULL == (fp = fopen(BmpFileName,"rb")))
		return FALSE;

	BITMAPINFOHEADER bf;
	BITMAPINFOHEADER bi;

	//文件头
	fread(&bf,14,1,fp);
	//信息头
	fread(&bi,40,1,fp);

    //每行字节数
	int LineBytes =(bi.biWidth * bi.biBitCount + 31)/32 * 4;
	
	//图像数据占据空间大小
	int ImgSize = LineBytes * bi.biHeight;

	//调色板的大小
	int NumColors;
	if(bi.biClrUsed != 0){     
		NumColors = bi.biClrUsed;
	}
	else
	{
		switch(bi.biBitCount)
		{
		case 1:
			NumColors = 2;
			break;
		case 4:
			NumColors = 16;
			break;
		case 8:
			NumColors = 256;
			break;
		case 24:
			NumColors = 0; //真彩图像没有调色板
			break;
		}
	}
	int size = 14 + 040 + NumColors * 4 + ImgSize;

	if(NULL == (lpBitsInfo = (BITMAPINFO *)malloc(size)))
	{
		return FALSE;
	}

    fseek(fp,14,SEEK_SET);
	
	fread(lpBitsInfo,size,1,fp);

	lpBitsInfo->bmiHeader.biClrUsed = NumColors;

	fclose(fp);


	return TRUE;
}

void gray()
{
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount +31)/32 *4;
	BYTE * lpBits = (BYTE *)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	int LineBytes_gray = (w * 8 +31)/32 * 4;
	LPBITMAPINFO lpBitsInfo_gray = (LPBITMAPINFO) malloc(40 + 1024 + LineBytes_gray *h);
	memcpy(lpBitsInfo_gray,lpBitsInfo,40);
	lpBitsInfo_gray->bmiHeader.biBitCount = 8;
	lpBitsInfo_gray->bmiHeader.biClrUsed = 256;

	int i,j;
	for(i = 0; i < 256; i++)
	{
		lpBitsInfo_gray->bmiColors[i].rgbRed = i;
		lpBitsInfo_gray->bmiColors[i].rgbGreen = i;
		lpBitsInfo_gray->bmiColors[i].rgbBlue = i;
		lpBitsInfo_gray->bmiColors[i].rgbReserved = 0;
	}
	BYTE* lpBits_gray = (BYTE*)&lpBitsInfo_gray->bmiColors[256];
	BYTE *R,*G,*B,avg,*pixel;
	for(i = 0; i < h; i++)
	{
		for(j = 0; j < w; j++)
		{
			B = lpBits + LineBytes * (h - 1 - i) + j * 3;
			G = B + 1;
			R = G + 1;
			avg = (*G + *R + *B) / 3;
			pixel = lpBits_gray + LineBytes_gray * (h - 1 - i)+j;
			*pixel = avg;
		}
	}
	free(lpBitsInfo);
	lpBitsInfo = lpBitsInfo_gray;
}
BOOL IsGray()
{
	int r,g,b;
	if(8 == lpBitsInfo->bmiHeader.biBitCount)
	{
		r = lpBitsInfo->bmiColors[128].rgbRed;
		g = lpBitsInfo->bmiColors[128].rgbGreen;
		b = lpBitsInfo->bmiColors[128].rgbBlue;
		if(r == b && r == g)
			return TRUE;
	}
	return FALSE;
}
void pixel(int i,int j, char* str)
{
	if(NULL == lpBitsInfo)
		return;
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount + 31)/32*4;
	BYTE * lpBits = (BYTE *)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	if(i >=h || j >= w)
		return;
	BYTE *pixel,bv,r,g,b;

	switch(lpBitsInfo->bmiHeader.biBitCount)
	{
	case 8:
		pixel = lpBits + LineBytes * (h - 1 - j) + j;
		if(IsGray())
			sprintf(str,"亮度值:%d",*pixel);
		else
		{
		    r = lpBitsInfo->bmiColors[*pixel].rgbRed;
		    g = lpBitsInfo->bmiColors[*pixel].rgbGreen;
		    b = lpBitsInfo->bmiColors[*pixel].rgbBlue;
			sprintf(str,"-RGB(%d,%d,%d)",r,g,b);
		}
		break;
	case 1:
		bv = *(lpBits + LineBytes * (h - 1 - i) +j/8) & (1 << (7 - j % 8));
		if(0 == bv)
			strcpy(str,"背景点");
		else
			strcpy(str,"前景点");
		break;
	case 4:

	case 24:
		break;
	}
}

DWORD H[256];
void Histogram()
{
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount + 31)/32*4;
	BYTE * lpBits = (BYTE *)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	int i,j;
	BYTE *pixel;

	for(i = 0; i < 256; i++)
	{
		H[i] = 0;
	}
	for(i = 0; i < h; i ++)
	{
		for(j = 0; j < w; j ++)
		{
			pixel = lpBits + LineBytes * (h - 1 - i) +j;
			H[*pixel] ++;
		}
	}
}
void LineTrans(float a,float b)
{
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount + 31)/32*4;
	BYTE * lpBits = (BYTE *)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];


}
void Equalize()
{
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount + 31)/32*4;
	BYTE * lpBits = (BYTE *)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	int i,j;
	BYTE* pixel;
	int temp;
	BYTE Map[256];

	Histogram();

	for(i = 0; i < 256; i++)
	{
		temp = 0;
		for(j = 0; j <= i; j++)
			temp += H[j];
		Map[i] = (BYTE)(temp * 255 / (w * h) + 0.5);
	}

	for(i = 0; i < h; i++)
	{
		for(j = 0; j < w; j++)
		{
			pixel = lpBits + LineBytes * (h - 1 - i) +j;
			*pixel = Map[*pixel];
		}
	}
}
void FT(complex<double>* TD, complex<double>* FD, int m)
{
	int x,u;
	double angle;
	for (u = 0; u < m; u++)
	{
		FD[u] = 0;
		for (x = 0; x < m; ++x)
		{
			angle = - 2 * PI * u * (x / m);
			FD[u] += TD[x] * complex<double>(cos(angle),sin(angle));
		}
		FD[u] /= m;
	}
}

void IFT(complex<double>* FD, complex<double>* TD, int m)
{
	int x,u;
	double angle;
	for (x = 0; x < m; x ++)
	{
		TD[u] = 0;
		for (u = 0; u < m; ++u)
		{
			angle =  2 * PI * u * x / m;
			TD[x] += FD[u] * complex<double>(cos(angle),sin(angle));
		}
	}
}
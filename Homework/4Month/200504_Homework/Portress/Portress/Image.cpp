#include "Image.h"

HRESULT Image::Init(int width, int height)
{
	HDC hdc = GetDC(g_hWnd); //윈도우를 담당하는 총괄 핸들을 가져온다.

	imageInfo = new IMAGE_INFO; 
	imageInfo->resID = 0; //초기화
	imageInfo->hMemDC = CreateCompatibleDC(hdc); //비트맵 데이터를 담당할 DC를 하나 만들어 준다. hdc : 윈도우를 담당하는 총괄 DC를 넘겨줘야됨.
	imageInfo->hBitmap = CreateCompatibleBitmap(hdc, width, height); //CreateCompatibleBitmap

	//LoadImage : 메모리에 데이터를 올리는 과정. MemDC가 처음 생성된 순간에도 데이터가 있긴 있지만 크기가 엄청 작은 데이터이기 때문에 쓸모가 없고 hMemDC와 hBitmap을 연결해준다.
	imageInfo->hOldBit = (HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap); //둘이 연결해준다. 그걸 hOldBit이 받음.
	imageInfo->width = width;
	imageInfo->height = height;

	ReleaseDC(g_hWnd, hdc); //hdc해제.

	//메모리에 올리는 과정을 실패할 경우.
	if (imageInfo->hBitmap == NULL)
	{
		//메모리 해제 후 fail
		Release();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Image::Init(const DWORD resID, int width, int height, bool trans, COLORREF transColor)
{
	return E_NOTIMPL;
}

HRESULT Image::Init(const char* fileName, int width, int height, bool trans, COLORREF transColor)
{
	HDC hdc = GetDC(g_hWnd); //윈도우를 담당하는 총괄 핸들을 가져온다.

	imageInfo = new IMAGE_INFO;
	imageInfo->resID = 0; //초기화
	imageInfo->hMemDC = CreateCompatibleDC(hdc); //비트맵 데이터를 담당할 DC를 하나 만들어 준다. hdc : 윈도우를 담당하는 총괄 DC를 넘겨줘야됨.
	imageInfo->hBitmap = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE); //g_hInstance : extern으로 빼놓음. LR_LOADFROMFILE : 어디에서 로드가 되는지...
	//hBitmap도 hPen을 해제했던 것 처럼 삭제과정 필요

	//LoadImage : 메모리에 데이터를 올리는 과정. MemDC가 처음 생성된 순간에도 데이터가 있긴 있지만 크기가 엄청 작은 데이터이기 때문에 쓸모가 없고 hMemDC와 hBitmap을 연결해준다.
	imageInfo->hOldBit = (HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap); //둘이 연결해준다. 그걸 hOldBit이 받음.
	imageInfo->width = width;
	imageInfo->height = height;

	ReleaseDC(g_hWnd, hdc); //hdc해제.

	//메모리에 올리는 과정을 실패할 경우.
	if (imageInfo->hBitmap == NULL)
	{
		//메모리 해제 후 fail
		Release();
		return E_FAIL;
	}

	return S_OK;
}

void Image::Release()
{
	if (imageInfo)
	{
		SelectObject(imageInfo->hMemDC, imageInfo->hOldBit); //둘이 연결 해주고

		//해제는 역순으로..
		DeleteObject(imageInfo->hBitmap); 
		DeleteDC(imageInfo->hMemDC);
		delete imageInfo;
	}
}

void Image::Render(HDC hdc, int destX, int desY)
{
	//메모리에 있는 데이터를 화면에 고속복사한다.
	BitBlt(hdc, destX, desY, imageInfo->width, imageInfo->height, imageInfo->hMemDC, 0, 0, SRCCOPY);   //비트단위로 하나하나 복사해주는 것. cx : 복사가 

		     /* 원본 소스를 관리하는 dc 0, 0위치에서 부터 가져 올 것이다. */ //SRCCOPY : 원본에 있는걸 그대로 복사해서
		//SRCPAINT : OR연산 해서 ~ 여러가지 비트연산을 통해 픽셀값을 바꿔 복사할 수 있음.

	/*
	
		BitBlt(hdc,					// 복사 목적지 DC
		destX, destY,				// 복사 시작 위치
		imageInfo->width,			// 원본에서 복사될 가로 크기
		imageInfo->height,			// 원본에서 복사될 세로 크기  
		imageInfo->hMemDC,			// 원본 DC
		0, 0,						// 원본에서 복사 시작위치 
		SRCCOPY);					// 복사 옵션


	*/





	//
}

Image::Image()
{

}

Image::~Image()
{

}

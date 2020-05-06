#include "Image.h"

HRESULT Image::Init(int width, int height)
{
	HDC hdc = GetDC(g_hWnd); //�����츦 ����ϴ� �Ѱ� �ڵ��� �����´�.

	imageInfo = new IMAGE_INFO; 
	imageInfo->resID = 0; //�ʱ�ȭ
	imageInfo->hMemDC = CreateCompatibleDC(hdc); //��Ʈ�� �����͸� ����� DC�� �ϳ� ����� �ش�. hdc : �����츦 ����ϴ� �Ѱ� DC�� �Ѱ���ߵ�.
	imageInfo->hBitmap = CreateCompatibleBitmap(hdc, width, height); //CreateCompatibleBitmap

	//LoadImage : �޸𸮿� �����͸� �ø��� ����. MemDC�� ó�� ������ �������� �����Ͱ� �ֱ� ������ ũ�Ⱑ ��û ���� �������̱� ������ ���� ���� hMemDC�� hBitmap�� �������ش�.
	imageInfo->hOldBit = (HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap); //���� �������ش�. �װ� hOldBit�� ����.
	imageInfo->width = width;
	imageInfo->height = height;

	ReleaseDC(g_hWnd, hdc); //hdc����.

	//�޸𸮿� �ø��� ������ ������ ���.
	if (imageInfo->hBitmap == NULL)
	{
		//�޸� ���� �� fail
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
	HDC hdc = GetDC(g_hWnd); //�����츦 ����ϴ� �Ѱ� �ڵ��� �����´�.

	imageInfo = new IMAGE_INFO;
	imageInfo->resID = 0; //�ʱ�ȭ
	imageInfo->hMemDC = CreateCompatibleDC(hdc); //��Ʈ�� �����͸� ����� DC�� �ϳ� ����� �ش�. hdc : �����츦 ����ϴ� �Ѱ� DC�� �Ѱ���ߵ�.
	imageInfo->hBitmap = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE); //g_hInstance : extern���� ������. LR_LOADFROMFILE : ��𿡼� �ε尡 �Ǵ���...
	//hBitmap�� hPen�� �����ߴ� �� ó�� �������� �ʿ�

	//LoadImage : �޸𸮿� �����͸� �ø��� ����. MemDC�� ó�� ������ �������� �����Ͱ� �ֱ� ������ ũ�Ⱑ ��û ���� �������̱� ������ ���� ���� hMemDC�� hBitmap�� �������ش�.
	imageInfo->hOldBit = (HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap); //���� �������ش�. �װ� hOldBit�� ����.
	imageInfo->width = width;
	imageInfo->height = height;

	ReleaseDC(g_hWnd, hdc); //hdc����.

	//�޸𸮿� �ø��� ������ ������ ���.
	if (imageInfo->hBitmap == NULL)
	{
		//�޸� ���� �� fail
		Release();
		return E_FAIL;
	}

	return S_OK;
}

void Image::Release()
{
	if (imageInfo)
	{
		SelectObject(imageInfo->hMemDC, imageInfo->hOldBit); //���� ���� ���ְ�

		//������ ��������..
		DeleteObject(imageInfo->hBitmap); 
		DeleteDC(imageInfo->hMemDC);
		delete imageInfo;
	}
}

void Image::Render(HDC hdc, int destX, int desY)
{
	//�޸𸮿� �ִ� �����͸� ȭ�鿡 ��Ӻ����Ѵ�.
	BitBlt(hdc, destX, desY, imageInfo->width, imageInfo->height, imageInfo->hMemDC, 0, 0, SRCCOPY);   //��Ʈ������ �ϳ��ϳ� �������ִ� ��. cx : ���簡 

		     /* ���� �ҽ��� �����ϴ� dc 0, 0��ġ���� ���� ���� �� ���̴�. */ //SRCCOPY : ������ �ִ°� �״�� �����ؼ�
		//SRCPAINT : OR���� �ؼ� ~ �������� ��Ʈ������ ���� �ȼ����� �ٲ� ������ �� ����.

	/*
	
		BitBlt(hdc,					// ���� ������ DC
		destX, destY,				// ���� ���� ��ġ
		imageInfo->width,			// �������� ����� ���� ũ��
		imageInfo->height,			// �������� ����� ���� ũ��  
		imageInfo->hMemDC,			// ���� DC
		0, 0,						// �������� ���� ������ġ 
		SRCCOPY);					// ���� �ɼ�


	*/





	//
}

Image::Image()
{

}

Image::~Image()
{

}

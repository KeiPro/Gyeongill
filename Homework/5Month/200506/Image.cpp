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

	isTrans = trans;
	this->transColor = transColor;

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

HRESULT Image::Init(const char * fileName, float x, float y, int width,
	int height, int keyFrameX, int keyFrameY,
	bool trans, COLORREF transColor)
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

	//�߰�
	imageInfo->x = x - (width / 2); // x : �߽���ǥ�� width / 2 ��ŭ ����� �� ������� �ö󰣴�.
	imageInfo->y = y - (height / 2);
	imageInfo->currentKeyFrameX = 0;
	imageInfo->currentKeyFrameY = 0;
	imageInfo->maxKeyFrameX = keyFrameX - 1;
	imageInfo->maxKeyFrameY = keyFrameY - 1;
	imageInfo->keyFrameWidth = width / keyFrameX; // ��ü ũ�� ������ ������ ��
	imageInfo->keyFrameHeight = height / keyFrameY;

	isTrans = trans;
	this->transColor = transColor;

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

void Image::Render(HDC hdc, int destX, int destY)
{
	if (isTrans)
	{ 
		GdiTransparentBlt(hdc, destX, destY, imageInfo->width, imageInfo->height, imageInfo->hMemDC, 0, 0, imageInfo->width, imageInfo->height, transColor);
	}
	else
	{
		//�޸𸮿� �ִ� �����͸� ȭ�鿡 ��Ӻ����Ѵ�.
		BitBlt(hdc, destX, destY, imageInfo->width, imageInfo->height, imageInfo->hMemDC, 0, 0, SRCCOPY);   //��Ʈ������ �ϳ��ϳ� �������ִ� ��. cx : ���簡 

				 /* ���� �ҽ��� �����ϴ� dc 0, 0��ġ���� ���� ���� �� ���̴�. */  //SRCCOPY : ������ �ִ°� �״�� �����ؼ�
			//SRCPAINT : OR���� �ؼ� ~ �������� ��Ʈ������ ���� �ȼ����� �ٲ� ������ �� ����.
	}




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

void Image::FrameRender(HDC hdc, int destX, int destY, int currentKeyFrameX, int currentKeyFrameY, float scale = 1.0f)
{
	// ���� Ű������ �ε����� �ִ� Ű������ �ε������� Ŭ ��
	imageInfo->currentKeyFrameX = currentKeyFrameX;
	imageInfo->currentKeyFrameY = currentKeyFrameY;

	if (imageInfo->currentKeyFrameX > imageInfo->maxKeyFrameX)
	{
		imageInfo->currentKeyFrameX = imageInfo->maxKeyFrameX;
	}	
	
	if (imageInfo->currentKeyFrameY > imageInfo->maxKeyFrameY)
	{
		imageInfo->currentKeyFrameY = imageInfo->maxKeyFrameX;
	}

	if (isTrans)
	{
		GdiTransparentBlt(hdc,
			destX, destY,
			imageInfo->keyFrameWidth * scale,
			imageInfo->keyFrameHeight * scale,
			imageInfo->hMemDC,
			imageInfo->keyFrameWidth * imageInfo->currentKeyFrameX,
			imageInfo->keyFrameHeight * imageInfo->currentKeyFrameY,
			imageInfo->keyFrameWidth,
			imageInfo->keyFrameHeight,
			transColor);
	}
	else
	{
		BitBlt(hdc,
			destX, destY,
			imageInfo->keyFrameWidth,
			imageInfo->keyFrameHeight,
			imageInfo->hMemDC,
			imageInfo->keyFrameWidth * imageInfo->currentKeyFrameX, //currentKeyFrameX,	//currentKeyFrame�� ���� ��ŭ �̵��� ��ġ���� 
			imageInfo->keyFrameHeight * imageInfo->currentKeyFrameY, // currentKeyFrameY,
			SRCCOPY);
	}
	

}

Image::Image()
{

}

Image::~Image()
{

}

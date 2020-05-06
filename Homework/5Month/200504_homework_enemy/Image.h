#pragma once
#include "pch.h"

class Image
{
public:
	enum IMAGE_LOAD_KIND
	{
		RESOURCE, 
		FILE, //�ܺ� ������ �ε��ؼ� �޸𸮿� �ø��� ��.
		EMPTY, //����ִ� ��Ʈ�� ������ �ϳ� ���� ��.
		END 
	};

	typedef struct tagImageInfo
	{
		DWORD	resID;		// ���ҽ��� ������ ���̵�
		HDC		hMemDC;		// �׸��⸦ �ְ��ϴ� �ڵ�(�޸� ����)		--> �޸� �� �ϵ��� �ִ°� �޸𸮿� �ø���. �÷��� �޸� �����ϴ� ��
		HBITMAP	hBitmap;	// �̹��� ����							--> �ȼ��� 300 by300 ������ �� 90000���� ��Ʈ��(�ȼ�) ����.
		HBITMAP	hOldBit;	// ���� �̹��� ����						--> hMEMDC�� �⺻������ ��Ʈ���� ������ �ִµ� �� ��Ʈ���� ũ�Ⱑ ���� �۾� �⺻ ��Ʈ���ε�, �츮�� ũ�Ⱑ ū ��Ʈ���� ��� �� �Ŵϱ� �¸� ���⿡ �ٷ� ���� �� ��� ū ũ�⸦ �ϳ� ���� ����.
		int		width;		// �̹��� ���� ũ��
		int		height;		// �̹��� ���� ũ��
		BYTE	loadType;	// �ε� Ÿ��


		//������ - �ʱ�ȭ
		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBitmap = NULL;
			hOldBit = NULL;
			width = 0;
			height = 0;
			loadType = IMAGE_LOAD_KIND::EMPTY;
		}

	} IMAGE_INFO, *LPIMAGE_INFO;

private:
	IMAGE_INFO* imageInfo;	// �̹��� ������ ���� ����ü ������
	char* fileName;			// ���� ��� + �̸�
	bool isTrans;			// ����ȭ ����
	COLORREF transColor;	// ����ȭ�� ��
	

public:
	// �� ��Ʈ�� �̹����� �����.
	HRESULT Init(int width, int height);

	// ���ҽ��κ��� �����͸� �о �����.
	HRESULT Init(const DWORD resID, int width, int height, bool trans = FALSE, COLORREF transColor = FALSE);

	// ���Ϸκ��� �����͸� �о �����.
	HRESULT Init(const char* fileName, int width, int height, bool trans = FALSE, COLORREF transColor = FALSE);

	// �޸� ����
	void Release();

	void Render(HDC hdc, int destX, int dexY);
	void TransparentBltRender(HDC hdc, int destX, int destY);

	HDC GetMemDC() { return imageInfo->hMemDC; }

	Image();
	~Image();

};


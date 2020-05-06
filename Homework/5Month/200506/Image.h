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

		float	x;						// ����� ��ġ ��ǥ
		float	y;			
		int		currentKeyFrameX;	    // ���� Ű�����ӿ� �ε���
		int		currentKeyFrameY;	
		int		maxKeyFrameX;			// �ִ� Ű ������ ��
		int		maxKeyFrameY;
		int		keyFrameWidth;			// Ű������ �� ũ��.
		int		keyFrameHeight;


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

			x = 0.0f;
			y = 0.0f;
			currentKeyFrameX = 0;
			currentKeyFrameY = 0;
			maxKeyFrameX = 0;
			maxKeyFrameY = 0;
			keyFrameWidth = 0;
			keyFrameHeight = 0;
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

	/////////////////�߰�
	// �̹��� + Ű ������ �ʱ�ȭ
	HRESULT Init(const char* fileName, float x, float y, 
		int width, int height,
		int keyFrameX, int keyFrameY,	//��ü ������
		bool trans = FALSE, COLORREF transColor = FALSE);

	// �޸� ����
	void Release();

	void Render(HDC hdc, int destX, int dexY);
	void FrameRender(HDC hdc, int destX, int destY, int currentKeyFrameX, int currentKeyFrameY, float scale);

	HDC GetMemDC() { return imageInfo->hMemDC; }

	Image();
	~Image();

};


#pragma once
#include "pch.h"

class Image
{
public:
	enum IMAGE_LOAD_KIND
	{
		RESOURCE, 
		FILE, //외부 파일을 로드해서 메모리에 올리는 것.
		EMPTY, //비어있는 비트맵 공간을 하나 만든 것.
		END 
	};

	typedef struct tagImageInfo
	{
		DWORD	resID;		// 리소스의 고유한 아이디
		HDC		hMemDC;		// 그리기를 주관하는 핸들(메모리 관리)		--> 메모리 디씨 하드웨어에 있는걸 메모리에 올린다. 올려서 메모리 관리하는 놈
		HBITMAP	hBitmap;	// 이미지 정보							--> 픽셀이 300 by300 있으면 총 90000개의 비트맵(픽셀) 정보.
		HBITMAP	hOldBit;	// 기존 이미지 정보						--> hMEMDC가 기본적으로 비트맵을 가지고 있는데 그 비트맵이 크기가 아주 작아 기본 비트맵인데, 우리는 크기가 큰 비트맵을 들고 올 거니까 걔를 여기에 바로 넣을 수 없어서 큰 크기를 하나 만들어서 쓴다.
		int		width;		// 이미지 가로 크기
		int		height;		// 이미지 세로 크기
		BYTE	loadType;	// 로드 타입


		//생성자 - 초기화
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
	IMAGE_INFO* imageInfo;	// 이미지 정보에 대한 구조체 포인터
	char* fileName;			// 파일 경로 + 이름
	bool isTrans;			// 투명화 여부
	COLORREF transColor;	// 투명화할 색
	

public:
	// 빈 비트맵 이미지를 만든다.
	HRESULT Init(int width, int height);

	// 리소스로부터 데이터를 읽어서 만든다.
	HRESULT Init(const DWORD resID, int width, int height, bool trans = FALSE, COLORREF transColor = FALSE);

	// 파일로부터 데이터를 읽어서 만든다.
	HRESULT Init(const char* fileName, int width, int height, bool trans = FALSE, COLORREF transColor = FALSE);

	// 메모리 해제
	void Release();

	void Render(HDC hdc, int destX, int dexY);
	void TransparentBltRender(HDC hdc, int destX, int destY);

	HDC GetMemDC() { return imageInfo->hMemDC; }

	Image();
	~Image();

};


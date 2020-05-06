#include "KofPlayer.h"
#include "Image.h"

HRESULT KofPlayer::Init()
{
	posX = WINSIZE_X / 5;
	posY = WINSIZE_Y / 2;

	img = new Image();

	if (FAILED(img->Init("Image/Iori_walk.bmp", posX, posY, 612, 104, 9, 1, true, RGB(255, 0, 255))  )) //HRESULT값에 따라서 얘가 성공했는지 실패 했는지를 반환하는 함수
	{
		MessageBox(g_hWnd, "Image/Iori_walk.bmp 초기화 실패", "KofPlayer.cpp", MB_OK); //윈도우 핸들,

		return E_FAIL;
	}

	currKeyFrameX = 0;
	currKeyFrameY = 0;
	elapsedFrame = 0;

	scale = 1.0f;

	return S_OK;
}

void KofPlayer::Release()
{
	img->Release();
	delete img;
}

void KofPlayer::Update()
{
	elapsedFrame++;
	if (elapsedFrame % 10 == 9)
	{
		currKeyFrameX++;
		elapsedFrame = 0;

		if (currKeyFrameX > 8)
		{
			currKeyFrameX = 0;
		}
	}

}

void KofPlayer::Render(HDC hdc)
{
	if (img)
	{
		img->FrameRender(hdc, posX, posY, currKeyFrameX, currKeyFrameY, scale);
	}
}

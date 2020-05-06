#include "KofPlayer2.h"
#include "Image.h"

HRESULT KofPlayer2::Init()
{
	posX = WINSIZE_X * 2 / 3.0f;
	posY = WINSIZE_Y / 2;

	img = new Image();
	img->Init("Image/Iori_walk.bmp", posX, posY, 612, 104, 9, 1, true, RGB(255, 0, 255));

	currKeyFrameX = 0;
	currKeyFrameY = 0;
	elapsedFrame = 0;

	return S_OK;
}

void KofPlayer2::Release()
{
	img->Release();
	delete img;
}

void KofPlayer2::Update()
{
	if (img)
	{
		elapsedFrame++;
		if (elapsedFrame % 10 == 9)
		{
			elapsedFrame = 0;
			currKeyFrameX++;

			if (currKeyFrameX > 8)
			{
				currKeyFrameX = 0;
			}
		}
	}
}

void KofPlayer2::Render(HDC hdc)
{
	if (img)
	{
		//img->FrameRender(hdc, posX, posY, currKeyFrameX, currKeyFrameY, 3);
	}
}

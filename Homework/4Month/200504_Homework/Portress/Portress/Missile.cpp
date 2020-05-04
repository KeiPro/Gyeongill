#include "Missile.h"
#include "macroFunction.h"

HRESULT Missile::Init()
{
	pos.x = 0;
	pos.y = 0;
	size = 40;
	speed = 1.0f;
	isFire = false;
	angle = 0.0f;

	return S_OK;
}

void Missile::Release()
{
}

void Missile::Update()
{
	if (isFire)
	{
		pos.x += speed * cosf(angle);
		pos.y -= speed * sinf(angle);

		if (pos.x > WINSIZE_X || pos.y <= 0 || pos.y >= WINSIZE_Y)
		{
			isFire = false;
		}
	}
}

void Missile::Render(HDC hdc)
{
	if (isFire)
	{
		RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);
	}
}

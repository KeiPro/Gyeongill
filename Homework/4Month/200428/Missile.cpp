#include "Missile.h"
#include "macroFunction.h"

HRESULT Missile::Init()
{
	pos.x = 0;
	pos.y = 0;
	size = 70;
	angle = PI / 2.0f;
	speed = 5.0f;
	isFire = false;

	return S_OK;
}

void Missile::Release()
{
}

void Missile::Update()
{
	/*

		x * x + y * y = h * h;
		x == x2 - x1;
		y == y2 - y1;

		==> (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1) = h * h;

	*/

	if (isFire == true)
	{
		pos.x += speed * cosf(angle);
		pos.y -= speed * sinf(angle);

		if (pos.x - (size / 2) <= 0) //pos.x는 중점을 기준으로 하므로
		{
			angle = PI - angle;
		}
		else if (pos.x + (size / 2) >= WINSIZE_X)
		{
			angle = PI - angle;
		}
		
		
		if (pos.y - (size / 2) <= 0)
		{
			angle = 2 * PI - angle;
		}
		else if (pos.y + (size / 2) >= WINSIZE_Y)
		{
			angle = 2 * PI - angle;
		}
		
		
		//SetIsFire(false);
	}
}

void Missile::Render(HDC hdc)
{
	if (isFire)
	{
		RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);
	}
}


Missile::~Missile()
{

}

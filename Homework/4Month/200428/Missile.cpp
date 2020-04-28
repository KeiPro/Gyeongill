#include "Missile.h"
#include "macroFunction.h"

HRESULT Missile::Init()
{
	pos.x = 0;
	pos.y = 0;
	size = 10;
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
	if (isFire == true)
	{
		pos.x += speed * cosf(angle);
		pos.y -= speed * sinf(angle);
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

#include "Missile.h"
#include "macroFunction.h"
#include "Enemy.h"

HRESULT Missile::Init()
{
	pos.x = 0;
	pos.y = 0;
	size = 20;
	angle = PI / 2.0f;
	speed = 10.0f;
	tmpSpeed = 5.0f;
	isFire = false;
	isUDoeTan = false;
	minEnemy = nullptr;
	atanAngle = 0;
	tmpAngle = 0;
	targetTimer = 0;

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
		if ( (isUDoeTan == true) && (minEnemy != NULL) )
		{
			targetTimer++;

			if (targetTimer >= 20) //20프레임 이상이 되면 추적을 시작한다.
			{
				atanAngle = GetTanAngle(pos.x, pos.y, minEnemy->GetMyPos().x, minEnemy->GetMyPos().y);

				if (tmpAngle - atanAngle < 0)
				{
					tmpAngle += 0.01f;

					if (tmpAngle - atanAngle >= 0.0f)
					{
						tmpAngle = atanAngle;
					}
				}
				else
				{
					tmpAngle -= 0.01f;
					if (tmpAngle - atanAngle <= 0.0f)
					{
						tmpAngle = atanAngle;
					}
				}
				tmpSpeed += 0.5f;

				pos.x += tmpSpeed * cosf(atanAngle);
				pos.y += tmpSpeed * sinf(tmpAngle);
			}
			else
			{
				pos.x += speed * cosf(angle);
				pos.y -= speed * sinf(angle);
			}	
		}
		else
		{
			pos.x += speed * cosf(angle);
			pos.y -= speed * sinf(angle);
		}
		
		if (pos.x <= 0 || pos.x >= WINSIZE_X || pos.y <= 0)
		{
			SetIsFire(false);
			SetMinEnemy(nullptr);
		}

		//for (int i = 0; i < ENEMYCOUNT; i++)
		//{

		//}

		//if (pos.x - (size / 2) <= 0) //pos.x는 중점을 기준으로 하므로
		//{
		//	angle = PI - angle;
		//}
		//else if (pos.x + (size / 2) >= WINSIZE_X)
		//{
		//	angle = PI - angle;
		//}
		//
		//
		//if (pos.y - (size / 2) <= 0)
		//{
		//	angle = 2 * PI - angle;
		//}
		//else if (pos.y + (size / 2) >= WINSIZE_Y)
		//{
		//	angle = 2 * PI - angle;
		//}
		//
		
		//SetIsFire(false);
	}
}

void Missile::Render(HDC hdc)
{
	if (isFire)
	{
		RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);

		if (minEnemy != NULL)
		{
			MoveToEx(hdc, pos.x, pos.y, NULL);
			LineTo(hdc, minEnemy->GetMyPos().x, minEnemy->GetMyPos().y);
		}
	}
}


Missile::~Missile()
{

}

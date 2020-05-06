#include "Missile.h"
#include "macroFunction.h"
#include "Enemy.h"
#include "Image.h"

HRESULT Missile::Init()
{
	pos.x = 0;
	pos.y = 0;
	size = 40;
	angle = (float)(PI / 2.0f);
	speed = 0.3f;
	isFire = false;

	target = nullptr;
	adjustAngle = 0.0f;


	marble = new Image();
	if (FAILED( marble->Init("����.bmp", size, size) ) ); //HRESULT���� ���� �갡 �����ߴ��� ���� �ߴ����� ��ȯ�ϴ� �Լ�
	{
		return E_FAIL;
	}
	return S_OK;
}

void Missile::Release()
{
	marble->Release();
	delete marble;
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
		if (target)
		{
			float x = target->GetPos().x - pos.x;
			float y = target->GetPos().y - pos.y;

			float targetAngle = atan2(-y, x);

			adjustAngle += 2.0f;

			if (adjustAngle >= 100.0f)
			{
				adjustAngle = 98.0f;
			}
			
			angle += (targetAngle - angle) / (100.0f - adjustAngle); //�������� ���� �� ���� ������ ������ -�� ���ش�.
		}
		
		pos.x += speed * cosf(angle);
		pos.y -= speed * sinf(angle);
	}
}

void Missile::Render(HDC hdc)
{
	if (isFire)
	{
		if (marble)
		{
			marble->Render(hdc, (int)pos.x - size / 2, (int)pos.y - size / 2);
		}

 		//RenderEllipseToCenter(hdc, (int)pos.x, (int)pos.y, size, size);
		
	}
}


Missile::~Missile()
{

}


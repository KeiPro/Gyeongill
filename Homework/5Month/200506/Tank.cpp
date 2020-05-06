#include "Tank.h"
#include "macroFunction.h"
#include "Missile.h"
#include "Enemy.h"
#include "Image.h"

HRESULT Tank::Init()
{
	// ����
	center.x = WINSIZE_X / 2;
	center.y = WINSIZE_Y;
	bodySize = 150;

	// ����
	barrelEnd.x = WINSIZE_X / 2;
	barrelEnd.y = center.y - 150;

	barrelAngle = (float)(PI / 4.0f) ;
	shootTimer = 0; // 30�����ӿ� �� ����.
	
	return S_OK;
}

void Tank::Release()
{

}

void Tank::Update()
{
	// ��ũ�� Ű�Է��� ó���Ѵ�.
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
	{
		barrelAngle += (float)(PI / 180 * 3);
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
	{
		barrelAngle -= (float)(PI / 180 * 3);
	}

	if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_SPACE))
	{
		Fire();
	}

	// ���� �� ��ǥ�� �����Ӹ��� ����Ѵ�.
	barrelEnd.x = center.x + cosf(barrelAngle) * 150; //center x, y��ǥ�� �������� ���� ����� ���ش�.
	barrelEnd.y = center.y - sinf(barrelAngle) * 150;

	//�̻��� ��ġ ������Ʈ
	if (missile) 
	{
		for (int i = 0; i < missileMaxCount; i++)
		{
			missile[i].Update();
		}
	}	
}

//backBuffer->MemDC�� ���� ���̰�,
void Tank::Render(HDC hdc)
{
	// ����
	RenderEllipseToCenter(hdc, (int)center.x, (int)center.y, (int)bodySize, (int)bodySize);

	// ����
	RenderLine(hdc, (int)center.x, (int)center.y, (int)barrelEnd.x, (int)barrelEnd.y);

	if (missile)
	{
		for (int i = 0; i < missileMaxCount; i++)
		{
 			missile[i].Render(hdc);
		}
	}

	
}

void Tank::Fire()
{
	// ���� Ȯ���ؾ� �ϴ� ����?
	for (int i = 0; i < missileMaxCount; i++)
	{
		if (missile[i].GetIsFire() == false)
		{
			missile[i].SetIsFire(true);
			missile[i].SetPos(barrelEnd);
			missile[i].SetAngle(barrelAngle);

			if ( i % 3 == 2 )
			{
				missile[i].SetTarget(target);
			}

			break;
		}
	}
}

Tank::Tank() : missileMaxCount(50)
{
	missile = new Missile[missileMaxCount];

	for (int i = 0; i < missileMaxCount; i++)
	{
		missile[i].Init();
		
	}
}

Tank::~Tank()
{

}


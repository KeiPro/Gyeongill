#pragma once
#include "GameNode.h"

class Missile;
class MainGame;
class Tank : public GameNode
{
private:

	FPOINT pos;
	int size;
	float barrelAngle;
	FPOINT barrelEnd;
	int missileMaxCount; //�ִ� �̻��� ����

	Missile* missile;
	MainGame* mainGame;
	float power; //�Ŀ��� ����ϴ� ����
	int printPower;

	char szText[128];
	

public:
	virtual HRESULT Init(MainGame* _mainGame);		// ��� ���� �ʱ�ȭ, �޸� �Ҵ�
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ���� ���� (������ ����)
	virtual void Render(HDC hdc);	// ������ ���� ��� (�̹���, �ؽ�Ʈ ��)

	void PowerInfoUpdate(HDC hdc);

	float GetPower() { return power; } //���� ���ΰ��ӿ� ��ȯ�ϴ� �Լ�

	void Fire();

	Tank();
	~Tank();
};


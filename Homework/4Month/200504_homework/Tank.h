#pragma once
#include "GameNode.h"

class Missile;
class Tank : public GameNode
{
private:

	FPOINT pos;
	int size;
	float barrelAngle;
	FPOINT barrelEnd;
	int missileMaxCount; //�ִ� �̻��� ����

	Missile* missile;

public:
	virtual HRESULT Init();		// ��� ���� �ʱ�ȭ, �޸� �Ҵ�
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ���� ���� (������ ����)
	virtual void Render(HDC hdc);	// ������ ���� ��� (�̹���, �ؽ�Ʈ ��)

	void Fire();

	Tank();
	~Tank();
};


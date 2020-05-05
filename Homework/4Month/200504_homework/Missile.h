#pragma once
#include "pch.h"
#include "GameNode.h"

class Image;
class MainGame; //���׹̿� ���� ������ ���� ���� ���� ����.
class Enemy;

class Missile : public GameNode
{
private:
	FPOINT pos;
	int size;
	float speed;
	bool isFire;
	float angle;

	int yFrame; //�߷��� ������ ������ �����Ű�� ���� ����

	Image* missileImg;
	MainGame* mainGame;
	Enemy* enemy;

public:

	virtual HRESULT Init(MainGame* _mainGame);			// ��� ���� �ʱ�ȭ, �޸� �Ҵ�
	virtual void Release();			// �޸� ����
	virtual void Update();			// ������ ���� ���� ���� ���� (������ ����)
	virtual void Render(HDC hdc);	// ������ ���� ��� (�̹���, �ؽ�Ʈ ��)

	inline void SetAngle(float _angle) { angle = _angle; }
	inline void SetIsFire(bool _isFire) { isFire = _isFire; }	
	inline void SetPos(FPOINT _pos) { pos = _pos; }
	inline void SetSpeed(float _speed) { speed = _speed; }
	
	int GetSize() { return size; }
	FPOINT GetPos() { return pos; }

	inline bool GetIsFire() { return isFire; }

	

};


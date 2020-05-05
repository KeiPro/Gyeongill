#pragma once
#include "GameNode.h"

class Enemy : public GameNode
{
private:
	FPOINT pos;
	float speed;
	float angle;
	int size;
	
	bool isAlive;

public:

	virtual HRESULT Init();		// ��� ���� �ʱ�ȭ, �޸� �Ҵ�
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ���� ���� (������ ����)
	virtual void Render(HDC hdc);	// ������ ���� ��� (�̹���, �ؽ�Ʈ ��)

	inline int GetSize() { return size; }
	inline FPOINT GetPos() { return pos; }
	inline float GetSpeed() { return speed; }

	inline void SetAlive(bool _isAlive) { isAlive = _isAlive; }
	inline void SetPos(FPOINT _pos) { pos = _pos; }
	inline void SetSpeed(float _speed) { speed = _speed; }

};


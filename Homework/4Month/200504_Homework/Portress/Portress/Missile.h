#pragma once
#include "pch.h"
#include "GameNode.h"

class Missile : public GameNode
{
private:
	FPOINT pos;
	int size;
	float speed;
	bool isFire;
	float angle;

public:

	virtual HRESULT Init();			// ��� ���� �ʱ�ȭ, �޸� �Ҵ�
	virtual void Release();			// �޸� ����
	virtual void Update();			// ������ ���� ���� ���� ���� (������ ����)
	virtual void Render(HDC hdc);	// ������ ���� ��� (�̹���, �ؽ�Ʈ ��)

	inline void SetAngle(float _angle) { angle = _angle; }
	inline void SetIsFire(bool _isFire) { isFire = _isFire; }	
	inline void SetPos(FPOINT _pos) { pos = _pos; }

	inline bool GetIsFire() { return isFire; }


};


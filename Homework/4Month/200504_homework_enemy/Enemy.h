#pragma once
#include "GameNode.h"

class Image;
class Enemy : public GameNode
{
private:
	FPOINT pos;
	float speed;
	float angle;
	int size;
	
	bool isAlive;
	Image* enemyImg;

public:

	virtual HRESULT Init();		// 멤버 변수 초기화, 메모리 할당
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 게임 로직 실행 (데이터 변경)
	virtual void Render(HDC hdc);	// 프레임 단위 출력 (이미지, 텍스트 등)

	inline int GetSize() { return size; }
	inline FPOINT GetPos() { return pos; }
	inline float GetSpeed() { return speed; }

	inline void SetAlive(bool _isAlive) { isAlive = _isAlive; }
	inline void SetPos(FPOINT _pos) { pos = _pos; }
	inline void SetSpeed(float _speed) { speed = _speed; }

};


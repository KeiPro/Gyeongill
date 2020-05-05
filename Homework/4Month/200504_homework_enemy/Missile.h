#pragma once
#include "pch.h"
#include "GameNode.h"

class Image;
class MainGame; //에네미에 대한 정보를 갖고 오기 위해 설정.
class Enemy;

class Missile : public GameNode
{
private:
	FPOINT pos;
	int size;
	float speed;
	bool isFire;
	float angle;

	int yFrame; //중력을 프레임 단위로 적용시키기 위한 변수

	Image* missileImg;
	MainGame* mainGame;
	Enemy* enemy;

public:

	virtual HRESULT Init(MainGame* _mainGame);			// 멤버 변수 초기화, 메모리 할당
	virtual void Release();			// 메모리 해제
	virtual void Update();			// 프레임 단위 게임 로직 실행 (데이터 변경)
	virtual void Render(HDC hdc);	// 프레임 단위 출력 (이미지, 텍스트 등)

	inline void SetAngle(float _angle) { angle = _angle; }
	inline void SetIsFire(bool _isFire) { isFire = _isFire; }	
	inline void SetPos(FPOINT _pos) { pos = _pos; }
	inline void SetSpeed(float _speed) { speed = _speed; }
	
	int GetSize() { return size; }
	FPOINT GetPos() { return pos; }

	inline bool GetIsFire() { return isFire; }

	

};


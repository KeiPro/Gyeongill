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
	int missileMaxCount; //최대 미사일 개수

	Missile* missile;
	MainGame* mainGame;
	float power; //파워를 담당하는 변수
	int printPower;

	char szText[128];
	

public:
	virtual HRESULT Init(MainGame* _mainGame);		// 멤버 변수 초기화, 메모리 할당
	virtual void Release();		// 메모리 해제
	virtual void Update();		// 프레임 단위 게임 로직 실행 (데이터 변경)
	virtual void Render(HDC hdc);	// 프레임 단위 출력 (이미지, 텍스트 등)

	void PowerInfoUpdate(HDC hdc);

	float GetPower() { return power; } //힘을 메인게임에 반환하는 함수

	void Fire();

	Tank();
	~Tank();
};


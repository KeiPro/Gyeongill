#pragma once
#include "GameNode.h"

class Image;
class KofPlayer2 : public GameNode
{
private:
	float posX;
	float posY;
	Image* img;

	int currKeyFrameX;
	int currKeyFrameY;
	int elapsedFrame;

public:

	virtual HRESULT Init() override;		// 멤버 변수 초기화, 메모리 할당
	virtual void Release() override;		// 메모리 해제
	virtual void Update() override;		// 프레임 단위 게임 로직 실행 (데이터 변경)
	virtual void Render(HDC hdc) override;	// 프레임 단위 출력 (이미지, 텍스트 등)
	
};


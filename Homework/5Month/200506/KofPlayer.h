#pragma once
#include "GameNode.h"

class Image;
class KofPlayer : public GameNode
{
private:
	float posX;
	float posY;
	Image* img;
	float scale;

	int currKeyFrameX;
	int currKeyFrameY;
	int elapsedFrame;

public:
	virtual HRESULT Init() override;		//overriding이 제대로 이뤄지지 않은 경우, 문법적으로 잘못 사용 됐을 경우(ex. 매개변수를 잘못 썼다든지...), 
											//오류를 띄워주는 역할을 한다.
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetPosX(float x) { posX = x; }
	void SetPosY(float y) { posY = y; }
	void SetScale(float scale) { this->scale = scale; }

};


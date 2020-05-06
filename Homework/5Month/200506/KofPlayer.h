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
	virtual HRESULT Init() override;		//overriding�� ����� �̷����� ���� ���, ���������� �߸� ��� ���� ���(ex. �Ű������� �߸� ��ٵ���...), 
											//������ ����ִ� ������ �Ѵ�.
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetPosX(float x) { posX = x; }
	void SetPosY(float y) { posY = y; }
	void SetScale(float scale) { this->scale = scale; }

};


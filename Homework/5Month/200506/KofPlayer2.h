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

	virtual HRESULT Init() override;		// ��� ���� �ʱ�ȭ, �޸� �Ҵ�
	virtual void Release() override;		// �޸� ����
	virtual void Update() override;		// ������ ���� ���� ���� ���� (������ ����)
	virtual void Render(HDC hdc) override;	// ������ ���� ��� (�̹���, �ؽ�Ʈ ��)
	
};


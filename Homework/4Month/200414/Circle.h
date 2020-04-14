#pragma once
#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

class Circle
{
private:
	RECT rect;
	int speed;

public:
	void Draw();
	void Move();
	void setCircle();

	Circle(int _left = 0, int _top = 0, int _right = 0, int _bottom = 0) : rect { _left, _top, _right, _bottom }
	{

	}
};


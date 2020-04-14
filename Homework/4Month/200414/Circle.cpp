#include "Circle.h"

void Circle::Draw()
{
	HDC hdc = GetWindowDC(GetForegroundWindow());
	Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

void Circle::Move()
{
	speed = rand() % 10 + 10;
	rect.left += speed;
	rect.right += speed;
}

int main()
{
	Circle c1{ 100, 100, 200, 200 };
	Circle c2{ 100, 200, 150, 250 };
	
	while (1)
	{
		c1.Move();
		c2.Move();
		c1.Draw();
		c2.Draw();


		Sleep(100);
		system("cls");
	}


	return 0;
}
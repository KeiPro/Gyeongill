#include "Time.h"

int main()
{
	Time a;
	cout << sizeof(a) << endl;
	a.hour = 10;
	a.minute = 25;
	//a.Print();

	cout << &a << endl;
	//a.InitTime(5, 15);

	//Time b;
	//b.hour = 26;
	//b.minute = 70;
	//b.Print();
}
/*
	p. 203 ������ ���� ����
*/

//cpp����
#include "CircleRun.h"

int main()
{
	srand(time(NULL));

	CircleRun c[10];

	for (int i = 0; i < 15; i++)
	{
		c[i].rc = { 100, 100 + i * 50, 150, 150 + i * 50 };
	}


	while (1)
	{
		system("cls");
		Sleep(10);

		for (int i = 0; i < 10; i++)
		{
			c[i].speed = rand() % 10;
			c[i].rc.left += c[i].speed;
			c[i].rc.right += c[i].speed;
			c[i].draw();
		}
	}
}

//�������
#pragma once
#include <iostream>
#include <ctime>
#include <windows.h>

class CircleRun
{
public:
	int speed;
	RECT rc;

	void draw();
};

void CircleRun::draw()
{
	HDC hdc = GetWindowDC(GetForegroundWindow());
	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
}


/*
	p.210 1��
*/

// cpp����
#include "Person.h"

int main()
{
	Person person;
	person.name = "��ö��";
	person.age = 21;
	person.setPerson(person.name, person.age);
	person.print();

	return 0;
}

// ��� ����
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	string name;
	int age;

	void setPerson(string name, int age);
	void print();
};

void Person::setPerson(string _name, int _age)
{
	name = _name;
	age = _age;
}

void Person::print()
{
	cout << "�̸� : " << name << endl;
	cout << "���� : " << age << endl;
}

/*
	p.210 2��
*/


// .cpp����
#include "Computer.h"

int main()
{
	//Computer obj = { "���ǽ���ǻ��", 8, 4.2 };
	Computer obj;
	obj.setComputer("���ǽ���ǻ��", 8, 4.2);
	obj.print();

	return 0;
}

// �������

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Computer
{
public:

	string name;
	int ram;
	double cpu_speed;

	void setComputer(string _name, int _Ram, double _cpu_speed);
	void print();
};

void Computer::setComputer(string _name, int _ram, double _cpu_speed)
{
	name = _name;
	ram = _ram;
	cpu_speed = _cpu_speed;
}

void Computer::print()
{
	cout << "�̸�: " << name << endl;
	cout << "RAM: " << ram << endl;
	cout << "CPU �ӵ�: " << cpu_speed << endl;
}

/*
	p. 211 3��
*/


// .cpp����
#include "Sum.h"

int main()
{
	Sum obj;

	int  num1, num2;
	cout << "ù ��° ���� : ";
	cin >> num1;

	cout << "�� ��° ���� : ";
	cin >> num2;

	obj.init(num1, num2);
	cout << "���� ��� : " << obj.add(obj.n1, obj.n2) << endl;

	return 0;
}

// �������
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Sum
{
public:
	int n1, n2;

	void init(int _n1, int _n2);
	int add(int _n1, int _n2);
};

void Sum::init(int _n1, int _n2)
{
	n1 = _n1;
	n2 = _n2;
}

int Sum::add(int _n1, int _n2)
{
	return _n1 + _n2;
}


/*
	p. 211 4��
*/

// .cpp����
#include "Book.h"

int main()
{
	Book obj;
	obj.title = "Great C++";
	obj.author = "Bob";

	cout << "å �̸�: " << obj.title << endl;
	cout << "å ����: " << obj.author << endl;

	return 0;
}

//�������
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
	string title;
	string author;
};

/*
	p. 211 5��
*/

// .cpp����
#include "Dice.h"

int main()
{
	srand(time(NULL));

	Dice dice;
	cout << "�ֻ��� ��=" << dice.roll() << endl;
	cout << "�ֻ��� ��=" << dice.roll() << endl;

	return 0;
}

// �������
#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Dice {
private:
	int face;

public:
	int roll();
};

int Dice::roll()
{


	face = rand() % 6 + 1;
	return face;
}


/*
	p. 212 6��
*/

// .cpp����
#include "Employee.h"

int main()
{
	Employee employee = { "��ö��", 38, 2000000 };
	cout << "Employee1:" << endl;
	cout << employee.name << endl;
	cout << employee.age << endl;
	cout << employee.salary << endl;
}

//�������
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee {

public:
	string name;
	int age;
	int salary;

};

/*
	p. 212 7��
*/

// .cpp����
#include "CellPhone.h"

int main()
{
	CellPhone cellphone;
	cellphone.on = false;
	cellphone.number = "010-3333-8888";
	cellphone.model = "Galaxy";
	cellphone.color = "Black";

	cout << boolalpha;
	cout << "CellPhone1:" << endl;
	cout << cellphone.number << endl;
	cout << cellphone.model << endl;
	cout << cellphone.color << endl;
	cout << cellphone.setOn() << endl;

	return 0;
}

//�������
#pragma once
#include <iostream>
#include <string>

using namespace std;

class CellPhone
{
public:
	bool on;
	string number;
	string model;
	string color;

	bool setOn();
};

bool CellPhone::setOn()
{
	return (!on);
}

/*
	p. 213 8��
*/

// .cpp����
#include "Complex.h"

int main()
{
	Complex complex, complex2;
	complex.realNumber = 5;
	complex.falseNumber = 3;
	complex.print();

	complex2.realNumber = 3;
	complex2.falseNumber = -4;
	complex2.print();

	return 0;
}

//�������
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Complex
{
public:
	double realNumber, falseNumber;

	void print();
};

void Complex::print()
{
	if (falseNumber < 0)
		cout << realNumber << " - " << (-falseNumber) << "i" << endl;
	else
		cout << realNumber << " + " << falseNumber << "i" << endl;

}

/*
	p. 213 9��
*/

//.cpp����
#include "Triangle.h"

int main()
{
	Triangle triangle = { 3, 4 };

	cout << "�غ��� " << triangle.b << "�̰� ���̰� " << triangle.h << "�� �ﰢ���� ����: " << triangle.area();

	return 0;
}

// �������
#pragma once
#include <iostream>

using namespace std;

class Triangle
{
public:
	int b, h;
	float _area;

	float area();
};

float Triangle::area()
{
	return (b * h) / 2.0f;
}


/*
	p. 214 10��
*/

// .cpp����
#include "BankAccount.h"

int main()
{
	BankAccount bankAccount;
	bankAccount.init("9999-5555-4444", 1000000);
	bankAccount.deposit(1000000);
	bankAccount.withdraw(1000000);

	return 0;
}

//�������
#pragma once
#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
	string number;
	int balance;

public:
	void init(string _number, int _balance)
	{
		number = _number;
		balance = _balance;
		cout << "���� �ܾ�: " << balance << endl;
	}

	void deposit(int amount)
	{
		balance += amount;
		cout << "after deposit(" << amount << ") ���� �ܾ�: " << balance << endl;
	}
	void withdraw(int amount)
	{
		balance -= amount;
		cout << "after widthdraw(" << amount << ") ���� �ܾ�: " << balance;
	}
};

/*
	p. 214 11��
*/

// .cpp����
#include "Box.h"

int main()
{
	Box box;
	box.setWidth(6);
	box.setLength(7);
	box.setHeight(5);
	cout << "������ ����: " << box.getVolume() << endl;
}

//�������
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Box
{
	double length;
	double width;
	double height;

public:
	double getVolume()
	{
		cout << "[" << getWidth() << "," << getLength() << "," << getHeight() << "]" << endl;
		return width * length * height;
	}

	double getHeight()
	{
		return height;
	}

	void setHeight(double _height)
	{
		height = _height;
	}

	double getLength()
	{
		return length;
	}

	void setLength(double _length)
	{
		length = _length;
	}

	double getWidth()
	{
		return width;
	}

	void setWidth(double _width)
	{
		width = _width;
	}
};

/*
	p. 215 12��
*/

// .cpp����
#include "Time.h"

int main()
{
	Time time;
	time.setTime(07, 10, 20);
	time.print();

	return 0;
}

// �������
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time
{
private:

	int hour;
	int minute;
	int second;

public:
	void setTime(const int h, const int m, const int s);
	void print() const;
};

void Time::setTime(const int h, const int m, const int s)
{
	hour = h, minute = m, second = s;
}

void Time::print() const
{
	cout << hour << ":" << minute << ":" << second << endl;
}
#pragma once

#include <string>
using namespace std;

// p.244 1번
	class Homework
	{
	private:
		int x, y;

	public:

		//1번
		//Homework(int _x, int _y)
		//{
		//	this->x = _x;
		//	this->y = _y;
		//}
		//~Homework(){};

		Homework(int _x, int _y);
		~Homework();
	};

	//2번 ~ 3번 ~ 4번
	Homework::Homework(int _x = 0, int _y = 0) : x{ _x }, y{_y} //3번
	{
		//2번
		this->x = _x;
		this->y = _y;
	}

	Homework::~Homework()
	{
	
	};


/* 2번 */

class Person
{
private:
	string name;
	int snumber;
	int age;

public:
	Person() { }

	Person(string name, int snum, int age) : name{ name }, snumber{ snum }, age{age}
	{
	
	}

	~Person()
	{}

};

/* 3번 */
class BankAccount
{
private:
	int balance;
	double rate;

public:
	BankAccount(int _balance = 0, double _rate = 0.05) : balance(_balance), rate(_rate)
	{
	
	}

	void deposit(int _balance)
	{
		balance += _balance;
	}

	void withdraw(int _balance)
	{
		balance -= _balance;
	}
};

/* 4번 */
class Dog
{
	string name;
	string breed;
	int age;

public:
	Dog(string name = "", int age = 0)
	{
		this->name = name;
		this->breed = age;
	}

	Dog(string name= "", string breed  = "", int age = 0)
	{
		this->name = name;
		this->breed = breed;
		this->age = age;
	}
};

/* 5번 */
class Cube
{
private:
	double side;
public:

	Cube() : side{0} {

	};

	Cube(int _side)
	{
		this->side = _side;
	}

	double getSide() {
		return side;
	}

	double getVolume() {
		return side * side * side;
	}


};

class Book
{
	string title;
	string author;
public:
	Book(string t, string a)
	{
		title = t;
		author = a;
	}

	string getTitle() {
		return title;
	}

	string getAuthor()
	{
		return author;
	}
};
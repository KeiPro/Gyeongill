#include "Homework.h"

int main()
{
	/* 1�� ����
	Homework Point{100, 200};
	*/

	Book book("Greate C++", "Bob");

	cout << "å �̸�: " << book.getTitle() << endl;
	cout << "å ����: " << book.getAuthor() << endl;

	return 0;
}
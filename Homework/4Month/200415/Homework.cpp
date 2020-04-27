#include "Homework.h"

int main()
{
	/* 1번 문제
	Homework Point{100, 200};
	*/

	Book book("Greate C++", "Bob");

	cout << "책 이름: " << book.getTitle() << endl;
	cout << "책 저자: " << book.getAuthor() << endl;

	return 0;
}
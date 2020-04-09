/* p.127 함수 만들기

	#include <iostream>
	using namespace std;
	int PowFunction(int num);
	int main()
	{
		int num;

		cout << "제곱할 값을 입력해주세요 : ";
		cin >> num;

		cout << "제곱한 값은 : " << PowFunction(num) << "입니다.";

		return 0;
	}

	int PowFunction(int num)
	{
		return num * num;
	}
*/
/*	p.127 중간점검

		1. 함수앞에 void가 있으면 반환값이 없다는 의미이다.
		2. 매개변수, 인수
		3. {} 중괄호

		int multi(int x, int y)
		{
			return x * y;
		}

*/

/*	p.133 ~ 134 swap()함수 만들기

#include <iostream>

using namespace std;

void swap(int& refA, int& refB); //스왑함수 원형

int main()
{
	int a = 10, b = 20;
	swap(a, b);
	cout << "a : " << a << ", b : " << b << endl;

	return 0;
}

void swap(int& a, int& b) //스왑함수
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

*/

/*	p.138 중복함수 만들기 (오버 로딩, 함수의 중복정의)


#include <iostream>

using namespace std;

void Print(int); //정수를 출력하는 함수
void Print(float); //실수를 출력하는 함수
void Print(char); //문자를 출력하는 함수
int absolute(int); //정수버전
float absolute(float); //실수버전

int main()
{
	Print(2);
	Print(9.5f);
	Print('A');

	cout << absolute(2.9f) << endl;
	
	return 0;
}

void Print(int i)
{
	cout << "정수 출력 : " << i << endl;
}

void Print(float i)
{
	cout << "실수 출력 : " << i << endl;
}

void Print(char i)
{
	cout << "문자 출력 : " << i << endl;
}

int absolute(int num)
{
	if (num < 0)
		return -num;
	else
		return num;
}

float absolute(float num)
{
	if (num < 0)
		return -num;
	else
		return num;
}

*/

/*	p. 143

	#include <iostream>
	using namespace std;

	int sum(int a = 0, int b = 0, int c = 0 , int d = 0)
	{
		return a + b + c + d;
	}

	int main()
	{
		cout << "sum(10, 15) = " << sum(10, 15) << endl;
		cout << "sum(10, 25) = " << sum(10, 15, 25) << endl;
		cout << "sum(10, 15, 25, 30) = " << sum(10, 15, 25, 30) << endl;

		return 0;
	}

*/
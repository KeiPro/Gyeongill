/* p.127 �Լ� �����

	#include <iostream>
	using namespace std;
	int PowFunction(int num);
	int main()
	{
		int num;

		cout << "������ ���� �Է����ּ��� : ";
		cin >> num;

		cout << "������ ���� : " << PowFunction(num) << "�Դϴ�.";

		return 0;
	}

	int PowFunction(int num)
	{
		return num * num;
	}
*/
/*	p.127 �߰�����

		1. �Լ��տ� void�� ������ ��ȯ���� ���ٴ� �ǹ��̴�.
		2. �Ű�����, �μ�
		3. {} �߰�ȣ

		int multi(int x, int y)
		{
			return x * y;
		}

*/

/*	p.133 ~ 134 swap()�Լ� �����

#include <iostream>

using namespace std;

void swap(int& refA, int& refB); //�����Լ� ����

int main()
{
	int a = 10, b = 20;
	swap(a, b);
	cout << "a : " << a << ", b : " << b << endl;

	return 0;
}

void swap(int& a, int& b) //�����Լ�
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

*/

/*	p.138 �ߺ��Լ� ����� (���� �ε�, �Լ��� �ߺ�����)


#include <iostream>

using namespace std;

void Print(int); //������ ����ϴ� �Լ�
void Print(float); //�Ǽ��� ����ϴ� �Լ�
void Print(char); //���ڸ� ����ϴ� �Լ�
int absolute(int); //��������
float absolute(float); //�Ǽ�����

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
	cout << "���� ��� : " << i << endl;
}

void Print(float i)
{
	cout << "�Ǽ� ��� : " << i << endl;
}

void Print(char i)
{
	cout << "���� ��� : " << i << endl;
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
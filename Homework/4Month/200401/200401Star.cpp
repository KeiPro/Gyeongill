#include<iostream>

using namespace std;

int main()
{
	/*
		������ ���
		2�ܺ��� 9�ܱ��� ������� ����غ���.
		ex) 2 * 1 = 2
			2 * 2 = 4
			2 * 3 = 6
	*/

	

#pragma region 1) 2�ܺ��� 9�ܱ��� ������� ����غ���.
	////���1
	//for (int i = 2; i < 10; i++)
	//{
	//	for (int j = 1; j < 10; j++)
	//	{
	//		cout << i << " * " << j << " = " << i * j << endl;
	//	}
	//}

	////���2
	//for (int i = 2, j = 1; i < 10; )
	//{
	//	cout << i << " * " << j << " = " << i * j << endl;
	//	j++;
	//	if (j > 9)
	//	{
	//		j = 1;
	//		i++;
	//	}
	//}
#pragma endregion

#pragma region 2) �� ���� �ٹٲ��ؼ� �������.

	////���1
	//for (int i = 2; i < 10; i++)
	//{
	//	for (int j = 1; j < 10; j++)
	//	{
	//		cout << i << " * " << j << " = " << i * j << endl;
	//	}
	//	cout << endl;
	//}

	////���2
	//for (int i = 2, j = 1; i < 10; )
	//{
	//	cout << i << " * " << j << " = " << i * j << endl;
	//	j++;
	//	if (j > 9) //9�ܱ��� �� ����� ���
	//	{
	//		j = 1;
	//		i++;
	//		cout << endl;
	//	}
	//}

#pragma endregion

	//for (int i = 2; i < 10; i += 3)
	//{
	//	cout << "  " << i << "��";
	//	cout << "\t\t   " << i + 1 << "��";
	//	
	//	if (i + 2 == 10)
	//		cout << endl;
	//	else
	//		cout << "\t\t   " << i + 2 << "��" << endl;

	//	for (int j = 1; j < 10; j++)
	//	{
	//		cout << i << " * " << j << " = " << i * j;
	//		cout << "\t" << i+1 << " * " << j << " = " << (i+1) * j;
	//		
	//		if (i + 2 == 10)
	//			cout << endl;
	//		else
	//			cout << "\t"  << i+2 << " * " << j << " = " << (i+2) * j << endl;
	//	}

	//	cout << endl;
	//}

	//for (int j = 2; j < 10; j += 3) 
	//{
	//	for (int i = 1; i <= 9; i++)
	//	{
	//		cout << j << " * " << i << " = " << j * i << "\t" <<
	//			(j + 1) << " * " << i << " = " << (j + 1) * i << " \t";

	//		if (j + 2 != 10)
	//		{
	//			cout << (j + 2) << " * " << i << " = " << (j + 2) * i << endl;
	//		}
	//		else
	//			cout << endl;
	//	}
	//	cout << endl;
	//}

	/*
		1)
			*****
			*****
			*****
			*****
			*****
	*/
	
	//for (int i = 0; i < 25; i++)
	//{
	//	cout << "*";
	//	if ((i+1) % 5 == 0)
	//		cout << endl;
	//}


	/*
		2) 
			*
			**
			***
			****
			*****
	*/

	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j <= i ; j++)
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}

	/*
		3)
			----*
			---**
			--***
			-****
			*****
	*/

	//int i;
	//int j;
	//int count = 0;
	//for (i = 5; i > 0; i--)
	//{
	//	for (j = i; j > 1; j--)
	//	{
	//		count++;
	//		cout << " ";
	//	}

	//	for (int k = 0 ; k < 5-count ; k++ )
	//		cout << "*";
	//	

	//	count = 0;
	//	cout << endl;
	//}

	//for (int i = 5; i > 0; i--)
	//{
	//	for (int j = 1; j < i ; j++)
	//	{
	//		cout << " ";
	//	}

	//	for (int k = 5; k >= i ; k--)
	//	{
	//		cout << "*";
	//	}

	//	cout << endl;
	//}

	/*
		4)
			----*
			---***
			--*****
			-*******
			*********
	*/

	////���1
	//for (int i = 5; i > 0; i--)
	//{
	//	for (int j = i;  j > 1; j--) //�����̽��ٿ� ���� �ݺ���
	//	{
	//		cout << " ";
	//	}

	//	for (int k = 1; k <= 2 * (5 - i) + 1; k++ ) //����� �ݺ���
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}

	////���2
	//for (int j = 0; j < 5; j++)
	//{
	//	for (int i = 0; i < (4-j); i++)
	//	{
	//		cout << " ";
	//	}

	//	for (int i = 0; i < 2*(j+1)-1; i++)
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}

	/*
		5)	
			----*
			---***
			--*****
			-*******
			*********
			-*******
			--*****
			---***
			----* 
	*/

	////���1
	//for (int i = 5; i > 0; i--)
	//{
	//	for (int j = i;  j > 1; j--) //�����̽��ٿ� ���� �ݺ���
	//	{
	//		cout << " ";
	//	}

	//	for (int k = 1; k <= 2 * (5 - i) + 1; k++ ) //����� �ݺ���
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}	
	//
	//for (int i = 4; i > 0; i--)
	//{
	//	for (int j = 0;  j < 5-i; j++) //�����̽��ٿ� ���� �ݺ���
	//	{
	//		cout << " ";
	//	}

	//	for (int k = 1; k <= 2 * i - 1; k++ ) //����� �ݺ���
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}

	////���2
	//for (int i = 0; i < 9; i++)
	//{
	//	if (i < 5)
	//	{
	//		//�پ��
	//		for (int j = 0; j < 4-i ; j++)
	//		{
	//			cout << " ";
	//		}
	//		//�����
	//		for (int k = 1; k <= 2*i+1 ; k++)
	//		{
	//			cout << "*";
	//		}
	//		cout << endl; //�ٹٲ�
	//	}
	//	else
	//	{
	//		//�پ��
	//		for (int j = 0; j < i-4 ; j++ )
	//		{
	//			cout << " ";
	//		}

	//		//�����
	//		for (int k = 1; k <= 9 - 2 * (i-4) ; k++)
	//		{
	//			cout << "*";
	//		}
	//		cout << endl;
	//	}
	//}



	

	return 0;
}
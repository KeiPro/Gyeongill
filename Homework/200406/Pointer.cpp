#include <iostream>
using namespace std;

/*
	1. ������
		
		���� 
		
		1)�̸�	2)��		3)������Ÿ��(ũ��)	 4)�޸��ּ�
		
		& : ������ �޸��ּҸ� �� �� �ִ� ��ȣ

		������? ������ �޸� �ּҸ� �����ϴ� ����

		������ ������ ����ϴ� ����?
			1) ������ �����̳� ��� �Ұ����� �ܺο��� �ش� ������ �����Ͽ� ���� �����ϱ� ���ؼ�(call by reference)
			2) �����Ҵ��� ���ؼ� ��Ÿ�� �� �޸𸮿� �Ҵ�Ǵ� ������ �����ϱ� ���ؼ�


	2. �����Ҵ�
		1) �����Ҵ��� �⺻ ����� ����		
		���� : �� �޸𸮿� �ڷḦ ������ ������ �Ҵ��� ���� ��.
		
		�ڷ���* ������ = new �ڷ���;

		2) Heap Memory�� Stack�޸�
		�� : ���α׷���(���α׷�)�� �����Ӱ� �Ҵ��ϰ� ������ �� �ִ� �޸� ����.
			 ���α׷��� ����Ǹ� �˾Ƽ� ��������� �������� ������ ����ؼ� �����ֱ� ������ �޸� ������ �߻��ϰ� �ȴ�.
		���� : Ư�� ����{} ���� ������ �ӽ÷� �Ҵ�Ǵ� ������ �����ϴ� ����.


			< �����Ҵ� >
			a) �������� ũ�Ⱑ �������� ���� ������ �ڷ���.
			b) ���� �ٸ� ���� {}���� ������ ���� ���� ���� ���� ��.
			c) �������� ũ�Ⱑ �ڵ� ���� ��(��Ÿ��)���� �����Ǿ�� �� ��.

		3) �迭�� �����Ҵ�
		int i;
		cin >> i;

		int tsetNum[i];		// ���� �߻� => �迭 ����� ����� ������� �ʾҴ�.
		
		--> int* pTestNum = new int[i];
		pTestNum[0];
		pTestNum[1] = 10;


		4) 2���� �̻��� �迭�� �����Ҵ�
		int testNum[2][4]; //4���� 2���� �迭
		�����Ҵ� ?
			int* testNums = new int[2][4]; (X)

			int** testNums = new int*[2]; (O) //int�� ������ ������ �޸� �ּҸ� ��� �����ͺ��� //int*[2] <-- ��Ʈ�� ������ 2��


*/

int main()
{
//	//������
//	int a = 10; // (���ø޸�) �̸� : a, �� : 10, ũ�� : 4byte, �޸��ּ� : 0x0018FCAE
//	int* pA;	//�̸� : pA, �� : ���� ����, ũ�� : 4byte(�����ʹ� int, float, double����� '�ּ�'�� ��� ���̹Ƿ� �׻� 4byte�̴�.) �޸��ּ� : ���Ƿ� 0x003F2DCE, 
//
//	pA = &a;	// �� : 0x0018FCAE
//
//	float f = 0.1564f; // 4byte
//	float* pF = &f;
//
//	__int64 bigInt = 12312312312123548947;
//	__int64* pBigInt = &bigInt;

	//cout << a << endl;
	//cout << pA << endl;
	//cout << sizeof(pA) << endl;
	//cout << sizeof(pA) << endl;
	//cout << sizeof(pF) << endl;
	//cout << sizeof(pBigInt) << endl;
	//cout << endl;
	//cout << &a << endl;
	//cout << &pA << endl;

	/*
		�ǽ�.

		�� �ܱ��� ������ ������ cin���� �Է¹޾Ƽ� int inputDan;
		�������� 2�� ~ inputDan�ܱ��� guguData�� ����

		int guguData[?][9];
	*/
 
	//int* guguData = new int; //�� �޸𸮿� 4(int)byte ������ �Ҵ�ȴ�. new�� ����ϸ� �Ҵ�� �޸� �ּҸ� �����Ѵ�.

	//*guguData = 2;

	//int inputDan; //���� �Է��ϼ���

	//cout << "�� �ܱ��� ����ұ��? ";
	//cin >> inputDan;

	//int* length = new int[inputDan];

	//cout << le

	/*
		�ǽ�.
		���� �迭 �Ҵ���(�����Ҵ�)�� �Ἥ ���ڸ� 1 ~ 10���� �Է¹޾�
		�Է� ���� Ƚ����ŭ �����͸� cin���� �Է��Ѵ�.

		1 ~ 10 ������ ���ڸ� �Է��ϸ� �ش� �ε��� �����͸� ����Ѵ�.
		floatŸ��
	*/

	//int whatNumber; //�� �ܱ��� �Է��� ������ ������ ����
	//int* guguData;

	//cout << "�� �ܱ��� ����ұ��?";
	//cin >> whatNumber;


	//
	//int num;
	//int inputNum;
	//int indexPrint;
	//float* index; //�����Ҵ��� �޸� �ּҸ� ����ų ������ ������ �����Ѵ�.

	//cout << "�����͸� �� �� �Է¹����ðڽ��ϱ�? ";
	//cin >> num;

	//index = new float[num]; //���� �Ҵ��� �޸𸮰��� ��ȯ�Ǿ� index�� �� ���� �޴´�.

	//for (int i = 0; i < num; i++)
	//{
	//	cout << "1~10������ ���ڸ� �Է��� �ּ��� :";
	//	cin >> inputNum;
	//	index[i] = inputNum;
	//}

	//while (1)
	//{
	//	cout << "1~10������ �ε��� ��ȣ�� �Է��� �ּ��� : ";
	//	cin >> indexPrint;

	//	for (int i = 0; i < num; i++)
	//	{
	//		if (index[i] == indexPrint)
	//			cout << "�ش� ������ �ε����� " << i << "�Դϴ�.";
	//	}

	//	cout << endl;
	//}


	////������ ���߿� ũ�Ⱑ �������°Ű�
	//int i;
	//int array[10]; //���� �޸𸮿� �Ҵ�

	////�������� ������ ���α׷��� ���ư��� ���߿�(��Ÿ�ӽÿ�) �޸� ũ�⸦ �����ְ� ���� ��. --> �����Ҵ�
	//new int[i]; //�� �޸𸮿� �Ҵ��� ��, ������ ����� �� �ִ�. 
	////�޸� �Ҵ縸 ���� ����̹Ƿ�  �� �޸� �ּҸ� ������ ������ �ʿ��ϴ�.
	//int* array = new int[i]; //�޸𸮿� �����ϱ� ���ؼ�



	//int array2[10][5]; //5���� 10��¥�� �迭�� ����.;

	//int k;
	//int** array3 = new int*[i]; //���� �ּҸ� ����ִ� ������ int*�̰� �� ������ ����Ű�� ���ؼ� *�� ����.
	////�� �迭���� �����迭�� �����ּҸ� �����Ѵ�. �� ���� �����Ҵ��� �� �� �� �Ѵٴ� ��.
	//						   /*�����͸� � ¥���� �ϳ��� �׷����� ������ �迭���� �������� 
	//	cin���� 5�� ������ ������ 5��¥���� �ȴ�.*/
	//
	//for (int j = 0; j < i; j++)
	//{
	//	array3[j] = new int[k];
	//}


	int dan; //��ܱ���?

	cin >> dan;

	int** guguData = new int*[dan];

	for (int i = 0; i < dan-1; i++)
	{
		guguData[i] = new int[9];
		for (int j = 0; j < 9; j++)
		{
			guguData[i][j] = (i + 2) * (j + 1);
		}
	} 

	for (int i = 0; i < dan-1; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << (i + 2) << " * " << (j + 1) << " = " << guguData[i][j] << " ";
		}
		cout << endl;
	}

	delete[] guguData;
		
	return 0;
}
#include <iostream>
using namespace std;

/*
	1. 포인터
		
		변수 
		
		1)이름	2)값		3)데이터타입(크기)	 4)메모리주소
		
		& : 변수의 메모리주소를 알 수 있는 기호

		포인터? 변수의 메모리 주소를 저장하는 변수

		포인터 변수를 사용하는 이유?
			1) 변수의 접근이나 제어가 불가능한 외부에서 해당 변수에 접근하여 값을 제어하기 위해서(call by reference)
			2) 동적할당을 통해서 런타임 때 메모리에 할당되는 변수를 제어하기 위해서


	2. 동적할당
		1) 동적할당의 기본 방법과 개념		
		개념 : 힙 메모리에 자료를 저장할 공간을 할당해 놓는 것.
		
		자료형* 변수명 = new 자료형;

		2) Heap Memory와 Stack메모리
		힙 : 프로그래머(프로그램)이 자유롭게 할당하고 해제할 수 있는 메모리 영역.
			 프로그램이 종료되면 알아서 종료되지만 종료하지 않으면 계속해서 남아있기 때문에 메모리 누수가 발생하게 된다.
		스택 : 특정 구문{} 영역 내에서 임시로 할당되는 변수를 저장하는 영역.


			< 동적할당 >
			a) 데이터의 크기가 일정하지 않은 형태의 자료형.
			b) 서로 다른 구문 {}에서 변수의 값을 같이 쓰고 싶을 때.
			c) 데이터의 크기가 코드 실행 중(런타임)에서 결정되어야 할 때.

		3) 배열의 동적할당
		int i;
		cin >> i;

		int tsetNum[i];		// 에러 발생 => 배열 선언시 상수를 사용하지 않았다.
		
		--> int* pTestNum = new int[i];
		pTestNum[0];
		pTestNum[1] = 10;


		4) 2차원 이상의 배열의 동적할당
		int testNum[2][4]; //4개씩 2개인 배열
		동적할당 ?
			int* testNums = new int[2][4]; (X)

			int** testNums = new int*[2]; (O) //int형 포인터 변수의 메모리 주소를 담는 포인터변수 //int*[2] <-- 인트형 포인터 2개


*/

int main()
{
//	//포인터
//	int a = 10; // (스택메모리) 이름 : a, 값 : 10, 크기 : 4byte, 메모리주소 : 0x0018FCAE
//	int* pA;	//이름 : pA, 값 : 아직 없음, 크기 : 4byte(포인터는 int, float, double등등의 '주소'를 담는 것이므로 항상 4byte이다.) 메모리주소 : 임의로 0x003F2DCE, 
//
//	pA = &a;	// 값 : 0x0018FCAE
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
		실습.

		몇 단까지 저장할 것인지 cin으로 입력받아서 int inputDan;
		구구단을 2단 ~ inputDan단까지 guguData에 저장

		int guguData[?][9];
	*/
 
	//int* guguData = new int; //힙 메모리에 4(int)byte 공간이 할당된다. new를 사용하면 할당된 메모리 주소를 리턴한다.

	//*guguData = 2;

	//int inputDan; //단을 입력하세요

	//cout << "몇 단까지 출력할까요? ";
	//cin >> inputDan;

	//int* length = new int[inputDan];

	//cout << le

	/*
		실습.
		위의 배열 할당방법(동적할당)을 써서 숫자를 1 ~ 10까지 입력받아
		입력 받은 횟수만큼 데이터를 cin으로 입력한다.

		1 ~ 10 사이의 숫자를 입력하면 해당 인덱스 데이터를 출력한다.
		float타입
	*/

	//int whatNumber; //몇 단까지 입력을 받을지 설정할 변수
	//int* guguData;

	//cout << "몇 단까지 출력할까요?";
	//cin >> whatNumber;


	//
	//int num;
	//int inputNum;
	//int indexPrint;
	//float* index; //동적할당의 메모리 주소를 가리킬 포인터 변수를 설정한다.

	//cout << "데이터를 몇 번 입력받으시겠습니까? ";
	//cin >> num;

	//index = new float[num]; //동적 할당한 메모리값이 반환되어 index가 그 값을 받는다.

	//for (int i = 0; i < num; i++)
	//{
	//	cout << "1~10까지의 숫자를 입력해 주세요 :";
	//	cin >> inputNum;
	//	index[i] = inputNum;
	//}

	//while (1)
	//{
	//	cout << "1~10까지의 인덱스 번호를 입력해 주세요 : ";
	//	cin >> indexPrint;

	//	for (int i = 0; i < num; i++)
	//	{
	//		if (index[i] == indexPrint)
	//			cout << "해당 숫자의 인덱스는 " << i << "입니다.";
	//	}

	//	cout << endl;
	//}


	////컴파일 도중에 크기가 정해지는거고
	//int i;
	//int array[10]; //스택 메모리에 할당

	////컴파일이 끝나고 프로그램이 돌아가는 도중에(런타임시에) 메모리 크기를 정해주고 싶은 것. --> 동적할당
	//new int[i]; //힙 메모리에 할당할 땐, 변수를 사용할 수 있다. 
	////메모리 할당만 해준 경우이므로  이 메모리 주소를 저장할 변수가 필요하다.
	//int* array = new int[i]; //메모리에 접근하기 위해서



	//int array2[10][5]; //5개씩 10개짜리 배열을 쓴다.;

	//int k;
	//int** array3 = new int*[i]; //시작 주소를 담고있는 변수가 int*이고 그 변수를 가리키기 위해서 *를 쓴다.
	////각 배열마다 하위배열의 시작주소를 설정한다. 이 말은 동적할당을 한 번 더 한다는 뜻.
	//						   /*포인터를 몇개 짜리를 하나의 그룹으로 할지를 배열에서 정해지고 
	//	cin값이 5가 들어오면 포인터 5개짜리가 된다.*/
	//
	//for (int j = 0; j < i; j++)
	//{
	//	array3[j] = new int[k];
	//}


	int dan; //몇단까지?

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
#include <iostream>

using namespace std;

/*
	1) 함수
		- 같은 데이터 타입의 연속된 데이터를 추상화 : 배열 
		- 데이터들을 하위 속성으로 연관지어서 상위 데이터를 추상화 : 구조체
		- 기능 단위로 코드를 추상화 : 함수

		두 수를 입력받아서 합을 출력하는 코드

		1-1)함수의 기본형태

		'반환값의 데이터타입' '함수이름'('매개변수1', '매개변수2', ...)
		{
			'실행문'

			'return 반환값'
		}

		1-2) C++에서 함수의 기본 사용방식

		컴파일을 할 때 시간을 절약하기 위해서 원형과 정의를 나눈다.
		실제로 런타임에서는 코드 한 줄 한 줄 실행되지만
		컴파일 할 때는 이 함수가 어디서 쓰이고
		그걸 원형을 통해서 연결만 해줌.
		실제 코드가 실행되는건 런타임이지만 컴파일 때 원형을 통해 함수를 연결만 해줘서
		컴파일을 유용하게 해준다.

		(함수의 원형) => int main();

		(함수의 정의) => int main()
						{

						}

		1-3) 함수의 유용성
			- 코드가 극단적으로 간략해진다.
			- 함수명 자체적으로 기능을 나타내기 때문에 코드 관리가 수월해진다.
			- 코드의 국지화, 지역화를 통해서 에러 관리가 수월해진다. ( 함수를 통해 함수 하나만 고치게 되면 함수가 사용된 부분에 대한 에러를 한 방에 처리할 수 있다. )

			함수
			- rand();
			- srand(time(NULL));

	2) 변수의 지역성

		- 함수의 영역 {}로 묶인 구문 안에서 선언 / 초기화된 변수는
		해당 구문이 작동하는 동안에만 메모리 공간을 할당받는다.

		- A함수에서 선언/초기화된 변수는 B함수에서 변경할 수 없다.
			--> 변경하고 싶으면??
				: 포인터를 사용하자. //하드웨어에 직접적으로 접근할 수 있는 것.

				메모리 영역)
				스택 : 중괄호로 묶이는 지역변수.
				힙 : 영역은 동적 할당 new키워드를 사용해서 동적할당할때 사용되는 영역.
				데이터 영역 : 전역변수로 사용될 때. --> 

	스택 .... 힙 .... 데이터 

	** 영웅은 절차적 2 : 영웅은 구조적
	1) 가로 * 세로 타일 사이즈를 원하게 설정할 수 있도록 만들자. (동적 할당)
	2) w, a, s, d이동
	***3) 배열, 구조체, 함수를 최대한 활용해보자.
	4) 전투는 가위 바위 보
	5) 몬스터는 포켓몬스터처럼 랜덤한 인카운터 방식. //이 타일에 들어갔을 때 확률에 따라서 만날수도 있고 안만날수도있고
	6) 타일에 종류가 있다. (숲, 늪, 땅) 마다 만나는 몬스터도 다르다. 숲에서 만나는 얘들 늪에서 만나는 얘들 ... 다 다르게
	7) 플레이어 속성 : 이름 / 최대 HP(레벨에 따라 증가) / 현재 HP / 경험치 / 레벨 / 골드
	8) 물약 : 이름 / 가격 / 회복치
	9) 몬스터 : 이름(포켓몬스터) / 최대 HP / 현재 HP / 획득 경험치 / 획득 골드
	10) 상점 : 아이템 종류
*/

int global = 10; //전역변수 

/*
	1) 변수의 추적이 어려워진다.
	2) 프로그램이 시작된 순간부터 종료될 때까지 계속 메모리에 상주해 있다.

*/



int AddNum(int num1, int num2);
void IsAdult(int age); //성인인지를 판단하는 함수
float AverageCompute(int num1, int num2); //두 정수의 평균을 반환하는 함수

// 함수의 오버로딩
//		: 같은 함수의 이름을 갖고 있더라도 매개변수의 타입이나 개수가 다르면 다른 함수로 처리된다.
void ChangeNum(int* num);					// 변수의 값을 변경하는 함수
void ChangeNum(int* arrName, int arrNum);	// 배열, 해당 인덱스 값을 변경하는 함수
void ChangeNum(float num);



int main()
{
	//int num1, num2;
	//cin >> num1;
	//cin >> num2;

	//// 1) 이름 : sum		2)값 : 15		 3)크기 : 4byte		4)메모리주소 : 1234
	//int sum = AddNum(num1, num2);
	////sum = num1 + num2;

	//cout<< "합 : " << sum << endl;

	//cout << "합 : " << sum << endl;
	//위의 코드를 하나의 함수로 묶을 수 있다.
	//실습, 위의 코드를 AddNum이라는 이름을 가진 함수로 만들어보자.

	////실습1. 나이를 입력하면 미성년자인지 성년인지 텍스트로 알려주는 함수
	//int age;
	//cin >> age;
	//IsAdult(age);

	////실습2. 두 정수를 입력 받아서 평균을 반환하는 함수
	//int num1, num2;
	//float average;
	//cin >> num1;
	//cin >> num2;
	//average = AverageCompute(num1, num2);
	//cout << "두 정수의 평균은 " << average << "입니다." <<endl;
	//cout << "합 : " << AddNum(num1, num2) << endl;

	//int testNum = 50;
	//ChangeNum(&testNum); //call by value

	//cout << testNum << endl;

	int testArray[10];
	

	ChangeNum(testArray, 3);


	return 0;
}

//실습1) 성년인지를 판단하는 하고 출력하는 함수.
void IsAdult(int age)
{
	if (age <= 19)
		cout << "미성년자 입니다." << endl;
	else
		cout << "성인입니다." << endl;
}

//실습2) 두 정수의 평균을 반환하는 함수
float AverageCompute(int num1, int num2)
{
	return (num1 + num2) / 2.0f;
}


void ChangeNum(int* num)
{
	
	*num = 10;
}

void ChangeNum(int* arrName, int arrNum)
{
	*(arrName + arrNum) = 10;

}

void ChangeNum(float num)
{

}

//두 수의 합을 반환하는 함수
int AddNum(int num1, int num2)
{
	// 1) 이름 : sum		2)값 : 15		 3)크기 : 4byte		4)메모리주소 : 2034
	int sum = num1 + num2;

	return sum;
}
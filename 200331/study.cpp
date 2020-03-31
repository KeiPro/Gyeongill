
/*
	연산자
	데이터를 가공(연산)하는 모든 명령에 필요한 것들
	1) 어떤 종류의 연산자들이 있는지?
	2) 연산자들간의 우선순위 : 어떤 순서로 연산이 되는지?
	3) 결합순위 : 좌측부터 연산하는 연산자, 우측부터 연산하는 연산자

	01. 사칙 연산자 : 산술연산자 (좌측부터 연산)
	+ : 더하기
	- : 빼기
	* : 곱하기
	/ : 나누기	11 / 3 == 3 (몫)
	% : 나머지	11 % 3 == 2 (나머지)
	(* == / == %) > (+ == -)

	02. 대입연산자 (우측부터 연산)
	= : 왼쪽 항에 오른쪽 항의 값을 넣어준다(대입한다).

	03. 복합대입연산자
	+= : a += b;	 =>		 a = a + b;
	-= : a -= b;	 =>		 a = a - b;
	*= : a *= b;	 =>		 a = a * b;
	/= : a /= b;	 =>		 a = a / b;
	%= : a %= b;	 =>		 a = a % b;

	변수에 (-)연산자를 붙여서 양, 음수를 바꿀 수 있다.
	int testNum = 10;
	testNum = -testNum; //-10
	testNum -= testNum;	// 0

	간단 실습1 : 임의의 두 정수를 초기화해서 선언하고 복합대입연산자를 활용해서
				두 정수의 나머지값을 출력하세요.

	간단 실습2 : -- 증감연산자를 활용해서 방금전 예제를 복습해보자.

	04. 증감연산자
	특정 변수의 값을 1씩 증가시키거나 감소시킬 때 쓴다.
	변수의 앞이나 뒤에 ++ / -- 를 붙여서 사용한다.

	int i = 10;
	i++		(후위 연산자)
	++i		(전위 연산자)
	i--		(후위 연산자)
	--i		(전위 연산자)

	05. 관계연산자
	두 값을 비교한 결과가 참(1, true)인지 거짓(0, false)인지를 반환하는 연산자

	5 < 3 : 0 (false)
	3 + 2 > 4 : 1 (true)

	< :
	> :
	== : 왼쪽 값과 오른쪽 값이 같으면 1(true)을 반환 다르면 0을 반환
	!= : 왼쪽 값과 오른쪽 값이 같으면 0(false)을 반환 다르면 1을 반환
	<= : 왼쪽 값이 오른쪽 값보다 작거나 같으면 1(true)을 반환
	>= : 왼쪽 값이 오른쪽 값보다 크거나 같으면 1(true)을 반환

	실습 : 200331_이름약자.cpp 프로젝트 새로 작성

	고객의 나이를 입력받아서
	미성년자이면(19살 이하) false, 성년이면 true를 출력

	고객의 나이를 입력하세요 : 20
	성년인가요? : true, false
	주민등록증 발급 대상인가요? : true // <-- 딱 20살일때만
	아홉수 인가요? : false

	cout << boolalpha << endl;

	06. 논리 연산자
	참, 거짓으로 결과가 반환되는 연산자

	&& : 논리곱 (AND)
	A && B : A항목의 결과가 참이고 B항목의 결과도 참이면 1을 반환(true)

	|| : 논리합(OR)
	A || B : A항목의 결과가 참이거나 B항목의 결과가 참이면 1을 반환(true)

	! : 논리 부정(NOT)
	!A : A항목의 결과가 참이면 거짓을 반환하고 거짓이면 참을 반환.

	*난 수
	난수 == random number
	rand();함수 // 랜덤한 값을 리턴하는 함수 0~32767 사이의 정수형 값을 리턴한다. (unsigned short)
	rand()함수 내부에서 seed값이 있어서 이 값에 따라서 랜덤한 수치를 반환한다.
	기본적으로 seed값이 1로 세팅되어 있다.

	srand(); //random()함수의 seed값을 바꿔주는 함수. 
	#include <ctime> --> srand(time(NULL));

	*실습 1
	3 ~ 7 사이의 랜덤한 숫자를 출력하는 프로그램
	rand()%M = 0~M-1까지의 난수를 생성
	rand()%M + N = N ~ (M-1)+N
	N = 3으로 설정하면, M = 5로 설정 => 3~7까지 난수
	
	*실습 2
	최소값 ~ 최대값 사이의 랜덤한 숫자를 출력하는 프로그램
	rand()%(M-N+1)+N

	*실습 3
	컴퓨터가 1~10 사이의 숫자를 임의로 정한다. 
	유저는 1~10사이의 숫자를 입력하여
	맞으면 true 틀리면 false를 출력하는 프로그램을 작성하시오.

	데이터 타입 / 연산자 / (제어구조)

	1) 조건문 : 특정 조건에 따라 실행문을 실행 할지 안할지 제어 : if / switch
	2) 반복문 : 특정 조건에 따라서 실행문을 일정 횟수만큼 반복 실행 : while / for

	1) 조건문
	1-1) if문

	if(조건식)
	{
		실행문1;
	}
	else if(조건식2)
	{
		실행문2;
	}
	else
	{
		실행문3;
	}

	1-2)switch 문

	switch (정수형 변수)
	{
		case 값1:
			실행문1;
			break;

		case 값2:
			실행문2;
			break;

		...

		default:
			
			break;
	}

	2) 반복문
	2-1) while문

	while (조건식)
	{
		실행문;
	}

	2-2) do - while문

	do
	{
		실행문;
	}whlie (조건식)

	2-3) for문

	for ( (1)초기식 ; (2)조건식 ; (4)증감식 )
	{
		(3)실행문;
	}

	(1) 초기식 -> (2) 조건식 -> (3) 실행문 -> (4) 증감식 -> (2)조건식 -> (3)실행문 -> (4)증감식 -> ...
	조건식의 결과값이 false가 될 때 까지 반복
	
	(1) 초기식 : 조건 체크를 위한 변수의 선언과 초기화
	(2) 조건식 : 해당 조건의 리턴 값이 참일 때 중괄호 안의 실행문이 실행된다.
	(3) 실행문 : 조건식이 참일 때 실행되는 구문
	(4) 증감식 : 중괄호 안의 실행문이 실행된 뒤에 초기식에 선언한
				 변수의 값을 증가, 감소 시킨다.
*/



//실습1
	//srand(time(NULL));

	//int randNum;
	//randNum = (rand()%5) + 3;
	//cout << randNum << endl;

#pragma region 실습2

//srand(time(NULL));
//
//int randNum;
//
//int minValue;
//int maxValue;
//
//cout << "최소값 입력 : ";
//cin >> minValue;
//
//cout << "최대값 입력 : ";
//cin >> maxValue;
//
//randNum = rand() % (maxValue - minValue + 1) + minValue;
//
//cout << "임의의 값 : ";
//cout << randNum << endl;

#pragma endregion



#pragma region 실습3 - 방법1
	//srand(time(NULL));

	//int randNum;
	//randNum = rand() % 10 + 1; //1~10까지 랜덤숫자 추출.
	//
	//int inputNumber; //입력 받을 숫자.

	//cout << "컴 : 임의의 숫자가 정해졌습니다." << endl;

	//cin >> inputNumber;

	//if (inputNumber > randNum)
	//{
	//	cout << "컴 : 정답은 " << inputNumber << "보다 작습니다." << endl;

	//	cin >> inputNumber;

	//	if (inputNumber != randNum)
	//	{
	//		cout << "컴 : 정답은 " << randNum << "입니다." << endl;
	//	}
	//	else
	//	{
	//		cout << "컴 : 정답입니다." << endl;
	//	}
	//}
	//else if (inputNumber < randNum)
	//{
	//	cout << "컴 : 정답은 " << inputNumber << "보다 큽니다." << endl;

	//	cin >> inputNumber;

	//	if (inputNumber != randNum)
	//	{
	//		cout << "컴 : 정답은 " << randNum << "입니다." << endl;
	//	}
	//	else
	//	{
	//		cout << "정답입니다." << endl;
	//	}
	//}
	//else
	//{
	//	cout << "정답입니다." << endl;
	//}
#pragma endregion

#pragma region 실습3 - 방법2
srand(time(NULL));

int randNum = rand() % 10 + 1;
int inputNum;

cout << "컴 : 임의의 숫자가 정해졌습니다." << endl;

for (int i = 0; i < 2; i++)
{
	cin >> inputNum;

	if (i == 0)
	{
		if (inputNum > randNum)
		{
			cout << "컴 : 정답은 " << inputNum << "보다 작습니다. " << endl;
		}
		else if (inputNum < randNum)
		{
			cout << "컴 : 정답은 " << inputNum << "보다 큽니다." << endl;
		}
		else
		{
			cout << "정답입니다." << endl;
			break;
		}
	}
	else
	{
		if (inputNum != randNum)
		{
			cout << "컴 : 정답은 " << randNum << "입니다." << endl;
		}
		else
		{
			cout << "정답입니다." << endl;
		}
	}
}

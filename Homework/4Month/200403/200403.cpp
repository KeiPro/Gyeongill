#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct Monster
{
	string name;
	int HP;
	int attackValue;
	float moveSpeed;
};

struct Pirates
{
	string name;
	int hp;
	int attack;
	int defense;
	float speed;
};

struct Student
{
	string name;
	int age;
	float score[4]; //학점
	string sex;
	char graduation; //졸업 가능 여부 O, X로 받는다.
};

int main()
{
	
	/*
		구조체

		배열 / 구조체 / 함수 -> C언어에서 코드 추상화에 사용되는 3가지 요소중 하나이다.
		즉, 코드 추상화를 위한 도구.
		
		여기서 추상화란? 실제 현상(현실 세계)을 간략화와 기호화, 보편화를 통해서 데이터적으로 + 코드적으로 흉내를 낸 것.
		코드 추상화? student1, student2, student3 ........ --> student[] 을 통해 코드를 간소화 시킴 ==> 코드 추상화

		추상화가 중요한 이유 : 코드를 짜는 사람도, 컴파일의 결과물을 이용하는 것도 모두 사람이니까 사람이 인지하기 좋은게 중요하다.

		배열 : 속성이 동일한 여러 개의 데이터를 같은 이름과 연번으로 표현함으로써 추상화를 한다.
		구조체 : 데이터를 특정 단위로 묶어서 추상화를 한다.
		함수 : 코드 특정 기능 단위로 묶어서 추상화를 한다.

		구조체란?
		변수를 모아놓은 묶음 / 변수의 집합체
		구조체는 어떤 경우에 사용하는가?
		특정 변수들이 무언가의 하위 개념으로 묶일 때
		몬스터의 이름, 몬스터의 HP, 몬스터의 공격력, 몬스터의 이동력..... 몬스터라는 하나의 개체를 표현하는 것.

		int num;
		Monster goblin, orc, troll;
		Monster mobs[10];
		Monster slime = { "황금 슬라임", 10, 1, 0.02f };
		// 배열 변수 초기화 방법과 동일하게 초기화 할 수 있다.
		// 메모리 구조가 배열과 똑같으므로.

		구조체를 정의하는 법
		구조체를 사용하는 함수 이전에 정의한다.(해당 함수의 밖에 정의)
	*/

	/*
	//구조체를 안배웠다면?								배웠다면?
			A												B	
	string monsteName[5];
	int monsterHP[5];					========> Monster monsters[5];
	float monsterMoveSpeed[5];
	int monsterAttackValue[5];

	1) 메모리 공간 관점에서 보자.
		A 

	*/

	//Monster monsters[5];
	//monsters[0].name = "홍석훈";
	//monsters[0].HP = 100;
	//monsters[4].moveSpeed = 3.0f;

	/*
		실습.
		Pirates(해적)라는 구조체를 하나 정의한다.
		해적의 속성 : 이름, hp, 공격력, 방어력, 스피드(float)
		lupi라는 이름의 구조체 변수를 선언한 후에
		lupi변수의 각 하위 속성의 값을 입력하고 입력이 끝나면 출력해보자.

		+ 스피드가 3.0f 이상이면
		'이름'의 스피드는 5.0입니다. (빠름)
		'이름'의 스피드는 2.5입니다. (보통)
	*/

	/*
	Pirates lupi;

	cout << "이름 입력 : ";
	cin >> lupi.name;

	cout << "체력 입력 : ";
	cin >> lupi.hp;

	cout << "공격력 입력 : ";
	cin >> lupi.attack;

	cout << "방어력 입력 : ";
	cin >> lupi.defense;

	cout << "스피드 입력 : ";
	cin >> lupi.speed;

	cout << "이름 : " << lupi.name << ", 체력 : " << lupi.hp << ", 공격력 : " 
		<< lupi.attack << ", 방어력 : " << lupi.defense << ", 스피드 : " << lupi.speed << endl;

	if (lupi.speed >= 3.0f)
	{
		cout << "'" << lupi.name << "'" << "의 스피드는 " << lupi.speed << "입니다. (빠름)";
	}
	else
		cout << "'" << lupi.name << "'" << "의 스피드는 " << lupi.speed << "입니다. (느림)";
		*/

#pragma region 실습.
/*
	학생을 구조체화해서 다음 속성을 설정하자.
	이름, 나이, 1~4학년까지의 학점, 성별, 졸업가능여부를 학생의 정보를 cin으로 입력받는다. (3명)

	1) 학생의 번호를 입력하면 (1, 2, 3)
	해당 학생의 프로필이 출력된다.

	2) 학생의 이름을 입력하면
	해당 학생의 프로필이 출력된다.
*/

	Student students[3];
	
	int total;
	for (int i = 0; i < 3; i++)
	{
		cout << " <  입  력  > " << endl;
		cout << "이름 : ";
		cin >> students[i].name;

		cout << "나이 : ";
		cin >> students[i].age;

		total = 0;
		for (int j = 0; j < 4; j++)
		{
			cout << (j+1) << "학년 학점 : ";
			cin >> students[i].score[j];
			total += students[i].score[j];
		}

		cout << "성별(남, 여) : ";
		cin >> students[i].sex;

		students[i].graduation = (total / 4.0) > 2.5f ? 'O' : 'X';

		cout << "입력 완료!" << endl;
		Sleep(1000);
		system("cls");
	}

	int stuNumber; //학생의 번호
	string inputName;

	while (true) 
	{
		cout << "학생 번호를 입력해 주세요(1~3) : ";
		cin >> stuNumber;

		cout << " < 학생 프로필 > " << endl;
		cout << "이름 : " << students[stuNumber - 1].name << endl;
		cout << "나이 : " << students[stuNumber - 1].age << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i+1 << "학년 학점 : " << students[stuNumber - 1].score[i] << endl;
		}
		cout << "성별 : " << students[stuNumber - 1].sex << endl;
		cout << "졸업 가능 여부 : " << students[stuNumber - 1].graduation << endl;

		Sleep(2000);
		system("cls");

		cout << "학생 이름을 입력해 주세요 : ";
		cin >> inputName;

		for (int i = 0; i < 3; i++)
		{
			if (inputName == students[i].name)
			{
				cout << " < 학생 프로필 > " << endl;
				cout << "이름 : " << students[i].name << endl;
				cout << "나이 : " << students[i].age << endl;
				for (int i = 0; i < 4; i++)
				{
					cout << i + 1 << "학년 학점 : " << students[stuNumber - 1].score[i] << endl;
				}
				cout << "성별 : " << students[i].sex << endl;
				cout << "졸업 가능 여부 : " << students[i].graduation << endl;
			}
		}

		Sleep(2000);
		system("cls");
	}


#pragma endregion

	return 0;
}
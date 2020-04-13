#pragma region A ~ Z 임의의 값 문제 출력

/*
실습.
A ~ Z 키 중에 임의의 값을 컴퓨터가 설정한다. --> 65 ~ 90(대문자)
유저는 한 개의 키를 입력해서 설정된 값을 맞춘다.
유저가 입력한 키와 설정된 키가 맞으면 승리
틀리면 남은 기회를 보여주고, 5번 틀리면 정답을 알려주고 게임오버

+ 틀릴 때마다 정답이 입력된 알파벳 앞에 있는 알파벳인지 뒤에 있는 알파벳인지 알려준다.
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>

using namespace std;

int main()
{

	srand(time(NULL));
	char randChar = rand() % (90 - 65 + 1) + 65; //컴퓨터가 설정할 랜덤한 변수
	cout << (char)randChar << endl;
	int remainChance = 5; //남은 기회

	cout << "컴퓨터가 설정한 영문자를 맞춰주세요!" << endl;

	cout << "====================================" << endl;
	cout << endl;

	while (remainChance > 0)
	{
		cout << "< 남은 기회 : " << remainChance << "> " << endl;
		cout << "영문자를 입력해 주세요 : ";
		char inputKey; //입력받는 변수

		inputKey = _getch(); //유저한테 입력받는 코드 //97~122(소문자)
		cout << inputKey << endl;

		//예외처리
		if (!(inputKey >= 'A' && inputKey <= 'Z') && !(inputKey >= 'a' && inputKey <= 'z'))
		{
			cout << "잘못 입력하셨습니다. 다시 입력해 주세요." << endl;
			cout << endl;
			continue;
		}

		if (inputKey == randChar || (inputKey - 32) == randChar)
		{
			cout << "정답입니다!" << endl;
			break; //반복문을 즉시 종료시키는 키워드
		}
		else
		{
			remainChance--;

			if (remainChance <= 0) //게임오버
			{
				cout << endl;
				cout << "게임 오버..." << endl;
				cout << "컴퓨터가 설정한 키는 " << randChar << "입니다." << endl;
			}
			else //틀릴 때
			{
				if (inputKey >= 'a') //소문자 입력 a = 97
				{
					if ((inputKey - 32 > randChar))
					{
						cout << "정답이 입력된 알파벳보다 앞에 있습니다." << endl;
					}
					else if ((inputKey - 32 < randChar))
					{
						cout << "정답이 입력된 알파벳보다 뒤에 있습니다." << endl;
					}
				}
				else //대문자 입력 A = 65
				{
					if ((inputKey > randChar))
					{
						cout << "정답이 입력된 알파벳보다 앞에 있습니다." << endl;
					}
					else if ((inputKey < randChar))
					{
						cout << "정답이 입력된 알파벳보다 뒤에 있습니다." << endl;
					}
				}

			}
		}

		cout << endl;
		cout << "====================================" << endl;
		cout << endl;
	}
}
#pragma endregion
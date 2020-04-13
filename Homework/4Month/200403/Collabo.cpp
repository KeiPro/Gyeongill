﻿#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <malloc.h>

using namespace std;
/*
탈출게임
10 * 10 크기의 맵을 만든다.
w, a, s, d키 입력을 통해서 상하좌우 이동을 한다.
시작지점은 항상(0, 0).
탈출지점은(0, 0)을 제외하고 랜덤한 위치에 생성 = > 탈출구 X 생성.

O#########
##########
##########
##########
######X###
##########
##########
##########
##########
##########
*/

//몬스터 구조체
struct Monster
{
	string name;
	int hp;
	int monX, monY;
};

int main()
{
	srand(time(NULL));

#pragma region EscapeVariable

	const int mapWidth = 10; //맵 크기
	const int mapHeight = 10; //맵 크기
	char map[mapWidth][mapHeight]; //map을 저장할 변수 생성 ( x, y )
	int myXPosition = 0, myYPosition = 0; //나의 x, y좌표
	int myPrevXPosition = 0, myPrevYPosition = 0; //움직일 때마다 전 좌표를 저장하는 변수.
	int storeXPosition = 0, storeYPosition = 0; //상점의 x, y좌표
	char inputKey; //입력받을 문자

#pragma endregion

#pragma region HerosGameVariable

	string heroesName; //히어로 이름
	int heroesHp; //히어로의 체력
	int money = 0; //금액
	int randomGetMoney; //몬스터를 잡을 때 랜덤하게 돈을 받을 변수
	int damage = 1; //영웅의 공격력 

	int difficulty; //난이도
	int monsterCount; //for문을 위한 몬스터 수
	int monsterCountVariable;

	bool positionOverlapCheck; //몬스터의 위치가 겹치는지를 체크하는 변수
	int fightAndRun; //싸울지 도망갈지를 입력받을 변수
	bool victory = false; //몬스터와 싸울 이겼나 졌나를 판단할 변수

	const int SCISSORS = 1; //가위
	const int ROCK = 2; //바위
	const int PAPER = 3; //보
	
	int inputSPR; // 가위, 바위, 보 입력받을 변수
	int portion; //포션의 번호를 입력할 변수
	int randNumber; //컴퓨터가 랜덤하게 가위바위보를 설정할 변수

	//추가변수
	const int difficultyOne = 5; //난이도 1
	const int difficultyTwo = 10; //난이도 2
	const int difficultyThree = 15; //난이도 3
	const int difficultyFour = 20; //난이도 4
	string gyeongillStuName[] = { "김민지", "오창렬", "김민제", "박성진", "김종훈",
		"김영우", "남성은", "홍석훈", "김지욱", "강동균", "박청아", "오세진", "유준혁",
		"남궁혁", "윤영서", "김다로" };
	
	int stuNumberTotal = sizeof(gyeongillStuName) / sizeof(gyeongillStuName[0]); //총 학생의 개수

#pragma endregion
	
	cout << endl;
	cout << " =======================================" << endl;
	cout << "|\t\t\t\t\t|" << endl;
	cout << "|  ♪（ｖ＾＿＾）ｖｖ（＾＿＾ｖ）♪\t|" << endl; 
	cout << "|\t\t\t\t\t|" << endl;
	cout << "|\t  ▶ 영웅은 절차적 ◀ \t\t|" << endl; 
	cout << "|\t\t\t\t\t|" << endl; 
	cout << " =======================================" << endl;
	cout << endl;
	cout << "영웅의 이름을 입력하세요 : "; 
	cin >> heroesName;

	cout << "난이도를 입력하세요(1~10) : ";
	cin >> difficulty;

	heroesHp = ceil((15 - difficulty * 0.5f)); //난이도에 의해 체력부분 설정.

#pragma region 상점 위치 생성

	//탈출구 위치 설정하기. 
	while ((storeXPosition == 0) && (storeYPosition == 0))
	{
		storeXPosition = rand() % mapHeight;
		storeYPosition = rand() % mapWidth;
	}

#pragma endregion
	
#pragma region 난이도 (1~3)
	if (difficulty < 4) //난이도가 4보다 작을 경우 ( 난이도 1 )
	{
		monsterCount = difficultyOne;
		monsterCountVariable = monsterCount;
		Monster monsters[difficultyOne]; //초기화

		cout << endl;
		cout << " * * < 몬스터 좌표설정 > * * " << endl;
		cout << endl;

		//몬스터의 수 만큼 for문을 돌려 이름을 선택한다.
		for (int i = 0; i < monsterCount; i++)
		{
			monsters[i].name = gyeongillStuName[rand() % stuNumberTotal];  //몬스터 이름 설정. 중복이름 가능
			monsters[i].hp = (rand() % 5 + 1); // 1~5중 랜덤으로 체력 부여.
			
#pragma region 몬스터의 좌표를 설정하는 while문

			while (true) //상점 위치인 경우
			{
				positionOverlapCheck = false; //기본을 false로 설정.
				monsters[i].monX = rand() % mapHeight;
				monsters[i].monY = rand() % mapWidth;

				if ((monsters[i].monX == myXPosition && monsters[i].monY == myYPosition) //몬스터가 내 위치인 경우
					|| (monsters[i].monX == storeXPosition && monsters[i].monY == storeYPosition)) //몬스터가 상점 위치인 경우
				{
					continue; //다시 while문으로 돌아가 몬스터의 좌표를 다시 설정한다.
				}

				//몬스터들끼리 좌표가 겹치지 않기 위해 설정. 
				//i==0인 경우는 첫 번째 몬스터를 설정하는 것이므로 다른 몬스터의 위치에 영향을 받지 않는다.
				if (i != 0)
				{
					for (int j = 0; j < i; j++)
					{
						//전에 설정된 몬스터의 위치와 겹칠 경우 if문 안으로 들어간다.
						if (monsters[i].monX == monsters[j].monX && monsters[i].monY == monsters[j].monY)
						{
							positionOverlapCheck = true;
							break;
						}
					}

					//이 if문을 통해 겹치냐는 변수가 true가 되면, continue를 통해 다시 while문을 반복하게 된다.
					if (positionOverlapCheck == true)
						continue;
				}

				break; //몬스터가 내 위치도 아니고, 상점 위치도 아니고, 몬스터들끼리 좌표도 겹치지 않으므로 break를 통해 나간다.
			}

			cout << i << "번 monsters좌표 : " << monsters[i].monX << ", " << monsters[i].monY << endl;
			if (i < 6)
				Sleep(100);
			else if (i < 7)
				Sleep(300);
			else if (i < 8)
				Sleep(400);
			else if (i < 10)
				Sleep(800);
			else
				Sleep(100);

#pragma endregion
		}

#pragma region 단순 텍스트 출력
		cout << endl;
		cout << "< 난이도에 의해 HP와 몬스터를 조정합니다. >" << endl;
		Sleep(1500);

		cout << " - 영웅의 HP : " << heroesHp << endl;

		Sleep(1000);
		cout << " - 몬스터 숫자 : " << monsterCountVariable << endl;
		Sleep(1500);

		cout << " >> 모든 몬스터를 다 잡을때까지 전투는 계속됩니다..." << endl;
		Sleep(2000);

		cout << " >> 잠시만 기다려 주세요. 잠시후 전투가 시작됩니다. ";
		Sleep(3000);

		cout << endl;

#pragma endregion

#pragma region 미로 및 히어로, 상점, 몬스터 위치 저장

		//맵에 내 위치, 탈출구, map을 저장하는 for문.
		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				map[i][j] = '#';
			}
		}

		map[0][0] = 'O'; //내 위치 설정
		map[storeXPosition][storeYPosition] = '$'; //상점표시
		for (int i = 0; i < monsterCount; i++) //몬스터 위치 저장
		{
			map[monsters[i].monX][monsters[i].monY] = 'M';
		}

#pragma endregion

#pragma region 미로 출력 및 움직임 전투.
		while (true)
		{
			system("cls");

			//맵을 계속해서 출력하는 for문
			for (int i = 0; i < mapHeight; i++)
			{
				for (int j = 0; j < mapWidth; j++)
				{
					cout << map[i][j];
				}
				cout << endl;
			}

			cout << endl;
			cout << " * * < 영웅은 절차적 게임 설명 > * * " << endl;
			cout << endl;
			cout << " - 움직임 : w, a, s, d " << endl;
			cout << " - 나의 위치 : O " << endl;
			cout << " - 상점 위치 : $ " << endl;
			cout << " - 몬스터 위치 : M " << endl;
			cout << endl;
			cout << "설명)" << endl;
			cout << "\t1. 영웅을 움직여 몬스터를 모두 잡으면 승리하는 게임입니다. " << endl;
			cout << "\t2. 몬스터와 마주치면 전투와 도망을 선택할 수 있습니다. " << endl;
			cout << "\t\t2-1). 전투를 선택하면 가위바위보 게임을 진행합니다." << endl;
			cout << "\t\t2-2). 도망을 선택하면 전투하기 전 상황으로 돌아가게 됩니다." << endl;
			cout << "\t\t\t( 전투를 하던 중, 도망쳐도 몬스터의 체력은 유지되니 안심하세요!! )" << endl;
			cout << "\t3. 몬스터를 잡으면 돈을 랜덤으로 획득할 수 있습니다." << endl;
			cout << "\t4. 획득한 돈을 가지고 상점에서 공격력을 올리거나 체력을 회복하세요. " << endl;

			inputKey = _getch(); //사용자로부터 입력받는 _getch()함수.

#pragma region 움직임
			switch (inputKey)
			{
			case 'w':

				if (myXPosition == 0) //올라갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					//단순하게 몬스터나 상점이 없으면 이동하는 코드
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myXPosition--;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 'a':

				if (myYPosition == 0) //왼쪽으로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition--;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 's':

				if (myXPosition == mapHeight - 1) //아래로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myXPosition++;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 'd':

				if (myYPosition == mapWidth - 1) //오른쪽으로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition++;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			default:
				continue;
				break;
			}

#pragma endregion

#pragma region 상점
			//상점인지를 체크하는 코드
			if (myXPosition == storeXPosition && myYPosition == storeYPosition)
			{
				//상점에 대한 정보를 출력
				while (true)
				{
					system("cls");
					cout << endl;
					cout << "< 어서오세요~ " << heroesName << "님. 경일상점 입니다. >" << endl;
					cout << endl;
					cout << "=========================================" << endl;
					cout << "| hp   1  회복하기(금액 50원) :\t 1입력\t| " << endl;
					cout << "| hp full 회복하기(금액200원) :\t 2입력\t|" << endl;
					cout << "| 데미지 1증가하기 (금액200원) : 3입력\t| " << endl;
					cout << "| 상점 나가기\t\t\t: 4입력 |" << endl;
					cout << "=========================================" << endl;
					cout << endl;
					cout << " * * < 영 웅 정 보 > * * " << endl;
					cout << endl;
					cout << "< - 이름 : " << heroesName << " > " << endl;
					cout << "< - 공격력 : " << damage << " >" << endl;
					cout << "< - 현재 남은 체력 : " << heroesHp << " >" << endl;
					cout << "< - 남은 몬스터 수 : " << monsterCountVariable << " >" << endl;
					cout << "< - 가진 금액 : " << money << " >" << endl;

					cout << endl;

					cout << "번호를 입력해 주세요 : ";
					cin >> portion;
					if (portion == 1)
					{
						//돈이 없는 경우
						if (money < 50)
						{
							cout << "금액이 부족합니다." << endl;
						}
						//체력이 full인 경우
						else if (heroesHp >= (int)(15 - difficulty * 0.5f))
						{
							cout << "체력이 풀 입니다." << endl;
						}
						//체력이 full이 아니고 돈도 충분한 경우
						else
						{
							money -= 50;
							heroesHp += 1;
							cout << "체력이 1회복 되었습니다. " << endl;
							cout << "현재 체력 : " << heroesHp << endl;
						}
					}
					else if (portion == 2)
					{
						//돈이 없는 경우
						if (money < 200)
						{
							cout << "금액이 부족합니다." << endl;
						}
						//체력이 full인 경우
						else if (heroesHp >= (int)(10 - difficulty * 0.5f))
						{
							cout << "체력이 풀 입니다." << endl;
						}
						//체력이 full이 아니고 돈도 충분한 경우
						else
						{
							money -= 200;
							heroesHp = (int)(15 - difficulty * 0.5f);
							cout << "체력이 풀로 회복되었습니다. " << endl;
							cout << "현재 체력 : " << heroesHp << endl;
						}
					}
					else if (portion == 3)
					{
						if (money < 200)
						{
							cout << "금액이 부족합니다." << endl;
						}
						else
						{
							money -= 200;
							damage++;
							cout << "데미지가 1증가되었습니다." << endl;
						}
					}
					else if (portion == 4)
					{
						cout << "상점에서 나갑니다." << endl;
						Sleep(2000);
						system("cls");
						break;
					}
					else
					{
						cout << "다시 입력해 주세요." << endl;
						Sleep(2000);
						system("cls");
					}

					Sleep(2000);
				}
				myXPosition = myPrevXPosition, myYPosition = myPrevYPosition;
				map[myXPosition][myYPosition] = 'O';
				map[storeXPosition][storeYPosition] = '$';
			}
#pragma endregion

#pragma region 몬스터 전투

			//몬스터인지를 체크하는 코드
			for (int i = 0; i < monsterCount; i++)
			{
				if (myXPosition == monsters[i].monX && myYPosition == monsters[i].monY) //몬스터와 만난 경우.
				{
					victory = false;

					while (true)
					{
						system("cls");
						cout << " < 몬스터 정보 > " << endl;
						cout << "  - 이름 : " << monsters[i].name << endl;
						cout << "  - 체력 : " << monsters[i].hp << endl;
						cout << endl;
						cout << " < 영웅의 정보 > " << endl;
						cout << "  - 이름 : " << heroesName << endl;
						cout << "  - 공격력 : " << damage << endl;
						cout << "  - 체력 : " << heroesHp << endl;
						cout << "  - 보유한 금액 : " << money << endl;
						cout << endl;
						cout << " >> 싸우시겠습니까?(0) 도망가시겠습니까?(1) : ";
						cin >> fightAndRun;

						if (fightAndRun == 1)
							break;
						else if (fightAndRun != 0)
						{
							cout << "다시 입력해 주세요." << endl;
							Sleep(1000);
							continue;
						}

						//가위바위보를 하는 코드
						randNumber = (rand() % 3 + 1); //컴퓨터 가위바위보 선택
						system("cls");
						cout << "전투 시작!!" << endl;
						cout << "가위(1), 바위(2), 보(3) 숫자로 입력 : ";
						cin >> inputSPR;

						if (inputSPR == SCISSORS) //1 내가 가위를 낸 경우
						{
							if (randNumber == SCISSORS) //1
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 가위" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == ROCK) //2
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 바위" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else if (inputSPR == ROCK) //1
						{
							if (randNumber == ROCK) //1
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 바위" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == PAPER) //2
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 보" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250			
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else if (inputSPR == PAPER) //2
						{
							if (randNumber == PAPER) //2
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 보" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == SCISSORS) //1
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 가위" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250		
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else
						{
							cout << "다시 입력해 주세요" << endl;
							Sleep(1500);
							continue;
						}
					}

					if (victory == true)
					{
						break;
					}

					//도망갔으면 굳이 for문을 계속해서 체크하지 않아도 된다.
					if (fightAndRun != 0)
					{
						myXPosition = myPrevXPosition, myYPosition = myPrevYPosition;
						map[myXPosition][myYPosition] = 'O';
						map[monsters[i].monX][monsters[i].monY] = 'M';

						break;
					}

				}
			}

#pragma endregion

#pragma region 승리
			if (monsterCountVariable <= 0)
			{
				cout << endl;
				cout << " ♪（ｖ＾＿＾）ｖｖ（＾＿＾ｖ）♪ " << endl;
				cout << endl;
				cout << heroesName << "님이 모든 몬스터를 처치하고 승리하셨습니다!" << endl;
				cout << "보유한 금액 : " << money << endl;
				cout << "처치한 몬스터 명단 : ";
				for (int i = 0; i < monsterCount; i++)
				{
					if (i == monsterCount - 1)
					{
						cout << monsters[i].name;
					}
					else
					{
						cout << monsters[i].name << ", ";
					}
				}
				cout << endl;
				exit(0);
			}
#pragma endregion

		}

	}
#pragma endregion

#pragma region 난이도 (3~6)
	else if (difficulty < 7) //난이도가 4이상 7미만인 경우 ( 난이도 2 )
	{
		monsterCount = difficultyTwo;
		monsterCountVariable = monsterCount;
		Monster monsters[difficultyTwo];

		cout << endl;
		cout << " * * < 몬스터 좌표설정 > * * " << endl;
		cout << endl;

		//몬스터의 수 만큼 for문을 돌려 이름을 선택한다.
		for (int i = 0; i < monsterCount; i++)
		{
			monsters[i].name = gyeongillStuName[rand() % stuNumberTotal]; //몬스터 이름 설정 중복 가능
			monsters[i].hp = (rand() % 4 + 2); // 2~5중 랜덤으로 체력 부여.

#pragma region 몬스터의 좌표를 설정하는 while문

			while (true) //상점 위치인 경우
			{
				positionOverlapCheck = false; //기본을 false로 설정.
				monsters[i].monX = rand() % mapHeight;
				monsters[i].monY = rand() % mapWidth;

				if ((monsters[i].monX == myXPosition && monsters[i].monY == myYPosition) //몬스터가 내 위치인 경우
					|| (monsters[i].monX == storeXPosition && monsters[i].monY == storeYPosition)) //몬스터가 상점 위치인 경우
				{
					continue; //다시 while문으로 돌아가 몬스터의 좌표를 다시 설정한다.
				}

				//몬스터들끼리 좌표가 겹치지 않기 위해 설정. 
				//i==0인 경우는 첫 번째 몬스터를 설정하는 것이므로 다른 몬스터의 위치에 영향을 받지 않는다.
				if (i != 0)
				{
					for (int j = 0; j < i; j++)
					{
						//전에 설정된 몬스터의 위치와 겹칠 경우 if문 안으로 들어간다.
						if (monsters[i].monX == monsters[j].monX && monsters[i].monY == monsters[j].monY)
						{
							positionOverlapCheck = true;
							break;
						}
					}

					//이 if문을 통해 겹치냐는 변수가 true가 되면, continue를 통해 다시 while문을 반복하게 된다.
					if (positionOverlapCheck == true)
						continue;
				}

				break; //몬스터가 내 위치도 아니고, 상점 위치도 아니고, 몬스터들끼리 좌표도 겹치지 않으므로 break를 통해 나간다.
			}

			cout << i << "번 monsters좌표 : " << monsters[i].monX << ", " << monsters[i].monY << endl;
			if (i < 6)
				Sleep(100);
			else if (i < 7)
				Sleep(300);
			else if (i < 8)
				Sleep(400);
			else if (i < 10)
				Sleep(800);
			else
				Sleep(100);

#pragma endregion
		}

#pragma region 단순 텍스트 출력
		cout << endl;
		cout << "< 난이도에 의해 HP와 몬스터를 조정합니다. >" << endl;
		Sleep(1500);

		cout << " - 영웅의 HP : " << heroesHp << endl;

		Sleep(1000);
		cout << " - 몬스터 숫자 : " << monsterCountVariable << endl;
		Sleep(1500);

		cout << " >> 모든 몬스터를 다 잡을때까지 전투는 계속됩니다..." << endl;
		Sleep(2000);

		cout << " >> 잠시만 기다려 주세요. 잠시후 전투가 시작됩니다. ";
		Sleep(3000);

		cout << endl;

#pragma endregion

#pragma region 미로 및 히어로, 상점, 몬스터 위치 저장

		//맵에 내 위치, 탈출구, map을 저장하는 for문.
		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				map[i][j] = '#';
			}
		}

		map[0][0] = 'O'; //내 위치 설정
		map[storeXPosition][storeYPosition] = '$'; //상점표시
		for (int i = 0; i < monsterCount; i++) //몬스터 위치 저장
		{
			map[monsters[i].monX][monsters[i].monY] = 'M';
		}

#pragma endregion

#pragma region 미로 출력 및 움직임 전투.
		while (true)
		{
			system("cls");

			//맵을 계속해서 출력하는 for문
			for (int i = 0; i < mapHeight; i++)
			{
				for (int j = 0; j < mapWidth; j++)
				{
					cout << map[i][j];
				}
				cout << endl;
			}

			cout << endl;
			cout << " * * < 영웅은 절차적 게임 설명 > * * " << endl;
			cout << endl;
			cout << " - 움직임 : w, a, s, d " << endl;
			cout << " - 나의 위치 : O " << endl;
			cout << " - 상점 위치 : $ " << endl;
			cout << " - 몬스터 위치 : M " << endl;
			cout << endl;
			cout << "설명)" << endl;
			cout << "\t1. 영웅을 움직여 몬스터를 모두 잡으면 승리하는 게임입니다. " << endl;
			cout << "\t2. 몬스터와 마주치면 전투와 도망을 선택할 수 있습니다. " << endl;
			cout << "\t\t2-1). 전투를 선택하면 가위바위보 게임을 진행합니다." << endl;
			cout << "\t\t2-2). 도망을 선택하면 전투하기 전 상황으로 돌아가게 됩니다." << endl;
			cout << "\t\t\t( 전투를 하던 중, 도망쳐도 몬스터의 체력은 유지되니 안심하세요!! )" << endl;
			cout << "\t3. 몬스터를 잡으면 돈을 랜덤으로 획득할 수 있습니다." << endl;
			cout << "\t4. 획득한 돈을 가지고 상점에서 공격력을 올리거나 체력을 회복하세요. " << endl;

			inputKey = _getch(); //사용자로부터 입력받는 _getch()함수.

#pragma region 움직임
			switch (inputKey)
			{
			case 'w':

				if (myXPosition == 0) //올라갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					//단순하게 몬스터나 상점이 없으면 이동하는 코드
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myXPosition--;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 'a':

				if (myYPosition == 0) //왼쪽으로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition--;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 's':

				if (myXPosition == mapHeight - 1) //아래로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myXPosition++;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 'd':

				if (myYPosition == mapWidth - 1) //오른쪽으로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition++;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			default:
				continue;
				break;
			}

#pragma endregion

#pragma region 상점
			//상점인지를 체크하는 코드
			if (myXPosition == storeXPosition && myYPosition == storeYPosition)
			{
				//상점에 대한 정보를 출력
				while (true)
				{
					system("cls");
					cout << endl;
					cout << "< 어서오세요~ " << heroesName << "님. 경일상점 입니다. >" << endl;
					cout << endl;
					cout << "=========================================" << endl;
					cout << "| hp   1  회복하기(금액 50원) :\t 1입력\t| " << endl;
					cout << "| hp full 회복하기(금액200원) :\t 2입력\t|" << endl;
					cout << "| 데미지 1증가하기 (금액200원) : 3입력\t| " << endl;
					cout << "| 상점 나가기\t\t\t: 4입력 |" << endl;
					cout << "=========================================" << endl;
					cout << endl;
					cout << " * * < 영 웅 정 보 > * * " << endl;
					cout << endl;
					cout << "< - 이름 : " << heroesName << " > " << endl;
					cout << "< - 공격력 : " << damage << " >" << endl;
					cout << "< - 현재 남은 체력 : " << heroesHp << " >" << endl;
					cout << "< - 남은 몬스터 수 : " << monsterCountVariable << " >" << endl;
					cout << "< - 가진 금액 : " << money << " >" << endl;

					cout << endl;

					cout << "번호를 입력해 주세요 : ";
					cin >> portion;
					if (portion == 1)
					{
						//돈이 없는 경우
						if (money < 50)
						{
							cout << "금액이 부족합니다." << endl;
						}
						//체력이 full인 경우
						else if (heroesHp >= (int)(15 - difficulty * 0.5f))
						{
							cout << "체력이 풀 입니다." << endl;
						}
						//체력이 full이 아니고 돈도 충분한 경우
						else
						{
							money -= 50;
							heroesHp += 1;
							cout << "체력이 1회복 되었습니다. " << endl;
							cout << "현재 체력 : " << heroesHp << endl;
						}
					}
					else if (portion == 2)
					{
						//돈이 없는 경우
						if (money < 200)
						{
							cout << "금액이 부족합니다." << endl;
						}
						//체력이 full인 경우
						else if (heroesHp >= (int)(10 - difficulty * 0.5f))
						{
							cout << "체력이 풀 입니다." << endl;
						}
						//체력이 full이 아니고 돈도 충분한 경우
						else
						{
							money -= 200;
							heroesHp = (int)(15 - difficulty * 0.5f);
							cout << "체력이 풀로 회복되었습니다. " << endl;
							cout << "현재 체력 : " << heroesHp << endl;
						}
					}
					else if (portion == 3)
					{
						if (money < 200)
						{
							cout << "금액이 부족합니다." << endl;
						}
						else
						{
							money -= 200;
							damage++;
							cout << "데미지가 1증가되었습니다." << endl;
						}
					}
					else if (portion == 4)
					{
						cout << "상점에서 나갑니다." << endl;
						Sleep(2000);
						system("cls");
						break;
					}
					else
					{
						cout << "다시 입력해 주세요." << endl;
						Sleep(2000);
						system("cls");
					}

					Sleep(2000);
				}
				myXPosition = myPrevXPosition, myYPosition = myPrevYPosition;
				map[myXPosition][myYPosition] = 'O';
				map[storeXPosition][storeYPosition] = '$';
			}
#pragma endregion

#pragma region 몬스터 전투

			//몬스터인지를 체크하는 코드
			for (int i = 0; i < monsterCount; i++)
			{
				if (myXPosition == monsters[i].monX && myYPosition == monsters[i].monY) //몬스터와 만난 경우.
				{
					victory = false;

					while (true)
					{
						system("cls");
						cout << " < 몬스터 정보 > " << endl;
						cout << "  - 이름 : " << monsters[i].name << endl;
						cout << "  - 체력 : " << monsters[i].hp << endl;
						cout << endl;
						cout << " < 영웅의 정보 > " << endl;
						cout << "  - 이름 : " << heroesName << endl;
						cout << "  - 공격력 : " << damage << endl;
						cout << "  - 체력 : " << heroesHp << endl;
						cout << "  - 보유한 금액 : " << money << endl;
						cout << endl;
						cout << " >> 싸우시겠습니까?(0) 도망가시겠습니까?(1) : ";
						cin >> fightAndRun;

						if (fightAndRun == 1)
							break;
						else if (fightAndRun != 0)
						{
							cout << "다시 입력해 주세요." << endl;
							Sleep(1000);
							continue;
						}

						//가위바위보를 하는 코드
						randNumber = (rand() % 3 + 1); //컴퓨터 가위바위보 선택
						system("cls");
						cout << "전투 시작!!" << endl;
						cout << "가위(1), 바위(2), 보(3) 숫자로 입력 : ";
						cin >> inputSPR;

						if (inputSPR == SCISSORS) //1 내가 가위를 낸 경우
						{
							if (randNumber == SCISSORS) //1
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 가위" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == ROCK) //2
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 바위" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else if (inputSPR == ROCK) //1
						{
							if (randNumber == ROCK) //1
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 바위" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == PAPER) //2
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 보" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250			
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else if (inputSPR == PAPER) //2
						{
							if (randNumber == PAPER) //2
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 보" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == SCISSORS) //1
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 가위" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250		
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else
						{
							cout << "다시 입력해 주세요" << endl;
							Sleep(1500);
							continue;
						}
					}

					if (victory == true)
					{
						break;
					}

					//도망갔으면 굳이 for문을 계속해서 체크하지 않아도 된다.
					if (fightAndRun != 0)
					{
						myXPosition = myPrevXPosition, myYPosition = myPrevYPosition;
						map[myXPosition][myYPosition] = 'O';
						map[monsters[i].monX][monsters[i].monY] = 'M';

						break;
					}

				}
			}

#pragma endregion

#pragma region 승리
			if (monsterCountVariable <= 0)
			{
				cout << endl;
				cout << " ♪（ｖ＾＿＾）ｖｖ（＾＿＾ｖ）♪ " << endl;
				cout << endl;
				cout << heroesName << "님이 모든 몬스터를 처치하고 승리하셨습니다!" << endl;
				cout << "보유한 금액 : " << money << endl;
				cout << "처치한 몬스터 명단 : ";
				for (int i = 0; i < monsterCount; i++)
				{
					if (i == monsterCount - 1)
					{
						cout << monsters[i].name;
					}
					else
					{
						cout << monsters[i].name << ", ";
					}
				}
				cout << endl;
				exit(0);
			}
#pragma endregion

		}


	}
#pragma endregion

#pragma region 난이도 (7~8)
	else if (difficulty < 9)
	{
		monsterCount = difficultyThree;
		monsterCountVariable = monsterCount;
		Monster monsters[difficultyThree];

		cout << endl;
		cout << " * * < 몬스터 좌표설정 > * * " << endl;
		cout << endl;

		//몬스터의 수 만큼 for문을 돌려 이름을 선택한다.
		for (int i = 0; i < monsterCount; i++)
		{
			
			monsters[i].name = gyeongillStuName[rand() % stuNumberTotal]; //몬스터 이름 설정 중복 가능
			monsters[i].hp = (rand() % 5 + 3); // 3~7중 랜덤으로 체력 부여.

#pragma region 몬스터의 좌표를 설정하는 while문

			while (true) //상점 위치인 경우
			{
				positionOverlapCheck = false; //기본을 false로 설정.
				monsters[i].monX = rand() % mapHeight;
				monsters[i].monY = rand() % mapWidth;

				if ((monsters[i].monX == myXPosition && monsters[i].monY == myYPosition) //몬스터가 내 위치인 경우
					|| (monsters[i].monX == storeXPosition && monsters[i].monY == storeYPosition)) //몬스터가 상점 위치인 경우
				{
					continue; //다시 while문으로 돌아가 몬스터의 좌표를 다시 설정한다.
				}

				//몬스터들끼리 좌표가 겹치지 않기 위해 설정. 
				//i==0인 경우는 첫 번째 몬스터를 설정하는 것이므로 다른 몬스터의 위치에 영향을 받지 않는다.
				if (i != 0)
				{
					for (int j = 0; j < i; j++)
					{
						//전에 설정된 몬스터의 위치와 겹칠 경우 if문 안으로 들어간다.
						if (monsters[i].monX == monsters[j].monX && monsters[i].monY == monsters[j].monY)
						{
							positionOverlapCheck = true;
							break;
						}
					}

					//이 if문을 통해 겹치냐는 변수가 true가 되면, continue를 통해 다시 while문을 반복하게 된다.
					if (positionOverlapCheck == true)
						continue;
				}

				break; //몬스터가 내 위치도 아니고, 상점 위치도 아니고, 몬스터들끼리 좌표도 겹치지 않으므로 break를 통해 나간다.
			}

			cout << i << "번 monsters좌표 : " << monsters[i].monX << ", " << monsters[i].monY << endl;
			if (i < 6)
				Sleep(100);
			else if (i < 7)
				Sleep(300);
			else if (i < 8)
				Sleep(400);
			else if (i < 10)
				Sleep(800);
			else
				Sleep(100);

#pragma endregion
		}

#pragma region 단순 텍스트 출력
		cout << endl;
		cout << "< 난이도에 의해 HP와 몬스터를 조정합니다. >" << endl;
		Sleep(1500);

		cout << " - 영웅의 HP : " << heroesHp << endl;

		Sleep(1000);
		cout << " - 몬스터 숫자 : " << monsterCountVariable << endl;
		Sleep(1500);

		cout << " >> 모든 몬스터를 다 잡을때까지 전투는 계속됩니다..." << endl;
		Sleep(2000);

		cout << " >> 잠시만 기다려 주세요. 잠시후 전투가 시작됩니다. ";
		Sleep(3000);

		cout << endl;

#pragma endregion

#pragma region 미로 및 히어로, 상점, 몬스터 위치 저장

		//맵에 내 위치, 탈출구, map을 저장하는 for문.
		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				map[i][j] = '#';
			}
		}

		map[0][0] = 'O'; //내 위치 설정
		map[storeXPosition][storeYPosition] = '$'; //상점표시
		for (int i = 0; i < monsterCount; i++) //몬스터 위치 저장
		{
			map[monsters[i].monX][monsters[i].monY] = 'M';
		}

#pragma endregion


#pragma region 미로 출력 및 움직임 전투.
		while (true)
		{
			system("cls");

			//맵을 계속해서 출력하는 for문
			for (int i = 0; i < mapHeight; i++)
			{
				for (int j = 0; j < mapWidth; j++)
				{
					cout << map[i][j];
				}
				cout << endl;
			}

			cout << endl;
			cout << " * * < 영웅은 절차적 게임 설명 > * * " << endl;
			cout << endl;
			cout << " - 움직임 : w, a, s, d " << endl;
			cout << " - 나의 위치 : O " << endl;
			cout << " - 상점 위치 : $ " << endl;
			cout << " - 몬스터 위치 : M " << endl;
			cout << endl;
			cout << "설명)" << endl;
			cout << "\t1. 영웅을 움직여 몬스터를 모두 잡으면 승리하는 게임입니다. " << endl;
			cout << "\t2. 몬스터와 마주치면 전투와 도망을 선택할 수 있습니다. " << endl;
			cout << "\t\t2-1). 전투를 선택하면 가위바위보 게임을 진행합니다." << endl;
			cout << "\t\t2-2). 도망을 선택하면 전투하기 전 상황으로 돌아가게 됩니다." << endl;
			cout << "\t\t\t( 전투를 하던 중, 도망쳐도 몬스터의 체력은 유지되니 안심하세요!! )" << endl;
			cout << "\t3. 몬스터를 잡으면 돈을 랜덤으로 획득할 수 있습니다." << endl;
			cout << "\t4. 획득한 돈을 가지고 상점에서 공격력을 올리거나 체력을 회복하세요. " << endl;

			inputKey = _getch(); //사용자로부터 입력받는 _getch()함수.

#pragma region 움직임
			switch (inputKey)
			{
			case 'w':

				if (myXPosition == 0) //올라갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					//단순하게 몬스터나 상점이 없으면 이동하는 코드
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myXPosition--;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 'a':

				if (myYPosition == 0) //왼쪽으로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition--;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 's':

				if (myXPosition == mapHeight - 1) //아래로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myXPosition++;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 'd':

				if (myYPosition == mapWidth - 1) //오른쪽으로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition++;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			default:
				continue;
				break;
			}

#pragma endregion

#pragma region 상점
			//상점인지를 체크하는 코드
			if (myXPosition == storeXPosition && myYPosition == storeYPosition)
			{
				//상점에 대한 정보를 출력
				while (true)
				{
					system("cls");
					cout << endl;
					cout << "< 어서오세요~ " << heroesName << "님. 경일상점 입니다. >" << endl;
					cout << endl;
					cout << "=========================================" << endl;
					cout << "| hp   1  회복하기(금액 50원) :\t 1입력\t| " << endl;
					cout << "| hp full 회복하기(금액200원) :\t 2입력\t|" << endl;
					cout << "| 데미지 1증가하기 (금액200원) : 3입력\t| " << endl;
					cout << "| 상점 나가기\t\t\t: 4입력 |" << endl;
					cout << "=========================================" << endl;
					cout << endl;
					cout << " * * < 영 웅 정 보 > * * " << endl;
					cout << endl;
					cout << "< - 이름 : " << heroesName << " > " << endl;
					cout << "< - 공격력 : " << damage << " >" << endl;
					cout << "< - 현재 남은 체력 : " << heroesHp << " >" << endl;
					cout << "< - 남은 몬스터 수 : " << monsterCountVariable << " >" << endl;
					cout << "< - 가진 금액 : " << money << " >" << endl;

					cout << endl;

					cout << "번호를 입력해 주세요 : ";
					cin >> portion;
					if (portion == 1)
					{
						//돈이 없는 경우
						if (money < 50)
						{
							cout << "금액이 부족합니다." << endl;
						}
						//체력이 full인 경우
						else if (heroesHp >= (int)(15 - difficulty * 0.5f))
						{
							cout << "체력이 풀 입니다." << endl;
						}
						//체력이 full이 아니고 돈도 충분한 경우
						else
						{
							money -= 50;
							heroesHp += 1;
							cout << "체력이 1회복 되었습니다. " << endl;
							cout << "현재 체력 : " << heroesHp << endl;
						}
					}
					else if (portion == 2)
					{
						//돈이 없는 경우
						if (money < 200)
						{
							cout << "금액이 부족합니다." << endl;
						}
						//체력이 full인 경우
						else if (heroesHp >= (int)(10 - difficulty * 0.5f))
						{
							cout << "체력이 풀 입니다." << endl;
						}
						//체력이 full이 아니고 돈도 충분한 경우
						else
						{
							money -= 200;
							heroesHp = (int)(15 - difficulty * 0.5f);
							cout << "체력이 풀로 회복되었습니다. " << endl;
							cout << "현재 체력 : " << heroesHp << endl;
						}
					}
					else if (portion == 3)
					{
						if (money < 200)
						{
							cout << "금액이 부족합니다." << endl;
						}
						else
						{
							money -= 200;
							damage++;
							cout << "데미지가 1증가되었습니다." << endl;
						}
					}
					else if (portion == 4)
					{
						cout << "상점에서 나갑니다." << endl;
						Sleep(2000);
						system("cls");
						break;
					}
					else
					{
						cout << "다시 입력해 주세요." << endl;
						Sleep(2000);
						system("cls");
					}

					Sleep(2000);
				}
				myXPosition = myPrevXPosition, myYPosition = myPrevYPosition;
				map[myXPosition][myYPosition] = 'O';
				map[storeXPosition][storeYPosition] = '$';
			}
#pragma endregion

#pragma region 몬스터 전투

			//몬스터인지를 체크하는 코드
			for (int i = 0; i < monsterCount; i++)
			{
				if (myXPosition == monsters[i].monX && myYPosition == monsters[i].monY) //몬스터와 만난 경우.
				{
					victory = false;

					while (true)
					{
						system("cls");
						cout << " < 몬스터 정보 > " << endl;
						cout << "  - 이름 : " << monsters[i].name << endl;
						cout << "  - 체력 : " << monsters[i].hp << endl;
						cout << endl;
						cout << " < 영웅의 정보 > " << endl;
						cout << "  - 이름 : " << heroesName << endl;
						cout << "  - 공격력 : " << damage << endl;
						cout << "  - 체력 : " << heroesHp << endl;
						cout << "  - 보유한 금액 : " << money << endl;
						cout << endl;
						cout << " >> 싸우시겠습니까?(0) 도망가시겠습니까?(1) : ";
						cin >> fightAndRun;

						if (fightAndRun == 1)
							break;
						else if (fightAndRun != 0)
						{
							cout << "다시 입력해 주세요." << endl;
							Sleep(1000);
							continue;
						}

						//가위바위보를 하는 코드
						randNumber = (rand() % 3 + 1); //컴퓨터 가위바위보 선택
						system("cls");
						cout << "전투 시작!!" << endl;
						cout << "가위(1), 바위(2), 보(3) 숫자로 입력 : ";
						cin >> inputSPR;

						if (inputSPR == SCISSORS) //1 내가 가위를 낸 경우
						{
							if (randNumber == SCISSORS) //1
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 가위" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == ROCK) //2
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 바위" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else if (inputSPR == ROCK) //1
						{
							if (randNumber == ROCK) //1
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 바위" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == PAPER) //2
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 보" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250			
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else if (inputSPR == PAPER) //2
						{
							if (randNumber == PAPER) //2
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 보" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == SCISSORS) //1
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 가위" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250		
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else
						{
							cout << "다시 입력해 주세요" << endl;
							Sleep(1500);
							continue;
						}
					}

					if (victory == true)
					{
						break;
					}

					//도망갔으면 굳이 for문을 계속해서 체크하지 않아도 된다.
					if (fightAndRun != 0)
					{
						myXPosition = myPrevXPosition, myYPosition = myPrevYPosition;
						map[myXPosition][myYPosition] = 'O';
						map[monsters[i].monX][monsters[i].monY] = 'M';

						break;
					}

				}
			}

#pragma endregion

#pragma region 승리
			if (monsterCountVariable <= 0)
			{
				cout << endl;
				cout << " ♪（ｖ＾＿＾）ｖｖ（＾＿＾ｖ）♪ " << endl;
				cout << endl;
				cout << heroesName << "님이 모든 몬스터를 처치하고 승리하셨습니다!" << endl;
				cout << "보유한 금액 : " << money << endl;
				cout << "처치한 몬스터 명단 : ";
				for (int i = 0; i < monsterCount; i++)
				{
					if (i == monsterCount - 1)
					{
						cout << monsters[i].name;
					}
					else
					{
						cout << monsters[i].name << ", ";
					}
				}
				cout << endl;
				exit(0);
			}
#pragma endregion

		}

	}
#pragma endregion

#pragma region 난이도 (9~10)
	else //난이도 9, 10
	{
		monsterCount = difficultyFour;
		monsterCountVariable = monsterCount;
		Monster monsters[difficultyFour];

		cout << endl;
		cout << " * * < 몬스터 좌표설정 > * * " << endl;
		cout << endl;
		//몬스터의 수 만큼 for문을 돌려 이름을 선택한다.
		for (int i = 0; i < monsterCount; i++)
		{
			
			monsters[i].name = gyeongillStuName[rand() % stuNumberTotal]; //몬스터 이름 설정 중복 가능
			monsters[i].hp = (rand() % 5 + 4); // 4~8중 랜덤으로 체력 부여.

#pragma region 몬스터의 좌표를 설정하는 while문

			while (true) //상점 위치인 경우
			{
				positionOverlapCheck = false; //기본을 false로 설정.
				monsters[i].monX = rand() % mapHeight;
				monsters[i].monY = rand() % mapWidth;

				if ((monsters[i].monX == myXPosition && monsters[i].monY == myYPosition) //몬스터가 내 위치인 경우
					|| (monsters[i].monX == storeXPosition && monsters[i].monY == storeYPosition)) //몬스터가 상점 위치인 경우
				{
					continue; //다시 while문으로 돌아가 몬스터의 좌표를 다시 설정한다.
				}

				//몬스터들끼리 좌표가 겹치지 않기 위해 설정. 
				//i==0인 경우는 첫 번째 몬스터를 설정하는 것이므로 다른 몬스터의 위치에 영향을 받지 않는다.
				if (i != 0)
				{
					for (int j = 0; j < i; j++)
					{
						//전에 설정된 몬스터의 위치와 겹칠 경우 if문 안으로 들어간다.
						if (monsters[i].monX == monsters[j].monX && monsters[i].monY == monsters[j].monY)
						{
							positionOverlapCheck = true;
							break;
						}
					}

					//이 if문을 통해 겹치냐는 변수가 true가 되면, continue를 통해 다시 while문을 반복하게 된다.
					if (positionOverlapCheck == true)
						continue;
				}

				break; //몬스터가 내 위치도 아니고, 상점 위치도 아니고, 몬스터들끼리 좌표도 겹치지 않으므로 break를 통해 나간다.
			}

			cout << i << "번 monsters좌표 : " << monsters[i].monX << ", " << monsters[i].monY << endl;
			if (i < 6)
				Sleep(100);
			else if (i < 7)
				Sleep(300);
			else if (i < 8)
				Sleep(400);
			else if (i < 10)
				Sleep(800);
			else
				Sleep(100);

#pragma endregion

		}
#pragma region 단순 텍스트 출력
		cout << endl;
		cout << "< 난이도에 의해 HP와 몬스터를 조정합니다. >" << endl;
		Sleep(1500);

		cout << " - 영웅의 HP : " << heroesHp << endl;

		Sleep(1000);
		cout << " - 몬스터 숫자 : " << monsterCountVariable << endl;
		Sleep(1500);

		cout << " >> 모든 몬스터를 다 잡을때까지 전투는 계속됩니다..." << endl;
		Sleep(2000);

		cout << " >> 잠시만 기다려 주세요. 잠시후 전투가 시작됩니다. ";
		Sleep(3000);

		cout << endl;

#pragma endregion

#pragma region 미로 및 히어로, 상점, 몬스터 위치 저장

		//맵에 내 위치, 탈출구, map을 저장하는 for문.
		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				map[i][j] = '#';
			}
		}

		map[0][0] = 'O'; //내 위치 설정
		map[storeXPosition][storeYPosition] = '$'; //상점표시
		for (int i = 0; i < monsterCount; i++) //몬스터 위치 저장
		{
			map[monsters[i].monX][monsters[i].monY] = 'M';
		}
		
#pragma endregion

#pragma region 미로 출력 및 움직임 전투.
		while (true)
		{
			system("cls");

			//맵을 계속해서 출력하는 for문
			for (int i = 0; i < mapHeight; i++)
			{
				for (int j = 0; j < mapWidth; j++)
				{
					cout << map[i][j];
				}
				cout << endl;
			}

			cout << endl;
			cout << " * * < 영웅은 절차적 게임 설명 > * * " << endl;
			cout << endl;
			cout << " - 움직임 : w, a, s, d " << endl;
			cout << " - 나의 위치 : O " << endl;
			cout << " - 상점 위치 : $ " << endl;
			cout << " - 몬스터 위치 : M " << endl;
			cout << endl;
			cout << "설명)" << endl;
			cout << "\t1. 영웅을 움직여 몬스터를 모두 잡으면 승리하는 게임입니다. " << endl;
			cout << "\t2. 몬스터와 마주치면 전투와 도망을 선택할 수 있습니다. " << endl;
			cout << "\t\t2-1). 전투를 선택하면 가위바위보 게임을 진행합니다." << endl;
			cout << "\t\t2-2). 도망을 선택하면 전투하기 전 상황으로 돌아가게 됩니다." << endl;
			cout << "\t\t\t( 전투를 하던 중, 도망쳐도 몬스터의 체력은 유지되니 안심하세요!! )" << endl;
			cout << "\t3. 몬스터를 잡으면 돈을 랜덤으로 획득할 수 있습니다." << endl;
			cout << "\t4. 획득한 돈을 가지고 상점에서 공격력을 올리거나 체력을 회복하세요. " << endl;

			inputKey = _getch(); //사용자로부터 입력받는 _getch()함수.

#pragma region 움직임
			switch (inputKey)
			{
			case 'w':

				if (myXPosition == 0) //올라갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					//단순하게 몬스터나 상점이 없으면 이동하는 코드
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myXPosition--;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 'a':

				if (myYPosition == 0) //왼쪽으로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition--;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 's':

				if (myXPosition == mapHeight - 1) //아래로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myXPosition++;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 'd':

				if (myYPosition == mapWidth - 1) //오른쪽으로 갈 곳이 없으면 계속해서 while문을 돌린다.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition++;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			default:
				continue;
				break;
			}
			
#pragma endregion

#pragma region 상점
			//상점인지를 체크하는 코드
			if (myXPosition == storeXPosition && myYPosition == storeYPosition)
			{
				//상점에 대한 정보를 출력
				while (true)
				{
					system("cls");
					cout << endl;
					cout << "< 어서오세요~ " << heroesName << "님. 경일상점 입니다. >" << endl;
					cout << endl;
					cout << "=========================================" << endl;
					cout << "| hp   1  회복하기(금액 50원) :\t 1입력\t| " << endl;
					cout << "| hp full 회복하기(금액200원) :\t 2입력\t|" << endl;
					cout << "| 데미지 1증가하기 (금액200원) : 3입력\t| " << endl;
					cout << "| 상점 나가기\t\t\t: 4입력 |" << endl;
					cout << "=========================================" << endl;
					cout << endl;
					cout << " * * < 영 웅 정 보 > * * " << endl;
					cout << endl;
					cout << "< - 이름 : " << heroesName << " > " << endl;
					cout << "< - 공격력 : " << damage << " >" << endl;
					cout << "< - 현재 남은 체력 : " << heroesHp << " >" << endl;
					cout << "< - 남은 몬스터 수 : " << monsterCountVariable << " >" << endl;
					cout << "< - 가진 금액 : " << money << " >" << endl;

					cout << endl;

					cout << "번호를 입력해 주세요 : ";
					cin >> portion;
					if (portion == 1)
					{
						//돈이 없는 경우
						if (money < 50)
						{
							cout << "금액이 부족합니다." << endl;
						}
						//체력이 full인 경우
						else if (heroesHp >= (int)(15 - difficulty * 0.5f))
						{
							cout << "체력이 풀 입니다." << endl;
						}
						//체력이 full이 아니고 돈도 충분한 경우
						else
						{
							money -= 50;
							heroesHp += 1;
							cout << "체력이 1회복 되었습니다. " << endl;
							cout << "현재 체력 : " << heroesHp << endl;
						}
					}
					else if (portion == 2)
					{
						//돈이 없는 경우
						if (money < 200)
						{
							cout << "금액이 부족합니다." << endl;
						}
						//체력이 full인 경우
						else if (heroesHp >= (int)(10 - difficulty * 0.5f))
						{
							cout << "체력이 풀 입니다." << endl;
						}
						//체력이 full이 아니고 돈도 충분한 경우
						else
						{
							money -= 200;
							heroesHp = (int)(15 - difficulty * 0.5f);
							cout << "체력이 풀로 회복되었습니다. " << endl;
							cout << "현재 체력 : " << heroesHp << endl;
						}
					}
					else if (portion == 3)
					{
						if (money < 200)
						{
							cout << "금액이 부족합니다." << endl;
						}
						else
						{
							money -= 200;
							damage++;
							cout << "데미지가 1증가되었습니다." << endl;
						}
					}
					else if (portion == 4)
					{
						cout << "상점에서 나갑니다." << endl;
						Sleep(2000);
						system("cls");
						break;
					}
					else
					{
						cout << "다시 입력해 주세요." << endl;
						Sleep(2000);
						system("cls");
					}

					Sleep(2000);
				}
				myXPosition = myPrevXPosition, myYPosition = myPrevYPosition;
				map[myXPosition][myYPosition] = 'O';
				map[storeXPosition][storeYPosition] = '$';
			}
#pragma endregion

#pragma region 몬스터 전투

			//몬스터인지를 체크하는 코드
			for (int i = 0; i < monsterCount; i++)
			{
				if (myXPosition == monsters[i].monX && myYPosition == monsters[i].monY) //몬스터와 만난 경우.
				{
					victory = false;

					while (true)
					{
						system("cls");
						cout << " < 몬스터 정보 > " << endl;
						cout << "  - 이름 : " << monsters[i].name << endl;
						cout << "  - 체력 : " << monsters[i].hp << endl;
						cout << endl;
						cout << " < 영웅의 정보 > " << endl;
						cout << "  - 이름 : " << heroesName << endl;
						cout << "  - 공격력 : " << damage << endl;
						cout << "  - 체력 : " << heroesHp << endl;
						cout << "  - 보유한 금액 : " << money << endl;
						cout << endl;
						cout << " >> 싸우시겠습니까?(0) 도망가시겠습니까?(1) : ";
						cin >> fightAndRun;

						if (fightAndRun == 1)
							break;
						else if (fightAndRun != 0)
						{
							cout << "다시 입력해 주세요." << endl;
							Sleep(1000);
							continue;
						}

						//가위바위보를 하는 코드
						randNumber = (rand() % 3 + 1); //컴퓨터 가위바위보 선택
						system("cls");
						cout << "전투 시작!!" << endl;
						cout << "가위(1), 바위(2), 보(3) 숫자로 입력 : ";
						cin >> inputSPR;

						if (inputSPR == SCISSORS) //1 내가 가위를 낸 경우
						{
							if (randNumber == SCISSORS) //1
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 가위" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == ROCK) //2
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 바위" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % ( 171 ) + 80; // 80 ~ 250
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else if (inputSPR == ROCK) //1
						{
							if (randNumber == ROCK) //1
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 바위" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == PAPER) //2
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 보" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;
									
									randomGetMoney = rand() % (171) + 80; // 80 ~ 250			
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else if (inputSPR == PAPER) //2
						{
							if (randNumber == PAPER) //2
							{
								cout << "결과 : 비겼습니다." << endl;
								cout << monsters[i].name << " 낸 것 : 보" << endl;
								cout << "다시 입력해 주세요." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == SCISSORS) //1
							{
								cout << "결과 : 패배..." << endl;
								cout << monsters[i].name << " 낸 것 : 가위" << endl;
								cout << "현재 남은 체력 : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " 공격으로 인해 " << heroesName <<
										"님이 패배하였습니다. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //이긴 경우
							{
								cout << "결과 : 승!!" << endl;
								
								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250		
									money += randomGetMoney;
									cout << monsters[i].name << " 를(을) 잡아 돈" << randomGetMoney << "원을"
										" 획득!" << endl;
									cout << "현재 남은 체력 : " << heroesHp << endl;
									cout << "보유한 금액 : " << money << endl;
									cout << "남은 몬스터의 수 : " << --monsterCountVariable << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "님이 데미지를 입혔다!" << endl;
									Sleep(1500);
								}
							}
						}
						else
						{
							cout << "다시 입력해 주세요" << endl;
							Sleep(1500);
							continue;
						}
					}

					if (victory == true)
					{
						break;
					}

					//도망갔으면 굳이 for문을 계속해서 체크하지 않아도 된다.
					if (fightAndRun != 0)
					{
						myXPosition = myPrevXPosition, myYPosition = myPrevYPosition;
						map[myXPosition][myYPosition] = 'O';
						map[monsters[i].monX][monsters[i].monY] = 'M';

						break;
					}

				}
			}

#pragma endregion

#pragma region 승리
			if (monsterCountVariable <= 0)
			{
				cout << endl;
				cout << " ♪（ｖ＾＿＾）ｖｖ（＾＿＾ｖ）♪ " << endl;
				cout << endl;
				cout << heroesName << "님이 모든 몬스터를 처치하고 승리하셨습니다!" << endl;
				cout << "보유한 금액 : " << money << endl;
				cout << "처치한 몬스터 명단 : ";
				for (int i = 0; i < monsterCount; i++)
				{
					if (i == monsterCount - 1)
					{
						cout << monsters[i].name;
					}
					else
					{
						cout << monsters[i].name << ", ";
					}
				}
				cout << endl;
				exit(0);
			}
#pragma endregion

		}
	}
#pragma endregion

	return 0;
}
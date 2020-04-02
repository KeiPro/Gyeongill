/*
	1) 텍스트로 진행되는 게임
	2) 게임이 시작되면 영웅의 이름과 난이도를 입력
	3) 난이도에 따라서 영웅의 HP / 만나게 되는 몬스터의 숫자가 변동
	4) 게임이 시작되면 마지막 몬스터를 잡을 때까지 전투가 진행되는 방식
	5) 몬스터를 잡으면 랜덤하게 돈을 획득한다. ( 0 ~ 100 )
	6) 몬스터를 잡으면 던전을 계속 탐험할 지, 상점을 들릴지를 결정한다.
	7) 상점을 들르면 돈을 소모해서 HP를 회복할 수 있다.
	8) 전투 방식은 가위 바위 보로 이루어진다. //몬스터와 승패를 겨룸, 비기면 다시, 지면 HP가 소모(몬스터는 1번 지면 사망.)
	9) 몬스터를 다 잡으면 Claer / HP가 0이 되면 게임오버.
	10) 클리어시 엔딩 멘트 출력.
*/

#include<iostream>
#include<string>
#include<Windows.h>
#include<ctime>

using namespace std;

int main()
{

	// < 영웅의 이름과 난이도 입력 >

	string heroesName; //히어로 이름
	int heroesHp; //히어로의 체력
	int money = 0; //금액
	int randomGetMoney;

	int difficulty; //난이도
	int monsterCount; //몬스터 수

	const string SCISSORS = "가위"; //0
	const string ROCK = "바위"; //1
	const string PAPER = "보"; //2
	string monsterSelect = "선택중";
	string inputString; // 가위, 바위, 보 입력받을 변수
	int inputSelect; //상점(0)을 갈 지, 탐험(1)을 더 할 지를 입력받을 변수

	srand(time(NULL));
	
	cout << "영웅의 이름을 입력하세요 : ";
	cin >> heroesName;

	cout << "난이도를 입력하세요(1~10) : ";
	cin >> difficulty;

	heroesHp = (int)(10 - difficulty * 0.5f);
	monsterCount = (int)(difficulty * 2.7f);

	//난이도에 따라서 영웅의 HP, 몬스터 숫자가 변동된다.
	//--> 난이도 : difficulty ==> 영웅의 HP : 10 - difficulty*0.5 , 몬스터 숫자 : difficulty * 2.7f를 정수 변환;
	cout << "< 난이도에 의해 HP와 몬스터를 조정합니다. >" << endl;
	Sleep(1500);

	cout << "영웅의 HP : " << heroesHp << endl;

	Sleep(1000);
	cout << "몬스터 숫자 : " << monsterCount << endl;

	Sleep(1500);
	cout << "모든 몬스터를 다 잡을 때까지 전투는 계속됩니다..." << endl;
	cout << endl;
	Sleep(2000);

	system("cls"); //화면 지우기

	while (true)
	{
		cout << " < 전투 시작 > " << endl;
		cout << "영웅의 HP : " << heroesHp << endl;
		cout << "몬스터 숫자 : " << monsterCount << "마리" << endl;

		int randNumber = rand() % 3; // 0 ~ 2 

		cout << "가위, 바위, 보 입력 : ";
		cin >> inputString;
		cout << "=========================" << endl;
		if (inputString == SCISSORS) //0
		{
			if (randNumber == 0)
			{
				cout << "결과 : 비겼습니다." << endl;
				cout << "다시 입력해 주세요." << endl;
				cout << endl;
			}
			else if (randNumber == 1)
			{
				cout << "결과 : 졌습니다." << endl;
				cout << "현재 남은 체력 : " << --heroesHp << endl;

				if (heroesHp <= 0)
				{
					cout << "전투에서 패배하였습니다." << endl;
					break;
				}
			}
			else
			{
				cout << "결과 : 승리! " << endl;
				randomGetMoney = rand() % 100 + 1;
				money += randomGetMoney;
				cout << randomGetMoney << "원 획득 하셨습니다." << endl;
				cout << "현재 남은 체력 : " << heroesHp << endl;
				cout << "남은 몬스터 수 : " << --monsterCount << endl;
				cout << "가진 금액 : " << money << endl;
				cout << "==========================================" << endl;
				Sleep(2000);

				if (monsterCount <= 0) //남은 몬스터의 수가 0 이하이면
				{
					cout << "축하합니다." << heroesName << "님. 승리하셨습니다." << endl;
					break;
				}

				cout << "상점 이동 : 0, 던전 탐험 : 1 => ";
				cin >> inputSelect;

				int portion;

				switch (inputSelect)
				{
				case 0: //상점으로 이동
					system("cls");
					cout << "< 상점 입니다. >" << endl;
					cout << "hp 1 회복하기(금액100원): 0입력 " << endl;
					cout << "hp full 회복하기(금액300원) : 1입력 " << endl;
					cout << "상점 나가기 : 2입력" << endl;
					cout << "==========================================" << endl;
					cout << "현재 남은 체력 : " << heroesHp << endl;
					cout << "남은 몬스터 수 : " << monsterCount << endl;
					cout << "가진 금액 : " << money << endl;
					while (true)
					{
						cout << "번호를 입력해 주세요 : ";
						cin >> portion;
						if (portion == 0)
						{
							//돈이 없는 경우
							if (money < 100)
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
								money -= 100;
								heroesHp += 1;
								cout << "체력이 1회복 되었습니다. " << endl;
								cout << "현재 남은 체력 : " << heroesHp << endl;
								cout << "남은 몬스터 수 : " << monsterCount << endl;
							}
						}
						else if (portion == 1)
						{
							//돈이 없는 경우
							if (money < 300)
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
								money -= 300;
								heroesHp = (int)(10 - difficulty * 0.5f);
								cout << "체력이 풀로 회복되었습니다. " << endl;
								cout << "현재 남은 체력 : " << heroesHp << endl;
								cout << "남은 몬스터 수 : " << monsterCount << endl;
							}
						}
						else
						{
							cout << "상점에서 나갑니다." << endl;
							Sleep(2000);
							system("cls");
							break;
						}

					}

					break;

				case 1: //던전 탐험
					cout << "던전으로 이동합니다..." << endl;
					Sleep(2000);
					system("cls");

					break;

				default:
					break;
				}
			}
		}
		if (inputString == ROCK) //1
		{
			if (randNumber == 1)
			{
				cout << "결과 : 비겼습니다." << endl;
				cout << "다시 입력해 주세요." << endl;
				cout << endl;
			}
			else if (randNumber == 2)
			{
				cout << "결과 : 졌습니다." << endl;
				cout << "현재 남은 체력 : " << --heroesHp << endl;

				if (heroesHp <= 0)
				{
					cout << "전투에서 패배하였습니다." << endl;
					break;
				}
			}
			else
			{
				cout << "결과 : 승리! " << endl;
				randomGetMoney = rand() % 100 + 1;
				money += randomGetMoney;
				cout << randomGetMoney << "원 획득 하셨습니다." << endl;
				cout << "현재 남은 체력 : " << heroesHp << endl;
				cout << "남은 몬스터 수 : " << --monsterCount << endl;
				cout << "가진 금액 : " << money << endl;
				cout << "==========================================" << endl;

				Sleep(2000);

				if (monsterCount <= 0) //남은 몬스터의 수가 0 이하이면
				{
					cout << "축하합니다." << heroesName << "님. 승리하셨습니다." << endl;
					break;
				}

				cout << "상점 이동 : 0입력, 던전 탐험 : 1입력 => ";
				cin >> inputSelect;

				int portion;

				switch (inputSelect)
				{
				case 0: //상점으로 이동
					system("cls");
					cout << "< 상점 입니다. >" << endl;
					cout << "hp 1 회복하기(금액100원): 0입력 " << endl;
					cout << "hp full 회복하기(금액300원) : 1입력 " << endl;
					cout << "상점 나가기 : 2입력" << endl;
					cout << "==========================================" << endl;
					cout << "현재 남은 체력 : " << heroesHp << endl;
					cout << "남은 몬스터 수 : " << monsterCount << endl;
					cout << "가진 금액 : " << money << endl;

					while (true)
					{
						cout << "번호를 입력해 주세요 : ";
						cin >> portion;
						if (portion == 0)
						{
							//돈이 없는 경우
							if (money < 100)
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
								money -= 100;
								heroesHp += 1;
								cout << "체력이 1회복 되었습니다. " << endl;
								cout << "현재 남은 체력 : " << heroesHp << endl;
								cout << "남은 몬스터 수 : " << monsterCount << endl;
							}
						}
						else if (portion == 1)
						{
							//돈이 없는 경우
							if (money < 300)
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
								money -= 300;
								heroesHp = (int)(10 - difficulty * 0.5f);
								cout << "체력이 풀로 회복되었습니다. " << endl;
								cout << "현재 남은 체력 : " << heroesHp << endl;
								cout << "남은 몬스터 수 : " << monsterCount << endl;
							}
						}
						else
						{
							cout << "상점에서 나갑니다." << endl;
							Sleep(2000);
							system("cls");
							break;
						}
					}

					break;

				case 1: //던전 탐험
					cout << "던전으로 이동합니다..." << endl;
					Sleep(2000);
					system("cls");

					break;

				default:
					break;
				}
			}
		}
		if (inputString == PAPER) //2
		{
			if (randNumber == 2)
			{
				cout << "결과 : 비겼습니다." << endl;
				cout << "다시 입력해 주세요." << endl;
				cout << endl;
			}
			else if (randNumber == 1)
			{
				cout << "결과 : 졌습니다." << endl;
				cout << "현재 남은 체력 : " << --heroesHp << endl;
				
				if (heroesHp <= 0)
				{
					cout << "전투에서 패배하였습니다." << endl;
					break;
				}
			}
			else
			{
				cout << "결과 : 승리! " << endl;
				randomGetMoney = rand() % 100 + 1;
				money += randomGetMoney;
				cout << randomGetMoney << "원 획득 하셨습니다." << endl;
				cout << "현재 남은 체력 : " << heroesHp << endl;
				cout << "남은 몬스터 수 : " << --monsterCount << endl;
				cout << "가진 금액 : " << money << endl;

				Sleep(2000);

				if (monsterCount <= 0) //남은 몬스터의 수가 0 이하이면
				{
					cout << "축하합니다." << heroesName << "님. 승리하셨습니다." << endl;
					break;
				}

				cout << "상점 이동 : 0, 던전 탐험 : 1 => ";
				cin >> inputSelect;

				int portion;

				switch (inputSelect)
				{
				case 0: //상점으로 이동
					system("cls");
					cout << "< 상점 입니다. >" << endl;
					cout << "hp 1 회복하기(금액100원): 0입력 " << endl;
					cout << "hp full 회복하기(금액300원) : 1입력 " << endl;
					cout << "상점 나가기 : 2입력" << endl;
					cout << "==========================================" << endl;
					cout << "현재 남은 체력 : " << heroesHp << endl;
					cout << "남은 몬스터 수 : " << monsterCount << endl;
					cout << "가진 금액 : " << money << endl;
					cout << "==========================================" << endl;

					while (true)
					{
						cout << "번호를 입력해 주세요 : ";
						cin >> portion;
						if (portion == 0)
						{
							//돈이 없는 경우
							if (money < 100)
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
								money -= 100;
								heroesHp += 1;
								cout << "체력이 1회복 되었습니다. " << endl;
								cout << "현재 남은 체력 : " << heroesHp << endl;
								cout << "남은 몬스터 수 : " << monsterCount << endl;
							}
						}
						else if (portion == 1)
						{
							//돈이 없는 경우
							if (money < 300)
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
								money -= 300;
								heroesHp = (int)(10 - difficulty * 0.5f);
								cout << "체력이 풀로 회복되었습니다. " << endl;
								cout << "현재 남은 체력 : " << heroesHp << endl;
								cout << "남은 몬스터 수 : " << monsterCount << endl;
							}
						}
						else
						{
							cout << "상점에서 나갑니다." << endl;
							Sleep(2000);
							system("cls");
							break;
						}

					}

					break;

				case 1: //던전 탐험
					cout << "던전으로 이동합니다..." << endl;
					Sleep(2000);
					system("cls");

					break;

				default:
					break;
				}
			}
		}

		cout << "=========================" << endl;
	}
	return 0;
}
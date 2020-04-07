/*
	200402. 
	1. _getch()라는 함수를 배움. ( #include < conio.h > )
		해당 함수는 키 값을 입력받기 위해 대기를 하고 있다가
		키 값을 입력받는 순간! 출력은 따로 하지 않고, 바로 해당 키 값에
		해당하는 아스키코드의 값을 입력해준다. 

		물론, cin >> char 형으로 받는 부분으로 처리해도 괜찮지만
		이렇게 할 경우에는 입력한 키가 콘솔창에 뜨게끔 적용이 돼버리기 때문에
		내가 입력한 키를 콘솔창에 굳이 띄우고 싶지 않은경우 난감한 상황이
		될 수 있다. 

		따라서, 입력받은 순간 내가 입력한 데이터를 콘솔창에 따로 보여주지 않고
		바로 입력이 완료 돼어 처리되는 것을 원할경우 해당 함수를 사용하면
		나름 끄덕여지는 결과가 나올거라 생각한다.
*/
/*
	200403.

		주말 할일) 1. 자소서 완성해오기

				탈출게임과 영웅은 절차적 콜라보!

		주말 과제 2. 영웅은 절차적 시즌 업데이트
		게임 공간 10 * 10의 2차원 타일 공간으로 구성 (WASD이동)
		만나는 몬스터는 난이도에 따라 HP를 가지게 된다. -- 1)
		타일 위의 몬스터와 위치가 겹치면 전투가 시작된다. (가위바위보) -- 2)
		몬스터와의 전투에서 패배 시 '도망'을 선택할 수 있다. --3)
		(도망을 선택하면, 위나 아래나 왼쪽이나 오른쪽으로 이동하게 (아이디어 넣어보기))
		상점도 타일 위에 존재한다. --> 상점 가실래요? 가 아니라 직접 상점에 가는것.
		각 몬스터는 이름을 가지고 20기 학생들 이름으로 초기화한다.

		//추가하고 싶은 사항 : 크리티컬 데미지, 

		배열 / 구조체 / 함수 --> C언어에서 사용되는 코드 추상화의 도구. 코드 추상화를 위한 도구.
		여기서 추상화란? 실제 현상(현실 세계)을 간략화와 기호화, 보편화를 통해서 데이터적으로 + 코드적으로 흉내를 낸 것.
		코드 추상화? student1, student2, student3 ........ --> student[] 을 통해 코드를 간소화 시킴 ==> 코드 추상화

*/

/*
	200406.
	  1.** cin>>입력 오류 예외처리하는 방법.
		예를 들어, int형으로 선언한 변수 testNum이 있다고 하자.
		무한루프를 돌리며 해당 testNum변수에다가 값을 입력받는다고 했을 때
		int형이 아닌 char형을 입력 받는 경우 cin함수가 오류가 나버리게 되며,
		다시 입력을 받지 못하고 무한루프에 빠져 프로그램이 망가져버리는 사태가 발생하게 된다.
		이때 오류가 난 경우는 다음과 같이 확인할 수 있다.

		cin.fail()을 확인하여 값이 1이 나온경우 해당 입력은 오류가 난 것으로 처리된다.
		따라서 이 오류를 해결하기 위해서는, cin.fail()로 1차 처리를 하고 
		cin.clear()함수를 통해 cin객체의 내부 상태 플래그를 초기화한다.
		마지막으로 cin.ignore(256, '\n'); 함수를 통해 현재 버퍼안에 있는 내용을 무시하는 함수를 사용한다.

		이렇게 처리하고 오류메시지만 사용자에게 출력해주면, 무한루프는 그대로 유지하되 입력을 정상적으로 받을 수 있도록 처리된다.
		간단히 코드를 보면 다음과 같다.

		void main()
		{
			int num;

			while ( true )
			{
				cout << "숫자입력: ";

				cin >> val1;

				if ( cin.fail() )
				{
					cin.clear();
					cin.ignore(256, '\n');
					cout << "숫자를 다시 입력해 주세요." << endl;
				}
				else

					break;
			}
		}

		이렇게 간단히 처리만 해줘도 프로그램이 터지는 것을 방지할 수 있다.
		
*/

/*
	2020.04.06
	
	동적할당....

		--> 2차원 배열을 동적할당으로 표현하기.
		int p[2][3]; 을 동적할당으로!


		1) new int*[2]; //메모리 주소를 가리키는 변수 2개를 동적할당`.

		2) int** p = new int*[2]; //이러한 변수를 가리킬 포인터를 선언한다. 따라서 이중 포인터가 된다.

		3) for(int i = 0 ; i < 2 ; i++)
			*(p+i) = new int[3];

		동적할당을 완료하였으므로, 메모리 해제 작업에 들어가야한다. 
		우리는 2)과 3)에 의해 new키워드를 두 번 사용했고 이 두 번 사용한 부분에 대해 메모리 해제를 진행해줘야 한다.

		4) for(int i = 0 ; i < 2 ; i++)
			delete[] *(p+i);

		5) delete[] p;

		--> 3차원 배열을 동적할당으로 표현하기.
		int p[2][3][4];

		1) new int**[2]; //어떠한 메모리 주소를 가리키는 변수를 가리키는 변수 2개를 동적할당.

		2) int*** p = new int**[2]; //이러한 변수를 가리키는 포인터를 선언한다. 따라서 삼중 포인터가 된다.

		3) for(int i = 0 ; i < 2 ; i++)
				*(p+i) = new int*[3];

		4) for(int i = 0 ; i < 2 ; i++)
				for(int j=0 ; j < 3 ; j++)
					*(*(p+1)+j) = new int[4];

		5) for(int i = 0 ; i < 2; i++)
			for(int j = 0 ; j < 3 ; j++)
				delete[] *(*(p + i) + j);

		6) for( int i = 0; i < 2 ; i++)
				delete[] *(p+i);

		7) delete[] p;

					
*/

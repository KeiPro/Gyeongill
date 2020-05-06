
#include "KeyManager.h"

HRESULT KeyManager::Init()
{
	for (int i = 0; i < KEY_MAX_COUNT; i++)
	{
		SetKeyDown(i, false);
		SetKeyUp(i, true);
	}

	return S_OK;
}

void KeyManager::Release()
{
}

bool KeyManager::IsOnceKeyDown(int key)
{
	//WinAPI에서 제공하는 함수 
	// GetAsyncKeyState(VK_...)
	/*
		함수 호출 시점에 가상키(VK_...)가 어떤 상태인지 확인이 가능하다.
		1. (저 함수의 결과가) 
		2. 0x0000 => 이전 프레임에 누른 적이 없고 호출시점에도 눌려있지 않음
		2. 0x0001 => 이전 프레임에 누른 적이 있고 호출시점에는 눌려있지 않은상태
		3. 0x8000 => 이전 프레임에 누른 적이 없고 호출시점에는 눌려있는 상태
		4. 0x8001 => 이전 프레임에 누른 적이 있고 호출시점에도 눌려있는 상태
	*/

	if (GetAsyncKeyState(key) & 0x8000) // 3, 4번만 true가 된다.
	{
		if (this->GetKeyDown()[key] == false) //256개 중에 현재 해당하는 키가
		{
			this->SetKeyDown(key, true); //그 위치에 '눌렸다'를 저장한다.
			return true;
		}
	}
	else //현재 눌려있지 않은 상황이면
	{
		this->SetKeyDown(key, false);
	}


	return false;
}

bool KeyManager::IsOnceKeyUp(int key)
{
	//키가 업 상태인지 아닌지 그것도 한 번 업인지 아닌지 판단해야된다.
	if ( GetAsyncKeyState(key) & 0x8000 ) //눌린상태
	{
		this->SetKeyUp(key, false);
	}
	else
	{
		if (this->GetKeyUp()[key] == false)
		{
			this->SetKeyUp(key, true);
			return true;
		}
	}

	return false;


/*
	if (GetAsyncKeyState(key) & 0x0001)
	{
		if (this->GetKeyUp()[key] == false)
		{
			this->SetKeyUp(key, true);
			return true;
		}
	}
	else
	{
		this->SetKeyUp(key, false);
	}


	return false;*/
}

bool KeyManager::IsStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
		return true;

	return false;
}

KeyManager::KeyManager()
{
}

KeyManager::~KeyManager()
{
}

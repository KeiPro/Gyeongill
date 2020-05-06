
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
	//WinAPI���� �����ϴ� �Լ� 
	// GetAsyncKeyState(VK_...)
	/*
		�Լ� ȣ�� ������ ����Ű(VK_...)�� � �������� Ȯ���� �����ϴ�.
		1. (�� �Լ��� �����) 
		2. 0x0000 => ���� �����ӿ� ���� ���� ���� ȣ��������� �������� ����
		2. 0x0001 => ���� �����ӿ� ���� ���� �ְ� ȣ��������� �������� ��������
		3. 0x8000 => ���� �����ӿ� ���� ���� ���� ȣ��������� �����ִ� ����
		4. 0x8001 => ���� �����ӿ� ���� ���� �ְ� ȣ��������� �����ִ� ����
	*/

	if (GetAsyncKeyState(key) & 0x8000) // 3, 4���� true�� �ȴ�.
	{
		if (this->GetKeyDown()[key] == false) //256�� �߿� ���� �ش��ϴ� Ű��
		{
			this->SetKeyDown(key, true); //�� ��ġ�� '���ȴ�'�� �����Ѵ�.
			return true;
		}
	}
	else //���� �������� ���� ��Ȳ�̸�
	{
		this->SetKeyDown(key, false);
	}


	return false;
}

bool KeyManager::IsOnceKeyUp(int key)
{
	//Ű�� �� �������� �ƴ��� �װ͵� �� �� ������ �ƴ��� �Ǵ��ؾߵȴ�.
	if ( GetAsyncKeyState(key) & 0x8000 ) //��������
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

#include "Level_Back.h"
#include "InputManager.h"

Level_Back::Level_Back()
{

}

Level_Back::~Level_Back()
{

}


void Level_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "Select1";
	Active = false;
	Time = GetTickCount64();
	Page_Num = 1;
}

int Level_Back::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	//** Start~Quit 선택
	if (Time + 80 < GetTickCount64())
	{
		Time = GetTickCount64();
		if (dwKey & KEY_UP && Page_Num != 1)
		{
			Page_Num--;
		}
		else if (dwKey & KEY_DOWN && Page_Num != 4)
		{
			Page_Num++;
		}
	}


	switch (Page_Num)
	{
	case 1:
		strKey = "Select1";
		break;
	case 2:
		strKey = "Select2";
		break;
	case 3:
		strKey = "Select3";
		break;
	case 4:
		strKey = "Select4";
		break;
	default:
		break;
	}
	return Page_Num;
}

void Level_Back::Render(HDC _hdc)
{
	//백그라운드
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList[strKey]->GetMemDC(),
		0, 0,
		SRCCOPY);

	//난이도 선택
	

}

void Level_Back::Release()
{

}
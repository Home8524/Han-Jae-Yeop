#include "Stage_Back.h"
#include "InputManager.h"

Stage_Back::Stage_Back()
{

}

Stage_Back::~Stage_Back()
{

}


void Stage_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "BackGround1";
	Active = false;
	Time = GetTickCount64();
	Page_Num = 1;
}

int Stage_Back::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	//** Start~Quit º±≈√
	if (Time + 60 < GetTickCount64())
	{
		Time = GetTickCount64();
		if (dwKey & KEY_UP && Page_Num!=1)
		{
			Page_Num--;
		}
		else if (dwKey & KEY_DOWN && Page_Num != 8)
		{
			Page_Num++;
		}
	}


	switch(Page_Num)
	{
	case 1:
		strKey = "BackGround1";
		break;
	case 2:
		strKey = "BackGround2";
		break;
	case 3:
		strKey = "BackGround3";
		break;
	case 4:
		strKey = "BackGround4";
		break;
	case 5:
		strKey = "BackGround5";
		break;
	case 6:
		strKey = "BackGround6";
		break;
	case 7:
		strKey = "BackGround7";
		break;
	default:
		break;
	}
	return 0;
}

void Stage_Back::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList[strKey]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Stage_Back::Release()
{

}

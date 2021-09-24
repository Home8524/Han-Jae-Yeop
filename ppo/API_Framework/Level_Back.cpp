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

	strKey = "Level";
	Active = false;
}

int Level_Back::Update()
{
	return 0;
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
	TransparentBlt(_hdc, // ** 최종 출력 위치
		200,
		0,
		259,
		55,
		ImageList["Select0"]->GetMemDC(),
		0, 0,
		259,
		55,
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** 최종 출력 위치
		200,
		100,
		259,
		97,
		ImageList["Select1"]->GetMemDC(),
		0, 0,
		259,
		97,
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** 최종 출력 위치
		200,
		250,
		259,
		102,
		ImageList["Select2"]->GetMemDC(),
		0, 0,
		259,
		102,
		RGB(255, 0, 255));

}

void Level_Back::Release()
{

}
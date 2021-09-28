#include "Stage1_Back.h"
#include "InputManager.h"

Stage1_Back::Stage1_Back()
{

}

Stage1_Back::~Stage1_Back()
{

}


void Stage1_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "Level";
	Active = false;
}

int Stage1_Back::Update()
{
	return 0;
}

void Stage1_Back::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList[strKey]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Stage1_Back::Release()
{

}
#include "Logo_Back.h"
#include "InputManager.h"

Logo_Back::Logo_Back()
{

}

Logo_Back::~Logo_Back()
{

}


void Logo_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "LBackGround";
	Active = false;
}

int Logo_Back::Update()
{
	return 0;
}

void Logo_Back::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList[strKey]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Logo_Back::Release()
{

}
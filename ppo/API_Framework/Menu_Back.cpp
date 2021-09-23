#include "Menu_Back.h"
#include "InputManager.h"

Menu_Back::Menu_Back()
{

}

Menu_Back::~Menu_Back()
{

}


void Menu_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "Menu";
	Active = false;
}

int Menu_Back::Update()
{
	return 0;
}

void Menu_Back::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList[strKey]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Menu_Back::Release()
{

}
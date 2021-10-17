#include "End_Back.h"
#include "InputManager.h"

End_Back::End_Back()
{

}

End_Back::~End_Back()
{

}


void End_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "End";
	Active = false;
}

int End_Back::Update()
{
	return 0;
}

void End_Back::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList[strKey]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void End_Back::Release()
{

}
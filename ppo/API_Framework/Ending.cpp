#include "Ending.h"
#include "SceneManager.h"
#include "End_Back.h"
Ending::Ending()
{

}

Ending::~Ending()
{

}

void Ending::Initialize()
{
	MenuBack = new End_Back;
	MenuBack->Initialize();
	ImageList = Object::GetImageList();
	Time = GetTickCount64();
}

void Ending::Update()
{

	if (GetAsyncKeyState('X') && Time + 100 < GetTickCount64()) {

		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
		Time = GetTickCount64();
	}
}

void Ending::Render(HDC _hdc)
{
	MenuBack->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Ending::Release()
{

}
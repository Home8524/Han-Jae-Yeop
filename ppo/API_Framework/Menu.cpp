#include "Menu.h"
#include "SceneManager.h"
#include "Menu_Back.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::Initialize()
{
	MenuBack = new Menu_Back;
	MenuBack->Initialize();
	ImageList = Object::GetImageList();
	Time = GetTickCount64();
}

void Menu::Update()
{

	if (GetAsyncKeyState('Z') && Time + 60 < GetTickCount64()) {

		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
		Time = GetTickCount64();
	}
}

void Menu::Render(HDC _hdc)
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

void Menu::Release()
{

}

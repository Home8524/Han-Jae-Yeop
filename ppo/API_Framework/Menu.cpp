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
}

void Menu::Update()
{
	if (GetAsyncKeyState('S'))
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
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

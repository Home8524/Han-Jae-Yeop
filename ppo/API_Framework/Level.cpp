#include "Level.h"
#include "SceneManager.h"
#include "Level_Back.h"

Level::Level() 
{

}

Level::~Level()
{
	Release();
}

void Level::Initialize()
{
	State_Back = new Level_Back();
	State_Back->Initialize();

	ImageList = Object::GetImageList();
}

void Level::Update()
{
	State_Back->Update();

}

void Level::Render(HDC _hdc)
{
	State_Back->Render(ImageList["Buffer"]->GetMemDC());



	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Level::Release()
{

}

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
	Time = GetTickCount64();
}

void Level::Update()
{
	int tmp;
	tmp = State_Back->Update();
	
	if (GetAsyncKeyState('Z') && tmp == 1 && Time + 100 < GetTickCount64()) {

		SceneManager::GetInstance()->SetScene(SCENEID::STAGE1);
		Time = GetTickCount64();
	}
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

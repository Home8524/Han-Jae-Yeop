#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Stage_Back.h"
#include "SoundManager.h"

Stage::Stage()
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	State_Back = new Stage_Back;
	State_Back->Initialize();

	Time = GetTickCount64();
	ImageList = Object::GetImageList();
}

void Stage::Update()
{
	int tmp;
	tmp = State_Back->Update();

	
	if (GetAsyncKeyState('Z') && tmp==1&&Time + 100 < GetTickCount64()) {

		SceneManager::GetInstance()->SetScene(SCENEID::LEVEL);
		Time = GetTickCount64();
	}
	
	if (GetAsyncKeyState('Z') && tmp == 7 && Time + 100 < GetTickCount64()) {

		SceneManager::GetInstance()->SetScene(SCENEID::EXIT);
		Time = GetTickCount64();
	}
	
}

void Stage::Render(HDC _hdc)
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

void Stage::Release()
{

}

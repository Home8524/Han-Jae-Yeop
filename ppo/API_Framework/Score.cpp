#include "Score.h"
#include "SceneManager.h"
#include "Score_Back.h"

Score::Score()
{

}

Score::~Score()
{

}

void Score::Initialize()
{
	ScoreBack = new Score_Back;
	ScoreBack->Initialize();
	ImageList = Object::GetImageList();
	Time = GetTickCount64();

}

void Score::Update()
{

	if (GetAsyncKeyState('X') && Time + 100 < GetTickCount64()) {

		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
		Time = GetTickCount64();
	}
}

void Score::Render(HDC _hdc)
{
	ScoreBack->Render(ImageList["Buffer"]->GetMemDC());


	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Score::Release()
{

}


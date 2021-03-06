#include "Logo.h"
#include "Player.h"
#include "Enemy.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"


Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Initialize()
{
	ObjectManager::GetInstance()->Initialize();

	ObjectManager::GetInstance()->SetPlayer(
		ObjectFactory<Player>::CreateObject() );

	ImageList["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Buffer.bmp");
	ImageList["BackGround"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround.bmp");
	ImageList["Hammer"] = (new Bitmap)->LoadBmp(L"../Resource/Hammer.bmp");
	ImageList["Mole"] = (new Bitmap)->LoadBmp(L"../Resource/Mole.bmp");
	ImageList["Mole2"] = (new Bitmap)->LoadBmp(L"../Resource/Mole2.bmp");
	ImageList["Hole"] = (new Bitmap)->LoadBmp(L"../Resource/Hole.bmp");
	ImageList["Effect"] = (new Bitmap)->LoadBmp(L"../Resource/Effect.bmp");

	Object::SetImageList(ImageList);
}

void Logo::Update()
{
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render(HDC _hdc)
{
    
}

void Logo::Release()
{

}

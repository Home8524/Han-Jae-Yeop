#include "Logo.h"
#include "Player.h"
#include "Enemy.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Logo_Back.h"

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

	ImageList["BackGround1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main1.bmp");
	ImageList["BackGround2"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main2.bmp");
	ImageList["BackGround3"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main3.bmp");
	ImageList["BackGround4"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main4.bmp");
	ImageList["BackGround5"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main5.bmp");
	ImageList["BackGround6"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main6.bmp");
	ImageList["BackGround7"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main7.bmp");

	ImageList["LBackGround"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/logo.bmp");
	ImageList["Menu"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/menu.bmp");

	ImageList["Hammer"] = (new Bitmap)->LoadBmp(L"../Resource/Hammer.bmp");
	ImageList["Mole"] = (new Bitmap)->LoadBmp(L"../Resource/Mole.bmp");
	ImageList["Mole2"] = (new Bitmap)->LoadBmp(L"../Resource/Mole2.bmp");
	ImageList["Hole"] = (new Bitmap)->LoadBmp(L"../Resource/Hole.bmp");
	ImageList["Effect"] = (new Bitmap)->LoadBmp(L"../Resource/Effect.bmp");

	LogoBack = new Logo_Back;
	LogoBack->Initialize();
	Object::SetImageList(ImageList);
}

void Logo::Update()
{
	if (GetAsyncKeyState('Z'))
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render(HDC _hdc)
{
	LogoBack->Render(ImageList["Buffer"]->GetMemDC());


	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Logo::Release()
{

}

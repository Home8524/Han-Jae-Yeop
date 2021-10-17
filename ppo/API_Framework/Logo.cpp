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
#pragma region start~quit 선택용
	ImageList["BackGround1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main1.bmp");
	ImageList["BackGround2"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main2.bmp");
	ImageList["BackGround3"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main3.bmp");
	ImageList["BackGround4"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main4.bmp");
	ImageList["BackGround5"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main5.bmp");
	ImageList["BackGround6"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main6.bmp");
	ImageList["BackGround7"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/main7.bmp");
#pragma endregion

#pragma region 백그라운드 모음
	ImageList["LBackGround"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/logo.bmp");
	ImageList["Menu"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/menu.bmp");
	ImageList["Level"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/select00.bmp");
	ImageList["Stage1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/stg1bg.bmp");
	ImageList["Spell1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/eff02.bmp");
	ImageList["Spell2"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/eff03.bmp");
	ImageList["Spell3"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/eff04.bmp");
	ImageList["End"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/end00.bmp");
#pragma endregion
	
#pragma region 난이도 선택
	ImageList["Select1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/select01.bmp");
	ImageList["Select2"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/select02.bmp");
	ImageList["Select3"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/select03.bmp");
	ImageList["Select4"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/select04.bmp");
#pragma endregion
	ImageList["Hammer"] = (new Bitmap)->LoadBmp(L"../Resource/Hammer.bmp");
	ImageList["Mole"] = (new Bitmap)->LoadBmp(L"../Resource/Mole.bmp");
	ImageList["Mole2"] = (new Bitmap)->LoadBmp(L"../Resource/Mole2.bmp");
	ImageList["Hole"] = (new Bitmap)->LoadBmp(L"../Resource/Hole.bmp");
	ImageList["Effect"] = (new Bitmap)->LoadBmp(L"../Resource/Effect.bmp");

	//1정면 2우 3좌
	ImageList["Player1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/player1.bmp");
	ImageList["Player2"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/player2.bmp");
	ImageList["Player3"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/player3.bmp");

	//Enemy
	ImageList["Enemy1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/enemy1.bmp");
	ImageList["Enemy2"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/enemy2.bmp");
	ImageList["Boss"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/boss.bmp");

	ImageList["Bullet1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/bullet01.bmp");
	ImageList["EnemyBullet1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/enemybullet1.bmp");
	ImageList["EnemyBullet2"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/enemybullet2.bmp");
	ImageList["EnemyBullet3"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/enemybullet3.bmp");
	ImageList["BossBullet1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/bossbullet01.bmp");
	ImageList["BossBullet2"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/bossbullet02.bmp");
	ImageList["Magic1"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/magic.bmp");
	ImageList["Magic2"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/magic2.bmp");
	ImageList["Magic3"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/magic3.bmp");
	ImageList["Knife"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/knife.bmp");

	ImageList["BossHP"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/bosshp1.bmp");
	ImageList["Power"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/power.bmp");
	ImageList["Heart"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/heart.bmp");
	ImageList["Fire"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/fire.bmp");
	ImageList["Cloud"] = (new Bitmap)->LoadBmp(L"../Resource/TH_Resource/cloud.bmp");
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

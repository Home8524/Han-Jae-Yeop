#include "Stage1.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Stage1_Back.h"
#include "Player.h"


Stage1::Stage1()
{

}

Stage1::~Stage1()
{
	Release();
}

void Stage1::Initialize()
{
	State_Back = new Stage1_Back;
	State_Back->Initialize();

	/*
	// ** Àû »ý¼º
	for (int i = 0; i < 8; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		Vector3 RandomPos = Vector3(
			float(rand() % (WindowsWidth - 120) + 60),
			float(rand() % (WindowsHeight - 120) + 60));

		pObj->SetPosition(RandomPos.x, RandomPos.y);
		pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

		EnemyList->push_back(pObj);
	}
	Vector3 Center = Vector3(WindowsWidth / 2.0f, WindowsHeight / 2.0f);

	for (int y = 0; y < TileHeightCnt; ++y)
	{
		for (int x = 0; x < TileWidthCnt; ++x)
		{
			Object* pObj = new EnemyHole;
			pObj->Initialize();

			pObj->SetPosition(
				(Center.x - ((TileWidthCnt / 2) * pObj->GetScale().x )) + pObj->GetScale().x * x,
				(Center.y - ((TileHeightCnt / 2) * pObj->GetScale().y)) + pObj->GetScale().y * y);

			EnemyList->push_back(pObj);
		}
	}

	*/
	Time = GetTickCount64();
	ImageList = Object::GetImageList();
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

void Stage1::Update()
{
	int tmp;
	tmp = State_Back->Update();

	m_pPlayer->Update();

	if (GetAsyncKeyState('Z') && tmp == 1 && Time + 100 < GetTickCount64()) {

		SceneManager::GetInstance()->SetScene(SCENEID::LEVEL);
		Time = GetTickCount64();
	}

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Update();

}

void Stage1::Render(HDC _hdc)
{
	State_Back->Render(ImageList["Buffer"]->GetMemDC());
	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Stage1::Release()
{

}
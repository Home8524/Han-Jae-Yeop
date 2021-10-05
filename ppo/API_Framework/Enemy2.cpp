#include "Enemy2.h"
#include "ObjectManager.h"
#include "Bullet.h"
#include "EnemyBullet1.h"
#include "EnemyBullet2.h"
#include "EnemyBullet3.h"
#include "EnemyBullet4.h"
#include "EnemyBullet5.h"
#include "ObjectFactory.h"
Enemy2::Enemy2()
{

}

Enemy2::~Enemy2()
{

}

void Enemy2::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(32.0f, 32.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(32.0f, 32.0f);

	Offset = Vector3(32.0f, 32.0f);

	Active = false;
	strKey = "Enemy2";
	HP = 5;
	SetHp(HP);
	Speed = 1.5f;
	BulletList = ObjectManager::GetInstance()->GetEnemyBulletList();
	Time = GetTickCount64();
	Time2 = GetTickCount64();
	Frame = rand() % 8;
}

int Enemy2::Update()
{
	/*
	if( !(Offset.y >= 94) )
		Offset.y += 2.5f;
	*/
	if (Time + 3000 > GetTickCount64())
	{
		if (TransInfo.Position.x > WindowsWidth / 2)
		{
			TransInfo.Position.x -= 0.8f;
		}
		else
			TransInfo.Position.x += 0.8f;
	}
	else
	{
		if (Time2 + 1000 < GetTickCount64())
		{
			Object::SetImageList(ImageList);
			BulletList->push_back(CreateBullet<EnemyBullet1>());
			BulletList->push_back(CreateBullet<EnemyBullet2>());
			BulletList->push_back(CreateBullet<EnemyBullet3>());
			BulletList->push_back(CreateBullet<EnemyBullet4>());
			BulletList->push_back(CreateBullet<EnemyBullet5>());
			Time2 = GetTickCount64();
		}
	}
	return 0;
}

void Enemy2::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2) - Offset.y - 50),
		int(TransInfo.Scale.x),
		int(Offset.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x) * Frame, 0,
		int(TransInfo.Scale.x),
		int(Offset.y),
		RGB(255, 0, 255));
}

void Enemy2::Release()
{

}

template <typename T>
Object* Enemy2::CreateBullet()
{
	Bridge* pBridge = new T;
	Transform tmp;
	tmp.Position.x = TransInfo.Position.x;
	tmp.Position.y = TransInfo.Position.y - 60;
	Object* pBullet = ObjectFactory<Bullet>::CreateObject(tmp.Position, pBridge);

	return pBullet;
}
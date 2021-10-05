#include "Enemy.h"
#include "ObjectManager.h"
#include "Bullet.h"
#include "EnemyBullet1.h"
#include "EnemyBullet2.h"
#include "EnemyBullet3.h"
#include "EnemyBullet4.h"
#include "EnemyBullet5.h"
#include "ObjectFactory.h"
Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(32.0f, 36.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(32.0f, 36.0f);

	Offset = Vector3(32.0f, 36.0f);

	Active = false;
	strKey = "Enemy1";
	HP = 5;
	SetHp(HP);
	Speed = 1.5f;
	BulletList = ObjectManager::GetInstance()->GetEnemyBulletList();
	Time = GetTickCount64();
	Time2 = GetTickCount64();
	Frame = rand() % 8;
}

int Enemy::Update()
{
	/*
	if( !(Offset.y >= 94) )
		Offset.y += 2.5f;
	*/
	if(Time+5000>GetTickCount64())
	TransInfo.Position.y += 1.0f;
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

void Enemy::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2) - Offset.y - 50),
		int(TransInfo.Scale.x),
		int(Offset.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x)*Frame, 0,
		int(TransInfo.Scale.x),
		int(Offset.y),
		RGB(255, 0, 255));
}

void Enemy::Release()
{

}

template <typename T>
Object* Enemy::CreateBullet()
{
	Bridge* pBridge = new T;
	Transform tmp;
	tmp.Position.x = TransInfo.Position.x;
	tmp.Position.y = TransInfo.Position.y - 60;
	Object* pBullet = ObjectFactory<Bullet>::CreateObject(tmp.Position, pBridge);

	return pBullet;
}
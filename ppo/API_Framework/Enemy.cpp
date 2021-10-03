#include "Enemy.h"
#include "ObjectManager.h"
#include "Bullet.h"
#include "EnemyBullet1.h"
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
	HP = 10;
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
	if(Time+7000>GetTickCount64()||TransInfo.Position.y<140)
	TransInfo.Position.y += 0.5f;
	else
	{
		if (Time2 + 500 < GetTickCount64())
		{
			Object::SetImageList(ImageList);
			BulletList->push_back(CreateBullet<EnemyBullet1>());
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

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

	return pBullet;
}
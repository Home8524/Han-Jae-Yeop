#include "Boss.h"
#include "ObjectManager.h"
#include "Bullet.h"
#include "Blt.h"
#include "ObjectFactory.h"
Boss::Boss()
{

}

Boss::~Boss()
{

}

void Boss::Initialize()
{
	TransInfo.Position = Vector3(300.0f, 50.0f);
	TransInfo.Scale = Vector3(32.0f, 48.0f);

	Collider.Position = Vector3(300.0f, 50.0f);
	Collider.Scale = Vector3(32.0f, 48.0f);

	Offset = Vector3(32.0f, 48.0f);

	Active = false;
	strKey = "Boss";
	HP = 150;
	SetHp(HP);
	Speed = 1.5f;
	BulletList = ObjectManager::GetInstance()->GetEnemyBulletList();
	Time = GetTickCount64();
	Time2 = GetTickCount64();
	Time3 = GetTickCount64();
	Frame = 200;
	MoveTerm = 5000;
	Left = true;
	Cnt = 1;
	HpBar = false;
}

int Boss::Update()
{
	/*
	if( !(Offset.y >= 94) )
		Offset.y += 2.5f;
	*/
	//페이즈1
	if (HP >= 100 && HP <125)
	{
		if (Time2 + 1000 < GetTickCount64())
		{
			Object::SetImageList(ImageList);
			BulletList->push_back(CreateBullet<BigBullet>());
			BulletList->push_back(CreateBullet<EnemyBullet1>());
			BulletList->push_back(CreateBullet<EnemyBullet2>());
			BulletList->push_back(CreateBullet<EnemyBullet3>());
			BulletList->push_back(CreateBullet<EnemyBullet4>());
			BulletList->push_back(CreateBullet<EnemyBullet5>());
			Time2 = GetTickCount64();
		}
		Frame = 200;
	}
	else if (HP >= 50 && HP < 75)
	{
		Object::SetImageList(ImageList);
		if (Time2 + 1000 < GetTickCount64())
		{
			BulletList->push_back(CreateBullet<BossBullet1>());
			BulletList->push_back(CreateBullet<BossBullet2>());
			BulletList->push_back(CreateBullet<BossBullet3>());
			BulletList->push_back(CreateBullet<BossBullet4>());
			BulletList->push_back(CreateBullet<BossBullet5>());
			BulletList->push_back(CreateBullet<BossBullet6>());
			BulletList->push_back(CreateBullet<BossBullet7>());
			BulletList->push_back(CreateBullet<BossBullet8>());
			Time2 = GetTickCount64();
		}
		if (Time3 + 500 < GetTickCount64())
		{
			BulletList->push_back(CreateBullet<Sbullet1>());
			BulletList->push_back(CreateBullet<Sbullet2>());
			BulletList->push_back(CreateBullet<Sbullet3>());
			BulletList->push_back(CreateBullet<Sbullet4>());
			BulletList->push_back(CreateBullet<Sbullet5>());
			BulletList->push_back(CreateBullet<Sbullet6>());
			BulletList->push_back(CreateBullet<Sbullet7>());
			BulletList->push_back(CreateBullet<Sbullet8>());
			BulletList->push_back(CreateBullet<Sbullet9>());
			BulletList->push_back(CreateBullet<Sbullet10>());
			BulletList->push_back(CreateBullet<Sbullet11>());
			BulletList->push_back(CreateBullet<Sbullet12>());
			BulletList->push_back(CreateBullet<Sbullet13>());
			BulletList->push_back(CreateBullet<Sbullet14>());
			BulletList->push_back(CreateBullet<Sbullet15>());
			BulletList->push_back(CreateBullet<Sbullet16>());
			Time3 = GetTickCount64();
		}
		Frame = 200;
	}
	//기본패턴
	else if (Time + 1000 > GetTickCount64())
		TransInfo.Position.y += 1.0f;
	else if (Time + MoveTerm > GetTickCount64() && Time+(MoveTerm-2000) < GetTickCount64())
	{
		if(!Left)
			TransInfo.Position.x += 1.2f;
		else
			TransInfo.Position.x -= 1.2f;
		if (Frame != 0) Frame--;
	}
	else
	{
		if (Frame != 200) {
			Cnt++;
			MoveTerm += 5000;
		}
		Frame = 200;
		if (Cnt == 2)
		{
			Cnt = 0;
			Left = !Left;
		}

		//디폴트 탄막
		if (Time2 + 500 < GetTickCount64())
		{
			HpBar = true;
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

void Boss::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2) - Offset.y - 50),
		int(TransInfo.Scale.x),
		int(Offset.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x) * (Frame/50),
		0,
		int(TransInfo.Scale.x),
		int(Offset.y),
		RGB(255, 0, 255));

	if (HpBar)
	{
		int Tmp;
		int Hpsave;
		if (HP > 100)
		{
			Hpsave = HP - 100;
			Tmp = 0;
		}
		else if (HP > 50)
		{
			Hpsave = HP - 50;
			Tmp = 1;
		}
		else
		{
			Hpsave = HP;
			Tmp = 2;
		}
		TransparentBlt(_hdc, // ** 최종 출력 위치
			100,
			10,
			Hpsave*9,
			10,
			ImageList["BossHP"]->GetMemDC(),
			50*Tmp,
			0,
			50,
			10,
			RGB(255, 0, 255));
	}
}

void Boss::Release()
{

}

template <typename T>
Object* Boss::CreateBullet()
{
	Bridge* pBridge = new T;
	Transform tmp;
	tmp.Position.x = TransInfo.Position.x;
	tmp.Position.y = TransInfo.Position.y - 60;
	Object* pBullet = ObjectFactory<Bullet>::CreateObject(tmp.Position, pBridge);

	return pBullet;
}
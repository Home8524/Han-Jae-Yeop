#include "BigBullet.h"
#include "Object.h"
#include "ObjectManager.h"
#include "MathManager.h"
BigBullet::BigBullet()
{

}

BigBullet::~BigBullet()
{

}


void BigBullet::Initialize()
{
	Speed = 2.0f;

	ImageList = Object::GetImageList();
	DrawKey = "BossBullet2";
	Player = ObjectManager::GetInstance()->GetPlayer();

	Vector3 _Pos;
	_Pos.x = RealObject->GetPosition().x;
	_Pos.y = RealObject->GetPosition().y;
	float Tp = MathManager::GetDistance(_Pos, Player->GetPosition());

	Tmp.Direction = MathManager::GetDirection(_Pos, Player->GetPosition());

}

int BigBullet::Update(Transform& _rTransInfo)
{
	
	Vector3 _Pos;
	_Pos = Tmp.Direction;
	_rTransInfo.Direction = _Pos;
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += 1.0f * Speed;
	


	if (_rTransInfo.Position.x >= (WindowsWidth - 100)|| _rTransInfo.Position.x<0)
		return 1;
	else if (_rTransInfo.Position.y >= WindowsHeight|| _rTransInfo.Position.y<0)
		return 1;

	return 0;
}


void BigBullet::Render(HDC _hdc)
{
	
	for (int i = 3; i >0 ; --i)
	{
		for (int j = i; j > 0; --j)
		{
			int tmp = j - 5;
			TransparentBlt(_hdc, // ** 최종 출력 위치
				int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)+(tmp*20)+80),
				int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)+(i*-20)+80),
				12,
				18,
				ImageList[DrawKey]->GetMemDC(),
				0,
				0,
				12,
				18,
				RGB(255, 0, 255));
			TransparentBlt(_hdc, // ** 최종 출력 위치
				int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2) - (tmp * 20)-80),
				int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2) + (i * -20) + 80),
				12,
				18,
				ImageList[DrawKey]->GetMemDC(),
				0,
				0,
				12,
				18,
				RGB(255, 0, 255));
		}
	}

	
}

void BigBullet::Release()
{

}
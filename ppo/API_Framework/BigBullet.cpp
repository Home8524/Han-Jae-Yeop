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
	DrawKey = "BossBullet1";
	Player = ObjectManager::GetInstance()->GetPlayer();
	/*
	if (Player->GetPosition().x - RealObject->GetPosition().x >= 0)
		Tmp.Direction.x = 1.0f;
	else
		Tmp.Direction.x = -1.0f;
	*/
	Tmp.Direction.x = Player->GetPosition().x - RealObject->GetPosition().x;
}

int BigBullet::Update(Transform& _rTransInfo)
{
	
	//_rTransInfo.Position.x += Tmp.Direction.x/30.0f;
	//_rTransInfo.Position.y -= _rTransInfo.Direction.y * Speed;
	Vector3 _Pos;
	_Pos.x = _rTransInfo.Position.x;
	_Pos.y = _rTransInfo.Position.y;
	float Tmp = MathManager::GetDistance(_Pos, Player->GetPosition());
	if (Tmp)
	{
		_rTransInfo.Direction = MathManager::GetDirection(_rTransInfo.Position, Player->GetPosition());
			//printf("%.2f %.2f \n", Player->GetPosition().x, _rTransInfo.Position.x);
			//printf("방향 %.2f\n", _rTransInfo.Direction.x);
		_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
		_rTransInfo.Position.y += 1.0f * Speed;
	}


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
				10,
				10,
				ImageList[DrawKey]->GetMemDC(),
				0,
				0,
				32,
				32,
				RGB(255, 0, 255));
			TransparentBlt(_hdc, // ** 최종 출력 위치
				int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2) - (tmp * 20)-80),
				int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2) + (i * -20) + 80),
				10,
				10,
				ImageList[DrawKey]->GetMemDC(),
				0,
				0,
				32,
				32,
				RGB(255, 0, 255));
		}
	}

	
}

void BigBullet::Release()
{

}
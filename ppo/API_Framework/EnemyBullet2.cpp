#include "EnemyBullet2.h"
#include "Object.h"
EnemyBullet2::EnemyBullet2()
{

}

EnemyBullet2::~EnemyBullet2()
{

}


void EnemyBullet2::Initialize()
{
	Speed = 2.0f;
	DrawKey = "EnemyBullet1";
	ImageList = Object::GetImageList();
}

int EnemyBullet2::Update(Transform& _rTransInfo)
{
	int tmp = Object::GetMobNum();
	if (tmp == 0)
	{
		DrawKey = "EnemyBullet1";
	}
	if (tmp == 1)
	{
		DrawKey = "EnemyBullet2";
	}
	_rTransInfo.Position.x += 1.0f * Speed * -1;
	//_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed * -1;

	if (_rTransInfo.Position.x >= (WindowsWidth) || _rTransInfo.Position.x < 0)
		return 1;
	else if(_rTransInfo.Position.y>=WindowsHeight)
		return 1;
	return 0;
}


void EnemyBullet2::Render(HDC _hdc)
{


	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		16,
		16,
		ImageList[DrawKey]->GetMemDC(),
		0,
		0,
		16,
		16,
		RGB(255, 0, 255));

}

void EnemyBullet2::Release()
{

}
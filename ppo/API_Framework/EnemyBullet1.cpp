#include "EnemyBullet1.h"
#include "Object.h"
EnemyBullet1::EnemyBullet1()
{

}

EnemyBullet1::~EnemyBullet1()
{

}


void EnemyBullet1::Initialize()
{
	Speed = 3.0f;
	DrawKey = "Bullet1";

	ImageList = Object::GetImageList();
}

int EnemyBullet1::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed*-1;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed*-1;

	if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		return 1;

	return 0;
}


void EnemyBullet1::Render(HDC _hdc)
{


	TransparentBlt(_hdc, // ** 최종 출력 위치
		3 + int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		80 + int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		17,
		16,
		ImageList[DrawKey]->GetMemDC(),
		0,
		0,
		17,
		16,
		RGB(255, 0, 255));

}

void EnemyBullet1::Release()
{

}

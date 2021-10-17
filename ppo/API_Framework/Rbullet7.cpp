#include "Rbullet7.h"
#include "Object.h"
Rbullet7::Rbullet7()
{

}

Rbullet7::~Rbullet7()
{

}


void Rbullet7::Initialize()
{
	Speed = 5.0f;
	DrawKey = "EnemyBullet3";
	ImageList = Object::GetImageList();
}

int Rbullet7::Update(Transform& _rTransInfo)
{


	_rTransInfo.Position.x += -1.0f * Speed;
	_rTransInfo.Position.y += 0.3f * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth) || _rTransInfo.Position.x < 0)
		return 1;
	else if (_rTransInfo.Position.y >= WindowsHeight || _rTransInfo.Position.y < 0)
		return 1;
	return 0;
}


void Rbullet7::Render(HDC _hdc)
{


	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		17,
		17,
		ImageList[DrawKey]->GetMemDC(),
		0,
		0,
		17,
		17,
		RGB(255, 0, 255));

}

void Rbullet7::Release()
{

}
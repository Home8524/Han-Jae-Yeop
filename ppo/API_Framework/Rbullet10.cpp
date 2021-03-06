#include "Rbullet10.h"
#include "Object.h"
Rbullet10::Rbullet10()
{

}

Rbullet10::~Rbullet10()
{

}


void Rbullet10::Initialize()
{
	Speed = 5.0f;
	DrawKey = "EnemyBullet3";
	ImageList = Object::GetImageList();
}

int Rbullet10::Update(Transform& _rTransInfo)
{


	_rTransInfo.Position.x += 0.3f * Speed;
	_rTransInfo.Position.y += -1.0f * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth) || _rTransInfo.Position.x < 0)
		return 1;
	else if (_rTransInfo.Position.y >= WindowsHeight || _rTransInfo.Position.y < 0)
		return 1;
	return 0;
}


void Rbullet10::Render(HDC _hdc)
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

void Rbullet10::Release()
{

}
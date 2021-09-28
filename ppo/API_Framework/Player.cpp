#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Bullet.h"
#include "NormalBullet.h"
#include "BigBullet.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	//플레이어 이미지
	TransInfo.Position = Vector3(WindowsWidth / 2, WindowsHeight / 2);
	TransInfo.Scale = Vector3(32.0f, 50.0f);

	//충돌체
	Collider.Position = Vector3(TransInfo.Position.x, TransInfo.Position.y - 20.0f);
	Collider.Scale = Vector3(120.0f, 60.0f);

	strKey = "Player1";
	Active = false;

	Speed = 3.0f;

	Drop = false;
	bJump = false;

	Frame = 0;
	OldPositionY = 0.0f;
	JumpSpeed = 8.0f;
	JumpTime = 0.0f;

	Offset = Vector3(5.0f, -12.0f);

	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	
	if (dwKey & KEY_UP)
	{
		strKey = "Player1";
		if (Frame != 20) Frame++;
		else Frame = 0;
		TransInfo.Position.y -= 2;
		Collider.Position.y  -= 2;
	}
	if (dwKey & KEY_DOWN)
	{
		strKey = "Player1";
		if (Frame != 20) Frame++;
		else Frame = 0;
		TransInfo.Position.y += 2;
		Collider.Position.y += 2;
	}
	if (dwKey & KEY_LEFT)
	{
		strKey = "Player3";
		if (Frame != 20) Frame++;
		else Frame = 0;
		TransInfo.Position.x -= 2;
		Collider.Position.x -= 2;
	}
	if (dwKey & KEY_RIGHT)
	{
		strKey = "Player2";
		if (Frame != 20) Frame++;
		else Frame = 0;
		TransInfo.Position.x += 2;
		Collider.Position.x += 2;
	}
	
	if (GetAsyncKeyState('A'))
	{
		BulletList->push_back(CreateBullet<NormalBullet>());
	}

	


	return 0;
}

void Player::Render(HDC _hdc)
{
	//플레이어 이미지 띄울것(아직 이미지없음)
	TransparentBlt(_hdc, 
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)+Offset.x),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + Offset.y),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * (Frame/5)),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
	
	//판정히트박스
	Ellipse(_hdc, Collider.Position.x, Collider.Position.y, Collider.Position.x + 10, Collider.Position.y + 10);

}

void Player::Release()
{
	
}

void Player::Jump()
{
	if (bJump)
		return;

	bJump = true;
	OldPositionY = TransInfo.Position.y;
	JumpTime = 0.0f;
}

template <typename T>
Object* Player::CreateBullet()
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

	return pBullet;
}

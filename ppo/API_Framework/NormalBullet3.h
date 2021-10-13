#pragma once
#include "BulletBridge.h"

class NormalBullet3 : public BulletBridge
{
public:
	map<string, Bitmap*> ImageList;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	NormalBullet3();
	virtual ~NormalBullet3();
};


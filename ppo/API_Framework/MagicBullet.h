#pragma once
#include "BulletBridge.h"

class MagicBullet : public BulletBridge
{
public:
	map<string, Bitmap*> ImageList;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	MagicBullet();
	virtual ~MagicBullet();
};


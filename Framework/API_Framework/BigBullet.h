#pragma once
#include "BulletBridge.h"
class BigBullet : public BulletBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	BigBullet();
	virtual ~BigBullet();
};


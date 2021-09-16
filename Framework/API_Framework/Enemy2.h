#pragma once
#include "Object.h"

class Enemy2 : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Enemy2(*this); }
public:
	Enemy2();
	Enemy2(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Enemy2();
};

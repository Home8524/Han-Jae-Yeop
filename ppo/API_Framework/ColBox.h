#include "Object.h"

class ColBox : public Object
{
public:
	int Frame;
	ULONGLONG Time;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new ColBox(*this); }
public:
	ColBox();
	ColBox(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~ColBox();
};
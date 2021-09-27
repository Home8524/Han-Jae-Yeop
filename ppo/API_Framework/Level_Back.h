#include "Object.h"

class Level_Back : public Object
{
public:
	int Page_Num;
	ULONGLONG Time;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()
	{
		return new Level_Back(*this);
	};
public:
	Level_Back();
	virtual ~Level_Back();
};
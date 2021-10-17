#include "Object.h"

class End_Back : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()
	{
		return new End_Back(*this);
	};
public:
	End_Back();
	virtual ~End_Back();
};
#include "Object.h"

class Menu_Back : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()
	{
		return new Menu_Back(*this);
	};
public:
	Menu_Back();
	virtual ~Menu_Back();
};
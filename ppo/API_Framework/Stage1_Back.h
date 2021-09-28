#include "Object.h"

class Stage1_Back : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()
	{
		return new Stage1_Back(*this);
	};
public:
	Stage1_Back();
	virtual ~Stage1_Back();
};
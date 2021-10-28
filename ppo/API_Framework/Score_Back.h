#include "Object.h"

class Score_Back : public Object
{
public:
	int LoadDate(const char* _FileName);
	vector<int>* NumberList;
	Bitmap* Image;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()
	{
		return new Score_Back(*this);
	};
public:
	Score_Back();
	virtual ~Score_Back();
};
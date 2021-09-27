#include "Scene.h"


class Object;
class Stage1 : public Scene
{
private:
	Object* State_Back;

	map<string, Bitmap*> ImageList;
	ULONGLONG Time;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Stage1();
	virtual ~Stage1();
};
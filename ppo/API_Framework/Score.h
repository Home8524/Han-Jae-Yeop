#include "Scene.h"

class Object;
class Score : public Scene
{
	ULONGLONG Time;
private:
	Object* ScoreBack;
	map<string, Bitmap*> ImageList;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Score();
	virtual ~Score();
};
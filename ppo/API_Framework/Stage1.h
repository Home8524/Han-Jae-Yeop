#include "Scene.h"


class Object;
class Stage1 : public Scene
{
private:
	Object* State_Back;

	map<string, Bitmap*> ImageList;
	ULONGLONG Time;

	Object* m_pPlayer;
	vector<Object*>* EnemyList;
	vector<Object*>* BulletList;
	vector<Object*>* EnemyBulletList;
	vector<Object*>* ItemList;

	int MobCnt;
	int StageCnt;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Stage1();
	virtual ~Stage1();
};
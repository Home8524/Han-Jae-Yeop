#include "Scene.h"


class Object;
class Stage1 : public Scene
{
private:
	Object* State_Back;

	map<string, Bitmap*> ImageList;
	ULONGLONG Time;
	ULONGLONG Time2;

	Object* m_pPlayer;
	Object* Effect;
	vector<Object*>* EnemyList;
	vector<Object*>* BulletList;
	vector<Object*>* EnemyBulletList;
	vector<Object*>* ItemList;

	int MobCnt;
	int StageCnt;
	int Flag;
	int SoundSt;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Stage1();
	virtual ~Stage1();
};
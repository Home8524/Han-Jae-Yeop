#include "cocos2d.h"
#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class po:public cocos2d::Scene
{

public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	//���� Scene���� ������ �� �ڵ����� ȣ��Ǵ� �Լ�
	void onEnter();

	//���� Scene���� Ż���� �� �ڵ����� ȣ��Ǵ� �Լ�
	void onExit();

	//��ġ �̺�Ʈ�� �ݹ��Լ�
	//���� ������� �ʾƵ� ������ ���Ǽ��� ���ؼ� �̸� �����δ� ���� ���ϴ�.
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onKeyPressed
	(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased
	(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void startmoveing(float dt);
	void stopmoveing();
	void walkloading(float dt);
	void eatStart();
	void cmp(int a, int b, int i);
	void eatMob(float dt);
	void c_reset();
	void c_reset2(int i);
	void bullet1(float dt);
	void bullet2(float dt);
	void slash();
	void layerscan(); //���̾� ǥ��
	bool coltest();
	
	void fly(float dt);
	void nextscene();
	//���̵�
	void doPushScene();
	cocos2d::TransitionScene* createTransition
	(int nIndex, float t, cocos2d::Scene* s);

	CREATE_FUNC(po);
private:
	

	cocos2d::EventListenerTouchOneByOne* _listener;
	cocos2d::EventListenerKeyboard* _listener2;

#pragma region �浹üũ�� ���̾�

	
	cocos2d::Layer* layer2;
	cocos2d::Layer* layer3;
	cocos2d::Layer* layer4;
	cocos2d::Layer* layer5;
	cocos2d::Layer* layer6;
	cocos2d::Layer* mob_hi[3];
	cocos2d::Layer* hit[3];
	cocos2d::Layer* next;
#pragma endregion
	//����������Ʈ
	cocos2d::Sprite* Mob[3];
	bool mob_alive[3];
	int mob_hp[3];
	
	//����Ʈ ��������Ʈ

	int layer_sight=0;
	int repeat_nop;

	//�� �̵���
	int mob_timer1;
	int mob_timer2;
	int mob_timer3;

	//�� ��ȯ��
	int m_n[3];
};

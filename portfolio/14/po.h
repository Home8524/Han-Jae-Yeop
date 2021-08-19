#include "cocos2d.h"
#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class po:public cocos2d::Scene
{

public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	//현재 Scene으로 진입할 때 자동으로 호출되는 함수
	void onEnter();

	//현재 Scene에서 탈출할 때 자동으로 호출되는 함수
	void onExit();

	//터치 이벤트용 콜백함수
	//당장 사용하지 않아도 나중의 편의성을 위해서 미리 만들어두는 것이 편하다.
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
	void layerscan(); //레이어 표시
	bool coltest();
	
	void fly(float dt);
	void nextscene();
	//씬이동
	void doPushScene();
	cocos2d::TransitionScene* createTransition
	(int nIndex, float t, cocos2d::Scene* s);

	CREATE_FUNC(po);
private:
	

	cocos2d::EventListenerTouchOneByOne* _listener;
	cocos2d::EventListenerKeyboard* _listener2;

#pragma region 충돌체크용 레이어

	
	cocos2d::Layer* layer2;
	cocos2d::Layer* layer3;
	cocos2d::Layer* layer4;
	cocos2d::Layer* layer5;
	cocos2d::Layer* layer6;
	cocos2d::Layer* mob_hi[3];
	cocos2d::Layer* hit[3];
	cocos2d::Layer* next;
#pragma endregion
	//몹스프라이트
	cocos2d::Sprite* Mob[3];
	bool mob_alive[3];
	int mob_hp[3];
	
	//이펙트 스프라이트

	int layer_sight=0;
	int repeat_nop;

	//몹 이동용
	int mob_timer1;
	int mob_timer2;
	int mob_timer3;

	//몹 변환용
	int m_n[3];
};

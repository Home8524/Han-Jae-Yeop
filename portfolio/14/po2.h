#pragma once
#include "cocos2d.h"
#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class po2 :public cocos2d::Scene
{

public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	//몹 무빙, 공격 스프라이트
	cocos2d::Sprite* mob_createwalk();
	cocos2d::Sprite* mob_createatk();

	//변신후 스프라이트
	cocos2d::Sprite* c_create1();
	cocos2d::Sprite* c_create2();
	cocos2d::Sprite* c_create3();
	cocos2d::Sprite* c_create4();
	cocos2d::Sprite* c_create5();

	//변신전 스프라이트

	cocos2d::Sprite* make1();
	cocos2d::Sprite* make2();
	cocos2d::Sprite* make3();
	cocos2d::Sprite* make4();
	int mob_walk(cocos2d::Sprite* sprite,int time);
	
	CREATE_FUNC(po2);
private:
	cocos2d::Layer* layer1;
	cocos2d::Sprite* pSprite;
	cocos2d::Sprite* pSprite2;
};
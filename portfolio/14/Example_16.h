#pragma once
#include "cocos2d.h"

class Example_16 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example_16);

private:
	void doPushScene(Ref* pSender);


	cocos2d::TransitionScene* createTransition
	(int nIndex, float t, cocos2d::Scene* s);
};
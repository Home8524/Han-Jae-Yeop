#include "po2.h"
#include "setDefine.h"

USING_NS_CC;
static int a1 = 0;

cocos2d::Scene * po2::createScene()
{
	return po2::create();
}

bool po2::init()
{

	if (!Scene::init()) return false;
	
	return true;
}

cocos2d::Sprite * po2::mob_createatk()
{
	
		//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
		auto cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("kirby/mob/mob1_atk.plist");

		//cocos2d::vector
		Vector<SpriteFrame*>animFrames;

		//Vector에 SpriteFrame 삽입
		for (int i = 0; i < 5; i++)
		{
			//StringUtils::format = 지정된 형식으로 string을 만들어준다
			std::string _frames = StringUtils::format("mob1_atk%02d.png", i + 1);

			//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
			SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

			//spriteframe 벡터에 삽입
			animFrames.pushBack(frame);
		}
		//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
		auto pe = Sprite::createWithSpriteFrameName("mob1_atk01.png");
		pe->setScale(3.0f);

		//animation 설정
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		auto animate = Animate::create(animation);
		auto rep = RepeatForever::create(animate);
		pe->runAction(rep);
	
	return pe;
}

cocos2d::Sprite * po2::c_create1()
{
	//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("kirby/cha2/cha2_01.plist");

	//cocos2d::vector
	Vector<SpriteFrame*>animFrames;

	//Vector에 SpriteFrame 삽입
	for (int i = 0; i < 4; i++)
	{
		//StringUtils::format = 지정된 형식으로 string을 만들어준다
		std::string _frames = StringUtils::format("cha2_%02d.png", i + 1);

		//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//spriteframe 벡터에 삽입
		animFrames.pushBack(frame);
	}
	//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
	auto pe = Sprite::createWithSpriteFrameName("cha2_01.png");
	pe->setScale(3.0f);

	//animation 설정
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pe->runAction(rep);

	return pe;
}

cocos2d::Sprite * po2::c_create2()
{
	//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("kirby/cha2/cha2_02.plist");

	//cocos2d::vector
	Vector<SpriteFrame*>animFrames;

	//Vector에 SpriteFrame 삽입
	for (int i = 0; i < 4; i++)
	{
		//StringUtils::format = 지정된 형식으로 string을 만들어준다
		std::string _frames = StringUtils::format("cha3_%02d.png", i + 1);

		//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//spriteframe 벡터에 삽입
		animFrames.pushBack(frame);
	}
	//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
	auto pe = Sprite::createWithSpriteFrameName("cha3_01.png");
	pe->setScale(3.0f);

	//animation 설정
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pe->runAction(rep);

	return pe;
}

cocos2d::Sprite * po2::c_create3()
{
	//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("kirby/cha2/cha2_03.plist");

	//cocos2d::vector
	Vector<SpriteFrame*>animFrames;

	//Vector에 SpriteFrame 삽입
	for (int i = 0; i < 4; i++)
	{
		//StringUtils::format = 지정된 형식으로 string을 만들어준다
		std::string _frames = StringUtils::format("char4_%02d.png", i + 1);

		//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//spriteframe 벡터에 삽입
		animFrames.pushBack(frame);
	}
	//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
	auto pe = Sprite::createWithSpriteFrameName("char4_01.png");
	pe->setScale(3.0f);

	//animation 설정
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pe->runAction(rep);

	return pe;
}

cocos2d::Sprite * po2::c_create4()
{
	//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("kirby/cha2/cha2_04.plist");

	//cocos2d::vector
	Vector<SpriteFrame*>animFrames;

	//Vector에 SpriteFrame 삽입
	for (int i = 0; i < 5; i++)
	{
		//StringUtils::format = 지정된 형식으로 string을 만들어준다
		std::string _frames = StringUtils::format("cha5_%02d.png", i + 1);

		//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//spriteframe 벡터에 삽입
		animFrames.pushBack(frame);
	}
	//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
	auto pe = Sprite::createWithSpriteFrameName("cha5_01.png");
	pe->setScale(3.0f);

	//animation 설정
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pe->runAction(rep);

	return pe;
}

cocos2d::Sprite * po2::c_create5()
{
	//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("kirby/cha2/cha2_05.plist");

	//cocos2d::vector
	Vector<SpriteFrame*>animFrames;

	//Vector에 SpriteFrame 삽입
	for (int i = 0; i < 2; i++)
	{
		//StringUtils::format = 지정된 형식으로 string을 만들어준다
		std::string _frames = StringUtils::format("ch06_%02d.png", i + 1);

		//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//spriteframe 벡터에 삽입
		animFrames.pushBack(frame);
	}
	//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
	auto pe = Sprite::createWithSpriteFrameName("ch06_01.png");
	pe->setScale(3.0f);

	//animation 설정
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pe->runAction(rep);

	return pe;
}

int po2::mob_walk(Sprite * sprite,int time)
{
	time++;
	if (time <100) {
		sprite->setFlippedX(false);
	}
	else {
		sprite->setFlippedX(true);
	}

	if (time == 200) time = 0;
	if (time < 100)
	{
		sprite->setPositionX(sprite->getPositionX() + 1);
	}
	else
	{
		sprite->setPositionX(sprite->getPositionX() - 1);
	}

	return time;
}

cocos2d::Sprite * po2::mob_createwalk()
{

	
		//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
		auto cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("kirby/mob/mob1_walk.plist");

		//cocos2d::vector
		Vector<SpriteFrame*>animFrames;

		//Vector에 SpriteFrame 삽입
		for (int i = 0; i < 5; i++)
		{
			//StringUtils::format = 지정된 형식으로 string을 만들어준다
			std::string _frames = StringUtils::format("mob1_walk%02d.png", i + 1);

			//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
			SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

			//spriteframe 벡터에 삽입
			animFrames.pushBack(frame);
		}
		//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
		auto ps = Sprite::createWithSpriteFrameName("mob1_walk01.png");
		ps->setScale(3.0f);

		//animation 설정
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.10f);
		auto animate = Animate::create(animation);
		auto rep = RepeatForever::create(animate);
		ps->runAction(rep);
	

	return ps;
}

cocos2d::Sprite *po2::make1()
{

	//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("kirby/cha1/sp1.plist");

	//cocos2d::vector
	Vector<SpriteFrame*>animFrames;

	//Vector에 SpriteFrame 삽입
	for (int i = 0; i < 10; i++)
	{
		//StringUtils::format = 지정된 형식으로 string을 만들어준다
		std::string _frames = StringUtils::format("0%02d.png", i + 1);

		//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//spriteframe 벡터에 삽입
		animFrames.pushBack(frame);
	}
	//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
	auto sp = Sprite::createWithSpriteFrameName("010.png");
	sp->setScale(3.0f);

	//animation 설정
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.05f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	sp->runAction(rep);

	return sp;

}

cocos2d::Sprite * po2::make2()
{
	//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("kirby/cha1/sp2.plist");

	//cocos2d::vector
	Vector<SpriteFrame*>animFrames;

	//Vector에 SpriteFrame 삽입
	for (int i = 0; i < 8; i++)
	{
		//StringUtils::format = 지정된 형식으로 string을 만들어준다
		std::string _frames = StringUtils::format("1_0%02d.png", i + 1);

		//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//spriteframe 벡터에 삽입
		animFrames.pushBack(frame);
	}
	//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
	auto sp = Sprite::createWithSpriteFrameName("1_008.png");
	sp->setScale(3.0f);

	//animation 설정
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.05f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	sp->runAction(rep);
	return sp;

}

cocos2d::Sprite * po2::make3()
{

	//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("kirby/cha1/sp3.plist");

	//cocos2d::vector
	Vector<SpriteFrame*>animFrames;

	//Vector에 SpriteFrame 삽입
	for (int i = 0; i < 5; i++)
	{
		//StringUtils::format = 지정된 형식으로 string을 만들어준다
		std::string _frames = StringUtils::format("2_0%02d.png", i + 1);

		//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//spriteframe 벡터에 삽입
		animFrames.pushBack(frame);
	}
	//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
	auto sp = Sprite::createWithSpriteFrameName("2_005.png");
	sp->setScale(3.0f);


	//animation 설정
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.05f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	sp->runAction(rep);
	return sp;
}

cocos2d::Sprite * po2::make4()
{

	//외부 프로그램을 사용하여 만든 plist 파일이 있어야 한다.
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("kirby/cha1/sp4.plist");

	//cocos2d::vector
	Vector<SpriteFrame*>animFrames;

	//Vector에 SpriteFrame 삽입
	for (int i = 0; i < 7; i++)
	{
		//StringUtils::format = 지정된 형식으로 string을 만들어준다
		std::string _frames = StringUtils::format("eat%d.png", i + 1);

		//추출한 문자열을 이용하여 plist 내부의 sprite 정보를 받아온다
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//spriteframe 벡터에 삽입
		animFrames.pushBack(frame);
	}
	//plist 기반으로 만든 spriteframe 정보를 활용해 sprite객체만들기
	auto sp = Sprite::createWithSpriteFrameName("eat1.png");
	sp->setScale(3.0f);


	//animation 설정
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.05f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	sp->runAction(rep);

	return sp;
}


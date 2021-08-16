#include "Moving.h"
#include "setDefine.h"

void Moving::movemove()
{
	//log("%d", NUM);
	playerlayer->setPositionX(PLAYER2->getPositionX() - 100);
	playerlayer->setPositionY(PLAYER2->getPositionY() - 82);
	int move = 0;
	NUM++;
	
	if (NUM ==  100&&!jump_stay)
	{
		
		PLAYER->removeFromParent();
		if (Trans == 2) PLAYER = PO2->c_create2();
		else PLAYER = PO2->make2();
		PLAYER->setPosition(PLAYER2->getPosition());
		if(Trans==0) PLAYER->setPositionY(PLAYER->getPositionY() - 10);
		else if(Trans==2) PLAYER->setPositionY(PLAYER->getPositionY() + 10);
		layer1->addChild(PLAYER);
	}
	
	if (NUM >= 100&&!jump_stay) move = 2;
	else move = 1;

	if (flag_left||left_stay)
	{
		move *= -1;
		PLAYER->setFlipX(true);
		PLAYER->setPositionX(PLAYER->getPositionX() + move);
		PLAYER2->setPositionX(PLAYER2->getPositionX() + move);

	}
	else if (flag_right||!left_stay)
	{
		
		PLAYER->setFlipX(false);
		PLAYER->setPositionX(PLAYER->getPositionX() + move);
		PLAYER2->setPositionX(PLAYER2->getPositionX() + move);

	}
	

	//변수를 이용하여 Vec2 객체 생성
	auto resetPosition = Vec2(PLAYER->getPositionX() + move,
		PLAYER->getPositionY());

	auto resetPosition2 = Vec2(PLAYER2->getPositionX() + move,
		PLAYER2->getPositionY());
	// 캐릭터 스프라이트가 배경을 벗어나지 않도록 예외처리
	if (resetPosition.x < 0)
	{
		resetPosition.x = 0;
	}
	else if (resetPosition.x > 1200 * 2)
	{
		resetPosition.x = 1200 * 2;
	}
	if (resetPosition2.x < 0)
	{
		resetPosition2.x = 0;
	}
	else if (resetPosition2.x > 1200 * 2)
	{
		resetPosition2.x = 1200 * 2;
	}
	// 재조정한 좌표를 캐릭터에 대입
	PLAYER->setPosition(resetPosition);
	PLAYER2->setPosition(resetPosition2);

	// 카메라를 캐릭터의 중심으로 설정
	auto follow = Follow::create(PLAYER, Rect(0, 0, 1200 * 2, 720));
	layer1->runAction(follow);

}
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
	

	//������ �̿��Ͽ� Vec2 ��ü ����
	auto resetPosition = Vec2(PLAYER->getPositionX() + move,
		PLAYER->getPositionY());

	auto resetPosition2 = Vec2(PLAYER2->getPositionX() + move,
		PLAYER2->getPositionY());
	// ĳ���� ��������Ʈ�� ����� ����� �ʵ��� ����ó��
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
	// �������� ��ǥ�� ĳ���Ϳ� ����
	PLAYER->setPosition(resetPosition);
	PLAYER2->setPosition(resetPosition2);

	// ī�޶� ĳ������ �߽����� ����
	auto follow = Follow::create(PLAYER, Rect(0, 0, 1200 * 2, 720));
	layer1->runAction(follow);

}
#include "Stage1.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Stage1_Back.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Enemy2.h"
#include "Boss.h"
#include "CollisionManager.h"
#include "Effect1.h"
#include "ScoreManager.h"
#include "SoundManager.h"
Stage1::Stage1()
{

}

Stage1::~Stage1()
{
	Release();
}

void Stage1::Initialize()
{
	State_Back = new Stage1_Back;
	State_Back->Initialize();
	int a = 0;
	Object::SetMobNum(a);
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	// ** �� ����
	for (int i = 0; i < 5; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		Vector3 RandomPos = Vector3(
			float(rand() % (WindowsWidth-120) + 60),
			float(rand()%200+1)*-1);

		pObj->SetPosition(RandomPos.x, RandomPos.y);
		pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

		EnemyList->push_back(pObj);
	}
	MobCnt = 5;
	//StageCnt = 0~1 ->mob1 , 2~3 -> mob2 4> boss
	StageCnt = 0;
	Time = GetTickCount64();
	Time2 = GetTickCount64();
	ImageList = Object::GetImageList();
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	int B = 0;
	m_pPlayer->SetPhase(B);
	int A = 3;
	m_pPlayer->SetHp(A);
	m_pPlayer->SetColliderPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2 + 180.0f));
	m_pPlayer->SetPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2+200.0f));
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	EnemyBulletList = ObjectManager::GetInstance()->GetEnemyBulletList();
	ItemList = ObjectManager::GetInstance()->GetItemList();
	Flag = 0;
	Effect = new Effect1;
	Effect->Initialize();
	SoundSt = 0;
}

void Stage1::Update()
{
	m_pPlayer->Update();
	Effect->Update();
	State_Back->Update();
	int Test = m_pPlayer->GetPhase();
	if (GetAsyncKeyState('X')  && Time + 100 < GetTickCount64()) {
		int Tmp = 3;
		m_pPlayer->SetHp(Tmp);
	}
	if(Test== 4) SceneManager::GetInstance()->SetScene(SCENEID::END);
	
	if(Test== 5) SceneManager::GetInstance()->SetScene(SCENEID::END);
	if (Test!= 4&& Test != 5)
	{
		for (vector<Object*>::iterator iter = EnemyList->begin();
			iter != EnemyList->end(); ++iter)
			(*iter)->Update();

		// ** �Ѿ� ����Ʈ�� progress
		for (vector<Object*>::iterator iter = EnemyBulletList->begin();
			iter != EnemyBulletList->end(); )
		{
			// ** �Ѿ��� ȭ�� ���� �Ѿ�� �Ǹ� reutrn 1 �� ��ȯ �ϰ�, 
			// ** iResult == 1�̸� �Ѿ��� ������.
			int iResult = (*iter)->Update();
			// ** Enemy ����Ʈ�� progress
			// ** �浹 ó��
			if (CollisionManager::EllipseCollision((*iter), m_pPlayer))
			{
				
				if (Time2 + 3000 < GetTickCount64())
				{
					SoundManager::GetInstance()->OnPlaySound("Hit");
					int Tmp = m_pPlayer->GetHp();
					Tmp--;
					m_pPlayer->SetHp(Tmp);
					Effect->SetPosition((*iter)->GetPosition());
					Effect->SetActive(true);
					if (Tmp == 0)
					{
						int End = 4;
						m_pPlayer->SetPhase(End);
						break;
					}
					m_pPlayer->SetColliderPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2 + 180.0f));
					m_pPlayer->SetPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2 + 200.0f));
					Time2 = GetTickCount64();
				}
			}


			// ** �Ѿ��� �����ϴ� ����.
			if (iResult == 1)
				iter = EnemyBulletList->erase(iter);
			else
				++iter;
		}
		// ������
		for (vector<Object*>::iterator iter = ItemList->begin();
			iter != ItemList->end(); )
		{
			// ** �Ѿ��� ȭ�� ���� �Ѿ�� �Ǹ� reutrn 1 �� ��ȯ �ϰ�, 
			// ** iResult == 1�̸� �Ѿ��� ������.
			int iResult = (*iter)->Update();
			// ** Enemy ����Ʈ�� progress
			// ** �浹 ó��
			if (CollisionManager::EllipseCollision((*iter), m_pPlayer))
			{
				int Sc = ScoreManager::GetInstance()->GetScore();
				Sc += 15;
				ScoreManager::GetInstance()->SetScore(Sc);
				int Tmp;
				Tmp = m_pPlayer->GetPower();
				Tmp++;
				m_pPlayer->SetPower(Tmp);
				iResult = 1;
			}


			// ** �Ѿ��� �����ϴ� ����.
			if (iResult == 1)
				iter = ItemList->erase(iter);
			else
				++iter;
		}

		// ** �Ѿ� ����Ʈ�� progress
		for (vector<Object*>::iterator iter = BulletList->begin();
			iter != BulletList->end(); )
		{
			// ** �Ѿ��� ȭ�� ���� �Ѿ�� �Ǹ� reutrn 1 �� ��ȯ �ϰ�, 
			// ** iResult == 1�̸� �Ѿ��� ������.
			int iResult = (*iter)->Update();
			// ** Enemy ����Ʈ�� progress
			for (vector<Object*>::iterator iter2 = EnemyList->begin();
				iter2 != EnemyList->end(); )
			{
				// ** �浹 ó��
				if (CollisionManager::EllipseCollision((*iter), (*iter2)))
				{
					int tmp = (*iter2)->GetHp();
					tmp--;
					(*iter2)->SetHp(tmp);
					if (tmp == 0)
					{
						SoundManager::GetInstance()->OnPlaySound("Kill");
						int Sc = ScoreManager::GetInstance()->GetScore();
						Sc += 100;
						if (m_pPlayer->GetPhase() == 3)
						{
							Sc += 1000;
							int End = 5;
							m_pPlayer->SetPhase(End);
						}
						ScoreManager::GetInstance()->SetScore(Sc);
						// ** ���� ����
						Object* pObj = new Item;
						pObj->Initialize();
						pObj->SetPosition((*iter2)->GetPosition().x, (*iter2)->GetPosition().y - 30);
						pObj->SetColliderPosition((*iter2)->GetPosition().x, (*iter2)->GetPosition().y - 30);
						ItemList->push_back(pObj);
						iter2 = EnemyList->erase(iter2);
						MobCnt--;

					}
					// ** ������ ������Ʈ�� �����ѵ�
					iResult = 1;
					// ** ���� �ݺ����� Ż��.
					// ** ���� : �Ѿ� 1���� ������ 1���� �����ϱ� ����. 
					break;
					//** break �� �ȵǸ� �Ѿ��� ������ ���������� �浹ü�� �������϶� ��� �浹�� ������.
				}
				else
					++iter2;
			}

			// ** �Ѿ��� �����ϴ� ����.
			if (iResult == 1)
				iter = BulletList->erase(iter);
			else
				++iter;
		}

		//�� ������
		if (MobCnt == 0)
		{
			//mob1
			if (StageCnt >= 0 && StageCnt < 2)
			{
				for (int i = 0; i < 8; ++i)
				{
					Object* pObj = new Enemy;
					pObj->Initialize();

					Vector3 RandomPos = Vector3(
						float(rand() % (WindowsWidth - 120) + 60),
						float(rand() % 200 + 1) * -1);

					pObj->SetPosition(RandomPos.x, RandomPos.y);
					pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

					EnemyList->push_back(pObj);
				}
			}
			//mob2
			else if (StageCnt >= 2 && StageCnt < 4)
			{
				int a = 1;
				Object::SetMobNum(a);
				for (int i = 0; i < 8; ++i)
				{
					Object* pObj = new Enemy2;
					pObj->Initialize();

					Vector3 RandomPos = Vector3(
						float(rand() % (WindowsWidth + 100)),
						float(rand() % 200 + 50));

					pObj->SetPosition(RandomPos.x, RandomPos.y);
					pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

					EnemyList->push_back(pObj);
				}
			}
			MobCnt = 8;
			//boss
			if (StageCnt == 4)
			{
				MobCnt = 1;
				Object* pObj = new Boss;
				pObj->Initialize();
				EnemyList->push_back(pObj);
			}
			StageCnt++;
		}
	}
	
}

void Stage1::Render(HDC _hdc)
{
	State_Back->Render(ImageList["Buffer"]->GetMemDC());
	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());
	bool Vis = Effect->GetActive();
	if(Vis)	Effect->Render(ImageList["Buffer"]->GetMemDC());
	
	
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	
	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	
	for (vector<Object*>::iterator iter = ItemList->begin();
		iter != ItemList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = EnemyBulletList->begin();
		iter != EnemyBulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	
	
	if (SoundSt == 0)
	{
		SoundManager::GetInstance()->OnPlaySound("BGM2");
		SoundSt++;
	}

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Stage1::Release()
{
	EnemyList->clear();
	EnemyBulletList->clear();
	ItemList->clear();
	BulletList->clear();

	EnemyList->shrink_to_fit();
	EnemyBulletList->shrink_to_fit();
	ItemList->shrink_to_fit();
	BulletList->shrink_to_fit();
}
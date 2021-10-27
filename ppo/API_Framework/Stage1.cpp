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
	// ** 적 생성
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

		// ** 총알 리스트의 progress
		for (vector<Object*>::iterator iter = EnemyBulletList->begin();
			iter != EnemyBulletList->end(); )
		{
			// ** 총알이 화면 밖을 넘어가게 되면 reutrn 1 을 반환 하고, 
			// ** iResult == 1이면 총알은 삭제됨.
			int iResult = (*iter)->Update();
			// ** Enemy 리스트의 progress
			// ** 충돌 처리
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


			// ** 총알을 삭제하는 구간.
			if (iResult == 1)
				iter = EnemyBulletList->erase(iter);
			else
				++iter;
		}
		// 아이템
		for (vector<Object*>::iterator iter = ItemList->begin();
			iter != ItemList->end(); )
		{
			// ** 총알이 화면 밖을 넘어가게 되면 reutrn 1 을 반환 하고, 
			// ** iResult == 1이면 총알은 삭제됨.
			int iResult = (*iter)->Update();
			// ** Enemy 리스트의 progress
			// ** 충돌 처리
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


			// ** 총알을 삭제하는 구간.
			if (iResult == 1)
				iter = ItemList->erase(iter);
			else
				++iter;
		}

		// ** 총알 리스트의 progress
		for (vector<Object*>::iterator iter = BulletList->begin();
			iter != BulletList->end(); )
		{
			// ** 총알이 화면 밖을 넘어가게 되면 reutrn 1 을 반환 하고, 
			// ** iResult == 1이면 총알은 삭제됨.
			int iResult = (*iter)->Update();
			// ** Enemy 리스트의 progress
			for (vector<Object*>::iterator iter2 = EnemyList->begin();
				iter2 != EnemyList->end(); )
			{
				// ** 충돌 처리
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
						// ** 몬스터 삭제
						Object* pObj = new Item;
						pObj->Initialize();
						pObj->SetPosition((*iter2)->GetPosition().x, (*iter2)->GetPosition().y - 30);
						pObj->SetColliderPosition((*iter2)->GetPosition().x, (*iter2)->GetPosition().y - 30);
						ItemList->push_back(pObj);
						iter2 = EnemyList->erase(iter2);
						MobCnt--;

					}
					// ** 삭제할 오브젝트로 지정한뒤
					iResult = 1;
					// ** 현재 반복문을 탈출.
					// ** 이유 : 총알 1개에 오브젝 1개를 삭제하기 위함. 
					break;
					//** break 가 안되면 총알이 생성된 시점에에서 충돌체가 여러개일때 모두 충돌후 삭제됨.
				}
				else
					++iter2;
			}

			// ** 총알을 삭제하는 구간.
			if (iResult == 1)
				iter = BulletList->erase(iter);
			else
				++iter;
		}

		//몹 다죽음
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
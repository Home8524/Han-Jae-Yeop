#include "Magic.h"
#include "Object.h"
#include "CollisionManager.h"
#include "ObjectManager.h"
#include "ColBox.h"
Magic::Magic()
{

}

Magic::~Magic()
{

}


void Magic::Initialize()
{
	Speed = 3.0f;
	DrawKey = "Magic1";
	ImageList = Object::GetImageList();
	Time = GetTickCount64();
	Time2 = GetTickCount64();
	Flag = 0;
	T.clear();
	T.shrink_to_fit();
	
	for (int i = 0; i < 8; ++i)
	{
		if (i == 3) continue;
		int j = 0;
		int k = 0;
		if (i >= 6)
		{
			k = 30;
			j = 100 + 360 * (i - 6) - 40 + ((i - 5) * 120);
		}
		Object* Tmp = new ColBox;
		Tmp->SetPosition(WindowsWidth - (120 * i) + j + 24, 50 - k + 30);
		Vector3 Save;
		Save.x = 16;
		Save.y = 500;
		Tmp->SetScale(Save);
		T.push_back(Tmp);
	}
	
}

int Magic::Update(Transform& _rTransInfo)
{

	if (Time + 1000 < GetTickCount64())
	{
		Flag = 1;
	}
	if (Time + 2000 < GetTickCount64())
	{
		Flag = 2;
		Object* m_pPlayer;
		m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

		for (vector<Object*>::iterator iter = T.begin();
			iter != T.end(); ++iter)
		{

			if (CollisionManager::RectCollision((*iter), m_pPlayer))
			{
				int Tmp = m_pPlayer->GetHp();
				Tmp--;
				m_pPlayer->SetHp(Tmp);
				if (Tmp == 0)
				{
					int End = 4;
					m_pPlayer->SetPhase(End);
					break;
				}
				m_pPlayer->SetColliderPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2 + 180.0f));
				m_pPlayer->SetPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2 + 200.0f));

			}

		}
	}
	
	if (Time + 3000 < GetTickCount64())
	{
		Flag = 3;
		Object* m_pPlayer;
		m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
		
		for (vector<Object*>::iterator iter = T.begin();
			iter != T.end();++iter )
		{
			
			if (CollisionManager::RectCollision((*iter), m_pPlayer))
			{
					int Tmp = m_pPlayer->GetHp();
					Tmp--;
					m_pPlayer->SetHp(Tmp);
					if (Tmp == 0)
					{
						int End = 4;
						m_pPlayer->SetPhase(End);
						break;
					}
					m_pPlayer->SetColliderPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2 + 180.0f));
					m_pPlayer->SetPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2 + 200.0f));
				
			}
			
		}
		
	}
	
	if (Time + 5000 < GetTickCount64())
		return 1;
	
	return 0;
}


void Magic::Render(HDC _hdc)
{
	
	for (int i = 1; i <8; i++)
	{
		if (i == 3) continue;
		int j = 0;
		int k = 0;
		if (i >= 6)
		{
			k = 30;
			j = 100+360*(i-6)- 40 + ((i-5)*120);
		}
		TransparentBlt(_hdc, // ** 최종 출력 위치
			WindowsWidth-(120*i)+j,
			50-k,
			66,
			66,
			ImageList[DrawKey]->GetMemDC(),
			0,
			0,
			66,
			66,
			RGB(255, 0, 255));
		if (Flag == 2)
		{
			TransparentBlt(_hdc, // ** 최종 출력 위치
				WindowsWidth - (120 * i) + j + 24,
				50 - k + 30,
				16,
				500,
				ImageList["Magic3"]->GetMemDC(),
				0,
				0,
				16,
				16,
				RGB(255, 0, 255));

		}
		else if (Flag == 3)
		{
			TransparentBlt(_hdc, // ** 최종 출력 위치
				WindowsWidth - (120 * i) + j + 24,
				50 - k + 30,
				16,
				500,
				ImageList["Magic3"]->GetMemDC(),
				16,
				0,
				16,
				16,
				RGB(255, 0, 255));

		}

		if (Flag >= 1)
		{
			TransparentBlt(_hdc, // ** 최종 출력 위치
				WindowsWidth - (120 * i) + j+18,
				50 - k+18,
				32,
				32,
				ImageList["Magic2"]->GetMemDC(),
				0,
				0,
				32,
				32,
				RGB(255, 0, 255));
		}
		
	}


}

void Magic::Release()
{

}
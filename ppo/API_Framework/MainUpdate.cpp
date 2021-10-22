#include "MainUpdate.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "SoundManager.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}


void MainUpdate::Initialize()
{
	SoundManager::GetInstance()->Initialize();
#pragma region LoadSound
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_01.wav", "BGM1");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_02.wav", "BGM2");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_03.wav", "BGM3");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_04.wav", "BGM4");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_05.wav", "BGM5");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_06.wav", "BGM6");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_07.wav", "BGM7");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_08.wav", "BGM8");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_09.wav", "BGM9");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_10.wav", "BGM10");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_11.wav", "BGM11");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_12.wav", "BGM12");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_13.wav", "BGM13");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_14.wav", "BGM14");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_15.wav", "BGM15");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_16.wav", "BGM16");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/th06_17.wav", "BGM17");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/forget.mp3", "BGM18");
#pragma endregion
	
	m_hdc = GetDC(g_hWnd);
	
	SceneManager::GetInstance()->SetScene(SCENEID::LOGO);
}

void MainUpdate::Update()
{
	SoundManager::GetInstance()->StreamingUpdate();

	/*
	if (GetAsyncKeyState(VK_UP))
		SoundManager::GetInstance()->VolumeUp();
	if (GetAsyncKeyState(VK_DOWN))
		SoundManager::GetInstance()->VolumeDown();
	*/


	SceneManager::GetInstance()->Update();

	InputManager::GetInstance()->CheckKey();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render(m_hdc);
}

void MainUpdate::Release()
{
	
}

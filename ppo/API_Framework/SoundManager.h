#pragma once
#include "Headers.h"
class SoundManager
{
private:
	static SoundManager* Instance;
public:
	static SoundManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SoundManager;
		return Instance;
	}
private:
	FMOD::System* m_pSystem;
	map<string, SOUNDINFO*> SoundList;
	float Volume;
public:
	void Initialize();
	void LoadSoundDate(const char* _FileName,string _Key);
	void StreamingUpdate();
	void OnPlaySound(string _Key);
	void Release();
	void VolumeUp();
	void VolumeDown();
private:
	SoundManager() {};
public:
	~SoundManager() {};
};


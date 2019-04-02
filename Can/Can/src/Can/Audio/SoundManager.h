#pragma once

#include <vector>

#include "Sound.h"

namespace Can::Audio
{
	class SoundManager
	{
	public:
	private:
		SoundManager() {}
	public:
		static void Init();
		static void Update();
		static void Add(Sound* sound);
		static Sound* Get(const std::string& name);
		static void Clean();
	private:
		friend class Sound;
		static gau_Manager* m_Manager;
		static ga_Mixer* m_Mixer;

		static std::vector<Sound*> m_Sounds;
	};
}
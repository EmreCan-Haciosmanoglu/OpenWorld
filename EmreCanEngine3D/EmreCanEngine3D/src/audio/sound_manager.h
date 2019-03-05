#pragma once
#include <vector>
#include "sound.h"

namespace EmreCan3D
{
	namespace audio
	{
		class SoundManager
		{
		public:
		private:
			SoundManager() {}
		public:
			static void init();
			static void update();
			static void add(Sound* sound);
			static Sound* get(const std::string& name);
			static void clean();
		private:
			friend class Sound;
			static gau_Manager* m_Manager;
			static ga_Mixer* m_Mixer;

			static std::vector<Sound*> m_Sounds;
		};
	}
}
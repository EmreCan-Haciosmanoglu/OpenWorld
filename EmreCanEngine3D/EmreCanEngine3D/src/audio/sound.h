#pragma once

#include <string>
#include "../../ext/gorilla-audio/gau.h"
#include "../../ext/gorilla-audio/ga.h"
namespace EmreCan3D
{
	namespace audio
	{
		class Sound
		{
		public:
			Sound(const std::string& name ,const std::string& filename);
			~Sound();
			void play();
			void loop();
			void resume();
			void pause();
			void stop();

			inline const std::string& getName() const { return m_Name; }
			inline const std::string& getFilename() const { return m_Filename; }
		private:
		public:
		private:
			std::string m_Name;
			std::string m_Filename;
			
			ga_Sound* m_Sound;
			ga_Handle* m_Handle;
		};
	}
}
#pragma once

#include <string>
#include <iostream>

#include "../utils/stringutils.h"

#include "../../ext/gorilla-audio/gau.h"
#include "../../ext/gorilla-audio/ga.h"

namespace Can
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

			void setGain(float gain);
			void setPlaying(bool playing);

			inline const float getGain() const { return m_Gain; }
			inline const bool  isPlaying() const { return m_Playing; }
			inline const std::string& getName() const { return m_Name; }
			inline const std::string& getFilename() const { return m_Filename; }
			
			friend void destroy_on_finish(ga_Handle* in_handle, void* in_context);
			friend void loop_on_finish(ga_Handle* in_handle, void* in_context);

		private:
		public:
		private:
			std::string m_Name;
			std::string m_Filename;
			
			ga_Sound* m_Sound;
			ga_Handle* m_Handle;

			float m_Gain;
			bool m_Playing;
		};
	}
}
#include "sound.h"
#include "sound_manager.h"

namespace EmreCan3D
{
	namespace audio
	{
		void destroy_on_finish(ga_Handle* in_handle, void* in_context);
		void loop_on_finish(ga_Handle* in_handle, void* in_context);

		Sound::Sound(const std::string & name, const std::string & filename)
			: m_Name(name)
			, m_Filename(filename)
			, m_Gain(0.5f)
			, m_Playing(false)
		{
			std::vector<std::string> result = string_split(filename.c_str(), '.');
			if (result.size() < 2)
			{
				std::cout << "[Sound] Invalid filename = " << filename << "!" << std::endl;
			}
			m_Sound = gau_load_sound_file(filename.c_str(), result.back().c_str());
			if(m_Sound == nullptr)
				std::cout << "[Sound] Could not load file = " << filename << "!" << std::endl;
		}
		Sound::~Sound()
		{
			ga_sound_release(m_Sound);
		}
		void Sound::play()
		{
			if (m_Playing)
				return;
			int quit = 0;
			m_Handle = gau_create_handle_sound(SoundManager::m_Mixer, m_Sound, &destroy_on_finish, &quit, NULL);
			m_Handle->sound = this;
			ga_handle_play(m_Handle);
			m_Playing = true;
		}
		void Sound::loop()
		{
			if (m_Playing)
				return;
			int quit = 0;
			m_Handle = gau_create_handle_sound(SoundManager::m_Mixer, m_Sound, &loop_on_finish, &quit, NULL);
			m_Handle->sound = this;
			ga_handle_play(m_Handle);
			m_Playing = true;
		}
		void Sound::resume()
		{
			if (m_Playing)
				return;
			ga_handle_play(m_Handle);
			m_Playing = true;
		}
		void Sound::pause()
		{
			if (!m_Playing)
				return;
			ga_handle_stop(m_Handle);
			m_Playing = false;
		}
		void Sound::stop()
		{
			if (!m_Playing)
				return;
			ga_handle_destroy(m_Handle);
			m_Playing = false;
		}
		void Sound::setGain(float gain)
		{
			if (!m_Playing)
				return;
			m_Gain = gain;
			ga_handle_setParamf(m_Handle, GA_HANDLE_PARAM_GAIN, gain);
		}
		void Sound::setPlaying(bool playing)
		{
			m_Playing = playing;
		}
		void destroy_on_finish(ga_Handle* in_handle, void* in_context)
		{
			Sound* sound = (Sound*)in_handle->sound;
			sound->setPlaying(false);

			ga_handle_destroy(in_handle);
		}
		void loop_on_finish(ga_Handle* in_handle, void* in_context)
		{
			Sound* sound = (Sound*)in_handle->sound;
			sound->setPlaying(false);
			sound->loop();

			ga_handle_destroy(in_handle);
		}
	}
}
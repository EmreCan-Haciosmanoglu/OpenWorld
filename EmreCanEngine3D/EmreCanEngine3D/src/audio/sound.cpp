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
		{
			m_Sound = gau_load_sound_file(filename.c_str(), "wav");
		}
		Sound::~Sound()
		{
			ga_sound_release(m_Sound);
		}
		void Sound::play()
		{
			int quit = 0;
			m_Handle = gau_create_handle_sound(SoundManager::m_Mixer, m_Sound, &destroy_on_finish, &quit, NULL);
			ga_handle_play(m_Handle);
		}
		void Sound::loop()
		{
			int quit = 0;
			m_Handle = gau_create_handle_sound(SoundManager::m_Mixer, m_Sound, &loop_on_finish, &quit, NULL);
			m_Handle->sound = this;
			ga_handle_play(m_Handle);
		}
		void Sound::resume()
		{
		}
		void Sound::pause()
		{
		}
		void Sound::stop()
		{
		}
		void destroy_on_finish(ga_Handle* in_handle, void* in_context)
		{
			ga_handle_destroy(in_handle);
		}
		void loop_on_finish(ga_Handle* in_handle, void* in_context)
		{
			Sound* sound = (Sound*)in_handle->sound;
			ga_handle_destroy(in_handle);
			sound->loop();	
		}
	}
}
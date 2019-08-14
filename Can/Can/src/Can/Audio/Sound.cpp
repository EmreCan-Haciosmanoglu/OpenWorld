#include "Sound.h"
#include "SoundManager.h"

namespace Can::Audio
{
	void DestroyOnFinish(ga_Handle* in_handle, void* in_context);
	void LoopOnFinish(ga_Handle* in_handle, void* in_context);

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
		if (m_Sound == nullptr)
			std::cout << "[Sound] Could not load file = " << filename << "!" << std::endl;
	}
	Sound::~Sound()
	{
		ga_sound_release(m_Sound);
	}
	void Sound::Play()
	{
		if (m_Playing)
			return;
		int quit = 0;
		m_Handle = gau_create_handle_sound(SoundManager::m_Mixer, m_Sound, &DestroyOnFinish, &quit, NULL);
		m_Handle->sound = this;
		ga_handle_play(m_Handle);
		m_Playing = true;
	}
	void Sound::Loop()
	{
		if (m_Playing)
			return;
		int quit = 0;
		m_Handle = gau_create_handle_sound(SoundManager::m_Mixer, m_Sound, &LoopOnFinish, &quit, NULL);
		m_Handle->sound = this;
		ga_handle_play(m_Handle);
		m_Playing = true;
	}
	void Sound::Resume()
	{
		if (m_Playing)
			return;
		ga_handle_play(m_Handle);
		m_Playing = true;
	}
	void Sound::Pause()
	{
		if (!m_Playing)
			return;
		ga_handle_stop(m_Handle);
		m_Playing = false;
	}
	void Sound::Stop()
	{
		if (!m_Playing)
			return;
		ga_handle_destroy(m_Handle);
		m_Playing = false;
	}
	void Sound::SetGain(float gain)
	{
		if (!m_Playing)
			return;
		m_Gain = gain;
		ga_handle_setParamf(m_Handle, GA_HANDLE_PARAM_GAIN, gain);
	}
	void Sound::SetPlaying(bool playing)
	{
		m_Playing = playing;
	}
	void DestroyOnFinish(ga_Handle* in_handle, void* in_context)
	{
		Sound* sound = (Sound*)in_handle->sound;
		sound->setPlaying(false);

		ga_handle_destroy(in_handle);
	}
	void LoopOnFinish(ga_Handle* in_handle, void* in_context)
	{
		Sound* sound = (Sound*)in_handle->sound;
		sound->setPlaying(false);
		sound->loop();

		ga_handle_destroy(in_handle);
	}
}
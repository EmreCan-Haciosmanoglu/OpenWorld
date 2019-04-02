#pragma once

#include <string>
#include <iostream>

#include "Can/Utils.h"
#include "Can/Core.h"

#include <gorilla-audio/gau.h>
#include <gorilla-audio/ga.h>


namespace Can::Audio
{
	class CAN_API Sound
	{
	public:
		Sound(const std::string& name, const std::string& filename);
		~Sound();
		void Play();
		void Loop();
		void Resume();
		void Pause();
		void Stop();

		void SetGain(float gain);
		void SetPlaying(bool playing);

		inline const float GetGain() const { return m_Gain; }
		inline const bool  IsPlaying() const { return m_Playing; }
		inline const std::string& GetName() const { return m_Name; }
		inline const std::string& GetFilename() const { return m_Filename; }

		friend void DestroyOnFinish(ga_Handle* in_handle, void* in_context);
		friend void LoopOnFinish(ga_Handle* in_handle, void* in_context);

	private:
		std::string m_Name;
		std::string m_Filename;

		ga_Sound* m_Sound;
		ga_Handle* m_Handle;

		float m_Gain;
		bool m_Playing;
	};
}
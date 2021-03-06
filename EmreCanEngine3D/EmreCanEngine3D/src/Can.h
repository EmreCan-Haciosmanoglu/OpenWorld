#pragma once

#include <Windows.h>
#include <Defines.h>

#include "graphics/label.h"
#include "graphics/sprite.h"
#include "graphics/renderer2d.h"
#include "graphics/batchrenderer2d.h"
#include "graphics/window.h"
#include "graphics/layers/layer.h"
#include "graphics/layers/group.h"
#include "graphics/TextureManager.h"
#include "graphics/window.h"

#include "graphics/shaders/shader.h"
#include "graphics/shaders/ShaderFactory.h"

#include "audio/sound.h"
#include "audio/sound_manager.h"

#include "maths/maths.h"
#include "utils/timer.h"

namespace Can
{
	class Can
	{
	public:

		void start()
		{
			init();
			run();
		}
		
	protected:
		Can()
			: m_FramesPerSecond(0)
			, m_UpdatesPerSecond(0)
		{

		}
		virtual ~Can() 
		{
			delete m_Window;
			delete m_Timer;
		}

		Graphics::Window* createWindow(const char *title, int width, int height)
		{
			m_Window = new Graphics::Window(title, width, height);
			return m_Window;
		}

		virtual void init() = 0;
		virtual void tick() {};
		virtual void update() {};
		virtual void render() = 0;

		inline const unsigned int getFPS() const { return m_FramesPerSecond; }
		inline const unsigned int getUPS() const { return m_UpdatesPerSecond; }
	private:
		void run()
		{
			m_Timer = new Timer();
			float timer = 0.0f;
			float updateTimer = 0.0f;
			float updateTick = 1.0f/60.0f;
			unsigned int frames = 0;
			unsigned int updates = 0;
			while (!m_Window->closed())
			{
				m_Window->clear();
				if (m_Timer->elapsed() - updateTimer > updateTick)
				{
					m_Window->UpdateInput();
					update();
					updates++;
					updateTimer += updateTick;
				}
				render();
				frames++;
				m_Window->update();
				if (m_Timer->elapsed() - timer > 1.0f)
				{
					timer += 1.0f;
					m_FramesPerSecond = frames;
					m_UpdatesPerSecond = updates;
					frames = 0;
					updates = 0;
					tick();
				}
			}
		}
	private:
		Timer* m_Timer;
		Graphics::Window* m_Window;

		unsigned int m_FramesPerSecond, m_UpdatesPerSecond;
	};
}
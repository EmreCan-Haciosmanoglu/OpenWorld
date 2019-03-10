#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "font_manager.h"
#include "TextureManager.h"
#include "../audio/sound_manager.h"

namespace Can
{
	namespace Graphics
	{

#define MAX_KEYS	1024
#define MAX_BUTTONS	32

		class Window
		{
		public:
			static bool m_Keys[MAX_KEYS];
			static bool m_KeyState[MAX_KEYS];
			static bool m_KeyTyped[MAX_KEYS];

			static bool m_MouseButtons[MAX_BUTTONS];
			static bool m_MouseButtonState[MAX_BUTTONS];
			static bool m_MouseButtonTyped[MAX_BUTTONS];

			static maths::vec2 m_MousePosition;
		private:
			int m_Width, m_Height;
			const char *m_Title;
			bool m_Closed;

			GLFWwindow *m_Window;
		public:
			Window(const char *title, int width, int height);
			~Window();
			void clear() const;
			bool closed() const;
			void update();

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

			const maths::vec2& getMousePosition(double &x, double &y);

			static bool isKeyPressed(unsigned int keycode);
			static bool isKeyTyped(unsigned int keycode);
			static bool isMouseButtonPressed(unsigned int button);
			static bool isMouseButtonTyped(unsigned int button);

		private:
			bool init();

			friend void window_resize(GLFWwindow *window, int width, int height);
			friend void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
			friend void mouse_button_callback(GLFWwindow * window, int button, int action, int mods);
			friend void cursor_position_callback(GLFWwindow * window, double xpos, double ypos);
		};
	}
}
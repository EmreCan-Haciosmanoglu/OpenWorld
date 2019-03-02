#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "font_manager.h"

namespace EmreCan3D
{
	namespace graphics
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

			static double m_MouseX, m_MouseY;
		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;
		public:
			Window(const char *title, int width, int height);
			~Window();
			void clear() const;
			bool closed() const;
			void update();

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

			void getMousePosition(double &x, double &y);

			static bool isKeyPressed(unsigned int keycode);
			static bool isKeyTyped(unsigned int keycode);
			static bool isMouseButtonPressed(unsigned int button);
			static bool isMouseButtonTyped(unsigned int button);
		private:
			bool init();
			static void window_resize(GLFWwindow *window, int width, int height);
			static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
			static void mouse_button_callback(GLFWwindow * window, int button, int action, int mods);
			static void cursor_position_callback(GLFWwindow * window, double xpos, double ypos);
		};
	}
}
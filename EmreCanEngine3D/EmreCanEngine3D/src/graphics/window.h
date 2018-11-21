#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>

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
			static bool m_MouseButtons[MAX_BUTTONS];
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

			static bool isKeyPressed(unsigned int keycode);
			static bool isMouseButtonPressed(unsigned int button);
		private:
			bool init();
			static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
			static void mouse_button_callback(GLFWwindow * window, int button, int action, int mods);
		};
	}
}
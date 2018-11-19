#include "window.h"

namespace EmreCan3D
{
	namespace graphics
	{
		Window::Window(const char * title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if(!init())
				glfwTerminate();
		}
		Window::~Window()
		{
			glfwTerminate();
		}
		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}
		void Window::update() const
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}
		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height,m_Title, NULL,NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);

			return true;
		}
	}
}
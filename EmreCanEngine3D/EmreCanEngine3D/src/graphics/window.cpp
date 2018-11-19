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
			init();
		}
		Window::~Window()
		{
		}
		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}
		void Window::update() const
		{
		}
		void Window::init()
		{
			m_Window = glfwCreateWindow(m_Width, m_Height,m_Title, NULL,NULL);
			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW window!" << std::endl;
				return;
			}
			glfwMakeContextCurrent(m_Window);

		}
	}
}
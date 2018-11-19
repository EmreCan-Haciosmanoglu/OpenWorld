#include "window.h"

namespace EmreCan3D
{
	namespace graphics
	{
		Window::Window(const char * name, int width, int height)
		{
			m_Name = name;
			m_Width = width;
			m_Height = height;
		}
		Window::~Window()
		{
		}
		void Window::update() const
		{
		}
		void Window::init()
		{
		}
	}
}
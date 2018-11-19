#pragma once
#include <GLFW/glfw3.h>

namespace EmreCan3D
{
	namespace graphics
	{
		class Window
		{
		private:
			const char *m_Name;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
		public:
			Window(const char *name, int width, int height);
			~Window();
			void update() const;
		};
	}
}
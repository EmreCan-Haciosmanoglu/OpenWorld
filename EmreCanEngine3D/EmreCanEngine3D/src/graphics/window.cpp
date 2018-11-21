#include "window.h"

namespace EmreCan3D
{
	namespace graphics
	{
		bool Window::m_Keys[MAX_KEYS];
		bool Window::m_MouseButtons[MAX_BUTTONS];
		double Window::m_MouseX;
		double Window::m_MouseY;

		void window_resize(GLFWwindow *window, int width, int height);

		Window::Window(const char * title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if(!init())
				glfwTerminate();
			for (bool key : Window::m_Keys)
				key = false;
			for (bool button : Window::m_MouseButtons)
				button = false;
		}
		Window::~Window()
		{
			glfwTerminate();
		}
		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}
		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}
		bool Window::isKeyPressed(unsigned int keycode)
		{

			return (keycode < MAX_KEYS) ? Window::m_Keys[keycode] : /*TODO: Log this*/false;
		}
		bool Window::isMouseButtonPressed(unsigned int button)
		{
			return (button < MAX_BUTTONS) ? Window::m_MouseButtons[button] : /*TODO: Log this*/false;
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
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, window_resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);

			std::cout << "OpenGL : " << glGetString(GL_VERSION) << std::endl;

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}

			return true;
		}

		void Window::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
		{
			Window::m_Keys[key] = action != GLFW_RELEASE;
		}

		void Window::mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
		{
			Window::m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void window_resize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}
}
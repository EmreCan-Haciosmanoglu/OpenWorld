#include "window.h"

namespace Can
{
	namespace graphics
	{
		bool Window::m_Keys[MAX_KEYS];
		bool Window::m_KeyState[MAX_KEYS];
		bool Window::m_KeyTyped[MAX_KEYS];

		bool Window::m_MouseButtons[MAX_BUTTONS];
		bool Window::m_MouseButtonState[MAX_BUTTONS];
		bool Window::m_MouseButtonTyped[MAX_BUTTONS];

		double Window::m_MouseX;
		double Window::m_MouseY;

		Window::Window(const char * title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;

			if (!init())
				glfwTerminate();

			FontManager::add(new Font("Arial", "arial.ttf", 32));
			audio::SoundManager::init();

			memset(m_Keys,				0, MAX_KEYS		* sizeof(bool));
			memset(m_KeyState,			0, MAX_KEYS		* sizeof(bool));
			memset(m_KeyTyped,			0, MAX_KEYS		* sizeof(bool));
			memset(m_MouseButtons,		0, MAX_BUTTONS	* sizeof(bool));
			memset(m_MouseButtonState,	0, MAX_BUTTONS	* sizeof(bool));
			memset(m_MouseButtonTyped,	0, MAX_BUTTONS	* sizeof(bool));
		}
		Window::~Window()
		{
			glfwTerminate();
			FontManager::clean();
			audio::SoundManager::clean();
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
			for (int i = 0; i < MAX_KEYS; i++)
				m_KeyTyped[i] = m_Keys[i] && !m_KeyState[i];
			for (int i = 0; i < MAX_BUTTONS; i++)
				m_MouseButtonTyped[i] = m_MouseButtons[i] && !m_MouseButtonState[i];

			memcpy(m_KeyState, m_Keys, MAX_KEYS * sizeof(bool));
			memcpy(m_MouseButtonState, m_MouseButtons, MAX_BUTTONS * sizeof(bool));



			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
				std::cout << "OpenGl Error: " << error << std::endl;

			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}
		void Window::getMousePosition(double & x, double & y)
		{
			x = m_MouseX;
			y = m_MouseY;
		}
		bool Window::isKeyPressed(unsigned int keycode)
		{
			return (keycode < MAX_KEYS) ? Window::m_Keys[keycode] : /*TODO: Log this*/false;
		}
		bool Window::isKeyTyped(unsigned int keycode)
		{
			return (keycode < MAX_KEYS) ? Window::m_KeyTyped[keycode] : /*TODO: Log this*/false;
		}
		bool Window::isMouseButtonPressed(unsigned int button)
		{
			return (button < MAX_BUTTONS) ? Window::m_MouseButtons[button] : /*TODO: Log this*/false;
		}
		bool Window::isMouseButtonTyped(unsigned int button)
		{
			return (button < MAX_BUTTONS) ? Window::m_MouseButtonTyped[button] : /*TODO: Log this*/false;
		}
		void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
		{
			Window::m_Keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
		{
			Window::m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow * window, double xpos, double ypos)
		{
			Window::m_MouseX = xpos;
			Window::m_MouseY = ypos;
		}

		void window_resize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Width = width;
			win->m_Height = height;
		}
		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetFramebufferSizeCallback(m_Window, window_resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);
			glfwSwapInterval(0.0);

			std::cout << "OpenGL : " << glGetString(GL_VERSION) << std::endl;

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			return true;
		}

	}
}
#include "WindowsInput.h"

#include "Can/Application.h"
#include <GLFW/glfw3.h>

namespace Can
{
	Input* Input::s_Instance = new Platform::Windows::WindowsInput();
}

namespace Can::Platform::Windows
{

	bool WindowsInput::IsKeyPressedImp(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool WindowsInput::IsMouseButtonPressedImp(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}
	float WindowsInput::GetMouseXImp()
	{
		auto[x, y] = GetMousePosImp();
		return x;
	}
	float WindowsInput::GetMouseYImp()
	{
		auto[x, y] = GetMousePosImp();
		return y;
	}
	std::pair<float, float> WindowsInput::GetMousePosImp()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return { x, y };
	}
}
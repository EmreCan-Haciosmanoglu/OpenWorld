#include "src/graphics/window.h"
#include "src/maths/vec2.h"

int main()
{
	using namespace EmreCan3D;
	using namespace graphics;
	using namespace maths;

	Window window("3D Game Engine", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	vec2 a(2, 3);
	vec2 b(6, 35);
	vec2 c = a + b;

	std::cout << c  << " - " << (a != b) << std::endl;

	while (!window.closed())
	{
		window.clear();
		if(window.isKeyPressed(GLFW_KEY_A))
			std::cout << "Key Pressed" << std::endl;
		if(window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
			std::cout << "Mouse Button Pressed : Positions ( " << Window::m_MouseX << " , " << Window::m_MouseY << " )" << std::endl;
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();
#else
		//do something
#endif
		window.update();
	}
	return 0;
}
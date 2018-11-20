#include "src/graphics/window.h"


int main()
{
	using namespace EmreCan3D;
	using namespace graphics;

	Window window("3D Game Engine", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	while (!window.closed())
	{
		window.clear();
		std::cout << window.getWidth() << " , " << window.getHeight() << std::endl;
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		window.update();
	}
	return 0;
}
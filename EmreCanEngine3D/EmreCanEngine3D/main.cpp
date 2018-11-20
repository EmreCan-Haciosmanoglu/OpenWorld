#include<iostream>
#include<GLFW/glfw3.h>
#include "src/graphics/window.h"

int main()
{
	using namespace EmreCan3D;
	using namespace graphics;

	Window window("3D Game Engine", 800, 600);

	while (!window.closed())
	{
		window.update();
	}
	system("PAUSE");
	return 0;
}
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"
#include "src/utils/timer.h"		

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/batchrenderer2d.h"

#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"

#include "src/graphics/texture.h"	



#include "src/graphics/layers/tilelayer.h"

#include "src/graphics/layers/group.h"

#include <time.h>

#if 1
int main()
{
	using namespace EmreCan3D;
	using namespace graphics;
	using namespace maths;

	Window window("3D Game Engine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0, -1.0f, 1.0f);

	Shader* s = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader = *s;
	shader.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	TileLayer layer1(&shader);
	
	Texture* texture1 = new Texture("Test.png");
	Texture* texture2 = new Texture("Test2.png");
	
	for (float y = -9.0f; y < 9.0f; y++)
	{
		for (float x = -16.0f; x < 16.0f; x++)
		{
			//layer1.add(new Sprite(x, y, 0.09f, 0.09f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
			layer1.add(new Sprite(x, y, 0.9f, 0.9f,rand() % 2 == 0 ? texture1 : texture2));
		}
	}


	GLint texIDs[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};

	shader.enable();
	shader.setUniform1iv("textures", texIDs, 10);
	shader.setUniformMat4("pr_matrix", mat4::orthographic(-16, 16, -9, 9, -1, 1));

	Timer time;
	float timer = 0.0f;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.enable();
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));
		layer1.render();


		window.update();
 		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps BITCH\n", frames);
			frames = 0;
		}
	}
	delete texture1;
	delete texture2;
	return 0;
}
#endif

#if 0
int main()
{

	return 0;
}
#endif
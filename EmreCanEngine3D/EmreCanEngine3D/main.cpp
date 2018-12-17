#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/batchrenderer2d.h"

#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"
#include "src/utils/timer.h"

#include "src/graphics/layers/tilelayer.h"

#include "src/graphics/layers/group.h"

#include <time.h>

#define RENDER_50K 0
int main()
{
	using namespace EmreCan3D;
	using namespace graphics;
	using namespace maths;

	Window window("3D Game Engine", 960, 540);
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0, -1.0f, 1.0f);

	Shader* s1 = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader1 = *s1;
	shader1.enable();
	shader1.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	//Shader* s2 = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	//Shader& shader2 = *s2;
	//shader2.enable();
	//shader2.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	TileLayer layer1(&shader1);
	//TileLayer layer2(&shader2);
#if RENDER_50K
	for (float y = -9.0f; y < 9.0f; y += 0.1)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1)
		{
			layer1.add(new Sprite(x, y, 0.09f, 0.09f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}
	layer2.add(new Sprite(0, 0, 2, 2, vec4(0.8f, 0.2f, 0.8f, 1.0f)));

#else
	Group* group = new Group(mat4::translate(vec3(-15.0f, 5.0f, 0.0f)));
	group->add(new Sprite(0, 0, 6, 3, vec4(1, 1, 1, 1)));

	Group* group2 = new Group(mat4::translate(vec3(0.5f, 0.5f, 0.0f)));
	group2->add(new Sprite(0, 0, 5, 2, vec4(1, 0, 1, 1)));
	group2->add(new Sprite(0.5f, 0.5f, 4, 1, vec4(0, 0, 1, 1)));

	group->add(group2);

	layer1.add(group);
#endif

	Timer time;
	float timer = 0.0f;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader1.enable();
		shader1.setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));
		//shader2.enable();
		//shader2.setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));

		layer1.render();
		//layer2.render();

		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}
	return 0;
}
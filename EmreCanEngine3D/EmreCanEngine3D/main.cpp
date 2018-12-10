#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"

#include "src/graphics/static_sprite.h"

int main()
{
	using namespace EmreCan3D;
	using namespace graphics;
	using namespace maths;

	Window window("3D Game Engine", 1600, 900);
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);



	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0, -1.0f, 1.0f);


	Shader shader("src/shaders/basic.vert","src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", mat4::translate(vec3(2, 2, 0)));
	//shader.setUniformMat4("ml_matrix", mat4::rotate(45.0f, vec3(0, 0, 1)));

	StaticSprite sprite1(5,5,4,4, maths::vec4(1, 0, 1, 1), shader);
	StaticSprite sprite2(7,1,2,2, maths::vec4(0, 0, 1, 1), shader);
	Simple2DRenderer renderer;

	shader.setUniform2f("light_pos", vec2(8.0f, 4.0f));
	shader.setUniform4f("colour", vec4(1.0f, 0.0f, 0.0f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / window.getWidth()),(float)(9.0f - y * 9.0f / window.getHeight())));
		renderer.submit(&sprite1);
		renderer.submit(&sprite2);
		renderer.flush();

		window.update();
	}
	return 0;
}
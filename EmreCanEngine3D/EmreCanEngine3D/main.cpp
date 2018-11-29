#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"

int main()
{
	using namespace EmreCan3D;
	using namespace graphics;
	using namespace maths;

	Window window("3D Game Engine", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLfloat vertices[] =
	{
		 4, 3, 0,
		12, 3, 0,
		 4, 6, 0,
		 4, 6, 0,
		12, 6, 0,
		12, 3, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert","src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", mat4::translate(vec3(2, 2, 0)));
	//shader.setUniformMat4("ml_matrix", mat4::rotate(45.0f, vec3(0, 0, 1)));
	shader.setUniform2f("light_pos", vec2(8.0f, 4.0f));
	shader.setUniform4f("colour", vec4(1.0f, 0.0f, 0.0f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f),(float)(9.0f - y * 9.0f / 540.0f)));
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}
	return 0;
}
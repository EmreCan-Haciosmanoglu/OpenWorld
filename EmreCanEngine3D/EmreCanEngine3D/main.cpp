#define INDEX 0
#if INDEX
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"
#include "src/utils/timer.h"		

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/batchrenderer2d.h"

#include "src/graphics/sprite.h"

#include "src/graphics/texture.h"	
#include "src/graphics/label.h"
#include "src/graphics/layers/layer.h"
#include "src/graphics/font_manager.h"
#include "src/audio/sound_manager.h"

#include "src/graphics/layers/group.h"

#include <time.h>

#if 1
int main()
{
	using namespace Can;
	using namespace Graphics;
	using namespace maths;
	using namespace audio;

	Window window("3D Game Engine", 960, 540);
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0, -1.0f, 1.0f);

	Shader* s = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader = *s;
	shader.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	BatchRenderer2D* m_Renderer = new BatchRenderer2D();
	Layer layer1(m_Renderer, &shader, mat4::orthographic(-16, 16, -8, 8, -1, 1));

	Texture* texture1 = new Texture("Test.png");
	Texture* texture2 = new Texture("Test2.png");

	for (float y = -9.0f; y < 9.0f; y++)
	{
		for (float x = -16.0f; x < 16.0f; x++)
		{
			//layer1.add(new Sprite(x, y, 0.09f, 0.09f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
			layer1.add(new Sprite(x, y, 0.9f, 0.9f, rand() % 2 == 0 ? texture1 : texture2));
		}
	}
	Group* g = new Group(mat4::translate(vec3(-15.8f, 7.0f, 0.0f)));
	Label* label = new Label("Hello!?!", 0.4f, 0.4f, FontManager::get("Arial"), 0xff000000);
	g->add(new Sprite(0, 0, 5, 1.5f, 0xffffffff));
	g->add(label);

	layer1.add(g);

	GLint texIDs[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};

	shader.enable();
	shader.setUniform1iv("textures", texIDs, 10);
	shader.setUniformMat4("pr_matrix", mat4::orthographic(-16, 16, -9, 9, -1, 1));

	SoundManager::add(new Sound("test", "Evacuate.wav"));
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

		if (Window::isKeyTyped(GLFW_KEY_P))
			SoundManager::get("test")->play();
		if (Window::isKeyTyped(GLFW_KEY_S))
			SoundManager::get("test")->pause();
		if (Window::isKeyTyped(GLFW_KEY_A))
			SoundManager::get("test")->resume();
		if (Window::isKeyTyped(GLFW_KEY_D))
			SoundManager::get("test")->stop();

		window.update();
		SoundManager::update();
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
#endif
#if !INDEX
#include "src/Can.h"

using namespace Can;
using namespace Graphics;
using namespace maths;

class Game : public Can
{
public:
	Game()
	{

	}

	~Game()
	{
		delete layer;
		//delete fps;
		//delete shader;
	}

	void init() override
	{
		window = createWindow("First Game v1.0", 960, 540);

		shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
		//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
		FontManager::get()->setScale(window->getWidth() / 16.0f, window->getHeight() / 9.0f);
		layer = new Layer(new BatchRenderer2D(), shader, mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		fps = new Label("", -15.5f, 8.2f, FontManager::get("Arial"), 0xffffffff);
		sprite = new Sprite(-2, -1, 4, 2, new Texture("Test.png"));
		layer->add(fps);
		layer->add(sprite);
	}

	void tick() override
	{
		fps->m_Text = std::to_string(getFPS()) + " fps";
	}

	void update() override
	{
		vec3 pos = sprite->getPosition();
		if (window->isKeyPressed(GLFW_KEY_UP))
			sprite->setPosition(vec3(pos.x, ++pos.y, pos.z));
		else if (window->isKeyPressed(GLFW_KEY_DOWN))
			sprite->setPosition(vec3(pos.x, --pos.y, pos.z));
		if (window->isKeyPressed(GLFW_KEY_LEFT))
			sprite->setPosition(vec3(--pos.x, pos.y, pos.z));
		else if (window->isKeyPressed(GLFW_KEY_RIGHT))
			sprite->setPosition(vec3(++pos.x, pos.y, pos.z));
	}

	void render() override
	{
		layer->render();
	}
private:
	Window* window;
	Shader* shader;
	Sprite* sprite;
	Layer* layer;
	Label* fps;
};

int main()
{
	Game game;

	game.start();
	return 0;
}
#endif
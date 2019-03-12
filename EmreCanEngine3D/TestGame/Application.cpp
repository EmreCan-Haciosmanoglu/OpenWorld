#include "Can.h"

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
		TextureManager::add(new Texture("Test", "Test.png"));

		layer = new Layer(new BatchRenderer2D(), shader, mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		fps = new Label("", -15.5f, 8.2f, FontManager::get("Arial"), 0xffffffff);
		sprite = new Sprite(-2, -1, 4, 2, TextureManager::get("Test"));

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
		if (window->isKeyPressed(CAN_KEYSET_UP))
			sprite->setPosition(vec3(pos.x, ++pos.y, pos.z));
		else if (window->isKeyPressed(CAN_KEYSET_DOWN))
			sprite->setPosition(vec3(pos.x, --pos.y, pos.z));
		if (window->isKeyPressed(CAN_KEYSET_LEFT))
			sprite->setPosition(vec3(--pos.x, pos.y, pos.z));
		else if (window->isKeyPressed(CAN_KEYSET_RIGHT))
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
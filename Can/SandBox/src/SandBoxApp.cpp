#include <Can.h>

class ExampleLayer : public Can::Layer::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		CAN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Can::Event::Event& event) override
	{
		CAN_TRACE("{0}", event);
	}
};

class SandBox : public Can::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Can::Layer::ImGuiLayer());
	}
	~SandBox()
	{

	}

private:

};

Can::Application* Can::CreateApplication()
{
	return new SandBox();
}
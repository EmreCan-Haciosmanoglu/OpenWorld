#pragma once

#include "Core.h"
#include "Window.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "Layers/LayerStack.h"

#include <memory>

namespace Can 
{
	class CAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event::Event& e);

		void PushLayer(Layer::Layer* layer);
		void PushOverlay(Layer::Layer* overlay);
	private:
		bool OnWindowClose(Event::WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running;
		Layer::LayerStack m_LayerStack;
	};

	Application*  CreateApplication();
}


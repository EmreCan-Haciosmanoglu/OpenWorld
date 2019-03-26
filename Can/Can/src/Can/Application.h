#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
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
	private:
		bool OnWindowClose(Event::WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running;
	};

	Application*  CreateApplication();
}


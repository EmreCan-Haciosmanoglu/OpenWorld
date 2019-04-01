#pragma once

#include "Layer.h"

#include "Can/Core.h"

#include "Can/Events/MouseEvent.h"
#include "Can/Events/KeyEvent.h"
#include "Can/Events/ApplicationEvent.h"



namespace Can::Layer
{
	class CAN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event::Event& event);
	private:
		bool OnMouseButtonPressedEvent(Event::MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(Event::MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(Event::MouseMovedEvent& e);
		bool OnMouseScrolledEvent(Event::MouseScrolledEvent& e);
		bool OnKeyPressedEvent(Event::KeyPressedEvent& e);
		bool OnKeyReleasedEvent(Event::KeyReleasedEvent& e);
		bool OnKeyTypedEvent(Event::KeyTypedEvent& e);
		bool OnWindowResizeEvent(Event::WindowResizeEvent& e);
	private:
		float m_Time = 0.0f;
	};
}
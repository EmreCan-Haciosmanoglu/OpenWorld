#pragma once

#include "Can/Core.h"
#include "Layer.h"

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
		float m_Time = 0.0f;
	};
}
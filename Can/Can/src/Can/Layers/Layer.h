#pragma once

#include "Can/Core.h"
#include "Can/Events/Event.h"

namespace Can::Layer
{
	class CAN_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event::Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	public:
		bool m_Enabled;
	};
}
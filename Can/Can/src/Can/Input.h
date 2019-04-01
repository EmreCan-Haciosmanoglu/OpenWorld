#pragma once

#include "Can/Core.h"
#include <utility>

namespace Can
{
	class CAN_API Input
	{
	public:
		inline static bool IsKeyPressed( int keycode) { return s_Instance->IsKeyPressedImp(keycode); }
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImp(button); }
		inline static float GetMouseX() {return s_Instance->GetMouseXImp(); }
		inline static float GetMouseY() {return s_Instance->GetMouseYImp(); }
		inline static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImp(); }
	protected:
		virtual bool IsKeyPressedImp(int keycode) = 0;
		virtual bool IsMouseButtonPressedImp(int button) = 0;
		virtual float GetMouseXImp() = 0;
		virtual float GetMouseYImp() = 0;
		virtual std::pair<float, float> GetMousePosImp() = 0;
	private:
		static Input* s_Instance;
	};
}
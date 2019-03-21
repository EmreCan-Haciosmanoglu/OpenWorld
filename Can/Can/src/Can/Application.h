#pragma once

#include "Core.h"

namespace Can 
{
	class CAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application*  CreateApplication();
}


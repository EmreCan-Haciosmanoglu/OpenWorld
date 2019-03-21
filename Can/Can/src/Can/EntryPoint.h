#pragma once
#ifdef CAN_PLATFORM_WINDOWS
extern Can::Application* Can::CreateApplication();
int main(int argc, char** argv)
{
	auto app = Can::CreateApplication();
	app->Run();
	delete app;
}
#endif // CAN_PLATFORM_WINDOWS

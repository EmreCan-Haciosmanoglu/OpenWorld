#pragma once
#ifdef CAN_PLATFORM_WINDOWS
extern Can::Application* Can::CreateApplication();
int main(int argc, char** argv)
{
	Can::Log::Init();
	CAN_CORE_WARN("Initialized Log!");
	int a = 5;
	CAN_INFO("Hello! Var={0}", a);
	auto app = Can::CreateApplication();
	app->Run();
	delete app;
}
#endif // CAN_PLATFORM_WINDOWS

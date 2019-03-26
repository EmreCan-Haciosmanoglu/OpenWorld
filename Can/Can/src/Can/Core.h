#pragma once
#ifdef CAN_PLATFORM_WINDOWS
	#ifdef CAN_BUILD_DLL
		#define CAN_API __declspec(dllexport)
	#else
		#define CAN_API __declspec(dllimport)
	#endif // CAN_BUILD_DLL
#else
	#error Can Only supports Windows!
#endif // CAN_PLATFORM_WINDOWS

#ifdef CAN_ENABLED_ASSERTS
	#define CAN_ASSERT(x,...) {if(!(x)) { CAN_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak();}}
	#define CAN_CORE_ASSERT(x,...) {if(!(x)) { CAN_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak();}}
#else
	#define CAN_ASSERT(x,...)
	#define CAN_CORE_ASSERT(x,...)
#endif // CAN_ENABLED_ASSERTS


#define BIT(x) (1 << x)
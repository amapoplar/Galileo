#pragma once


#ifdef GL_PLATFORM_WINDOWS
	#ifdef GL_BUILD_DLL
		#define GALILEO_API __declspec(dllexport)
	#else
		#define GALILEO_API __declspec(dllimport)
	#endif // GL_BUILD_DLL
#else
	#error Galileo only support Window!
#endif // GL_PLATFORM_WINDOWS


#ifdef GL_ENABLE_ASSERTS

#define GL_ASSERT(x,...) {if(!(x)){GL_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
#define GL_CORE_ASSERT(x,...){if(!(x)){GL_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
#else
#define GL_ASSERT(x,...)
#define GL_CORE_ASSERT(x,...)
#endif

#define BIT(x) (1 << x)
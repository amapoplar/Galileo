#pragma once

#ifdef GL_PLATFORM_WINDOWS

extern Galileo::Application* Galileo::CreateApplication();
int main() {

	Galileo::Log::Init();
	GL_CORE_WARN("Initialized Log!");
	GL_INFO("Welcome to Galileo Engine!");
	auto app = Galileo::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif // GL_PLATFORM_WINDOWS

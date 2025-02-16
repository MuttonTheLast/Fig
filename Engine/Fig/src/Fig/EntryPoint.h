#pragma once
#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
extern Fig::Application* Fig::CreateApplication();

// create macro to create application
#define FIG_APPLICATION(T) extern Fig::Application* Fig::CreateApplication() { return new T(); }


int main(int argc, char* argv[])
{

	Fig::Log::Init();
	FIG_CORE_WARN("Initialized Log!");
	FIG_INFO("Initialized Log!");

	auto app = Fig::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
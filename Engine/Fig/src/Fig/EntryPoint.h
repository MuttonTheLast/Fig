#pragma once
#include "Fig.h"
#ifdef SDL_SUPPORTED
#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#endif
extern Fig::Application* Fig::CreateApplication();

// create macro to create application
#define FIG_APPLICATION(T) extern Fig::Application* Fig::CreateApplication() { return new T(); }


#ifdef SDL_SUPPORTED
int main(int argc, char* argv[])
{

	Fig::Log::Init();
	FIG_CORE_INFO("Initialized Log!");
	FIG_INFO("Initialized Log!");

	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		FIG_CORE_ERROR("SDL Initialization failed");
		return 1;
	}
	FIG_CORE_INFO("SDL Initialized");

	auto app = Fig::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif
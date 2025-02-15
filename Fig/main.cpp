
#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_gpu.h>

int main(int argc, char* argv[])
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		throw "Failed To Initialize SDL!";
		return 1;
	}

	return 0;
}


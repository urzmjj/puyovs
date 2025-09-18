#include "Game.h"

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

int main(int argc, char** argv)
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	if (!TTF_Init()) {
		SDL_Log("Unable to initialize SDL TTF: %s\n", SDL_GetError());
		SDL_Quit();
		return 2;
	}

    PuyoVS::ClientNG::Game game;
	game.run();
	SDL_Quit();
	return 0;
}

#include "Quadopoly.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "[ERROR] SDL_Init Failed. SDL_ERROR: " << SDL_GetError() << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cout << "[ERROR] IMG_Init Failed. SDL_ERROR: " << SDL_GetError() << std::endl;
	}

	SDL_Window *window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Texture *texture = IMG_LoadTexture(renderer, "test.png");
	if (texture == nullptr) {
		std::cout << "[ERROR] Failed to load texture. Error: " << SDL_GetError() << std::endl;
	}


	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);


	bool running = true;
	SDL_Event event;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
		}
	}
	return 0;
}

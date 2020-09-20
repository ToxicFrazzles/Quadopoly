#include "Quadopoly.h"

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "[ERROR] SDL_Init Failed. SDL_ERROR: " << SDL_GetError() << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cout << "[ERROR] IMG_Init Failed. SDL_ERROR: " << SDL_GetError() << std::endl;
	}

	RenderWindow window("Test", 500, 500);
	SDL_Texture *placeholderTex = window.loadTexture("test.png");
	SDL_Texture *digitsTex = window.loadTexture("res/gfx/digits.png");

	FPSCounter fps;
	double frameDelay = 0;
	bool running = true;
	SDL_Event event;
	
	while (running) {
		int start = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.repeat) break;
				std::cout << "Key pressed. " << event.key.keysym.sym << std::endl;
				break;
			case SDL_KEYUP:
				std::cout << "Key released. " << event.key.keysym.sym << std::endl;
				break;
			case SDL_MOUSEBUTTONDOWN:
				std::cout << "Mouse clicked. " << +event.button.button << std::endl;
				break;
			case SDL_MOUSEBUTTONUP:
				std::cout << "Mouse released. " << +event.button.button << std::endl;
				break;
			case SDL_MOUSEMOTION:
				std::cout << "l";
				break;
			case SDL_MOUSEWHEEL:
				std::cout << "Wheel " << event.wheel.y << std::endl;
				break;
			default:
				break;
			}
		}
		window.render(placeholderTex);
		window.render(fps.currentRate(), digitsTex, 495, 5);
		window.display();
		fps.process();


		int time = SDL_GetTicks() - start;
		if (time < 0) continue; // Probably overflowed

		int sleepTime = 7 - time;
		if (sleepTime > 0) {
			SDL_Delay(sleepTime);
		}
	}
	return 0;
}

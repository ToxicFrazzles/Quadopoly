#include "RenderWindow.h"


RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h) {
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


}

RenderWindow::~RenderWindow() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void RenderWindow::render(SDL_Texture *p_tex) {
	SDL_RenderCopy(renderer, p_tex, nullptr, nullptr);
}

void RenderWindow::render(uint64_t number, SDL_Texture *p_tex, int x, int y) {
	const int digit_w = 19;
	const int digit_h = 36;
	SDL_Rect src;
	src.y = 0;
	src.w = digit_w;
	src.h = digit_h;
	SDL_Rect dst;
	dst.y = y;
	dst.w = digit_w;
	dst.h = digit_h;
	int x_offset = 20 * digit_w;
	bool found_significant = false;
	uint64_t digit_locator = 10000000000000000000;
	while (digit_locator > 0) {
		uint64_t digit = number / digit_locator;
		if (!found_significant && digit_locator > 1 && digit == 0) {
			x_offset -= digit_w;
			digit_locator /= 10;
			continue;
		}
		found_significant = true;
		src.x = (int)(digit_w * digit);
		dst.x = x - (x_offset + digit_w);
		SDL_RenderCopy(renderer, p_tex, &src, &dst);
		number %= digit_locator;
		x_offset -= digit_w;
		digit_locator /= 10;
	}
}

SDL_Texture *RenderWindow::loadTexture(const char *p_filePath) {
	return IMG_LoadTexture(renderer, p_filePath);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}
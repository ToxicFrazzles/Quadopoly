#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>



class RenderWindow {
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
public:
	RenderWindow(const char *p_title, int p_w, int p_h);
	~RenderWindow();
	void render(SDL_Texture *p_tex);
	void render(uint64_t number, SDL_Texture *p_tex, int x, int y);
	SDL_Texture *loadTexture(const char *p_filePath);
	void display();
};
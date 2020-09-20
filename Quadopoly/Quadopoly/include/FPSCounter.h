#pragma once

#include <chrono>
#include <SDL.h>
#include <SDL_image.h>

class FPSCounter {
private:
	std::chrono::high_resolution_clock::time_point clock;
	int frameCount = 0;
	int frameRate = 1;
public:
	FPSCounter();
	void process();
	int currentRate();
};
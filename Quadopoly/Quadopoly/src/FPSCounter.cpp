#include "FPSCounter.h"


FPSCounter::FPSCounter() {
	clock = std::chrono::high_resolution_clock::now();

}

void FPSCounter::process() {
	frameCount += 1;
	double duration = (std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - clock)).count();
	if (duration >= 0.5) {
		clock = std::chrono::high_resolution_clock::now();
		frameRate = (int)((double)frameCount / duration);
		frameCount = 0;
	}
}

int FPSCounter::currentRate() {
	return frameRate;
}
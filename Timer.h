#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
class Timer
{
public:
	Timer();

	void start();
	void stop();
	void pause();

	Uint32 getTicks();

	bool isStarted();
	bool isPaused();

private:
	Uint32 mStartTicks;

	Uint32 mPauseTicks;

	bool mPaused;
	bool mStarted;
};


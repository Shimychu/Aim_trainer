#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Dot
{
public:
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	static const int DOT_VEL = 10;

	Dot();

	void handleEvent(SDL_Event& e);

	void move();

	void render();

private:

	// The position of the dot
	int posX, posY;

	// The velocity of the dot
	int velX, velY;
};


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

	Dot(int width, int height);

	//void handleEvent(SDL_Event& e);

	//void move();

	int getPosX();

	int getPosY();
private:

	// The position of the dot
	int posX;
	int posY;

	// The velocity of the dot
	int velX;
	int velY;
};


#pragma once
#include <SDL.h>
#include <SDL_image.h>

enum LButtonSprite
{
	BUTTON_SPIRTE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class Mouse
{
public:

	Mouse();

	void setPosition(int x, int y);

	void handleEvent(SDL_Event* e);

	void render();

private:
	 
	SDL_Point mousePosition;

	LButtonSprite currentSprite;
};


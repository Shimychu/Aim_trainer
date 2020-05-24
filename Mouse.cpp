#include "Mouse.h"

Mouse::Mouse()
{
	mousePosition.x = 0;
	mousePosition.y = 0;

	currentSprite = LButtonSprite::BUTTON_SPIRTE_MOUSE_OUT;
}

void Mouse::setPosition(int x, int y)
{
	mousePosition.x = x;
	mousePosition.y = y;
}

void handleEvent(SDL_Event* e)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
	}
}
#include "Dot.h"

Dot::Dot()
{
	//Initalize position of dot
	posX = 0;
	posY = 0;

	//Initalize velocity of dot
	velX = 0;
	velY = 0;
}

void Dot::handleEvent(SDL_Event& e)
{
	if (e.type == SDL_MOUSEMOTION)
	{
		//do someething
	}
}

void Dot::move()
{
	
	if ( (posX < 0 || posX + DOT_WIDTH > SCREEN_WIDTH ) )
	{
		posX -= velX;
	}

	if ( (posY < 0 || posY + DOT_WIDTH > SCREEN_HEIGHT ) )
	{ 
		posX -= velX;
	}
}

void Dot::render()
{
	//render the dot somehow
}
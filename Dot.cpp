#include "Dot.h"


Dot::Dot(int width, int height)
{
	//Initalize position of dot
	posX = 0;
	posY = 0;

	//Initalize velocity of dot
	velX = 10;
	velY = 0;

	//printf("Screen W: %d , Screen H: %d\n", SCREEN_WIDTH, SCREEN_WIDTH);
}

//void Dot::handleEvent(SDL_Event& e)
//{
//	if (e.type == SDL_MOUSEMOTION)
//	{
//		//do someething
//	}
//}

//void Dot::move()
//{
//	posX += velX;
//
//	if ( (posX < 0 || posX + DOT_WIDTH > SCREEN_WIDTH ) )
//	{
//		 velX = velX * -1;
//	}
//
//	if ( (posY < 0 || posY + DOT_WIDTH > SCREEN_HEIGHT ) )
//	{ 
//		//TODO::If we want a Y velocity
//	}
//	printf("debugging posx: %d velx %d\n",posX,velX);
//}

int Dot::getPosX()
{
	return posX;
}

int Dot::getPosY() 
{
	return posY;
}


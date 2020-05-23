#include <SDL.h>
#include <stdio.h>
#include "Texture.h"
#include "Game.h"


//Window we'll be rendering
SDL_Window* window = NULL;

//Surface contained by window
SDL_Surface* surface = NULL;

//Window Renderer
SDL_Renderer* gRenderer = NULL;

//Current display texture
SDL_Texture* gTexture = NULL;

Game* game = NULL;

double SCREEN_WIDTH;
double SCREEN_HEIGHT;

void close() {
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);
	window = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

void initScreen() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf(" SDL init failed: %s\n", SDL_GetError());
		exit(0);
	}

	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	SCREEN_WIDTH = DM.w;
	SCREEN_HEIGHT = DM.h;

	printf("Height: %d, Width: %d", DM.h, DM.w);

	//Create window
	window = SDL_CreateWindow(
		"Aim Trainer V1",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		0
	);

	SDL_MaximizeWindow(window);

	surface = SDL_GetWindowSurface(window);

	gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL) {
		printf("Renderer could not be created. Error: %s\n", SDL_GetError());
		exit(3);
	}

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int image = IMG_INIT_PNG;
	if (!(IMG_Init(image) & image)) {
		printf("Image could not be initalized. Error: %s\n", SDL_GetError());
		exit(4);
	}
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}



void LoadMedia()
{
	gTexture = loadTexture("Img/PLAY.png");
	if (gTexture == NULL) {
		printf("Failed to load png image.\n");
		close();
	}
}


void screenSetUp()
{

}


int main(int argc, char* args[]) {
	game = new Game();
	initScreen();
	LoadMedia();


	bool active = true;

	SDL_Event e;

	while (active) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT)
			{
				active = false;
			}
		}

		if (game->getGameState() == 0) {
			//Clear screen
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);

			//Top left corner viewport
			SDL_Rect topLeftViewport;
			topLeftViewport.x = 0;
			topLeftViewport.y = 0;
			topLeftViewport.w = SCREEN_WIDTH / 2;
			topLeftViewport.h = SCREEN_HEIGHT / 2;
			SDL_RenderSetViewport(gRenderer, &topLeftViewport);

			//Render texture to screen
			SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
		} 

		//Update screen
		SDL_RenderPresent(gRenderer);
	}

	return 0;
}
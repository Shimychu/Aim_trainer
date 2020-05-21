#include <SDL.h>
#include <stdio.h>




void initScreen() {
	SDL_Window* window;
	SDL_Surface* surface;

	//Window we'll be rendering
	window = NULL;

	//Surface contained by window
	surface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf(" SDL init failed: %s\n", SDL_GetError());
		exit(0);
	}

	//Create window
	window = SDL_CreateWindow(
		"Aim Trainer V1",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		0
	);

	SDL_MaximizeWindow(window);

	surface = SDL_GetWindowSurface(window);

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

	SDL_UpdateWindowSurface(window);

	SDL_Delay(5000);

	SDL_DestroyWindow(window);

	SDL_Quit();
}

int main(int argc, char* args[]) {
	initScreen();

	return 0;
}
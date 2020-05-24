#pragma once
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Texture 
{
public:
	//Initialize Texture
	Texture();

	~Texture();

	//Loads Image
	bool LoadImage(std::string path);

	//Deallocate Texture();
	void free();

	//Render Texture at given location
	void render(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Get Texture dimension
	int getHeight();
	int getWidth();
private:

	SDL_Texture* mTexture;

	//Image Dimensions
	int mWidth;
	int mHeight;

};
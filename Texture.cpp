#include "Texture.h"

Texture::Texture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

void Texture::free() {
	if (mTexture != NULL) 
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

Texture::~Texture() 
{	
	free();
}

SDL_Texture* Texture::LoadImage(std::string path)
{
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Error unable to load images: %s\n", IMG_GetError());
		exit(2);
	}

	mWidth = loadedSurface->w;
	mHeight = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);

	mTexture = newTexture;
	return mTexture;
}

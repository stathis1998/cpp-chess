#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* path) {
	SDL_Surface* tmpSurface = IMG_Load(path);
	SDL_Texture* texture = nullptr;

	if (!tmpSurface) {
		SDL_Log("SDL_ImageError, %s", SDL_GetError());
	} else {
		texture = SDL_CreateTextureFromSurface(Game::Renderer, tmpSurface);
		SDL_Log("Texture %s has been loaded", path);
	}
	SDL_FreeSurface(tmpSurface);

	return texture;
}

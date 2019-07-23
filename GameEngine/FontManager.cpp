#include "FontManager.h"


FontManager::FontManager(std::string text, int size, std::string font, SDL_Color color, int x, int y) : text(text), size(size), font(font), color(color), x(x), y(y) { }

void FontManager::setText(std::string text) {
	this->text = text;
}

void FontManager::render() {
	// Set font and size
	TTF_Font* selectedFont = TTF_OpenFont(this->font.c_str(), this->size);

	if (!selectedFont) {
		SDL_Log(SDL_GetError());
	}

	// Creating a surface and rendering the text
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(selectedFont, this->text.c_str(), this->color);

	if (!surfaceMessage) {
		SDL_Log(SDL_GetError());
	}

	// Converting the surface into texture
	SDL_Texture* message = SDL_CreateTextureFromSurface(Game::Renderer, surfaceMessage);

	if (!message) {
		SDL_Log(SDL_GetError());
	}

	SDL_Rect messageRect;
	messageRect.x = x;
	messageRect.y = y;
	messageRect.w = surfaceMessage->w;
	messageRect.h = surfaceMessage->h;
	
	SDL_RenderCopy(Game::Renderer, message, nullptr, &messageRect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(message);
	TTF_CloseFont(selectedFont);
}
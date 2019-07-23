#pragma once

#include "Game.h"

class FontManager {
private:
	std::string font;
	std::string text;
	SDL_Color color;
	int size;
	int x, y;
public:
	FontManager(std::string text, int size, std::string font, SDL_Color color, int x, int y);

	void setText(std::string text);

	void render();
};


#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define BLOCK 64


class Game {
private:
	Uint32 isRunning;
	SDL_Window* window;
public:
	static SDL_Renderer* Renderer;

	Game();

	void init(const char* title, int width, int height, bool flags);

	void handleEvents();
	void update();
	void render();

	void clean();

	Uint32 running();
};

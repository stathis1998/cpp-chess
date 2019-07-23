#include <iostream>

#include "Game.h"

int main(int argc, char** argv) {
	const int ChessWidth = 8 * BLOCK;
	const int ChessHeight = 8 * BLOCK;

	const int RightSideBar = 200;

	const int WindowWidth = ChessWidth + RightSideBar;
	const int WindowHeight = ChessHeight;

	int FPS = 60;
	int frameDelay = 1000 / FPS;
	Uint32 frameStart, frameTime;

	Game* game = new Game();
	game->init("Wannabe Chess", WindowWidth, WindowHeight, 0);

	while (game->running()) {
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > (int)frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}

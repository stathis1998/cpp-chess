#include <vector>
#include <string>

#include "Chessboard.h"
#include "Game.h"
#include "Player.h"
#include "FontManager.h"

SDL_Renderer* Game::Renderer = nullptr;

Chessboard* chessboard = nullptr;

Player* player1 = nullptr;
Player* player2 = nullptr;

FontManager* playerTurn = nullptr;

Game::Game() : isRunning(false), window(nullptr) { }

void Game::init(const char* title, int width, int height, bool flags) {
	// Initializing subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		SDL_Log("SDL_Error, %s", SDL_GetError());
		this->isRunning = false;
	} else {
		SDL_Log("Subsystems has been initialized");
	}

	// Creating window
	this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	if (!this->window) {
		SDL_Log("SDL_Error, %s", SDL_GetError());
		this->isRunning = false;
	} else {
		SDL_Log("Window has been created");
	}

	// Creating renderer
	Game::Renderer = SDL_CreateRenderer(this->window, -1, 0);
	if (!Game::Renderer) {
		SDL_Log("SDL_Error, %s", SDL_GetError());
		this->isRunning = false;
	} else {
		SDL_SetRenderDrawColor(Game::Renderer, 255, 255, 255, 255);
		SDL_Log("Renderer has been created");
	}

	// Initializing TTF
	if (TTF_Init()) {
		SDL_Log("SDL_Error, %s", SDL_GetError());
	} else {
		SDL_Log("TTF has been initialized");
	}

	this->isRunning = true;
	
	chessboard = new Chessboard("assets/whiteBox.png", "assets/blackBox.png");

	player1 = new Player(WHITE, chessboard);
	player2 = new Player(BLACK, chessboard);

	player1->setPlaying(true);

	playerTurn = new FontManager("White's Turn", 24, "assets/calibri.ttf", { 0, 0, 0 }, 8 * BLOCK + 10, 15);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		this->isRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		{ // Temp scope for declaring variables
			int x, y;
			SDL_GetMouseState(&x, &y);

			x = (int)(x / BLOCK) + 1;
			y = (int)(y / BLOCK) + 1;

			if (x <= 8) {
				if (player1->getPlaying()) {
					if (player1->getPhase() == 1) {
						bool selectedPawn = false;

						selectedPawn = player1->selectPiece(chessboard, x, y);

						if (selectedPawn) {
							player1->setPhase(2);
						}
					} else if (player1->getPhase() == 2) {
						bool selectedTile = player1->selectTile(chessboard, x, y);
						
						if (selectedTile) {
							player1->moveSelectedPieceAt(chessboard, x, y);

							player1->setPlaying(false);
							player2->setPlaying(true);

							player1->setPhase(1);
							playerTurn->setText("Black's Turn");
						} else {
							player1->setPhase(1);
						}
					}
				} else if (player2->getPlaying()) {

					if (player2->getPhase() == 1) {
						bool selectedPawn = false;

						selectedPawn = player2->selectPiece(chessboard, x, y);

						if (selectedPawn) {
							player2->setPhase(2);
						}
					} else if (player2->getPhase() == 2) {
						bool selectedTile = player2->selectTile(chessboard, x, y);

						if (selectedTile) {
							player2->moveSelectedPieceAt(chessboard, x, y);

							player2->setPlaying(false);
							player1->setPlaying(true);

							player2->setPhase(1);
							playerTurn->setText("White's Turn");
						}
						else {
							player2->setPhase(1);
						}
					}
				}
			}
		}
		break;
	default:
		break;
	}
}

void Game::update() {
	player1->updatePieces();
	player2->updatePieces();
}

void Game::render() {
	SDL_RenderClear(Game::Renderer);

	chessboard->render();

	player1->renderPieces();
	player2->renderPieces();
	playerTurn->render();

	SDL_RenderPresent(Game::Renderer);
}

void Game::clean() {
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(Game::Renderer);

	TTF_Quit();
	SDL_Quit();
}

Uint32 Game::running() {
	return this->isRunning;
}

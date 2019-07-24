#include "Chessboard.h"


Chessboard::Chessboard(const char* whiteTilePath, const char* blackTilePath) {
	this->tiles.reserve(64);

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if ((y + x) % 2 == 0) {
				// White tile
				this->tiles.push_back(new Tile(whiteTilePath, x * BLOCK, y * BLOCK, WHITE));
			} else {
				// Black tile
				this->tiles.push_back(new Tile(blackTilePath, x * BLOCK, y * BLOCK, BLACK));
			}
		}
	}
}

void Chessboard::update() {
	for (int i = 0; i < this->tiles.size(); i++) {
		this->tiles[i]->update();
	}
}

void Chessboard::render() {
	for (int i = 0; i < this->tiles.size(); i++) {
		this->tiles[i]->render();
	}
}

Piece* Chessboard::getPieceAt(int x, int y) {
	int index = (y - 1) * 8 + x - 1;

	if (index > 8 * 8 - 1 || index < 0) {
		return nullptr;
	}
	
	return this->tiles[index]->hasPiece();
}

void Chessboard::setPiece(Piece* piece) {
	int x = piece->getXPos() / BLOCK;
	int y = piece->getYPos() / BLOCK;

	int index = y * 8 + x;

	this->tiles[index]->setPiece(piece);
}

bool Chessboard::isTileEmpty(int x, int y) {
	int index = (y - 1) * 8 + x - 1;

	return !this->tiles[index]->hasPiece();
}

void Chessboard::emptyTile(int x, int y) {
	int index = (y - 1) * 8 + x - 1;
	this->tiles[index]->emptyPiece();

	std::cout << "tile " << index << " empty\n";
}

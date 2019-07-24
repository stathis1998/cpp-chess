#include "Piece.h"
#include "Chessboard.h"

Piece::Piece(const char* path, int x, int y, Color color, int value, std::string name) : StaticMesh(path, x, y), color(color), value(value), alive(true), name(name) { }

bool Piece::isAlive() {
	return this->alive;
}

// Setters

// Getters
std::string Piece::getName() {
	return this->name;
}

Color Piece::getColor() {
	return this->color;
}

void Piece::moveTo(Chessboard* chessboard, int x, int y) {
	int currentX = this->getXPos() / BLOCK + 1;
	int currentY = this->getYPos() / BLOCK + 1;

	this->setXPos((x - 1) * BLOCK);
	this->setYPos((y - 1) * BLOCK);

	chessboard->setPiece(this);
	chessboard->emptyTile(currentX, currentY);
}

#include "Tile.h"


Tile::Tile(const char* path, int x, int y, Color color) : StaticMesh(path, x, y), piece(nullptr), color(color) { }

// Setters
void Tile::setPiece(Piece* piece) {
	this->piece = piece;
}

Piece* Tile::hasPiece() {
	return (this->piece) ? this->piece : nullptr;
}

void Tile::emptyPiece() {
	this->piece = nullptr;
}

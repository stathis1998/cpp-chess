#pragma once

#include "StaticMesh.h"
#include "Piece.h"


class Tile : public StaticMesh {
private:
	Piece* piece;
	Color color;
public:
	Tile(const char* path, int x, int y, Color color);

	// Setters
	void setPiece(Piece* piece);

	Piece* hasPiece();
	void emptyPiece();
};

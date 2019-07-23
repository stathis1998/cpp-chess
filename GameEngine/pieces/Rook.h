#pragma once

#include "../Piece.h"


class Rook : public Piece {
public:
	Rook(const char* path, int x, int y, Color color);

	std::vector<Move> getPossibleMoves();
};
#pragma once

#include "../Piece.h"


class King : public Piece {
public:
	King(const char* path, int x, int y, Color color);

	std::vector<Move> getPossibleMoves(Chessboard* chessboard);
};
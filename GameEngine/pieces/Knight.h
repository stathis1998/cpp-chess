#pragma once

#include "../Piece.h"


class Knight : public Piece {
public:
	Knight(const char* path, int x, int y, Color color);

	std::vector<Move> getPossibleMoves(Chessboard* chessboard);
};
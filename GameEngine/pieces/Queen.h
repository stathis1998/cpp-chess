#pragma once

#include "../Piece.h"


class Queen : public Piece {
public:
	Queen(const char* path, int x, int y, Color color);

	std::vector<Move> getPossibleMoves(Chessboard* chessboard);
};
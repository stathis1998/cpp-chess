#pragma once

#include "../Piece.h"


class Pawn : public Piece {
public:
	Pawn(const char* path, int x, int y, Color color);

	std::vector<Move> getPossibleMoves(Chessboard* chessboard);
};
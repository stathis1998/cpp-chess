#pragma once

#include "../Piece.h"


class Bishop : public Piece {
public:
	Bishop(const char* path, int x, int y, Color color);
	
	std::vector<Move> getPossibleMoves(Chessboard* chessboard);
};
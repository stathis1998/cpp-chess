#pragma once

#include "../Piece.h"


class Pawn : public Piece {
private:
	bool firstMove;
public:
	Pawn(const char* path, int x, int y, Color color);

	std::vector<Move> getPossibleMoves(Chessboard* chessboard);
	void moveTo(Chessboard* chessboard, int x, int y);
};

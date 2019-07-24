#include "Queen.h"
#include "../Chessboard.h"


Queen::Queen(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::QUEEN, "Queen") { }

std::vector<Move> Queen::getPossibleMoves(Chessboard* chessboard) {
	std::vector<Move> moves;

	return moves;
}

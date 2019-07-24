#include "Knight.h"


Knight::Knight(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::KNIGHT, "Knight") { }

std::vector<Move> Knight::getPossibleMoves(Chessboard* chessboard) {
	std::vector<Move> moves;

	return moves;
}
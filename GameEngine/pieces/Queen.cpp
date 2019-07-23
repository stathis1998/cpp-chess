#include "Queen.h"


Queen::Queen(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::QUEEN, "Queen") { }

std::vector<Move> Queen::getPossibleMoves() {
	std::vector<Move> moves;

	return moves;
}
#include "Bishop.h"


Bishop::Bishop(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::BISHOP, "Bishop") { }

std::vector<Move> Bishop::getPossibleMoves() {
	std::vector<Move> moves;

	return moves;
}
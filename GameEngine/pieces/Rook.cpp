#include "Rook.h"


Rook::Rook(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::ROOK, "Rook") { }

std::vector<Move> Rook::getPossibleMoves() {
	std::vector<Move> moves;

	return moves;
}
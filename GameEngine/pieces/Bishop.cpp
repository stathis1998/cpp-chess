#include "Bishop.h"
#include "../Chessboard.h"


Bishop::Bishop(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::BISHOP, "Bishop") { }

std::vector<Move> Bishop::getPossibleMoves(Chessboard* chessboard) {
	std::vector<Move> moves;

	return moves;
}

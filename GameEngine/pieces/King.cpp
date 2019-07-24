#include "King.h"
#include "../Chessboard.h"


King::King(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::KING, "King") { }

std::vector<Move> King::getPossibleMoves(Chessboard* chessboard) {
	std::vector<Move> moves;

	return moves;
}

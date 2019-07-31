#include "King.h"
#include "../Chessboard.h"


King::King(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::KING, "King") { }

std::vector<Move> King::getPossibleMoves(Chessboard* chessboard) {
	std::vector<Move> moves;
	moves.reserve(8);

	int x = this->getXPos() / BLOCK + 1;
	int y = this->getYPos() / BLOCK + 1;

	bool empty;
	for (int i = 0; i < 3; i++) {
		// Top 3
		empty = (chessboard->getPieceAt(x - 1 + i, y - 1)) ? false : true;

		if (empty) {
			Move move;
			move.x = x - 1 + i;
			move.y = y - 1;

			moves.push_back(move);
		}

		// Bottom 3
		empty = (chessboard->getPieceAt(x - 1 + i, y + 1)) ? false : true;

		if (empty) {
			Move move;
			move.x = x - 1 + i;
			move.y = y + 1;

			moves.push_back(move);
		}
	}

	// Left
	empty = (chessboard->getPieceAt(x - 1, y)) ? false : true;

	if (empty) {
		Move move;
		move.x = x - 1;
		move.y = y;

		moves.push_back(move);
	}

	// Right
	empty = (chessboard->getPieceAt(x + 1, y)) ? false : true;

	if (empty) {
		Move move;
		move.x = x + 1;
		move.y = y;

		moves.push_back(move);
	}

	return moves;
}

#include "Rook.h"
#include "../Chessboard.h"


Rook::Rook(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::ROOK, "Rook") { }

std::vector<Move> Rook::getPossibleMoves(Chessboard* chessboard) {
	std::vector<Move> moves;
	moves.reserve(28);

	int x = this->getXPos() / BLOCK + 1;
	int y = this->getYPos() / BLOCK + 1;

	bool empty;
	Move move;
	for (int i = 1; i <= 7; i++) {
		// Up
		empty = (chessboard->getPieceAt(x, y - 1)) ? false : true;
		move.x = x;
		move.y = y - 1;

		if (empty) {
			moves.push_back(move);
		}

		// Down
		empty = (chessboard->getPieceAt(x, y + 1)) ? false : true;
		move.x = x;
		move.y = y + 1;

		if (empty) {
			moves.push_back(move);
		}

		// Left
		empty = (chessboard->getPieceAt(x - 1, y)) ? false : true;
		move.x = x - 1;
		move.y = y;

		if (empty) {
			moves.push_back(move);
		}
		
		// Right
		empty = (chessboard->getPieceAt(x + 1, y)) ? false : true;
		move.x = x + 1;
		move.y = y;

		if (empty) {
			moves.push_back(move);
		}
	}

	return moves;
}

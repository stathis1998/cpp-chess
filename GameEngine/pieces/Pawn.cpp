#include "Pawn.h"
#include "../Chessboard.h"


Pawn::Pawn(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::PAWN, "Pawn"), firstMove(false) { }

std::vector<Move> Pawn::getPossibleMoves(Chessboard* chessboard) {
	std::vector<Move> moves;
	moves.reserve(4);

	int x = this->getXPos() / BLOCK + 1;
	int y = this->getYPos() / BLOCK + 1;

	int move = (this->firstMove) ? 1 : 2;

	if (this->getColor() == WHITE) {
		for (int i = 1; i <= move; i++) {
			bool empty = (chessboard->getPieceAt(x, y - i)) ? false : true;

			Move move;
			move.x = x;
			move.y = y - i;

			if (empty) {
				moves.push_back(move);
			} else {
				break;
			}
		}
	} else if (this->getColor() == BLACK) {
		for (int i = 1; i <= move; i++) {
			bool empty = (chessboard->getPieceAt(x, y + i)) ? false : true;

			Move move;
			move.x = x;
			move.y = y + i;

			if (empty) {
				moves.push_back(move);
			} else {
				break;
			}
		}
	}

	return moves;
}

void Pawn::moveTo(Chessboard* chessboard, int x, int y) {
	this->firstMove = true;

	int currentX = this->getXPos() / BLOCK + 1;
	int currentY = this->getYPos() / BLOCK + 1;

	this->setXPos((x - 1) * BLOCK);
	this->setYPos((y - 1) * BLOCK);

	chessboard->setPiece(this);
	chessboard->emptyTile(currentX, currentY);
}

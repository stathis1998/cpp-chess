#include "Pawn.h"
#include "../TextureManager.h"


Pawn::Pawn(const char* path, int x, int y, Color color) : Piece(path, x, y, color, Value::PAWN, "Pawn") { }

std::vector<Move> Pawn::getPossibleMoves(Chessboard* chessboard) {
	std::vector<Move> moves;
	/*moves.reserve(4);

	int x = this->getXPos() / BLOCK + 1;
	int y = this->getYPos() / BLOCK + 1;

	if (this->getColor() == WHITE) {
		for (int i = 1; i <= 2; i++) { // Possible second step error
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
		for (int i = 1; i <= 2; i++) { // Possible second step error
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
	}*/

	return moves;
}
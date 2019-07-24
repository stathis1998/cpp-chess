#include "Player.h"

// Pieces
#include "pieces/Pawn.h"
#include "pieces/Rook.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Queen.h"
#include "pieces/King.h"


Player::Player(Color color, Chessboard* chessboard) : color(color), score(0), selectedPiece(nullptr), playing(false), phase(1) {
	this->pieces.reserve(16);

	int pawnsRow, piecesRow;
	std::string colorName;
	if (color == WHITE) {
		pawnsRow = 6;
		piecesRow = 7;
		colorName = "white";
	} else {
		pawnsRow = 1;
		piecesRow = 0;
		colorName = "black";
	}

	// Pawns
	for (int i = 0; i < 8; i++) {
		Piece* pawn = new Pawn(std::string("assets/" + colorName + "_pawn.png").c_str(), i * BLOCK, pawnsRow * BLOCK, color);
		this->pieces.push_back(pawn);

		chessboard->setPiece(pawn);
	}

	// Rooks
	Piece* rook = new Rook(std::string("assets/" + colorName + "_rook.png").c_str(), 0 * BLOCK, piecesRow * BLOCK, color);
	this->pieces.push_back(rook);
	chessboard->setPiece(rook);

	rook = new Rook(std::string("assets/" + colorName + "_rook.png").c_str(), 7 * BLOCK, piecesRow * BLOCK, color);
	this->pieces.push_back(rook);
	chessboard->setPiece(rook);

	// Knights
	Piece* knight = new Knight(std::string("assets/" + colorName + "_knight.png").c_str(), 1 * BLOCK, piecesRow * BLOCK, color);
	this->pieces.push_back(knight);
	chessboard->setPiece(knight);
	
	knight = new Knight(std::string("assets/" + colorName + "_knight.png").c_str(), 6 * BLOCK, piecesRow * BLOCK, color);
	this->pieces.push_back(knight);
	chessboard->setPiece(knight);


	// Bishops
	Piece* bishop = new Bishop(std::string("assets/" + colorName + "_bishop.png").c_str(), 2 * BLOCK, piecesRow * BLOCK, color);
	this->pieces.push_back(bishop);
	chessboard->setPiece(bishop);

	bishop = new Bishop(std::string("assets/" + colorName + "_bishop.png").c_str(), 5 * BLOCK, piecesRow * BLOCK, color);
	this->pieces.push_back(bishop);
	chessboard->setPiece(bishop);

	// Queen - King
	Piece* queen = new Queen(std::string("assets/" + colorName + "_queen.png").c_str(), 3 * BLOCK, piecesRow * BLOCK, color);
	this->pieces.push_back(queen);
	chessboard->setPiece(queen);

	Piece* king = new King(std::string("assets/" + colorName + "_king.png").c_str(), 4 * BLOCK, piecesRow * BLOCK, color);
	this->pieces.push_back(king);
	chessboard->setPiece(king);
}

// Getters
bool Player::getPlaying() {
	return this->playing;
}

std::vector<Piece*> Player::getPieces() const {
	return this->pieces;

}

int Player::getPhase() {
	return this->phase;
}

// Setters
void Player::setPlaying(bool playing) {
	this->playing = playing;
}

void Player::setPhase(int phase) {
	this->phase = phase;
}

void Player::updatePieces() const {
	for (int i = 0; i < this->pieces.size(); i++) {
		if (this->pieces[i]->isAlive()) {
			this->pieces[i]->update();
		}
	}
}

void Player::renderPieces() const {
	for (int i = 0; i < this->pieces.size(); i++) {
		if (this->pieces[i]->isAlive()) {
			this->pieces[i]->render();
		}
	}
}

bool Player::selectPiece(Chessboard* chessboard, int x, int y) {
	this->selectedPiece = chessboard->getPieceAt(x, y);

	if (!this->selectedPiece) {
		return false;
	}

	if (this->selectedPiece->getColor() != this->color) {
		this->selectedPiece = nullptr;
		return false;
	}

	this->possibleMoves = this->selectedPiece->getPossibleMoves(chessboard);

	return true;
}

bool Player::selectTile(Chessboard* chessboard, int x, int y) {
	bool tileEmpty = chessboard->isTileEmpty(x, y);

	if (tileEmpty) {
		for (int i = 0; i < this->possibleMoves.size(); i++) {
			if (this->possibleMoves[i].x == x && this->possibleMoves[i].y == y) {
				return true;
			}
		}
	}

	this->selectedPiece = nullptr;

	return false;
}

void Player::moveSelectedPieceAt(Chessboard* chessboard, int x, int y) {
	this->selectedPiece->moveTo(chessboard, x, y);
}

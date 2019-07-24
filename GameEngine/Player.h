#pragma once

#include <vector>
#include "Chessboard.h"
#include "Piece.h"


class Player {
private:
	std::vector<Piece*> pieces;
	Color color;
	int score;
	int phase;
	
	bool playing;

	Piece* selectedPiece;
	std::vector<Move> possibleMoves;
public:
	Player(Color color, Chessboard* chessboard);

	// Getters
	bool getPlaying();
	std::vector<Piece*> getPieces() const;
	int getPhase();

	// Setters
	void setPlaying(bool playing);
	void setPhase(int phase);

	void updatePieces() const;
	void renderPieces() const;

	bool selectPiece(Chessboard* chessboard, int x, int y);
	bool selectTile(Chessboard* chessboard, int x, int y);

	void moveSelectedPieceAt(Chessboard* chessboard, int x, int y);
};

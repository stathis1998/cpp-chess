#pragma once

#include <vector>
#include "Chessboard.h"
#include "Piece.h"


class Player {
private:
	std::vector<Piece*> pieces;
	Color color;
	int score;
	
	bool playing;

	Piece* selectedPiece;
public:
	Player(Color color, Chessboard* chessboard);

	// Getters
	bool getPlaying();
	std::vector<Piece*> getPieces() const;

	// Setters
	void setPlaying(bool playing);

	void updatePieces() const;
	void renderPieces() const;

	bool selectPiece(Chessboard* chessboard, int x, int y);
};

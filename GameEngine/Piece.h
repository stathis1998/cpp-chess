#pragma once

#include <vector>
#include "Game.h"
#include "StaticMesh.h"


typedef struct {
	int x;
	int y;
} Move;

enum Color {
	WHITE,
	BLACK
};

enum Value {
	PAWN = 1,
	KNIGHT = 3,
	BISHOP = 3,
	ROOK = 5,
	QUEEN = 9,
	KING = 900
};

class Piece : public StaticMesh {
protected:
	Color color;
	int value;
	bool alive;
	std::string name;
public:
	Piece(const char* path, int x, int y, Color color, int value, std::string name);

	bool isAlive();

	// Setters

	// Getters
	std::string getName();
	Color getColor();

	virtual std::vector<Move> getPossibleMoves() = 0;
};


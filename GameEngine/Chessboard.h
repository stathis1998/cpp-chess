#pragma once

#include <vector>
#include "Game.h"
#include "StaticMesh.h"
#include "Tile.h"


class Chessboard {
private:
	std::vector<Tile*> tiles;
public:
	Chessboard(const char* whiteTilePath, const char* blackTilePath);

	void update();
	void render();

	Piece* getPieceAt(int x, int y);
	void setPiece(Piece* piece);
	bool isTileEmpty(int x, int y);
	void emptyTile(int x, int y);
};

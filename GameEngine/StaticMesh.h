#pragma once

#include "Game.h"

class DrawCordinates {
public:
	int xPos;
	int yPos;

	DrawCordinates(int xPos, int yPos);
};

class StaticMesh {
protected:
	DrawCordinates drawCordinates;
	SDL_Texture* texture;

	SDL_Rect srcRect;
	SDL_Rect dstRect;
public:
	StaticMesh(const char* path, int xPos, int yPos);

	virtual void update();
	virtual void render();

	int getXPos() const;
	int getYPos() const;

	void setXPos(int xPos);
	void setYPos(int yPos);
};

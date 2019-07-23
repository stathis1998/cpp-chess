#include "StaticMesh.h"
#include "TextureManager.h"

// DrawCordinates Class
DrawCordinates::DrawCordinates(int xPos, int yPos) {
	this->xPos = xPos;
	this->yPos = yPos;
}

// StaticMesh Class
StaticMesh::StaticMesh(const char* path, int xPos, int yPos) : drawCordinates(DrawCordinates(xPos, yPos)) {
	this->texture = TextureManager::LoadTexture(path);

	this->update();
}

void StaticMesh::update() {
	this->srcRect.x = 0;
	this->srcRect.y = 0;
	this->srcRect.w = BLOCK;
	this->srcRect.h = BLOCK;

	this->dstRect.x = this->drawCordinates.xPos;
	this->dstRect.y = this->drawCordinates.yPos;
	this->dstRect.w = this->srcRect.w;
	this->dstRect.h = this->srcRect.h;
}

void StaticMesh::render() {
	SDL_RenderCopy(Game::Renderer, this->texture, nullptr, &(this->dstRect));
}

int StaticMesh::getXPos() const {
	return this->drawCordinates.xPos;
}

int StaticMesh::getYPos() const {
	return this->drawCordinates.yPos;
}

void StaticMesh::setXPos(int xPos) {
	this->drawCordinates.xPos = xPos;
}

void StaticMesh::setYPos(int yPos) {
	this->drawCordinates.yPos = yPos;
}

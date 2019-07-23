#include "Piece.h"

Piece::Piece(const char* path, int x, int y, Color color, int value, std::string name) : StaticMesh(path, x, y), color(color), value(value), alive(true), name(name) { }

bool Piece::isAlive() {
	return this->alive;
}

// Setters

// Getters
std::string Piece::getName() {
	return this->name;
}

Color Piece::getColor() {
	return this->color;
}
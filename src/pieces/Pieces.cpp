

#include "header/Pieces.hpp"

Pieces::Pieces(){}

std::string Pieces::getColor() const {
	return color_;
}

Pieces::~Pieces() {
	delete[] position_;
}

void Pieces::setColor(std::string color) {
	color_ = color;
}

int* Pieces::getPosition() const {
	return position_;
}

void Pieces::setPosition(int* position) {
	position_[0] = position[0];
	position_[1] = position[1];
}

bool Pieces::getStatus() const {
	return alive_;
}

void Pieces::setStatus(bool alive) {
	alive_ = alive;
}

void Pieces::setName(std::string& name) {
	name_ = name;
}

std::string Pieces::getName() const {
	return name_;
}

#include "header/Pieces.hpp"

Pieces::Pieces(){}

std::string Pieces::getColor() const {
	return color_;
}

void Pieces::setColor(std::string color) {
	color_ = color;
}

std::vector<int> Pieces::getPosition() const {
	return position_;
}

void Pieces::setPosition(const std::vector<int> position) {
	position_[0] = position[0];
	position_[1] = position[1];
}

bool Pieces::move(std::vector<std::vector<int>> possibleMoves, std::vector<int> desiredMove) {
  for(std::vector<int> i : possibleMoves) {
    if(i[0] == desiredMove[0] && i[1] = desiredMove[1])
      return false;
  }
  setPosition(desiredMove);
  return true;
}

bool Pieces::getStatus() const {
	return alive_;
}

void Pieces::setStatus(bool alive) {
	alive_ = alive;
}

void Pieces::setName(const std::string& name) {
  name_ = name;
}

std::string getName() const {
  return name_
}

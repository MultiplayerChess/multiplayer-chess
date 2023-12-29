#include "Pieces.hpp"

#ifndef KING_HPP
#define KING_HPP

class King: public Pieces{

	/*
	 * param: position and color
	 * output: sets the position and color and name
	 */
	King(std::vector<int> position, std::string color);

  // clone dw about this
  Pieces* clone() const override {
    return new King(*this);
  }
	/*
	 * return: 2D vector of all moves that's legal
	 */
  std::vector<std::vector<int>> getPossibleMoves(Board& board) const;

	/*
	 * param: vector of all pieces on board.
	 * return: if in check, return true, else return false.
	 */
	bool isInCheck(Board board) const;

}

#endif

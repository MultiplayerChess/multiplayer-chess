#include "Pieces.hpp"

#ifndef ROOK_HPP
#define ROOK_HPP

class Rook: public Pieces {

	/*
	 * param: starting position, color (black/white)
	 * output: sets the position to specified position
	 */
	Rook(std::vector<int> position, std::string& color);


  Pieces* clone() const override {
    return new Rook(*this);
  }

	/*
	 * output: destructor
	 */
	~Rook();	


	/*
	 * output: get all possible moves.
	 * return: 2D vector of all the possible moves.
	 * note: knight can move horizontally, but can be obstructed unlike the knight.
	 */
  std::vector<std::vector<int>> getPossibleMoves(const Board boards*) const;
}

#endif

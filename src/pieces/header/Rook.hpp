#include "Pieces.hpp"

#ifndef ROOK_HPP
#define ROOK_HPP

class Rook: public Pieces {

	/*
	 * param: starting position, color (black/white)
	 * output: sets the position to specified position
	 */
	Rook(int[2] position, std::string color);

	/*
	 * output: destructor
	 */
	~Rook();	


	/*
	 * output: get all possible moves.
	 * return: 2D array of all the possible moves.
	 * note: knight can move horizontally, but can be obstructed unlike the knight.
	 */
	int[][] getPossibleMoves() const;
}

#endif

#include "Pieces.hpp"

#ifndef KING_HPP
#define KING_HPP

class King: public Pieces{

	/*
	 * param: position and color
	 * output: sets the position and color
	 */
	King(int[2] position, std::string color);


	/*
	 * output: deconstructor
	 */
	~King();

	/*
	 * return: 2D array of all moves that's legal
	 */
	int[][] getPossibleMoves() const;

	/*
	 * param: vector of all pieces on board.
	 * return: if in check, return true, else return false.
	 */
	bool isInCheck() const;

}

#endif

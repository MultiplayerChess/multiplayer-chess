#include "Pieces.hpp"
#ifndef BISHOP_HPP
#define BISHOP_HPP

class Bishop: public Pieces {

	public:
		/*
		 * param: starting position and color
		 * output: creates a bishop in its position
		 */
		Bishop(int[2] pos, std::string color);

		/*
		 * output: destructor
		 */
		~Bishop();

		/*
		 * output: all the possible moves that the piece can make
		 * return: 2D array of all the possible moves.
		 * note: bishop moves diagonally.
		 */
		int[][] getPossibleMoves() const;

}

#endif


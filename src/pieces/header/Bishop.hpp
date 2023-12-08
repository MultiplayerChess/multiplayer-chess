#include "Pieces.hpp"
#ifndef BISHOP_HPP
#define BISHOP_HPP

class Bishop: public Pieces {

	public:
		/*
		 * param: starting position and color
		 * output: creates a bishop in its position
		 */
		Bishop(std::vector<int> position, std::string color);


		/*
		 * output: all the possible moves that the piece can make
		 * return: 2D array of all the possible moves.
		 * note: bishop moves diagonally.
     * note: do not check if it will be in check.
		 */
    std::vector<std::vector<int>> getPossibleMoves() const;

}

#endif


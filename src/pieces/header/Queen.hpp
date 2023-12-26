#include "Pieces.hpp"
#ifndef QUEEN_HPP
#define QUEEN_HPP
class Queen: public Pieces {

	public: 

		/*
		 * param: position to be set to and color
		 * output: creates a queen at position and specified color.
		 */
		Queen(std::vector<int> position, std::string color);

    Pieces* clone() const override {
      return new Queen(*this);
    }

		/*
		 * output: all the possible moves that the piece can do
		 * return 2D array of all possible moves
		 * note: queen can move horizontal, vertical, and diagonal.
		 */

    std::vector<std::vector<int>> getPossibleMoves(Board board) const;
}

#endif

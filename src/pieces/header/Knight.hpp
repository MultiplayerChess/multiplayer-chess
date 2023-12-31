#include "Pieces.hpp"
#ifndef KNIGHT_HPP
#define KNIGHT_HPP


class Knight: public Pieces{
	
	public:
		/*
		 * param: the position the knight will be in, the color it will be (White or Black)
		 * output: creates a knight in its positions.
		 * note: should use the methods defined in Pieces.hpp to set position and color, as those member variables are private
		 */
		Knight(std::vector<int> position, std::string color);
    
    Pieces* clone() const override {
      return new Knight(*this);
    }
		/*
		 * output: all the possible moves that the piece can do while still being a legal move
		 * return: 2D array of all the possible moves.
		 * note: the logic to check if the move is legal should have been implemented in the board class
		 */
    std::vector<std::vector<int>> getPossibleMoves(King ownKing) const; 
}

//
//
//
// FAT REMINDER THAT THE KNIGHT MOVES IN AN L. MAXIMUM OF 8 POSSIBLE MOVES. KNIGHT CANNOT BE OBSTRUCTED UNLESS IN A CHECK
//
//
#endif

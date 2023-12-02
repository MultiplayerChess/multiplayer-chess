#include "Pieces.hpp"

#ifndef PAWN_HPP
#define PAWN_HPP
class Pawn: public Pieces{
	
	public:
	/* 
	 * param: position and color
	 * output: creates constructor for pawn
	 */

	Pawn(int* position, std::string color);

	/*
<<<<<<< HEAD
=======
	 * output: destructor
	 */
	~Pawn();
	/*
>>>>>>> 5521d0bb1b6594243703bdfcdab59a88ded6db6e
	 * output: all the possible moves the piece can do while still being a legal move
	 * return: 2D vector of all the possible moves.
	 * note: the pawn can move diagnonally when capturing, and can en pessant. Logic for checking if the move is legal should be defined in the board class.
	 * note: pawn cannot move if there is a piece right ahead of it.
	 */
<<<<<<< HEAD
	
  std::vector<std::vector<int>> getPossibleMoves() const;
=======

	int** getPossibleMoves() const;
>>>>>>> 5521d0bb1b6594243703bdfcdab59a88ded6db6e

	/*
	 * param: the piece the player wishes to promote to.
	 * param: can be Knight, Rook, Bishop, or Queen.
	 * output: replaces the pawn with the desired promoted piece.
	 * note: you have to force the user to choose, or else the game cannot continue
	 */
	void promotion(std::string piece);
}
#endif

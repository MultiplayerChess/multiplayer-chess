#include "Pieces.hpp"

#ifndef PAWN_HPP
#define PAWN_HPP
class Pawn: public Pieces{
	
	public:
	/* 
	 * param: position and color
	 * output: creates constructor for pawn
	 */

	Pawn(std::vector<int> position, std::string& color);
   /*
	 * output: destructor
	 */
	~Pawn();
	
  // copy constructor
  Pawn(const Pawn& other);

  /*
	 * output: all the possible moves the piece can do while still being a legal move
	 * return: 2D vector of all the possible moves.
	 * note: the pawn can move diagnonally when capturing, and can en pessant. Logic for checking if the move is legal should be defined in the board class.
	 * note: pawn cannot move if there is a piece right ahead of it.
	 */
  std::vector<std::vector<int>> getPossibleMoves() const;


	/*
	 * param: the piece the player wishes to promote to.
	 * param: can be Knight, Rook, Bishop, or Queen.
	 * output: replaces the pawn with the desired promoted piece.
	 * note: you have to force the user to choose, or else the game cannot continue
	 */
	void promotion(std::string& piece);
  
  int getMoveCount() const;

  void setMoveTime(int moveTime);

  void incrementMoveCount();

  int getMoveTime() const;

  private:
  int moveCount_ = 0;
  int moveTime_;
}
#endif

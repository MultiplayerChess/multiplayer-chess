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
	 */
  std::vector<std::vector<int>> getPossibleMoves(const Board& boards) const;

  /*
   * output: all possible moves that don't land you in check
   */
  std::vector<std::vector<int>> getLegalMoves(const Board boards);

}
#endif

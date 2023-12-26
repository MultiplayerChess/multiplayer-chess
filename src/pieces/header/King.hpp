#include "Pieces.hpp"

#ifndef KING_HPP
#define KING_HPP

class King: public Pieces{

	/*
	 * param: position and color
	 * output: sets the position and color and name
	 */
	King(std::vector<int> position, std::string color);

	/*
	 * return: 2D vector of all moves that's legal
	 */
  std::vector<std::vector<int>> getPossibleMoves(std::vector<Pieces*> enemyPieces, std::vector<Pieces*> ownPieces, King enemyKing*) const;

	/*
	 * param: vector of all pieces on board.
	 * return: if in check, return true, else return false.
	 */
	bool isInCheck(Board board) const;

}

#endif

#include "header/Board.hpp"

Board::Board() {
	int board_** = new int*[8];
	for(int i = 0; i < 8; i++) {
		board_[i] = new int[8]
	}
}

Board::~Board()	{
	delete[] board_**;
}

static bool Board::isValidMove(int* currentPos, int* newPos, std::vector<Pieces> ownPieces, std::vector<Pieces> enemyPieces) {
	std::vector<std::vector<int>> occupied = getOccupiedSquares(std::vector<Pieces> ownPieces);
	
	bool tof = true;
	
	// gets size of the returned 2D vector. pieces should be the same color as the pieces.
	for(int i = 0; i < occupied.size(); i++) {
		tof = !(occupied[i][0] == newPos[0] && occupied[i][1] == newPos[1]);
	}
	
	// returns false if the new position is occupied.
	if(!tof) {
		return tof;
	}

	// to implement checking if will be in check.
	
	for(int i = 0; i < ownPieces.size(); i++) {
		if(ownPieces[i].getName().compare("King") == 0) {
		  tof = !ownPieces[i].isInCheck(enemyPieces, ownPieces);
      // this is in a not statement because isInCheck returns true if it is in check.
      // If it is in check, we want to return false <3
		} 
	}
  return tof;

}

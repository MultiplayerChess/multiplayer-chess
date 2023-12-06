#include "header/Board.hpp"

Board::Board() {
  board_[0][0] = new Rook(std::vector<int>{0,0}, "White");
  board_[1][0] = new Knight(std::vector<int>{1,0}, "White");
  board_[2][0] = new Bishop(std::vector<int>{2,0}, "White");
  board_[3][0] = new Queen(std::vector<int>{3,0}, "White");
  board_[4][0] = new King(std::vector<int>{4,0}, "White");
  board_[5][0] = new Bishop(std::vector<int>{5,0}, "White");
  board_[6][0] = new Knight(std::vector<int>{6,0}, "White");
  board_[7][0] = new Rook(std::vector<int>{7,0}, "White");
  for(int i = 0; i < 8; i++) {
    board_[i][1] = new Pawn(std::vector<int>{i,1}, "White");
    board_[i][6] = new Pawn(std::vector<int>{i,6}, "Black");
  }
  board_[0][7] = new Rook(std::vector<int>{0,7}, "Black");
  board_[1][7] = new Knight(std::vector<int>{1,7}, "Black");
  board_[2][7] = new Bishop(std::vector<int>{2,7}, "Black");
  board_[3][7] = new Queen(std::vector<int>{3,7}, "Black");
  board_[4][7] = new King(std::vector<int>{4,7}, "Black");
  board_[5][7] = new Bishop(std::vector<int>{5,7}, "Black");
  board_[6][7] = new Knight(std::vector<int>{6,7}, "Black");
  board_[7][7] = new Rook(std::vector<int>{7,7}, "Black");

}

static bool Board::isValidMove(std::vector<int> currentPos, std::vector<int> newPos, std::vector<Pieces> ownPieces, std::vector<Pieces> enemyPieces) {
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

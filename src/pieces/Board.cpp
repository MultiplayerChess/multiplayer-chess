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
// Copy constructor for Board class (deep copy)
Board::Board(const Board& other) : totalMoves_(other.totalMoves_) {
  for (int row = 0; row < 8; ++row) {
    for (int col = 0; col < 8; ++col) {
      if (other.board_[row][col]) {
        board_[row][col] = other.board_[row][col]->clone();
      } else {
       board_[row][col] = nullptr;
      }
    }
  }
}

// Assignment operator for Board class (deep copy)
Board& Board::operator=(const Board& other) {
  if (this != &other) { // Check for self-assignment
    totalMoves_ = other.totalMoves_;

    // Clear current board (release old resources)
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        delete board_[row][col];
        if (other.board_[row][col]) {
          board_[row][col] = other.board_[row][col]->clone();
        } else {
          board_[row][col] = nullptr;
        }
      }
    }
  }
  return *this;
}
std::vector<std::vector<Pieces*>> Board::getOccupiedSquares() {
  return board_;
}

void Board::replace(std::vector<int> pos1, std::vector<int> pos2) {
  if(board_[pos2[0]][pos2[1]])
    delete board_[pos2[0]][pos2[1]];
  board_[pos2[0]][pos2[1]] = board_[pos1[0]][pos1[1]]->clone();
  delete board_[pos1[0]][pos1[1]];
  board_[pos1[0]][pos1[1]] = nullptr;
}
int Board::getTotalMoves() {
  return totalMoves_;
} 

void Board::incrementTotalMoves() {
  totalMoves_++;
}


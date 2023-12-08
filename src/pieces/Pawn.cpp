#include "Pawn.hpp"

Pawn::Pawn(std::vector<int> position, std::string color) {
  setPosition(position);
  setColor(color);
  setName("Pawn");
}

std::vector<std::vector<int>> getPossibleMoves(Board boards) const {
  // there are 3 things that are possible with pawn.
  //
  // on the first move, the pawn has 2 choices. It could move 1 step, or it could move 2 steps.
  // Unless obstructed by another piece.
  // The pawn could move diagonally to capture.
  // the pawn could also en passant.
  std::vector<std::vector<Pieces>> board = boards.getOccupiedSquares();
  std::vector<int> currentPos = getPosition();
  std::vector<std::vector<int>> possibleMoves;
  // checks if it's black or white

  int moveDirection = 0;
  if(getName().compare("White") == 0) {
    moveDirection = 1;
  } else {
    moveDirection = -1;
  }
  for(int i = -1; i <= 1; i++) {
    if(currentPos[0]+i == 8 || currentPos[0]+i < 0 || currentPos[1]+moveDirection == 8 || currentPos[1]+moveDirection < 0) {
      continue;
    }
    bool blocked = false;
    if((!board[currentPos[0]][currentPos[1]+moveDirection].isEmpty()) || board[currentPos[0]+i][currentPos[1]+moveDirection].getColor().compare(getColor()) == 0)) {
      blocked = true;
    }
    if(!blocked) {
      possibleMoves.push_back({currentPos[0]+i,currentPos[1]+moveDirection);
    }
  }
  return possibleMoves;
}


int Pawn::getMoveCount() {
  return board_;
}

void Pawn::incrementMoveCount() {
  
}

#include "Pawn.hpp"

Pawn::Pawn(int* position, std::string color) {
  setPosition(position);
  setColor(color);
  setName("Pawn");
}

std::vector<std::vector<int>> getPossibleMoves() const {
  // there are 3 things that are possible with pawn.
  //
  // on the first move, the pawn has 2 choices. It could move 1 step, or it could move 2 steps.
  // Unless obstructed by another piece.
  // The pawn could move diagonally to capture.
  // the pawn could also en passant.

  // checks if it's black or white
  if(getName().compare("White") == 0) {
    // implement logic...
  } else if(getName().compare("Black") == 0){
    // implement logic...
  }
}

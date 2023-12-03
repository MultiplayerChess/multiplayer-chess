#include "Pawn.hpp"

Pawn::Pawn(int* position, std::string color) {
  setPosition(position);
  setColor(color);
  setName("Pawn");
}

std::vector<std::vector<int>> getPossibleMoves(std::vector<Pieces> enemyPieces, std::vector<Pieces> ownPieces, King ownKing) const {
  // there are 3 things that are possible with pawn.
  //
  // on the first move, the pawn has 2 choices. It could move 1 step, or it could move 2 steps.
  // Unless obstructed by another piece.
  // The pawn could move diagonally to capture.
  // the pawn could also en passant.
  int* currentPos[2] = getPosition();
  // checks if it's black or white
  int moveDirection = 0;
  if(getName().compare("White") == 0) {
    moveDirection = 1;
  } else {
    moveDirection = -1
  }
  
  for(int i = -1; i <= 1; i++) {
    std::vector<int> temp;

    for(int j = 0; j < enemyPieces.size(); j++) {
      int* enemyPosition[2] = enemyPieces[j].getPosition();
      int* ownPosition[2] = getPosition();
        // checks if there is an ememy straight ahead of the pawn
      bool enemyInFront = false;
      if(enemyPosition[0] == ownPosition[0]+moveDirection && enemyPosition[1] == ownPosition[1]) {
        enemyInFront = true;
      } else if(enemyPosition[0] == ownPosition[0]+moveDirection && enemyPosition[1] == ownPosition[1]+i) {



      }
    }
    if(i == 0) {
      if(!enemyInFront) {
        // checks if there is a piece obstructing its path.
        bool obstructed = false;
        for(int j = 0; j < ownPieces.size(); j++) {
          int* ownPiecePosition[2] = ownPieces[j].getPosition();
          if(ownPiecePosition[0] == ownPosition[0]+1 && ownPiecePosition[1] == ownPosition[1]) {
            obstructed = true;
            break;
          }
        }
        if(!obstructed) {
          temp.push_back(ownPosition[0]+moveDirection);
          temp.push_back(ownPosition[1])
        }
      }
    }
  }
  
  

}
  
  setPosition();
}

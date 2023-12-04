#include "Queen.hpp"


Queen::Queen(std::vector<int> position, std::string color) {
  setPosition(position);
  setColor(color);
  setName("Queen");
}



std::vector<std::vector<int>> Queen::getPossibleMoves(std::vector<Pieces> ownPieces, std::vector<Pieces> enemyPieces) {

  std::vector<std::vector<int>> possibleMoves;
  std::vector<int> currentPos = getPosition();
  // goes upward
  //
  // time to set directon
  // i guess the direction vector is not needed but whatever I'll keep it because it helps me read it
  enum Direction {
    N,S,E,W,NE,NW,SE,SW
  };
  for(int iter = N; iter <= SW; iter++) {
    Direction dir = (Direction)(iter);
    for(int i = 1; i < 8; i++) {
      //pushAtEnd is a vector that keeps track of the latest change
      std::vector<int> pushAtEnd;
      std::vector<int> tempCurrentPos = currentPos;
      bool outOfBound = false;
      switch(dir) {
        case N:
          if(i+currentPos[1] == 8) {
            outOfBound = true;
          } else {
            tempCurrentPos = std::vector<int>{currentPos[0], i+currentPos[1]};
          }
          break;
        case S:
          if(-i+currentPos[1] < 0) {
            outOfBound = true;
          } else {
            tempCurrentPos = std::vector<int>{currentPos[0], -i+currentPos[1]};
          }
          break;
        case E:
          if(-i+currentPos[0] < 0) {
            outOfBound = true;
          } else {
            tempCurrentPos = std::vector<int>{-i+currentPos[0], currentPos[1]};
          }
          break;
        case W:
          if(i+currentPos[0] == 8) {
            outOfBound = true;
          } else {
            tempCurrentPos = std::vector<int>{i+currentPos[0], currentPos[1]};
          }
          break;
        case NE:
          if(i+currentPos[1] == 8 || -i+currentPos[0] < 0) {
            outOfBound = true;
          } else {
            tempCurrentPos = std::vector{-i+currentPos[0], i+currentPos[1]};
          }
          break;
        case NW:
          if(i+currentPos[1] == 8 || i+currentPos[0] == 8) {
            outOfBound = true;
          } else {
            tempCurrentPos = std::vector{i+currentPos[0], i+currentPos[1]};
          }
          break;
        case SE:
          if(-i+currentPos[1] < 0 || -i+currentPos[0] < 0) {
            outOfBound = true;
          } else {
            tempCurrentPos = std::vector{-i+currentPos[0], -i+currentPos[1]};
          }
          break;
        case SW:
          if(-i+currentPos[1] < 0 || i+currentPos[0] == 8) {
            outOfBound = true;
          } else {
            tempCurrentPos = std::vector{i+currentPos[0], -i+currentPos[1]};
          }
          break;
      }
      if(outOfBound) {break;}

      bool onOwnPiece = false;
      for(int j = 0; j < ownPieces.size(); j++) {
        std::vector<int> temp = ownPieces[j].getPosition();
        if(tempCurrentPos[1] == temp[1] && tempCurrentPos[0] == temp[0]) {
          onOwnPiece = true;
          break;
      }
      if(onOwnPiece) {break;}

      bool onEnemyPiece = false;
      for(int i = 0; i < enemyPieces.size(); i++) {

        std::vector<int> temp = enemyPieces[i].getPosition();
        if(tempCurrentPos[1] == temp[1] && tempCurrentPos[0] == temp[0]) {
          pushAtEnd = tempCurrentPos;
          onEnemyPiece = true;
          break;
        }
      }
      possibleMoves.push_back(pushAtEnd);
      if(onEnemyPiece) {break;}
    
    }

  }
  return possibleMoves;
}

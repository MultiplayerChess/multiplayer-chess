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
  std::unordered_map<Direction, std::vector<int>> directionOffset = {
    {N:{0,1}},
    {S:{0,-1}},
    {E:{-1,0}},
    {W:{1,0}},
    {NE:{-1,1}},
    {NW:{1,1}},
    {SE:{-1,-1}},
    {SW:{1,-1}}
  };
  for(int iter = N; iter <= SW; iter++) {
    Direction dir = (Direction)(iter);
    for(int i = 1; i < 8; i++) {
      //pushAtEnd is a vector that keeps track of the latest change
      std::vector<int> pushAtEnd;
      std::vector<int> tempCurrentPos{
        currentPos[0]+directionOffset[iter][0]*i,
        currentPos[1]+directionOffset[iter][1]*i
      };

      if(tempCurrentPos[0] == 8 || tempCurrentPos[0] < 0 || tempCurrentPos[1] == 8 ||  < 0) {
        break;
      }

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

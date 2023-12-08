#include "Queen.hpp"


Queen::Queen(std::vector<int> position, std::string color) {
  setPosition(position);
  setColor(color);
  setName("Queen");
}



std::vector<std::vector<int>> Queen::getPossibleMoves(Board board) {

  std::vector<std::vector<int>> possibleMoves;
  std::vector<int> currentPos = getPosition();
  std::vector<std::vector<Pieces>> board = board.getOccupiedSquares();
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

      if(board[tempCurrentPos[0]][tempCurrentPos[1]] != null && board[tempCurrentPos[0]][tempCurrentPos[1]].getColor().compare(getColor()) == 0) {
        break;
      }

      std::vector<int> temp = enemyPieces[i].getPosition();
      if(board[tempCurrentPos[0]][tempCurrentPos[1]] != null && board[tempCurrentPos[0]][tempCurrentPos[1]].getColor().compare(getColor()) != 0) {
        pushAtEnd = tempCurrentPos;
        break;
      }
    }
    possibleMoves.push_back(pushAtEnd);
    
  }
  return possibleMoves;
}

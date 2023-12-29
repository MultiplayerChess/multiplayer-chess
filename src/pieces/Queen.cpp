#include "Queen.hpp"


Queen::Queen(std::vector<int> position, std::string color) {
  setPosition(position);
  setColor(color);
  setName("Queen");
}



std::vector<std::vector<int>> Queen::getPossibleMoves(Board& board) {

  std::vector<std::vector<int>> possibleMoves;
  std::vector<int> currentPos = getPosition();
  std::vector<std::vector<Pieces*>> board = board.getOccupiedSquares();
  // goes upward
  //
  // time to set directon
  // i guess the direction vector is not needed but whatever I'll keep it because it helps me read it
  enum Direction {
    N,S,E,W,NE,NW,SE,SW
  };
  std::unordered_map<Direction, std::vector<int>> directionOffset = {
    {N:std::vector<int>{0,1}},
    {S:std::vector<int>{0,-1}},
    {E:std::vector<int>{-1,0}},
    {W:std::vector<int>{1,0}},
    {NE:std::vector<int>{-1,1}},
    {NW:std::vector<int>{1,1}},
    {SE:std::vector<int>{-1,-1}},
    {SW:std::vector<int>{1,-1}}
  };
  for(int iter = N; iter <= SW; iter++) {
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

      if(board[tempCurrentPos[0]][tempCurrentPos[1]] != nullptr && board[tempCurrentPos[0]][tempCurrentPos[1]]->getColor().compare(getColor()) == 0) {
        break;
      }

      std::vector<int> temp = enemyPieces[i].getPosition();
      if(board[tempCurrentPos[0]][tempCurrentPos[1]] != nullptr && board[tempCurrentPos[0]][tempCurrentPos[1]]->getColor().compare(getColor()) != 0) {
        pushAtEnd = tempCurrentPos;
        break;
      }
      possibleMoves.push_back(pushAtEnd);
    }
    
  }
  return possibleMoves;
}

std::vector<std::vector<int>> Queen::getLegalMoves(Board& board) const {
  std::vector<std::vector<int>> ownPossibleMoves = getPossibleMoves();
  std::vector<int> ownPosition = getPosition();
  King* ownKing;
  Board board2 = boards;
  for(int i = 0; i < tempBoard.size(); i++) {
    for(int j = 0; j < tempBoard[i].size(); j++) {
      if(tempBoard[i][j]->getName().compare("King") == 0 && tempBoard[i][j]->getColor().compare(getColor()) == 0) {
        ownKing = tempBoard[i][j];
        break;
      }
    }
    if(!ownKing) {
      break;
    }
  }
  for(int i = ownPossibleMoves.size; i >= 0; i--) {
    Pieces* tempPiece = nullptr;
    if(tempBoard[ownPossibleMoves[i][0]][ownPossibleMoves[i][1]] != nullptr)
      tempPiece = tempBoard[ownPossibleMoves[i][0]][ownPossibleMoves[i][1]]->clone();
    move(board2, currentPos(), ownPossibleMoves[i]);
    if(ownKing.isInCheck()) {
      move(board2, ownPossibleMoves[i], currentPos());
      ownPossibleMoves.erase(i);
    }
    board2.setSquare(tempPiece);
    delete tempPiece;
  }
  return ownPossibleMoves;
}

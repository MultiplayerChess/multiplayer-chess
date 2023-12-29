#include "header/Knight.hpp"

Knight::Knight(int* pos, std::string color) {
	setPosition(pos);
	setColor(color);
  setName("Knight");
}

std::vector<std::vector<int>> Knight::getPossibleMoves(Board& board) const {
  std::vector<int> currentPos = getPosition();
  std::vector<std::vector<Pieces*>> tempBoard = board.getOccupiedSquares();
  std::vector<std::vector<int>> possibleMoves;
  possibleMoves.push_back(std::vector<int>{currentPos[0]+2, currentPos[1]+1});
  possibleMoves.push_back(std::vector<int>{currentPos[0]+2, currentPos[1]-1});
  possibleMoves.push_back(std::vector<int>{currentPos[0]-2, currentPos[1]+1});
  possibleMoves.push_back(std::vector<int>{currentPos[0]-2, currentPos[1]-1});
  possibleMoves.push_back(std::vector<int>{currentPos[0]+1, currentPos[1]+2});
  possibleMoves.push_back(std::vector<int>{currentPos[0]+1, currentPos[1]-2});
  possibleMoves.push_back(std::vector<int>{currentPos[0]-1, currentPos[1]+2});
  possibleMoves.push_back(std::vector<int>{currentPos[0]-1, currentPos[1]-2});

  for(int i = possibleMoves.size; i >= 0; i--) {
    if(possibleMoves[i][0] >= 8 || possibleMoves[i][0] < 0 || possibleMoves[i][1] >= 8 || possibleMoves[i][1] < 0 || tempBoard[possibleMoves[i][0]][possibleMoves[i][1]]->getColor().compare(getColor()) != 0) {
      possibleMoves.erase(i);
    }
  }
  return possibleMoves;
}

std::vector<std::vector<int>> Knight::getLegalMoves(Board& board) const {
  std::vector<std::vector<int>> ownPossibleMoves = getPossibleMoves(board);
}

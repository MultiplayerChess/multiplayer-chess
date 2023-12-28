#include "header/Rook.hpp"

Rook::Rook(int* position, std::string color) {
	setPosition(position);
	setColor(color);
	setName("Rook");
}


std::vector<std::vector<int>> getPossibleMoves(const Board& board) const {
  std::vector<std::vector<Pieces*>>	boardPos = boards.getOccupiedSquares();
  std::vector<std::vector<int>> possibleMoves;
  std::vector<int> ownPosition = getPosition();
  enum Directions {
    N,S,E,W
  };
  std::unordered_map<Directions, std::vector<int>> directionOffset = {
    {N:std::vector<int>{1,0}},
    {S:std::vector<int>{-1,0}},
    {E:std::vector<int>{0,1}},
    {W:std::vector<int>{0,-1}}
  };
  for(int i = N; i <= W; i++) {
    std::vector<int> newPosition{ownPosition[0]}
    Pieces* tp = boardPos[ownPosition[0]+directionOffset[0]*j][ownPosition[1]+directionOffset[1]*j];
    for(int j = 1; j < 8; j++) {
     if(ownPosition[0]+directionOffset[0]*j < 0
         || ownPosition[0] + directionOffset[0]*j >= 8
         || ownPosition[1] + directionOffset[1]*j < 0
         || ownPosition[1] + directionOffset[1]*j >= 8
     ) {
      break;
     } else if(tp != nullptr && tp->getColor().compare(getColor()) != 0) {}
        possibleMoves.push_back();
        break;
     } else if(tp != nullptr) {
        break;
     }
   } 
  }
  return possibleMoves;
}

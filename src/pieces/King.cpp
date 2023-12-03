#include "header/King.hpp"

King::King(int* position, std::string color) {
  setColor(color);
  setPosition();
  setName("King");
}

std::vector<std::vector<int>> King::getPossibleMoves(std::vector<Pieces> enemyPieces, std::vector<Pieces> ownPieces, King enemyKing) const {
  // to be implemented
  int* currentPos = getPosition();
  
  // this gets the final list of possible moves
  std::vector<std::vector<int>> possibleMoves;
  // I will hard code the logic to check if the king will be in bound because that's easier
  // this has all the possible combinations. Will have to weed down.

  for(int i = -1; i < 2; i++) {
    for(int j = -1; j < 2; j++) {
      if(i == 0 && j == 0) {
        continue;
      }
      int* position = new int[2];
      position[0] = currentPos[0]+i;
      position[1] = currentPos[1]+j;
      if(!(position[0] >= 0 && position[0] < 8 && position[1] >= 0 && position[1] < 8)) { continue;} 
      // ANOTHER FOR LOOP
      bool tof = false;
      for(int k = 0; k < ownPieces.size(); k++) {
        int* ownPiecePos = new int[2];
        ownPiecePos = ownPieces[k].getPosition();
        if(!(position[0] == ownPiecePos[0] && position[1] == ownPiecePos[1])) {
          delete[] ownPiecePos;
          continue;
        } else {
          tof = true;
        }
        delete[] ownPiecePos;
      }
      if(!tof) {
        setPosition(position);
       if(!isInCheck()) {
          std::vector<int> temp{position[0], position[1]};
          possibleMoves.push_back(temp);
        }
        setPosition(currentPos);
      }
    delete[] position;
    }
  }
  return possibleMoves;
}
bool isInCheck(std::vector<Pieces> enemyPieces, std::vector<Pieces> ownPieces, King enemyKing) {
  int* currentPos = getPosition();
  for(int i = 0; i < enemyPieces.size(); i++) {
    std::vector<std::vector<int>> possibleMoves = enemyPieces[i].getPossibleMoves();

    for(int j = 0; j < possibleMoves.size(); j++) {
      if(currentPos[0] == possibleMoves[j][0] && currentPos[1] == possibleMoves[j][1]) {
        delete[] currentPos;
        return true;
      }
    }
  }

  // temp lines
  // uses distance formula to find the distance between kings
  int* enemyKingPosition = enemyKing.getPosition();
  bool kingsWillTouch = sqrt(pow(currentPos[0] - enemyKing[0],2) + pow(currentPos[1] - enemyKing[1],2)) > 3;

  if(kingsWillTouch) {
    std::vector<std::vector<int>> kingNoGoZone;
    // find the average distance between the X and Y axis
    double averageX = (double)(currentPos[0] + enemyKingPosition[0])/2;
    double averageY = (double)(currentPos[1] + enemyKingPosition[1])/2;
    if(averageX == currentPos[0] || averageY == currentPos[1]) {

      for(int i = -1; i < 2; i++) {
        kingNoGoZone.push_back(std::vector<int>{currentPos[0]+i, currentPos[i]});
        kingNoGoZone.push_back(std::vector<int>{currentPos[0], currentPos[i]+i});
      }

    } else if(averageX - (int)averageX == 0.5) {
    
      kingNoGoZone.push_back(std::vector<int>{averageX, averageY});
      kingNoGoZone.push_back(std::vector<int>{(int)(averageX + 0.5), averageY});
    
    } else if(averageY - (int)averageY == 0.5) {
      
      kingNoGoZone.push_back(std::vector<int>{averageX, averageY});
      kingNoGoZone.push_back(std::vector<int>{averageX, (int)(averageY+0.5)});
    
    } else if(averageX != currentPos[0] && averageY != currentPos[1]) {

      

    }
  }

  delete[] currentPos;
  return false;
}

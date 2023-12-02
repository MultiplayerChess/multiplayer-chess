#include "header/King.hpp"

King::King(int* position, std::string color) {
  setColor(color);
  setPosition();
  setName("King");
}

std::vector<std::vector<int>> King::getPossibleMoves(std::vector<Pieces> enemyPieces, std::vector<Pieces> ownPieces) const {
  // to be implemented
  int* currentPos = getPosition();
  
  // this gets the final list of possible moves
  std::vector<std::vector<int>> possibleMoves;
  // I will hard code the logic to check if the king will be in bound because that's easier
  // this has all the possible combinations. Will have to weed down.
  for(int i = -1; i < 2; i++) {
    for(int j = -1; j < 2; j++) {
      if(i == 0 && j == 0) {
        continue
      }
      int* position = new int[2];
      position[0] = currentPos[0]+i;
      position[1] = currentPos[1]+j;
<<<<<<< HEAD
=======
      if(!(position[0] >= 0 && position[0] < 8 && position[1] >= 0 && position[1] < 8)) { continue;} 
>>>>>>> b68ae93a1d388cb60cdf998477878589d152709e
      // ANOTHER FOR LOOP
      bool tof = false;
      for(int k = 0; k < ownPieces.size(); k++) {
        int* ownPiecePos = new int[2];
        ownPiecePos = ownPieces[k].getPosition();
<<<<<<< HEAD
        if(!(posit  ion[0] == ownPiecePos[0] && position[1] == ownPiecePos[1])) {
=======
        if(!(position[0] == ownPiecePos[0] && position[1] == ownPiecePos[1])) {
>>>>>>> b68ae93a1d388cb60cdf998477878589d152709e
          free(ownPiecePos);
          continue;
        } else {
          tof = true;
        }
        free(ownPiecePos);
      }
      if(!tof) {
        setPosition(position);
        if(!isInCheck()) {
          std::vector<int> temp{position[0], position[1]};
          possibleMoves.push_back(temp);
        }
        setPosition(currentPos);
      }
    free(position);
    }
  }
  free(currentPos);
  return possibleMoves;
}
bool isInCheck(std::vector<Pieces> enemyPieces, std::vector<Pieces> ownPieces) {
  int* currentPos = getPosition();
  for(int i = 0; i < enemyPieces.size(); i++) {
    std::vector<std::vector<int>> possibleMoves = enemyPieces[i].getPossibleMoves();

    for(int j = 0; j < possibleMoves.size(); j++) {
      // I know what you're thinking
      // nested loop?
      // Yes. In cases like this with limited iteration (27 moves maximum per piece, so upper bound is in hundreds)
      // using a vector would be faster than using something
      // like a hashmap
      // not sure how the logic would work either
      // "By default, use vector when you need a container" - Bjarne Stroustrup.
      if(currentPos[0] == possibleMoves[j][0] && currentPos[1] == possibleMoves[j][1]) {
        free(currentPos);
        return true;
      }
    }
  }
  free(currentPos);
  return false;
}

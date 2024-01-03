#include "header/King.hpp"

King::King(int* position, std::string color) {
  setColor(color);
  setPosition();
  setName("King");
}

std::vector<std::vector<int>> King::getPossibleMoves(const Board& board) const {
  // to be implemented
  std::vector<int> currentPos = getPosition();
  std::vector<std::vector<Pieces*>> occupied = board.getOccupiedSquares();

  // this gets the final list of possible moves
  std::vector<std::vector<int>> possibleMoves;
  // I will hard code the logic to check if the king will be in bound because that's easier
  // this has all the possible combinations. Will have to weed down.

  // temp lines
  // uses distance formula to find the distance between kings

  King* enemyKing = nullptr;
  for(int i = 0; i < occupied.size(); i++) {
    for(int j = 0; j < occupied[i].size(); j++) {
      if(occupied[i][j] != nullptr && occupied[i][j].getName().compare("King") == 0 && occupied[i][j].getColor().compare(getColor()) != 0) {
        enemyKing = &occupied[i][j];
        break;
      }
    }
    if(enemyKing!=nullptr)
      break;
  }
  std::vector<int> enemyKingPosition = enemyKing->getPosition();
  bool kingsWillTouch = sqrt(pow(currentPos[0] - enemyKingPosition[0],2) + pow(currentPos[1] - enemyKingPosition[1],2)) > 3;
  
  std::vector<std::vector<int>> kingNoGoZone;
  if(kingsWillTouch) {
    // find the average distance between the X and Y axis
    double averageX = (double)(currentPos[0] + enemyKingPosition[0])/2;
    double averageY = (double)(currentPos[1] + enemyKingPosition[1])/2;
    if(averageX == currentPos[0] || averageY == currentPos[1]) {

      for(int i = -1; i < 2; i++) {
        kingNoGoZone.push_back(std::vector<int>{averageX, averageY+i});
        kingNoGoZone.push_back(std::vector<int>{averageX+i, averageY});
      }

    } else if(averageX - (int)averageX == 0.5) {
    
      kingNoGoZone.push_back(std::vector<int>{averageX, averageY});
      kingNoGoZone.push_back(std::vector<int>{(int)(averageX + 0.5), averageY});
    
    } else if(averageY - (int)averageY == 0.5) {
      
      kingNoGoZone.push_back(std::vector<int>{averageX, averageY});
      kingNoGoZone.push_back(std::vector<int>{averageX, (int)(averageY+0.5)});
    
    } else if(averageX != currentPos[0] && averageY != currentPos[1]) {

      kingNoGoZone.push_back(std::vector<int>{averageX,averageY});

    }
  }

  for(int x = -1; x < 2; x++) {
    for(int y = -1; y < 2; y++) {
      
      // for loop to skip over the moves the king can't make because it will be touching enemy king
      bool willTouch = false;
      for(int i = 0; i < kingNoGoZone.size(); i++) {
        if(currentPos[0] == kingNoGoZone[0] && currentPos[1] == kingNoGoZone[1]) {
          willTouch = true;
        }
      }
      if(willTouch || (x == 0 && y == 0) ) {
        continue;
      }
      
      // now we check if it will interfere with our own pieces
      bool inOwnPiecePos = false;
      for(int i = 0; i < ownPieces.size(); i++) {
        if(currentPos[0] == ownPieces[i][0] && currentPos[1] == ownPieces[i][1]) {
          inOwnPiecePos = true;
        }
      }
      if(inOwnPiecePos) {continue;}

      // now we check if it's in bound
      if(currentPos[0] > 8 || currentPos[0] < 0 || currentPos[1] > 8 || currentPos[1] < 0) {
        continue;
      }

    }
  }
  return possibleMoves;
}

std::vector<std::vector<int>> King::getLegalMoves(const Board& board) const {
  std::vector<std::vector<int>> ownPossibleMoves = getPossibleMoves();
  std::vector<int> ownPosition = getPosition();
  Board board2 = board;
  std::vector<std::vector<Pieces*>> tempBoard = board2.getOccupiedSquares()
  for(int i = ownPossibleMoves.size(); i>=0; i--) {
    Pieces* tempPiece = nullptr;
    if(tempBoard[ownPossibleMoves[0]][ownPossibleMoves[1]] != nullptr;)
      tempPiece = &tempBoard[ownPossibleMoves[0]][ownPossibleMoves[1]]->clone();
    move(board2, currentPos(), ownPossibleMoves[i]);
    if(isInCheck(board2)) {
      move(board2, ownPossibleMoves[i], currentPos());
      ownPossibleMoves.erase(i);
    }
    move(board2,ownPossibleMoves[i], currentPos());
    delete tempPiece;
  }
  return ownPossibleMoves;
}

bool King::isInCheck(Board board) {
  std::vector<int> currentPos = getPosition();
  std::vector<std::vector<int>> boardPos = board.getOccupiedSquares(); 
  for(int i = 0; i < enemyPieces.size(); i++) {
    std::vector<std::vector<int>> possibleMoves = enemyPieces[i]->getPossibleMoves();

    for(int j = 0; j < possibleMoves.size(); j++) {
      if(currentPos[0] == possibleMoves[j][0] && currentPos[1] == possibleMoves[j][1]) {
        return true;
      }
    }
  }
  return false;
}

// direction left = 0 right = 1
bool King::canCastle(int direction) const {
  if(getMoveCount() != 0) {
    return false;
  }
  if(isInCheck()) {
    return false;
  }
  std::vector<int> currentPos = getPosition();
  std::vector<std::vector<Pieces*>> tempBoard = board.getPossibleMoves();

  if(direction == 0 && tempBoard[0][getPosition()[1]] != nullptr && tempBoard[0][getPosition()[1]].getName().compare("Rook") == 0 && tempBoard[0][getPosition()[1]].getMoveCount() == 0) {
    return true;
  }
  if(direction == 1  tempBoard[7][getPosition()[1]] != nullptr && tempBoard[7][getPosition()[1]].getName().compare("Rook") == 0 && tempBoard[7][getPosition()[1]].getMoveCount() == 0) {
    
    return true;
  }
  return false;
}

int King::getMoveCount() const {
  return moveCount_;
}

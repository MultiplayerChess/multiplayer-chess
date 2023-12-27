#include "Pawn.hpp"

Pawn::Pawn(std::vector<int> position, std::string color) {
  setPosition(position);
  setColor(color);
  setName("Pawn");
}

Pawn::Pawn(const Pawn& other) : Pieces(other) {
  moveCount_ = other.moveCount_;
  moveTime_ = other.moveTime_;
}

std::vector<std::vector<int>> getPossibleMoves(Board boards*) const {
  // there are 3 things that are possible with pawn.
  //
  // on the first move, the pawn has 2 choices. It could move 1 step, or it could move 2 steps.
  // Unless obstructed by another piece.
  // The pawn could move diagonally to capture.
  // the pawn could also en passant.
  std::vector<std::vector<Pieces>> board = boards.getOccupiedSquares();
  std::vector<int> currentPos = getPosition();
  std::vector<std::vector<int>> possibleMoves;
  // checks if it's black or white
  int moveDirection = 0;
  if(getName().compare("White") == 0) {
    moveDirection = 1;
  } else {
    moveDirection = -1;
  }
  for(int i = -1; i <= 1; i++) {
    if(currentPos[0]+i == 8 || currentPos[0]+i < 0 || currentPos[1]+moveDirection == 8 || currentPos[1]+moveDirection < 0) {
      continue;
    }
    if(i == 0)
      continue;
    bool blocked = false;
    // sorry I could've made this more readable with a variable or a method :(
    if(board[currentPos[0]+i][currentPos[1]+moveDirection].getColor().compare(getColor()) == 0) {
      blocked = true;
    }
    if(!blocked) {
      possibleMoves.push_back({currentPos[0]+i,currentPos[1]+moveDirection);
    }
  }
  return possibleMoves;
}

std::vector<int> Pawn::getLegalMoves(Board& board) {
  std::vector<std::vector<int>> ownPossibleMoves = getPossibleMoves();
  std::vector<std::vector<int>> allPossibleMoves;
  std::string ownColor = getColor();
  King ownKing = nullptr;
  std::vector<std::vector<Pieces*>> tempBoard = board.getOccupiedSquares();
  // find King
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(tempBoard[i][j]->getName().compare("King") == 0 && tempBoard[i][j]->getColor().compare(ownColor) == 0) {
        ownKing = tempBoard[i][j];
        break;
      }
    }
    if(ownKing)
      break;
  }
    // check if it can advance twice
  int moveDirection = 1;
  if(getColor().compare("Black") == 0) {
    moveDirection = -1
  }
  if(getMoveCount() == 0 && tempBoard[getPosition()[0]][getPosition()[1]+moveDirection*2] == nullptr) {
    ownPossibleMoves.push_back(std::vector<int>{getPosition()[0],getPosition()[1]+moveDirection*2});
  } else if(tempBoard[getPosition()[0]][getPosition()[1]+moveDirection] == nullptr){
    ownPossibleMoves.push_back(std::vector<int>{getPosition()[0]mgetPosition()[1]+moveDirection*2});
  }
 
  for(int i = ownPossibleMoves.size()-1; i >= 0; i--) {
    Board board2 = board; // dw copy constructor is declared
    move(board2,currentPos(), ownPossibleMoves[i]);
    if(ownKing.isInCheck(board2)) {
      ownPossibleMoves.erase(i);
    }
  }
  return ownPossibleMoves;
}

int Pawn::getMoveCount() const {
  return moveCount_;
}

void Pawn::setMoveTime(int moveTime) {
  moveTime_ = moveTime;
}

void Pawn::incrementMoveCount() {
   moveCount_++;
}

int Pawn::getMoveTime() const {
  return moveTime_;
}

bool Pawn::promotion(std::string& piece, Board* board) {
  std::unordered_map<std::string, Pieces*> promotionOptions = {
    {"Queen": new Queen(getPosition(), getColor())},
    {"Rook": new Rook(getPosition(), getColor())},
    {"Bishop": new Bishop(getPosition(), getColor())},
    {"Knight": new Knight(getPosition(), getColor()}
  };
  std::vector<std::vector<int>> occupied = board->getOccupiedSquares();
  std::string name = getName();
  if((name.compare("White") == 0 && getPosition()[1] == 7) 
    || (name.compare("Black") == 0 && getPosition()[1] == 0)) {
    board->replace(promotionOptions[piece],this);
    return true;
  }
  return false;
}

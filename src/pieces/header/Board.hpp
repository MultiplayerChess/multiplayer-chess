#include<stdio>
#include<stdlib>
#include<string>
#include<regex>
#ifndef BOARD_HPP
#define BOARD_HPP


class Board {

	public:
		/*
		 * output: creates defautl constructor WILL NOT BE OVERLOADED
		 * note: size of board is 8x8
		 */
		Board();
		
		/*
		 * output: destructor
		 */
		~Board();

		/*
		 * param: the move to be made by piece
		 * return: if move is valid, return true. Else, return false.
		 * note: it will also check if the King is or will be in check.
		 */
		// static bool isValidMove(std::vector<int> currentPos, std::vector<int> newPos, std::vector<Pieces> ownPieces, std::vector<Pieces> enemyPieces, King ownKing);

    // deep copy
    Board(const Board& other); 
    Board& Board::operator=(const Board& other);
		/*
		 * param: list of all the pieces specified in vector
		 * return: list of all occupied squares. (color ambiguous)
		 */
    // unneeded for now. Might remove in future.
		std::vector<std::vector<int>> getOccupiedSquares();

    /*
     *
     */

    /*
     * param: the piece that is replacing, the piece to be replaced.
     * output: deletes the piece to be replaced.
     */
    void replace(Pieces* piece1, Pieces* piece2);
    /*
     * return: how many moves that has been done
     */
    int getTotalMoves();

    /*
     * output: increments the total moves by 1
     */
    void incrementTotalMoves();


	private:
    std::vector<std::vector<Pieces*>(8)>(8,nullptr) board_();
    int totalMoves_ = 0;
}


#endif

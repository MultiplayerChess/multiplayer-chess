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
		static bool isValidMove(int* currentPos, int* newPos, std::vector<Pieces> alivePieces);


		/*
		 * param: list of all the pieces specified in vector
		 * return: list of all occupied squares. (color ambiguous)
		 */
		std::vector<std::vector<int>> getOccupiedSquares(std::vector<Pieces> alivePieces);
	private:
		int board_**;
}


#endif

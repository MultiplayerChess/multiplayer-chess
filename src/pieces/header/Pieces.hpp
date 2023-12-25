#include<stdio>
#include<cmath>
#include<cstdlib>
#include<string>
#include<regex>
#include<unordered_map>
#include<vector>
#ifndef PIECES_H
#define PIECES_H

class Pieces {

	public:
		/*
		 * param: to be overloaded
		 * output: default constructor for piece
		 * note: the default constructor will be overloaded later, so this could quite literally be blank
		 */
		Pieces();
		
		/*
		 * output: destructor
		 */
		~Pieces();


    // copy constructor
    Pieces(const Pieces& other);
		/*
		 * return: color of piece
		 */
		std::string getColor() const;

		/*
		 * param: color
		 * output: changes the color to specified color
		 */
		void setColor(const std::string& color);

		/*
		 * return: the position of the piece on the board
		 */
    std::vector<int> getPosition() const;
		
		/*
		 * param: position to be set to
		 * output: sets the position to that position if it's a valid move
		 */
		void setPosition(const std::vector<int> position);
		
		/*
		 * output: if piece is alive or not
		 * return: status of piece
		 */
		bool getStatus() const;
	
    /*
     * output: dest
     */

    /*
     * param: vector of all possible moves and where the player wants to move it
     * output: move the piece if the move is in the vector of moves
     */
    bool move(std::vector<Board board,std::vector<int>> possibleMoves, std::vector<int> desiredMove);

		/*
		 * param: status to set the piece
		 * output: sets the status to status specified in parameter
		 */
		void setStatus(const bool alive);


    /*
     * param: moves
     *
     */

		/*
		 * param: name of the piece
		 * output: sets the name to parameter
		 */
		void setName(const std::string& name);


		/*
		 * return: name of piece
		 */
		std::string getName() const;

	private:
    std::vector<int> position_(2);
		std::string color_:
		bool alive_;
		std::string name_;
}

#endif

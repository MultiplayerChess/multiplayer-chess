#include<stdio>
#include<stdlib>
#include<string>
#include<regex>
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
		 * return: color of piece
		 */
		std::string getColor() const;

		/*
		 * param: color
		 * output: changes the color to specified color
		 */
		void setColor(std::string color);

		/*
		 * return: the position of the piece on the board
		 */
		int[2] getPosition() const;
		
		/*
		 * param: position to be set to
		 * output: sets the position to that position if it's a valid move
		 */
		void setPosition(int[2] position);
		
		/*
		 * output: if piece is alive or not
		 * return: status of piece
		 */
		bool getStatus() const;
		
		
		/*
		 * param: status to set the piece
		 * output: sets the status to status specified in parameter
		 */
		void setStatus(bool alive);

	private:
		int[2] position_;
		std::string color_:
		bool alive_;
}

#endif

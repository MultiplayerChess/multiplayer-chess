#include<stdio>
#include<cstdlib>
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
		 * output: destructor
		 */
		~Pieces();

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
		int* getPosition() const;
		
		/*
		 * param: position to be set to
		 * output: sets the position to that position if it's a valid move
		 */
		void setPosition(const int* position[2]);
		
		/*
		 * output: if piece is alive or not
		 * return: status of piece
		 */
		bool getStatus() const;
		
		
		/*
		 * param: status to set the piece
		 * output: sets the status to status specified in parameter
		 */
		void setStatus(const bool alive);


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
		int* position_ = new int[2];
		std::string color_:
		bool alive_;
		std::string name_;
}

#endif

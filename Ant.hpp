/*********************************************************************************
 * AUTHOR: Zachary Chestler
 * Date: 9/28/2017
 * DESCRIPTION: This is the Specification file for the Ant class. It cointains the
 * 	function prototypes and the function descriptions. 
 * ******************************************************************************/


#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum AntOrientation { North, East, South, West };

class Ant
{

	private:
		int boardRows;
		int boardColumns;
		int antRow;
		int antColumn;
		int **board;
		AntOrientation antDir;
		/*****************************************************************
		 * NAME: changeSpaceState()
		 * DESCRIPTION: This function will change the state of the board
		 * 	of the space that the ant is on. It is intended to be used
		 * 	in the moveAnt() function. 
		 * **************************************************************/
		void changeSpaceState();
		
		/******************************************************************
		 * NAME: isFacingWall()
		 * DESCRIPTION: This function will determine if the ant is on and faceing
		 * 	a wall or edge of the board. It will be used in the moveAnt
		 * 	function to make sure the ant does not exit the board. This is
		 * 	intended to by usedin the turnAnt() function.
		 * ***************************************************************/
		
		bool isFacingWall();
		/******************************************************************
		 * NAME: turnAnt()
		 * DESCRIPTION: This function provides the logic for turning the ant. 
		 * 	on a white space the ant will turn clockwise, and on a black 
		 * 	space the ant will turn counterclockwise. After the inital turn
		 * 	the ant orientation is checked and if the ant is facing a wall
		 * 	its orientation is reversed. 
		 * ***************************************************************/
		void turnAnt();
	
	public:
		/********************************************************************v
		 * NAME: Ant()
		 * DESCRIPTION: This is the default constructor for the Ant class. 
		 * 	it will give defualt values for the member variables of the 
		 * 	Ant class if none are provided.
		 * ******************************************************************/
		Ant();
		/******************************************************************
		 * NAME: Ant(int inBoardRows, int inBoardColumns, int inAntRow, int inAntColumn, AntOrientation inAntDir)
		 * DESCRIPTION: This is the parameter accepting comstructor for the
		 * 	Ant class. The the data members of the class will be set to
		 * 	the arguments passed to the constructor. 
		 * PARAMETERS:
		 * 	
		 * ***************************************************************/

		Ant(int inBoardRows, int inBoardColumns, int inAntRow, int inAntColumn, AntOrientation inAntDir);
		/******************************************************************
		 * NAME: ~Ant()
		 * DESCRIPTION: This is the destructor for the Ant class. It will
		 * 	clean up the dynamically allocated board.
		 * ***************************************************************/
		~Ant();

		/******************************************************************
		 * NAME: moveAnt()
		 * DESCRIPTION: This function handles a single move of the ant. It 
		 * 	will turn the ant ot a valid direction, change the state of
		 * 	the space, then move the ant a single space forward. 
		 * ***************************************************************/
		void moveAnt();
		
		/********************************************************************
		 * NAME: printBoard()
		 * DESCRIPTION: This function prints the current state of the board. 
		 * 	a blank space will stay blank, a balck space will be a #, and
		 * 	the ant will be represented as a *.
		 * *****************************************************************/
		void printBoard();

		/********************************
		 * Test function: used to print status of ant.
		 * ******************************/
		void testPrintStatus();
			

};

#endif //ANT_HPP

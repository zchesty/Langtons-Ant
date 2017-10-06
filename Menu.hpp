/**********************************************************************************
 * AUTHOR: Zachary Chestler
 * DATE: 9/30/2017
 * DESCRIPTION: This is the header file for the Menu class. It contains the class
 * 	 definition, function prototypes, and function descriptions.
 * DEPENDENCIES:
 * 	inValHelpers
 * HISTORY:
 * 	9/30/2017 - created
 * ********************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "inValHelpers.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::setw;

class Menu
{
	private:
		string title;
		vector<string> menuChoices;
		int numChoices;		
	public:
		/**************************************************************
		 * NAME: Menu()
		 * DESCRIPTION: default constructor for the Menu class.
		 * ***********************************************************/
		Menu();

		/***************************************************************
		 * NAME: Menu(string inTitle) 
		 * DESCRIPTION: constructor for the Menu class. will accept the 
		 * 	title of your menu as a string paramenter
		 * PARAMETERS:
		 * 	inTitle - the title of your menu.
		 * ************************************************************/
		Menu(string inTitle);

		/**************************************************************
		 * NAME: addMenuChoice(string inMenuChoice)
		 * DESCRIPTION: this function will add a menu choice to the 
		 * 	menuChoices vector. 
		 * Parameters:
		 * 	inMenuChoice - a string input for a menu choice.
		 * ***********************************************************/
		void addMenuChoice(string inMenuChoice);

		/**************************************************************
		 * NAME: getUserchoice()
		 * DESCRIPTION: This function will get a choice from the user and 
		 * 	validate that it is in fact a menu choice and return the choice 
		 * 	to be used by the calling function.
		 * RETURNS: an integer value that is a menu choice
		 * ***********************************************************/
		int getUserChoice();

		/**************************************************************
		 * NAME: displayMenu()
		 * DESCRIPTION: this function will display the menu on the
		 * 	 command line interface.
		 * ***********************************************************/
		void displayMenu();
};


#endif //MENU_HPP

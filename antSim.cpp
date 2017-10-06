/**************************************************************************
 * AUTHOR: Zachary Chestler
 * DATE: 9/30/2017
 * DESCRIPTION: main program file for Langton's Ant simulation.
 * ***********************************************************************/
#include "Ant.hpp"
#include "Menu.hpp"
#include "inValHelpers.hpp"
#include <ctime> 
#include <cstdlib> 

void simulation();
int getRandStart(int max);

int main()
{
	Menu startMenu("Langton's Ant Simulation");
	startMenu.addMenuChoice("Start Langton's Ant simulation");
	startMenu.addMenuChoice("Quit");
	startMenu.displayMenu();
	int choice = startMenu.getUserChoice();
	
	if (choice == 1)
	{
		simulation();
		Menu continueMenu ("Would you like to continue?");
		continueMenu.addMenuChoice("Play again.");
		continueMenu.addMenuChoice("Quit");
		while (choice == 1)
		{
			continueMenu.displayMenu();
			choice = continueMenu.getUserChoice();
			if (choice == 1)
			{
				simulation();
			}
		}	

	}
	
	return 0;

}


/*******************************************************************
 * NAME: simulation()
 * DESCRIPTION: runs one ant simulation.
 * *****************************************************************/
void simulation()
{
	//gather simulation information
	cout << "Enter the number of rows for the board: ";
	int boardRows = posIntVal();
	cout << "Enter the number of columns for the board: ";
	int boardColumns = posIntVal();
	
	Menu randomStart("Choose how the starting location of the Ant is determined");
	randomStart.addMenuChoice("I want to choose");
	randomStart.addMenuChoice("Choose a random starting location");
	randomStart.displayMenu();

	int random = randomStart.getUserChoice();
	int startAntRow;
	int startAntColumn;
	
	if (random == 1)
	{
		unsigned seed;
		seed = time(0);
		srand(seed);


		cout << "Enter the row the Ant will start in: ";
		startAntRow = posIntVal(boardRows);
		cout << "Enter the column the Ant will start in: ";
		startAntColumn = posIntVal(boardColumns);
	}
	else
	{
		startAntRow = getRandStart(boardRows);
		startAntColumn = getRandStart(boardColumns);
	}
	
	
	Menu antDirection("Choose the starting direction of the Ant");
	antDirection.addMenuChoice("North");
	antDirection.addMenuChoice("East");
	antDirection.addMenuChoice("South");
	antDirection.addMenuChoice("West");
	antDirection.displayMenu();
	int antStartDirection = antDirection.getUserChoice() - 1; //the directional enum starts at 1
	cout << "How many steps would you like the Ant to take? ";
	int steps = posIntVal();

	Ant theAnt(boardRows, boardColumns, startAntRow, startAntColumn, static_cast<AntOrientation>(antStartDirection));
	
	for (int i = 0; i < steps; i++)
	{
		theAnt.printBoard();
		theAnt.moveAnt();
	}	
	cout << "The Ant moved " << steps << " steps." << endl << endl;
}
/**********************************************************************
 * NAME: getRandStart(int max)
 * DESCRIPTION: This function will return a random integer for use
 * 	as the starting row or colum nof the Ant. 
 * ********************************************************************/
int getRandStart(int max)
{
	//unsigned seed;

	//seed = time(0);
	//srand(seed);

	return rand() % max + 1;	
}

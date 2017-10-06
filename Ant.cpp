/********************************************************************
 *Author: Zachary Chestler
 *Date: 9/28/2017
 *Description: This is the implementation file for the Ant Class. See 
 	Ant.hpp for function descriptions. 
 * ******************************************************************/

#include "Ant.hpp"

Ant::Ant()
{
	boardRows = 20;
	boardColumns = 20;
	antRow = 9;		// the 9 subscript is the 10th row in the board.  
	antColumn = 9;
	antDir = South;
	board = new int*[boardRows];
	for (int i = 0; i < boardRows; i++)
	{
		board[i] = new int[boardColumns];
	}
	//initialize the values in the board to be 0 (blank)
	for (int i = 0; i < boardRows; i++)
	{
		for (int j = 0; j < boardColumns; j++)
		{
			board[i][j] = 0;
		}
	} 
}


Ant::Ant(int inBoardRows, int inBoardColumns, int inAntRow, int inAntColumn, AntOrientation inAntDir)
{
	boardRows = inBoardRows;
	boardColumns = inBoardColumns;
	antRow = inAntRow - 1;		//subracting 1 since the board rows start at zero. 
	antColumn = inAntColumn - 1;	//the n - 1 row is the row that is specified by the input
	antDir = inAntDir;bool isFacingWall();
	board = new int*[boardRows];
	for (int i = 0; i < boardRows; i++)
	{
		board[i] = new int[boardColumns];
	}
	//intialize the values in the board to be 0 (blank)
	for (int i = 0; i < boardRows; i++)
	{
		for (int j = 0; j < boardColumns; j++)
		{
			board[i][j] = 0;
		}
	}
}


Ant::~Ant()
{
	for (int i = 0; i < boardRows; i++)
	{
		delete [] board[i];
	}
	delete [] board;
	board = nullptr;
}


void Ant::printBoard()
{
	//print the top border with dashes, boardColumns + 2
	for (int i = 0; i < (boardColumns + 2); i++)
	{
		cout << "-";
	}
	cout << endl;

	//print board with borders
	for (int i = 0; i < boardRows; i++)
	{
		cout << "|";
		for (int j = 0; j < boardColumns; j++)
		{
			char space = 32; //empty space character
			if (i == antRow && j == antColumn)
			{
				space = '*';
			}
			else if (board[i][j] == 1)
			{
				space = '#';
			}
			cout << space;
		}
		cout << "|" << endl;
	}
	//print the bottom border with dashes, boardColumns + 2
	for (int i = 0; i < (boardColumns + 2); i++)
	{
		cout << "-";
	}
	cout << endl;
}


void Ant::changeSpaceState()
{
	if (board[antRow][antColumn] == 0)
	{
		board[antRow][antColumn] = 1;
	}
	else
	{
		board[antRow][antColumn] = 0;
	}
}


bool Ant::isFacingWall()
{
	int maxAntRow = boardRows - 1;
	int maxAntCol = boardColumns - 1;

	if (antRow == 0 && antDir == North)
	{
		return true;
	}
	else if (antRow == maxAntRow && antDir == South)
	{
		return true;
	}
	else if (antColumn == 0 && antDir == West)
	{
		return true;
	}
	else if (antColumn == maxAntCol && antDir == East)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Ant::turnAnt()
{
	int antDirInt = antDir;
	
	if (board[antRow][antColumn] == 0) //if the space the ant is on is white
	{
		antDirInt = (antDirInt + 1) % 4;
		antDir = static_cast<AntOrientation>(antDirInt);
	}
	else 	//if the space the ant is on is black
	{
		antDirInt = (antDirInt + 3) % 4;
		antDir = static_cast<AntOrientation>(antDirInt);
	}

	if (isFacingWall()) //if the Ant is facing a wall, reverse its orientation. 
	{
		antDirInt = (antDirInt + 2)  % 4;
		antDir = static_cast<AntOrientation>(antDirInt);
	}
	
}
void Ant::moveAnt()
{
	turnAnt();
	changeSpaceState();
	if (antDir == North)
	{
		antRow--;
	}
	else if (antDir == East)
	{
		antColumn++;
	}
	else if (antDir == South)
	{
		antRow++;
	}
	else //antDir == West
	{
		antColumn--;		
	}
}
	
		


void Ant::testPrintStatus()
{
	
	cout << "____________" << endl << "**ANT STATUS**" << endl << "__________" << endl;
	cout << "Board Rows: " << boardRows << endl;
	cout << "Board Columns: " << boardColumns << endl;
	cout << "Ant row: " << antRow + 1 << endl;
	cout << "Ant Column: " << antColumn + 1 << endl;
	cout << "Ant Direction: " << antDir << endl;
	cout << "Space Status: " << board[antRow][antColumn] << endl;
}

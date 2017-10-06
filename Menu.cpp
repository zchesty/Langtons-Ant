/*******************************************************************************
 * AUTHOR: Zachary Chestler
 * DATE: 9/30/2017
 * DESCRIPTION: This is the implementation file for the Menu class. See Menu.hpp
 * 	for specification details and function descriptions.
 * ****************************************************************************/


#include "Menu.hpp"

Menu::Menu()
{
	title = "Menu";
	numChoices = 0;
}


Menu::Menu(string inTitle)
{
	title = inTitle;
	numChoices = 0;	
}

void Menu::addMenuChoice(string inMenuChoice)
{
	menuChoices.push_back(inMenuChoice);
	numChoices++;
}

int Menu::getUserChoice()
{
	cout << "Choose a menu option: ";
	
	int choice =integerValidation();

	while (choice < 1 || choice > numChoices)
	{
		cout << "Enter a menu choice 1-" << numChoices << "." << endl;
		choice = integerValidation();
	}
	return choice;
}

void Menu::displayMenu()
{
	cout << title << endl;
	for (int i = 0; i < numChoices; i++)
	{
		cout << setw(3) << i + 1 << ". " << menuChoices[i] << endl;
	}
	cout << endl;
}


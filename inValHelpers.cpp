/************************************************************
 * AUTHOR: Zachary Chestler
 * DESCRIPTION: This is the implementation file for input validation
 * 	functions. See inValHelpers.hpp for specification details.  
 * *********************************************************/

#include "inValHelpers.hpp"

int integerValidation()
{
	string str;
	int integer;
	getline(cin, str);
		

	integer = atoi(str.c_str());

	while (!atoi(str.c_str()) || containsSymbol(str) || containsSpace(str)) //atoi() returns 0 if the str cannot be converted, or if the string was "0" so wee need to ask for int again. 
	{
		if (str.compare("0") == 0) // check to see if the user actually wanted to enter a 0 for there int.
		{
			return 0; 
		}
		cout << "Please enter an integer." << endl;
		getline(cin, str);
		integer = atoi(str.c_str());

	}
	
	return integer;

}

int posIntVal(int max)
{
	string str;
	int integer;
	getline(cin, str);
	integer = atoi(str.c_str());
	
	if (max == 0) // defualt parameter for max is 0, this checks that the integet is greater than 0. 
	{	

		while (!atoi(str.c_str()) || containsSymbol(str) || containsSpace(str) || integer < 1) 
		{
			cout << "Please enter a positive integer." << endl;
			getline(cin, str);
			integer = atoi(str.c_str());

		}
	
	return integer;
	}

	else // check if integer is greater than 0 and less than or equal to the max. 
	{
		while (!atoi(str.c_str()) || containsSymbol(str) || containsSpace(str) || integer < 1 || integer > max) 
		{
			cout << "Please enter a positive integer between 0 and " << max + 1 << "." << endl;
			getline(cin, str);
			integer = atoi(str.c_str());
		}
	return integer;
	}
}
bool containsSymbol(string inStr)
{
	int strLen = inStr.length();

	if (inStr.c_str()[0] == '-')
	{
		for (int i = 1; i < strLen; i++)
		{
			if (ispunct(inStr.c_str()[i]))
			return true;
		}
	}
	else 
	{
		for (int i = 0; i < strLen; i++)
			{
				if (ispunct(inStr.c_str()[i]))
				return true;
			}

	}

	return false;
}

bool containsSpace(string inStr)
{
	int strLen = inStr.length();

	for (int i = 0; i < strLen; i++)
	{
		if (isspace(inStr.c_str()[i]))
			return true;
	}
	return false;
}


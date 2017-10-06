/***********************************************************
 * AUTHOR: Zachary Chestler
 * DESCRIPTION: Include this header file for input validation needs.
 * HISTORY:
 * 	9/30/2017 - added intValidation, containsSymbol,
 * 		containsSpace, posIntVal,
 * ********************************************************/
#ifndef INVALHELPERS_HPP
#define INVALHELPERS_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::string;


/***********************************************************
 * NAME: integerValidation()
 * DESCRIPTION: This function will get input from the user
 * 	then validate that the input is an integer.
 * PARAMETERS: NONE
 * RETURNS: validated integer
 * HISTORY:
 * 	9/30/2017 - created
 * *********************************************************/
int integerValidation();

/***********************************************************
 * NAME: containsSymbol(string str);
 * Description: determines if a string has any symbols in it.
 * 	Intended for use in input validation fuctions.
 * PARAMETERS:
 * 	str - a string to be checked
 * RETURNS:
 * 	true - if the input string has symbol.
 * 	false - if the input string has no symbols.
 * HISTORY: 
 * 	9/30/2017 - created
 * ***********************************************************/
bool containsSymbol(string inStr);

/***************************************************************
 *  NAME: containsSpace(string str)
 *  DESCRIPTION: determines if a string has any spaces in it. 
 *  	Intended for use in input validation functions.
 *  PARAMETERS:
 *  	str - a string to be checked
 *  RETURNS:
 *  	true - if the input string has a space.
 *  	false - if the input string has no spaces.
 *  HISTORY:
 *  9/30/2017 - created
 *  ***********************************************************/
bool containsSpace(string inStr);

/**************************************************************
 * NAME: posIntVal(int max)
 * DESCRIPTION: This function is used to get a positive integer
 * 	from the user. It also has a parameter to specify 
 * 	an upper limit to not accept values above.
 * PARAMETERS: 
 * 	max - a maximum int value to be accepted. if no value is
 * 		passed as the max, any int above zero will be
 * 		accepted. Integers less than and equal to the max
 * 		will be accepted.
 * RETURNS: a validated positive integer.
 * *************************************************************/ 
int posIntVal(int max = 0);

#endif //INVALHELPERS_HPP

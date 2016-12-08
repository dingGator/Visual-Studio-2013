//Kim Lien Chu	
//COP2000.0M1
/**************************************************
Character Converter Program
//	1.  Has CharConverter Class
	2.	Prompt user to input a string
	3.  Call properWords function 
	4.  display the output of properWords
	5.  Call uppercase function
	6.  display the output of uppercase
	7.  loop to allow additional strings conversion 
		
*********************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

/****************************************************
       CharConverter Class
a.	has upperCase member function
	1.  accept string : inputStr
	2.  convert all lowercase characters in string
		a.to uppercase : upCaseStr
	3.  if not letter or uppercase
		a.then left alone
	4.  return converted string : upCaseStr

b.  Has properWords member function
	1.  accept string:  inputPhrase
	2.  convert first letter of each word to uppercase
	3.  return convert phrase:  upCasePhrase

************************************************************/
class CharConverter
{
private:
	string upCaseString;
	string properString;
public:
	CharConverter();
//     upperCase member function
	string uppercase(string);
//     properWords member function
	string properWords(string);
};


CharConverter::CharConverter()   //constructor
{
	string inputStr;
}
/*********************************************************
uppercase(string inputStr)*** member methods**************

1.  accept string : inputStr
2.  convert all lowercase characters in string
a.	to uppercase : upCaseStr
3.  if not letter or uppercase
a.	then left alone
4.  return converted string : upCaseStr
*************************************************/

string CharConverter::uppercase(string inputStr)
{	
	upCaseString = inputStr;
	for (int charIdx = 0; charIdx <= upCaseString.length(); charIdx++)
	{
		if (isalpha(upCaseString[charIdx]))   //test for letter
		{
			if (islower(upCaseString[charIdx]))   //test for lowercase
			{
				//convert lowercase characters in string
				upCaseString[charIdx] = toupper(upCaseString[charIdx]);  //convert to upperase
			}
		}
	}
	// return the upper case string 
	return upCaseString;
}
/****************************************		
properWords *********member method
1.  accept string : inputPhrase
2.  convert first letter of each word to uppercase
3.  return convert phrase : upCasePhrase
***********************************************/
string CharConverter::properWords(string inputPhrase)
{
	properString = inputPhrase;
	bool found = false;
	properString[0] = toupper(properString[0]);
	for (int charIdx = 1; charIdx <= properString.length(); charIdx++)
	{
		
		if (isspace(properString[charIdx]))
		{
			found = true;
		//	charIdx = charIdx + 1;
		}
		else
		{
			if (found == true)
				//cout << "\n\n \t\t   index charIdx :  " << charIdx;
			{
				if (isalpha(properString[charIdx]))
				{
					if (islower(properString[charIdx]))   //test for lowercase
					{
						properString[charIdx] = toupper(properString[charIdx]);  //convert to upperase
						
					}
				}
				found = false;
			}
				
		}
	}
	return properString;
}

/******************
prototypes
******************/
void validateChoice(char&);
void validateString(string&);
string getInputPhrase();
/*******************************************
	main
		1.  Prompt user to input a string
		2.  Call properWords function
		3.  display the output of properWords
		4.  Call uppercase function
		5.  display the output of uppercase
		6.  loop to allow additional strings conversion
******************************************************/
int main()
{
	string inputStr;
	string properPhrase;
	string upCaseStr;
	char yOrN ='y';
	//	Prompt user to input a string
	cout << "\n\n                 Welcome to the Phrase Converter \n";

	while (yOrN == 'y')
	{
		inputStr = getInputPhrase();
	
		if (cin)
		{
			//instantiating of class: CharConverter
			CharConverter convertStr;    
			//  Call properWords function
			properPhrase = convertStr.properWords(inputStr);
			//  display the output of properWords
			cout << "\n\n     Your phrase converted to proper phrase is:  \n\n"
				<< "\t\t  " << properPhrase << "  \n\n ";
			//  Call uppercase function
			upCaseStr = convertStr.uppercase(inputStr);
			//  display the output of uppercase
			cout << "\n\n     Your phrase converted to uppercase is:  \n\n"
				<<"\t\t   "<< upCaseStr << "  \n\n";
		}
		/**************************
		  loop to prompt for more strings to convert
                1. clear buffer
				2.  prompt user for choice y or n
				3.  validate choice
		**************************/
		cin.sync();
		cin.clear();
		cout << "\n\n    Would you like to convert another phrase? (Enter y or n)  ";
		cin >> yOrN;
		validateChoice(yOrN);
	}
	
	return 0;
}
/***********************************
getInputPhrase()  ******function****
 Prompt user to input a string
 validate input
 return input

********************************/
string getInputPhrase()
{
	string inputPhrase;
	cin.sync();
	cin.clear();
	// prompt for input
	cout << "\n\n      Enter a phrase:  \n\n \t\t";
	getline(cin, inputPhrase);
	// validate input
	validateString(inputPhrase);
	// return input
	return inputPhrase;
}

/***************************
validateString   ******* function
             bring in string character as reference
   clear buffer
   prompt for input
   in this function the input is sent back as reference
****************************/
void validateString(string& inputString)
{
	if (!cin)
	{
		cin.sync();  //clear buffer
		cin.clear();
		//  prompt for input
		cout << "\n\n       Invalid input:  (Enter a phrase )";
		cin >> inputString;
	}
}
/***************************
validateChoice   ******* function
bring in choice character  y or n as reference
clear buffer
prompt for input
in this function the input is sent back as reference
**
***************************/

void validateChoice(char& a)
{
	if (!cin)
	{
		//clear the buffer
		cin.sync();
		cin.clear();
		//prompt and collect good input
		cout << "\n\n       Invalid input:  (Enter y or n )";
		cin >> a;
	}
}
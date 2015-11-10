//Kim Lien Chu	
//COP2000.0M1
/* Character Converter Program
//	1.  Has CharConverter Class
		a. has upperCase member function
			1.  accept string:  inputStr
			2.  convert all lowercase characters in string
				a. to uppercase:  upCaseStr 
			3.  if not letter or uppercase 
				a. then left alone
			4.  return converted string:  upCaseStr
		b.  Has properWord member function
			1.  accept string:  inputPhrase
			2.  convert first letter of each word to uppercase
			3.  return convert phrase:  upCasePhrase
	2.	Prompt user to input a string
	3.  Call properWords function 
	4.  display the output of properWords
	5.  Call uppercase function
	6.  display the output of uppercase
	7.  loop to allow additional strings 
		a.  to be converted 
		b.  displayed converted strings
		c.  until user chooses to quit

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

/*     CharConverter Class
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

*/


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


/********************************************************* 
uppercase(string inputStr)*** member function**************

1.  accept string : inputStr
2.  convert all lowercase characters in string
a.	to uppercase : upCaseStr
3.  if not letter or uppercase
a.	then left alone
4.  return converted string : upCaseStr
*************************************************/
CharConverter::CharConverter()
{
	string inputStr;
}
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
properWords member function
1.  accept string : inputPhrase
2.  convert first letter of each word to uppercase
3.  return convert phrase : upCasePhrase
***********************************************/
string CharConverter::properWords(string inputPhrase)
{
	properString = inputPhrase;
	for (int charIdx = 0; charIdx <= properString.length(); charIdx++)
	{

		if (isspace(properString[charIdx]) || charIdx == 0)
		{
			if (isspace(properString[charIdx]))
			{
				charIdx = charIdx + 1;
			}		
			if (isalpha(properString[charIdx]))   //test for letter
			{
				if (islower(properString[charIdx]))   //test for lowercase
				{
					properString[charIdx] = toupper(properString[charIdx]);  //convert to upperase
				}
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
/*******************************************
	main
		1.  Prompt user to input a string
		2.  Call properWords function
		3.  display the output of properWords
		4.  Call uppercase function
		5.  display the output of uppercase
		6.  loop to allow additional strings
				a.  to be converted
				b.  displayed converted strings
				c.  until user chooses to quit
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
		cin.sync();
		cin.clear();
		cout << "\n\n      Enter a phrase:  \n\n";
		getline(cin, inputStr);
		validateString(inputStr);
		if (cin)

		{
			CharConverter convertStr;
			//  Call properWords function
			properPhrase = convertStr.properWords(inputStr);
			//  display the output of properWords
			cout << "\n\n     Your phrase converted to proper phrase is:  \n\n"
				<< properPhrase << "  \n\n ";
			//  Call uppercase function
			upCaseStr = convertStr.uppercase(inputStr);
			//  display the output of uppercase
			cout << "\n\n     Your phrase converted to uppercase is:  \n\n"
				<< upCaseStr << "  \n\n";
		}

		//  loop to convert more strings
		cin.sync();
		cin.clear();
		cout << "\n\n    Would you like to convert another phrase? (Enter y or n)  ";
		cin >> yOrN;
		validateChoice(yOrN);
	}
	//		to be converted
		//		displayed converted strings
		//		until user chooses to quit

	return 0;
}
void validateChoice(char& a)
{
	if (!cin)
	{
		cin.sync();
		cin.clear();
		cout << "\n\n       Invalid input:  (Enter y or n )";
		cin >> a;
	}

}
void validateString(string& inputString)
{
	if (!cin)
	{
		cin.sync();
		cin.clear();
		cout << "\n\n       Invalid input:  (Enter a phrase )";
		cin >> inputString;
	}
}

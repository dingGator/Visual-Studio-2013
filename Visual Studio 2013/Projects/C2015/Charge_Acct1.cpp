//Kim Lien Chu	
/*  Charge Account Validation 
the program:
	Checks a user input of a charge account number 
		with list
		101		102		103		104		105		106		
		107		108		109		110		111		112
		113		114		115		116		117		118
	Uses a simple linear search to locate the number 
		entered by the user.
	If the user enters a number that is in the array, 
		the program should display a message 
		saying the number is valid.
	If the user enters a number not in the array, 
		the program should display a message 
		indicating it is invalid.
	7.  Uses a class with appropriate data variables and methods
	8.  The array that holds the charge account numbers is a private data variable.
******************************************************/
#include <iostream>
using namespace std;
/************************************************
***********class ChargeAcct***********
	private variables:
		SIZE				...is size of the array of charge account numbers
		chargeAcctNum[SIZE]	...is the array of charge account numbers
		validAcct 			...is the flag whether the account number is in the array
	public methods:
		ChargeAcct();			constructor ..initialize array
		population(int[]);		populate the array with the hard coded array from main	
		compare(int);			compare the userinput with the array	
		getValidAcct();			return valid account flag 
 *********/
class ChargeAcct
{
private:
//  The array that holds the charge account numbers is a private data variable.
	static const int SIZE = 18;
	int chargeAcctNum[SIZE];
	
	bool validAcct;
	
public:
	//TODO
	ChargeAcct();  //constructor 
	void population(int[]);
	//compare to see if it's a valid account number
	void compare(int);
	bool getValidAcct();
};
/********************************
	ChargeAcct *****constructor 
		initialize account number array
************************************/
ChargeAcct::ChargeAcct()
{
	chargeAcctNum[18];  //constructor initialize Account number array
};
/********************************
// ChargeAcct::population   *** method
		populate account number array
			with hardcode values from main from list[]
************************************/

void ChargeAcct::population(int list[])
{
	for (int i = 0; i < SIZE; i++)
	{
		chargeAcctNum[i] = list[i];
	};
};
/********************************
	ChargeAcct::compare(int input)*****method
		initialize the flag validAcct to false
		compare to see if the user input is a valid account number
		set flag validAcct if it is
************************************/

void ChargeAcct::compare(int input)
{
	int i = 0;
	validAcct = false;
	//search thru the array to see if its a winning
	while (i < SIZE && !validAcct)
	{
		if (input == chargeAcctNum[i])
		{
			validAcct = true;
		}
		i = i + 1;
	}
};
/************************
getValidAcct    ***********method*****
return validAcct flag
**************************/
bool ChargeAcct::getValidAcct()
{
	return validAcct;
};
/**************************
//prototypes
*****/
void getInput(int&);
void validate(int&);
void display(ChargeAcct);
/******************************
	main *************function*****
		Initialize a one - dimensional array with these values.
		get user input
		populate an array in class with values 
		validate user input
		compare the user input with 
			the account numbers in the array

	********************************/

int main()
{
	/****************
	  Initialize a one - dimensional array:  chargeAcctList 
	  with these values.

		101		102		103		104		105		106
		107		108		109		110		111		112
		113		114		115		116		117		118

	******************/
	int chargeAcctList[18] =  { 101, 102, 103, 104, 105, 106,
								107, 108, 109, 110, 111, 112,
								113, 114, 115, 116, 117, 118 };

	int userNum;
	ChargeAcct charAcctObj;   //instantiate class ChargeAcct
	//prompt the user for an account number  
	getInput(userNum);
	//populate the private array
	charAcctObj.population(chargeAcctList);
	//compare account number to list
	charAcctObj.compare(userNum);
	//display charAcctObj
	display(charAcctObj);
	return 0;
};
/************************************************
*******getInput(int& n)****** function
	1.  lets user input  a charge account number
	2.  validate the user input
	3.  reference return the user input
*************************************************/
void getInput(int& n)
{// prompt the user for account number
	cout << "\n \t Enter a Charge Account number:  ";
	cout << "\n \t Account number between 100 and 1000:  ";
	cin >> n;
	validate(n);

}
/*********************************
validate **********function  *********
	validate user input to see 
		if user enter a valid account number
*********************************/
void validate(int& n)
{
	while (!cin || n < 100 || n>1000)
	{
		cout << "\n\t This is not a valid Account number. ";
		cout << "\n\t Account number should be between 100 and 1000. ";
		cin.sync();
		cin.clear();
		cin >> n;
	}
};
/***************************
display*********** function   **************
	if the account is on the account list
		then it is a valid charge account
		if not then it is not a valid charge account
********************************/

void display(ChargeAcct acctObj)
{
	if (acctObj.getValidAcct())
		cout << "\n\t This is a Valid Charge Account Number." << endl;
	else
		cout << "\n\t This Charge Account Number is Invalid." << endl;
};
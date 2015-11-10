//Kim Lien Chu	
//COP2000.0M1
//Array introduction
#include <iostream>
#include <string>
using namespace std;

class Upper
{
private:
	string userInput;
	int count;
public: 
	//TODO
	//prompt user
	//validate
	//count the upperccase chara
	//display output

	Upper();

	void setInput();
	void validate();
	void process();
	void display();
	~Upper();
}
//array:  one dataype type
//data structures
Upper::Upper()
{
	count = 0;
}
void Upper::setInput()
{
	cin.sync;
	cout << "Enter a phrase, press Enter when done: ";
	getline(cin, userInput);
}
void Upper::validate()
{
	//be sure the user type in something
	while (userInput.length() == 0)
	{
		cout << "PLease enter a phrase: ";
		cin.sync();
		getline(cin, userInput);
	}
}
//process the string
void Upper::process()
{
	//Now Is the time for all good men
	for (int i = 0; i < userInput.length(); i++)
	{
		//if (userInput[i] >'A'&& userInput[i] <= 'Z')
		if (isupper(userInput[i] == true))
			count++;
	}
}
void Upper::display();
{
	cout << " the number of uppercase character is :"
}
Upper::Upper()
{
	cout << "In the destructor" << endl;
}
int main()
{
	Upper upperclass;
	upperclass.setInput();
	upperclass.process();
	upperclass.display();
	return 0;
}

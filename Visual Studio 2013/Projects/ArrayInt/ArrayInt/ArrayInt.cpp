//Kim Lien Chu	
//COP2000.0M1
//Array introduction
#include <iostream>
using namespace std;

//one dataype type
//data structures

int main()
{
	//variables
	//13 shoes size
	// initialize with {0} then initialize all members to 0
	// when {8,0}  then initialize first to 8 and the rest to 0
	float shoeSize[5] = { 0 };     // continuous spaces  52
	float sum = 0;
	float avg = 0;
	
	// prompt
	for (int i = 0; i < 5; i++)
	{
		cout << " Enter a shoe size:";
		cin >> shoeSize[i];
		sum += shoeSize[i];

	}

	//shoeSize[0] =8;
	//shoeSize[1] =13.5;
	//shoeSize[2] = 11;
	//shoeSize[3] =12;
	//shoeSize[4] = 17;
	
	//calculate average
	avg = sum / 5;

	//display
	cout << endl << endl;
	cout << " The average shoe size is:  "<< avg<<endl;

	return 0;

}

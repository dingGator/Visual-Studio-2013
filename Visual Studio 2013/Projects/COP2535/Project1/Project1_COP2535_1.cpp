//Kim Lien Chu
//COP2535.0M1
/*************************************************
 This program display a histogram of a survey of
20 students' rating of the food in the student food court
with 1 being "awful" and 10 being "excellent".
The responses are stored in the survey.txt file.
**************************************************/

#include <iostream>
#include <fstream>    // bring in survey.txt file
#include <string>
#include <iomanip>
#include <vector>

using namespace std;
/********************************************
		class HistoDisplay
	Read in these responses into an array
	and determine the frequency of each rating.
	Display the frequencies as a histogram

**************************************/
class HistoDisplay
{
private:
	int dataFile_size = 20;
	int surveyData[20];	// array to hold responses
	int rating_size = 10;
	int rateFrq[10];	// array to frequency of responses
public:
	
	//prototype
	void loadSurvey();  //load responses to a vector
	void showRating();		// display histogram

};
/***************************************
		HistoDisplay::loadSurvey
	this will load data from the survey.txt file
	into array surveyData which has 20 elements
****************************************/
void HistoDisplay::loadSurvey()
{
	// bring in survey.txt file
	ifstream inputFile;
	int count = 0;
	inputFile.open("survey.txt");
	if (inputFile)
	{
		// reading data from file
	
		while (inputFile >> surveyData[count])
		{
			count++;
		}
		// close file
		inputFile.close();
	}
	else
	{     // error in open of file
		cout << "Error opening the file";
	}


}
/***************************************
		HistoDisplay::showRating
	this will get the frequence of each rating from the surveyData array 
	and the running total is stored into RateFrq array 
	***************************************/

void HistoDisplay::showRating()
{	
	/*
	The RateFrq has 11 elements 
	because running total is stored in the element 
	that corresponds with the of the rating number
	so if a rating of 5 is given 
	then a point is added the RateFrq[5]
	Since rating starts with 1 thru 10 
	so there is no frequency stored in index 0
	Then a histogram is made of the frequency of the responses
*	*/
	//initialize rateFrq array
	//because a running total has to start with 0
	int rateFrq[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int accum = 0;
	for (int index = 0; index < 20; index++)
	{
		int rating = 0;
		rating = surveyData[index];
		// this is a running total
		accum = rateFrq[rating] + 1;
		// this total is load back into the RateFrq array
		rateFrq[rating] = accum;
				
	}
	// histogram showing the frequency of the responses
	cout << endl;
	cout << endl;
	cout << left << setw(15) << "Rating";
	cout << right<< "Frequency"<< endl;
	cout << endl;
	
	for (int rateCount = 1; rateCount < 11; rateCount++)
	{
		cout << left << setw(15) << rateCount;
		cout << right;
		for (int freq = 0; freq < rateFrq[rateCount]; freq++)
			cout << "*";
		cout << endl;

	}


};
/******************************************
this program calls class HistoDisplay 
		to load the survey results from the 
		survey.txt file 
		then display a histogram 
		of the frequency of the rating 
****************************************/

int main()
{

	// bring in and load survey.txt file into vector 

	HistoDisplay surveyGram;
	surveyGram.loadSurvey();  //load rating from file
	surveyGram.showRating();	// display histogram

	return 0;

}



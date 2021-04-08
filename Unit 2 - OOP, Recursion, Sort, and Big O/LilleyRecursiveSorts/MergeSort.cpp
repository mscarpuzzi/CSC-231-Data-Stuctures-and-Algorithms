// MergeSort.cpp : Defines the entry point for the console application.
// This application uses vectors to implement a merge sort algorighm.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <conio.h>			// Used for the getch() function to pause the operation of the program.
#include <cstdlib>			// Used for random number generation.
#include <time.h>			// This is used to seed the random number generator.



using namespace std;

// Press any key to continue.
void PressAnyKey()
{
	cout << "Press any key to continue..." << endl;
	_getch();
}

// FillVectorWithRandomNumbers --> This function prompts the user for the number of random numbers to 
// fill in a vector. It checks to make sure that the number entered does not exceed the maximum and is positive.
// It returns true if successful and false if not.

bool FillVectorWithRandomNumbers(vector<int> & vRandomIntegers, int i_MAX_VECTOR_SIZE)
{
	bool bSuccess = false;
	int iVectorSize = 0;
	int iLoopCount = 0;
	cout << "How many numbers would you like to fill the vector (the maximum is " << i_MAX_VECTOR_SIZE << ")? ";
	cin >> iVectorSize;
	if (iVectorSize >= 0 && iVectorSize <= i_MAX_VECTOR_SIZE)
	{
		srand((unsigned)time(NULL));			// Seed the random number generator.
		for (iLoopCount = 0; iLoopCount < iVectorSize; iLoopCount++)
		{
			vRandomIntegers.push_back(rand() % 100 + 1);		//Random number modulus 100 will result in 0 - 99 so add 1.
		}
		bSuccess = true;
	}
	return bSuccess;
}

// DisplayVectorValues --> This procedure displays the contents of the vector parameter to the console.
void DisplayVectorValues(vector<int>  & vRandomIntegers)
{
	int iLoopCount = 0;
	int iVectorLength = vRandomIntegers.size();
	cout << "The current values in the vector are: " << endl;
	for (iLoopCount = 0; iLoopCount < iVectorLength; iLoopCount++)
	{
		cout << vRandomIntegers[iLoopCount] << endl;
	}
}

void MergeVectors(vector<int> & vRandomIntegers, vector<int> & vLeftSide, vector<int> & vRightSide)
{
	int iLeftSideSize = vLeftSide.size();
	int iRightSideSize = vRightSide.size();
	int iLeftLoopCount = 0;
	int iRightLoopCount = 0;

	while (iLeftLoopCount < iLeftSideSize && iRightLoopCount < iRightSideSize)
	{
		if (vLeftSide[iLeftLoopCount] < vRightSide[iRightLoopCount])
		{
			vRandomIntegers.push_back(vLeftSide[iLeftLoopCount]);
			iLeftLoopCount++;
		}
		else
		{
			vRandomIntegers.push_back(vRightSide[iRightLoopCount]);
			iRightLoopCount++;
		}
	}

	while (iLeftLoopCount < iLeftSideSize)
	{
		vRandomIntegers.push_back(vLeftSide[iLeftLoopCount]);
		iLeftLoopCount++;
	}

	while (iRightLoopCount < iRightSideSize)
	{
		vRandomIntegers.push_back(vRightSide[iRightLoopCount]);
		iRightLoopCount++;
	}
}


void MergeSort(vector<int> & vRandomIntegers)
{
	int iVectorLength = vRandomIntegers.size();
	int iLoopCount = 0;
	vector<int> vLeftSide;
	vector<int> vRightSide;

	if (iVectorLength <= 1)
		return;

	for (iLoopCount = 0; iLoopCount < iVectorLength; iLoopCount++)
	{
		if (iLoopCount < (iVectorLength / 2))
		{
			vLeftSide.push_back(vRandomIntegers[iLoopCount]);
		}
		else
		{
			vRightSide.push_back(vRandomIntegers[iLoopCount]);
		}
	}

	MergeSort(vLeftSide);
	MergeSort(vRightSide);
	vRandomIntegers.clear();
	MergeVectors(vRandomIntegers, vLeftSide, vRightSide);

}


int main()
{
	const int i_MAX_VECTOR_SIZE = 500;
	vector<int> vRandomIntegers;
	bool bVectorFilled = false;
	bVectorFilled = FillVectorWithRandomNumbers(vRandomIntegers, i_MAX_VECTOR_SIZE);
	if (bVectorFilled)
	{
		DisplayVectorValues(vRandomIntegers);
		PressAnyKey();
		MergeSort(vRandomIntegers);
		DisplayVectorValues(vRandomIntegers);
		PressAnyKey();
	}
	else
	{
		cout << "An error occurred and the vector is empty." << endl;
		PressAnyKey();
	}

	return 0;
}
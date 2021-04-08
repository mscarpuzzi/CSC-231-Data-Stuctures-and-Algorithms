// QuickSort.cpp : Defines the entry point for the console application.
// This program demonstrates the quicksort algorithm using vectors.
// It prompts the user for the number of items to sort.
// It then creates a vector of that length full of random integers.
// It then displays the vector in initial form to the console.
// Then the program sorts the vector using the QuickSort algorithm.
// Finally the program displays the final sorted vector to the console.

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

// The Partition function rearranges elements in a vector parameter so that the elements on the left side
// of the vector are smaller than the elements on the right side of the vector. In other words, smaller elements
// are at the beginning of the vector and larger elements are at the end. Determining small vs. large is done via
// a "Pivot Value" that is selected. The Pivot Value is initially set to the first element in the vector. The function
// returns the index of the vector where the Pivot Value ends up located following the rearrangement.
int Partition(vector<int> & vRandomIntegers, int iStartIndex, int iFinishIndex)
{
	int iPivotValue = vRandomIntegers[iStartIndex];
	int iLeft = iStartIndex + 1;
	int iRight = iFinishIndex;
	int iTempValue = 0;
	int iPartitionIndex = 0;

	bool bFoundPivot = false;

	while (!bFoundPivot)
	{
		while (iLeft < iRight && vRandomIntegers[iRight] >= iPivotValue)
		{
			iRight--;
		}
		while (iLeft < iRight && vRandomIntegers[iLeft] < iPivotValue)
		{
			iLeft++;
		}
		if (iLeft == iRight)
		{
			bFoundPivot = true;
		}
		else
		{
			iTempValue = vRandomIntegers[iLeft];
			vRandomIntegers[iLeft] = vRandomIntegers[iRight];
			vRandomIntegers[iRight] = iTempValue;
		}
	}
	
	if (vRandomIntegers[iLeft] >= iPivotValue)
	{
		iPartitionIndex = iStartIndex;
	}
	else
	{
		vRandomIntegers[iStartIndex] = vRandomIntegers[iLeft];
		vRandomIntegers[iLeft] = iPivotValue;
		iPartitionIndex = iLeft;
	}
	return iPartitionIndex;
}


// The QuickSort function is a recursive function. It takes a vector of integers and divides it logically
// into two parts - one part of small numbers and one part of large numbers. The Partition function determins the pivot
// point and arranges the two halves. Then the QuickSort function calls itself twice to sort both sides and the process
// repeats until the entire vector is sorted.
void QuickSort(vector<int> & vRandomIntegers, int iStartIndex, int iFinishIndex)
{
	if (iStartIndex >= iFinishIndex)
		return;

	int iBoundary = Partition(vRandomIntegers, iStartIndex, iFinishIndex);
	QuickSort(vRandomIntegers, iStartIndex, iBoundary);
	QuickSort(vRandomIntegers, iBoundary + 1, iFinishIndex);

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
		QuickSort(vRandomIntegers, 0, vRandomIntegers.size() - 1);
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
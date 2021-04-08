/*
Michael Scarpuzzi
CSC 231
09/02/2019

This program is to demonstrate the time complexity of Binary Search.
This was properly executed and linked on Visual Studio C++ 2017 Community edition.
*/

#include <iostream>		// Used for input and output.
#include <cstdlib>		// Used for random number generation.
#include <time.h>       // Used to seed the random number generator.

using namespace std;

// Functions prototypes.
void randomizeArray(int array[], int length);
int binarySearch(int array[], int arraySize, int target);
void searchAndDisplayItem(int array[], int arraySize, int target);
void selectionSort(int array[], int length);

// Global variables and constants.
const int LENGTH = 200; // The size of the vector. Change this value for different runs.
long int counterForBinary = 0; // Counter for the steps

int main()
{

	int demo[LENGTH]; // Declare, initialize, and display array.
	srand((unsigned)time(NULL)); // Create seed
	for (int i = 0; i <= 1000 - 1; i++) // 1000 iterations
	{

		randomizeArray(demo, LENGTH);
		selectionSort(demo, LENGTH); // Sort vector 
		int target = binarySearch(demo, LENGTH, 120);
		//searchAndDisplayItem(demo, LENGTH, 120); // Uncomment to see what adreess the value was found
	}

	cout << "Total step count for Binary Search : " << counterForBinary
		<< endl;
	cout << "Average step count for Binary Search: " << (double)counterForBinary / 1000 << endl;

	system("pause");
}

// Give a random value to each element of the vector.
void randomizeArray(int array[], int length)
{
	for (int index = 0; index < length; index++)
	{
		array[index] = rand() % LENGTH * 2; // Values twice the size of the vector
	}
}

// Search for selected value in our vector and display results.
void searchAndDisplayItem(int array[], int arraySize, int target)
{
	int index = binarySearch(array, arraySize, target);

	if (index >= 0)
	{
		cout << "The value " << target << " was found at index " << index << ".\n";
	}
	else
	{
		cout << "The value " << target << " was not found in the array.\n";
	}

}

// Sort vector
void selectionSort(int array[], int length)
{
	int baseIndex, walker, minIndex, temp;
	// Loop: Traverse unsorted part of vector, find minimum value, and swap minimum value into correct position. 
	for (baseIndex = 0; baseIndex < length; baseIndex++)
	{
		// Set the initial minimum value as the first position in the unsorted part of the vector.
		minIndex = baseIndex;
		// Loop: Check each index in unsorted part of vector to find the minimum value.
		for (walker = baseIndex + 1; walker < length; walker++)
		{
			if (array[walker] < array[minIndex])	// Check for a new minimum.
			{
				minIndex = walker;
			}
		}
		if (minIndex != baseIndex)					// Swap to put minimum value in correct position.
		{
			temp = array[baseIndex];
			array[baseIndex] = array[minIndex];
			array[minIndex] = temp;
		}

		//cout << "[" << baseIndex << "] = " << array[baseIndex] << endl; // Uncomment to see the vector with address and values
	}
}

// The search that gets called by searchAndDisplayItem 
int binarySearch(int array[], int arraySize, int target)
{
	counterForBinary += 3; // Count 3 for initialization and while first execution  
	int low = 0;
	int high = arraySize;
	while (low + 1 < high)
	{
		// Choose the middle value of the vector's search range. 
		counterForBinary += 2; // Count 2 for assignment and if condition
		int checkIndex = (low + high) / 2;	// Side note: Alternate code int checkIndex = ( (low + high) >> 1); // Shift binary decimal point - it's quicker.
		if (array[checkIndex] > target)	// Is the middle value higher or lower.
		{
			high = checkIndex;
			counterForBinary++; // Count for statment above
			// Cut search range in half by eliminating the greater than section.
		}
		else
		{
			low = checkIndex;
			counterForBinary++; // Count for statment above
			// Cut search range in half by eliminating the lower than section.
		}

		counterForBinary++; // Count for while's condition

	}
	counterForBinary++;
	// Does this save time to check for equality only at the end???
	if (array[low] == target)
	{
		counterForBinary++; // Count for statment below
		return low;		// Return the index of the found target.
	}
	else
	{
		counterForBinary++; // Count for statment below
		return -1;		// Indicate that the target was not found.
	}

}
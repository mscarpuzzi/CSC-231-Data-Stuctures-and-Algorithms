/*
Michael Scarpuzzi
CSC 231
09/02/2019

This program is to demonstrate the time complexity of Linear Search.
This was properly executed and linked on Visual Studio C++ 2017 Community edition.
*/


#include <iostream>		// Used for input and output.
#include <cstdlib>		// Used for random number generation.
#include <time.h>       // Used to seed the random number generator.

using namespace std;

// Functions prototypes.
void randomizeArray(int array[], int length);
int linearSearch(int array[], int arraySize, int target);
void searchAndDisplayItem(int array[], int arraySize, int target);


// Global variables and constants.
const int LENGTH = 800; // The size of the vector. Change this value for different runs.
long int counterForLinear = 0; // Counter for the steps

int main()
{

	int demo[LENGTH]; // Declare, initialize, and display array.
	srand((unsigned)time(NULL)); // Create seed
	for (int i = 0; i <= 1000 - 1; i++) // 1000 iterations
	{
		randomizeArray(demo, LENGTH);
		int target = linearSearch(demo, LENGTH, 120);
		// searchAndDisplayItem(demo, LENGTH, 120); // Uncomment to see what adreess the value was found


	}

	cout << "Total step count for linear search : " << counterForLinear
		<< endl;
	cout << "Average step count for linear search: " << (double)counterForLinear / 1000 << endl;

	system("pause");
}

// Give a random value to each element of the vector.
void randomizeArray(int array[], int length)
{

	for (int index = 0; index < length; index++)
	{

		array[index] = rand() % LENGTH * 2; // Values twice the size of the vector 
	   // cout << "[" << index << "] = " << array[index] << endl; // Uncomment to see the vector with address and values
	}
}

// // The search that gets called by searchAndDisplayItem 
int linearSearch(int array[], int arraySize, int target)
{
	// Go through each index, one at a time sequentially and check to see if the index's value is the target.
	counterForLinear++; // Count for initialization of index
	for (int index = 0; index < arraySize; index++)
	{
		counterForLinear += 3; // Count 2 for condition and auto-increment in loop
							   // Count for below condition
		if (array[index] == target)
		{
			counterForLinear++; // Count for return
			return index;
			// Return the index of the found target.
		}

	}
	counterForLinear += 2; // Count for the outer loop auto-increment and return

	return -1; // Return -1 as a flag to indicate that the target was not found.

}

// Search for selected value in our vector and display results.
void searchAndDisplayItem(int array[], int arraySize, int target)
{
	int index = linearSearch(array, arraySize, target);

	if (index >= 0)
	{
		cout << "The value " << target << " was found at index " << index << ".\n";
	}
	else
	{
		cout << "The value " << target << " was not found in the array.\n";
	}

}
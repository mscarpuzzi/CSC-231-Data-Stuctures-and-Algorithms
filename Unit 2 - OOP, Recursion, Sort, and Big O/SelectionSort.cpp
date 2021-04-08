/*
The purpose of this program is to demonstrate selection sort and other programming features.
Selection sort begins by traversing the unsorted part of the array one element at a time and
finding the smallest element. The smallest element is then placed in the first position of 
the unsorted part of the array. In the first traversal, the whole array must be passed through 
because the whole array is unsorted. When the array has been traversed, the small element is 
swapped positions with the smallest position in the array. Now the array has a sorted part, 
consisting of the first item, and the unsorted part which is the rest of the array. The second 
traversal of the unsorted array begins with the second item of the array, when the traversal 
is complete the second smallest item of the array has been found and is swapped with the second 
item in the array. Similarly, the third, fourth, and subsequently small items of the array are 
swapped into their positions as well until the entire array is sorted.
*/

#include <iostream>		// Used for input and output.
#include <conio.h>		// Used for getch().
#include <cstdlib>		// Used for random number generation.
#include <time.h>       // Used to seed the random number generator.

using namespace std;

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl;
	_getch();					// Waits and gets next character entered.	
}

// Display values of array - each on their own line.
void displayArray(int array[], int length)
{
	int i = 0;
	while (i < length)
	{
		cout << array[i] << " ";
		i++;
	}	
	cout << endl;
}

// Give a random value to each element of the array.
void randomizeArray(int array[], int length)
{
	srand ( (unsigned) time(NULL));			// Seed random number generator. 

	int i = 0;
	do
	{
		array[i] = rand() % 100 + 1;		// A random number in the range of 1 to 100 is assigned.
		i++;
	} while (i < length);	
}

// Sort array.
void selectionSort(int array[], int length) 
{
	int baseIndex, walker, minIndex, temp;
	// Loop: Traverse unsorted part of array, find minimum value, and swap minimum value into correct position. 
	for (baseIndex = 0; baseIndex < length - 1; baseIndex++) 
	{
		// Set the initial minimum value as the first position in the unsorted part of the array.
		minIndex = baseIndex;
		// Loop: Check each index in unsorted part of array to find the minimum value.
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
		//displayArray(array, length);				// Uncomment for demonstration purposes.
		//pressAnyKey();
	}
}

int main()
{
	const int LENGTH = 20;				// The length of our demonstration array.
	int demo[LENGTH];					// Declare, initialize, and display array.
	randomizeArray(demo, LENGTH);
	displayArray(demo, LENGTH);

	pressAnyKey();						// Pause to take in the experience :-)

	selectionSort(demo, LENGTH);
	displayArray(demo, LENGTH);			// Sort array and display.

	pressAnyKey();						// End main function and end program.
	return 0;							
}
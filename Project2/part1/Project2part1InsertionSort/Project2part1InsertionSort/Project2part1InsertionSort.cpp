/*
Michael Scarpuzzi
CSC 231
09/18/2019

This program is to demonstrate the time complexity of Insertion Sort.
This was properly executed and linked on Visual Studio C++ 2017 Community edition.
*/

#include "pch.h"

#include <iostream>		// Used for input and output.
#include <cstdlib>		// Used for random number generation.
#include <ctime>       // Used to seed the random number generator.

using namespace std;

// Functions prototypes.
void displayArray(int array[], int length);
void randomizeArray(int array[], int length);
void insertionSort(int arr[], int length);


// Global variables and constants.
int const LENGTH = 100000;				// The length of our demonstration array.
int testArray[LENGTH];
int const CLOCK_PER_SEC = 1000;

int main()
{
	clock_t startTime, endTime;
	// Randomize values in array and display.
	randomizeArray(testArray, LENGTH);
	//displayArray(testArray, LENGTH); // Uncomment to see what addresses and values are
	system("pause");
	startTime = clock();
	insertionSort(testArray, LENGTH);
	endTime = clock();
	displayArray(testArray, LENGTH); // Uncomment to see what the sorted address and values are
	cout << "Time: " << difftime((float)endTime, (float)startTime) / CLOCK_PER_SEC * 1000 << " milliseconds" << endl;

	system("pause");

}

// Display values of array 
void displayArray(int array[], int length)
{
	int i = 0;
	while (i < length)
	{
		cout << "[" << i << "]= " << array[i] << " " << endl;
		i++;
	}
	cout << endl;
}

// Give a random value to each element of the array.
void randomizeArray(int array[], int length)
{
	srand((unsigned)time(NULL));			// Seed random number generator. 

	int i = 0;
	do
	{
		array[i] = rand() % (2 * length) + 1;		// A random number in the range of 1 to 100 is assigned.
		i++;
	} while (i < length);
}


void insertionSort(int arr[], int length) {

	int i, j, tmp;

	for (i = 1; i < length; i++) {

		j = i;

		while (j > 0 && arr[j - 1] > arr[j]) {

			tmp = arr[j];

			arr[j] = arr[j - 1];

			arr[j - 1] = tmp;

			j--;

		}

	}

}
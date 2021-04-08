/*
Michael Scarpuzzi
CSC 231
09/18/2019

This program is to demonstrate the time complexity of Quick Sort.
This was properly executed and linked on Visual Studio C++ 2017 Community edition.
*/

#include "pch.h"

#include <iostream>		// Used for input and output.
#include <cstdlib>		// Used for random number generation.
#include <ctime>       


using namespace std;

// Functions prototypes.
void displayArray(int array[], int length);
void randomizeArray(int array[], int length);
void quickSort(int array[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);


// Global variables and constants.
int const LENGTH = 40000;				// The length of our demonstration array.
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
	quickSort(testArray, 0, LENGTH + 1);
	endTime = clock();
	//displayArray(testArray, LENGTH); // Uncomment to see what addresses and values are
	cout << "Time: " << ((float)endTime - (float)startTime) / CLOCK_PER_SEC * 1000 << " milliseconds" << endl;

	system("pause");

}

 // Display values of array - each on their own line.
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


// A utility function to swap two elements 
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
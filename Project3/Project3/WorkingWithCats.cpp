/*
Michael Scarpuzzi
09/03/2019
CSC 231

This file is my driver for the Catlist.cpp
*/

#include <iostream>		// Used for input and output.
#include <string>
#include <conio.h>		// Used for getch().

		
#include "CatList.h"

using namespace std;

void pressAnyKey();

int main()
{
	
	
	// Declare, construct, and display list object.
	CatList catList;
	



	// Display menu for user choice.
	int choice;
	bool keepGoing = true;
	while (keepGoing)
	{
		cout << endl
			<< "---------------------------------------------------------------------\n"
			<< " Select an option from the menu below\n"
			<< " by entering the number of the choice\n"
			<< "---------------------------------------------------------------------\n"
			<< "\t1\tAdd a cat to the front of the list\n"
			<< "\t2\tAdd the cat at the back of the list\n"
			<< "\t3\tSearch in the list of cats\n"
			<< "\t4\tEdit a cat's attributes\n"
			<< "\t5\tRemove a cat\n"
			<< "\t6\tDisplay all cats in list\n"
			<< "\t7\tEnd program\n"
			<< "---------------------------------------------------------------------\n\n"
			<< "Enter your choice : \n\n";

		// Get user choice and process.
		cin >> choice;
		switch (choice)
		{
		case 1: //Call from Catlist.cpp
		{  
			string theType; int theSize;
			int theAge;
			
			cout << "Enter the type of cat you would like to add:\n";
			cin.ignore();
			getline(cin, theType);
			cout << "Enter the size of cat you would like to add:\n";
			cin >> theSize;
			cout << "Enter the age of the cat you would like to add:\n";
			cin >> theAge;
			
			Cat cat(theType, theSize, theAge);
			
			catList.addFront(cat);
			break;
		}
		case 2: //Call from Catlist.cpp
		{
			string theType; int theSize;
			int theAge;

			cout << "Enter the type of cat you would like to add:\n";
			cin.ignore();
			getline(cin, theType);
			cout << "Enter the size of cat you would like to add:\n";
			cin >> theSize;
			cout << "Enter the age of the cat you would like to add:\n";
			cin >> theAge;

			Cat cat(theType, theSize, theAge);

			catList.addBack(cat);
			break;

			
		}
		case 3: //Call from Catlist.cpp
		{
			string theType; int theSize;
			int theAge;

			cout << "Enter the type of cat you would like to search:\n";
			cin.ignore();
			getline(cin, theType);
			cout << "Enter the size of cat you would like to search:\n";
			cin >> theSize;
			cout << "Enter the age of the cat you would like to search:\n";
			cin >> theAge;
			

			catList.searchList(theType, theSize, theAge);

			break;
		}
		case 4: //Call from Catlist.cpp
		{

			string theType; int theSize;
			int theAge;

			cout << "Enter the type of cat you would like to edit:\n";
			cin.ignore();
			getline(cin, theType);
			cout << "Enter the size of cat you would like to edit:\n";
			cin >> theSize;
			cout << "Enter the age of the cat you would like to edit:\n";
			cin >> theAge;
			
            catList.edit(theType, theSize, theAge);

			break;
			

		}
		case 5: //Call from Catlist.cpp
		{
			string theType; int theSize;
			int theAge;

			cout << "Enter type of cat:\n";
			cin.ignore();
			getline(cin, theType);
			cout << "Enter the size of cat:\n";
			cin >> theSize;
			cout << "Enter the age of the cat:\n";
			cin >> theAge;

			catList.removeFrom(theType, theSize, theAge);


			break;


		}
		case 6:	//Call from Catlist.cpp
		{
			catList.displayList();
			pressAnyKey();
			break;
		}
		case 7: // Quit program.
		{
			keepGoing = false;		// Exit from menu loop and program.
			cout << "The program is now ending.\n";
			pressAnyKey();
			break;
		}
		default: // Catch all under construction items.
		{
			cout << "That option is currently not available\n";
			pressAnyKey();
			break;
		}
		}
	}

	// End program.	
	return 0;
}

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl << endl;
	_getch();					// Waits and gets next character entered.		
}

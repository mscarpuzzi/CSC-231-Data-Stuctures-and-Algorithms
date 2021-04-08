/*
Michael Scarpuzzi
11/17/2019
CSC 231

This file is my driver for the whoopingCrane.cpp
*/
#include <iostream>
#include <string>
#include <unordered_map>

#include <fstream>
#include <cstring>

#include "whoopingCrane.h"

using namespace std;

void pressAnyKey();
int initializeHash();
int hashIt(int theID);
void addNewCrane();
void searchForCrane(int value);
void searchByLocation();
void removeCrane();
void displayHashTable();
void addActualCrane(int attempts, int theID, whoopingCrane theCrane);

fstream craneFile;
int maxHashSize = 19; //array size

unordered_map<int, whoopingCrane> hashMap; //our template for the map(helps with interation through the array
//(I did copy the stucture and logic from online))))


void pressAnyKey()
{
	cout << "Press any key to continue" << endl << endl;
	
}

int hashIt(int theID) //hashes the crane's ID number.
{
	int hashedID = theID / maxHashSize;
	return hashedID;
}

int initializeHash()
{
	craneFile.open("craneFile.dat", ios::in | ios::out | ios::binary | ios::trunc);
	if (!craneFile) //open file
	{
		cout << "File error - file didn't open properly\n"
			 << "Program will end.\n"; 
		pressAnyKey();
		return 1; //flag check for the data file 
	}

	hashMap = { {hashIt(111111), whoopingCrane(111111, (char *)"Mobile", 2.3, (char *)"Male")},
				{hashIt(572145), whoopingCrane(572145, (char *)"Florida", 3.5, (char *)"Female")},
				{hashIt(824689), whoopingCrane(824689, (char *)"Mobile", 1.2, (char *)"Male")},
				{hashIt(184334), whoopingCrane(184334, (char *)"Mississippi", 5.7, (char *)"Male")},
				{hashIt(642467), whoopingCrane(642467, (char *)"Mobile", 1.2, (char *)"Male")},
				{hashIt(999999), whoopingCrane(999999, (char *)"Mobile", 1.2, (char *)"Male")},
	}; //
}

void addNewCrane() //adds a new crane
{
	int theID, theAge;
	string tempLocation, tempGender;
	cout << "You have selected adding a new whooping crane\n"
		<< "What is the Unique ID of the whooping crane? (6 digit number)\n";
	cin >> theID;
	cin.ignore();
	cout << "What is the location of this whooping crane?\n";
	getline(cin, tempLocation);
	cout << "How old is this whooping crane?\n";
	cin >> theAge;
	cin.ignore();
	cin.clear();
	cout << "Finally, what gender is this whooping crane? (Male or Female)\n";
	getline(cin, tempGender);

	char * theLocation = new char[tempLocation.size() + 1];
	char * theGender = new char[tempGender.size() + 1];

	copy(tempLocation.begin(), tempLocation.end(), theLocation);
	theLocation[tempLocation.size()] = '\0'; //the copy fuction is a part of "stdlib.h"

	copy(tempGender.begin(), tempGender.end(), theGender);
	theGender[tempGender.size()] = '\0';
	
	whoopingCrane theCrane = whoopingCrane(theID, theLocation, theAge, theGender);

	int attempts = 0;
	
addActualCrane(attempts, theID, theCrane);
}

void addActualCrane(int attempts, int theID, whoopingCrane theCrane) //open addrassing probing to add
{

	int temp = hashMap.count(hashIt(theID) + attempts);
	if (temp == 1)
	{
		if (attempts == 0 || attempts == 1)
		{
			attempts++;
		}
		else
		{
			attempts = attempts * attempts;
		}

		addActualCrane(attempts, theID, theCrane);
	}
	else
	{
		hashMap[hashIt(theID) + attempts] = theCrane;
		cout << hashMap[hashIt(theID) + attempts] << endl;
		return;
	}
} //

void searchForCrane(int value)
{


	for (const auto& item : hashMap)
	{
		if (value == item.second.getID())
			cout << item.second.getID() << " was found." << endl << item.second << endl;
	}
}
void searchByLocation() //uses the hash table mapping to find locations 
{
	string searchedLocation;
	cout << "Please enter a location to search for: \n";
	getline(cin, searchedLocation);
	pressAnyKey();
	for (const auto& item : hashMap)
	{
		if (searchedLocation == item.second.getLocation())
			cout << item.second.getID() << " is located in " << searchedLocation << endl; 
	}
}

void removeCrane() // removes a listed crane.
{
	int key;
	cout << "Which crane would you like to delete?\n";
	cin >> key;

	int temp = hashMap.count(hashIt(key));

	if (temp == 1)
	{
		cout << hashMap[hashIt(key)] << " has been deleted" << endl;
		hashMap.erase(hashIt(key));
	}
	else
	{
		cout << "No crane active. Try again\n";
	}
}

void displayHashTable() //display the entire hash table and print out the cranes in their correct position.
{
	for (const auto& item : hashMap)
	{
		cout << item.second << endl;
	}
}

void displayMenu() //output loop framework for the features
{

	int choice;
	bool keepGoing = true;
	while (keepGoing)
	{
	   cout << "---------------------------------------------------------------------\n"
			<< "Welcome to the Whooping Crane Program!\n"
			<< " Select an option from the menu below\n"
			<< " by entering the number of the choice\n"
			<< "---------------------------------------------------------------------\n"
			<< "\t1\tAdd a new Whooping Crane to the list.\n"
			<< "\t2\tSearch for a Whooping Crane by it's ID number.\n"
			<< "\t3\tDisplay all the cranes from a user defined area.\n"
			<< "\t4\tRemove a crane.\n"
			<< "\t5\tDisplay the hash table with each cranes position.\n"
			<< "\t6\tExit the program\n"
			<< "---------------------------------------------------------------------\n\n"
			<< "Enter your choice : \n\n";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			addNewCrane();
			pressAnyKey();
			break;
		}
		case 2:
		{
			int value, attempts;
			cout << "What unique ID do you wish to search for?\n";
			cin >> value;
			searchForCrane(value);
			cin.ignore();
			pressAnyKey();
			break;
		}
		case 3:
		{
			searchByLocation();
			pressAnyKey();
			break;
		}
		case 4:
		{
			removeCrane();
			pressAnyKey();
			break;
		}
		case 5:
		{
			displayHashTable();
			pressAnyKey();
			break;
		}
		case 6:
		{
			keepGoing = false;
			pressAnyKey();
			break;
		}
		}
	}
}

void readBinary(int pos, whoopingCrane& theCrane) //reading with the .dat file
{
	craneFile.seekg(pos * sizeof(whoopingCrane));
	craneFile.read((char *)&theCrane, sizeof(whoopingCrane));
}

void writeBinary(int pos, whoopingCrane theCrane) //writing with the .dat file
{
	craneFile.seekp(pos * sizeof(whoopingCrane));
	craneFile.write((char *)&theCrane, sizeof(whoopingCrane));
	craneFile.flush(); //for overwriting
	craneFile.seekp(0 * sizeof(whoopingCrane));
}


int main() //driver program
{
	initializeHash();
	displayMenu();
	return 0;
}
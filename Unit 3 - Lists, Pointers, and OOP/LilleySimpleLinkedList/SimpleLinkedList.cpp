// SimpleLinkedList.cpp : Defines the entry point for the console application.
// This is a simple singly linked list program that we built in class.
// It creates a basic linked list of people with last name and first name.

#include "stdafx.h"
#include <string>
#include <iostream>	

using namespace std;

// Basic node structure for our linked list.
// This is a singly linked list of people with last and first name.
struct Person
{
	string LName;
	string FName;
	Person* Next;
};

// This is a procedure that inserts a new node into the linked list in sorted order.
// The comparison for where to insert the node is simple and does not convert from upper to lower case or vice versa.
// Rather, this procedure was built in class to demonstrate the addition of a node and basic list operations.

void InsertNodeIntoList(Person* & pHead, string sLastName, string sFirstName)
{
	Person* tempPerson;
	Person* newPerson;

	tempPerson = pHead;
	bool bSlotFound = false;

	if (pHead != NULL)
	{	// List not empty so add new node in proper place
		if (sLastName < pHead->LName)	// Insert at the head of the list
		{
			newPerson = new Person;
			newPerson->LName = sLastName;
			newPerson->FName = sFirstName;
			newPerson->Next = pHead;
			pHead = newPerson;
		}
		else
		{	// Find slot or add to end of list
			while ((tempPerson->Next != NULL) && !bSlotFound)
			{
				if (tempPerson->Next->LName < sLastName)
				{
					tempPerson = tempPerson->Next;
				}
				else
				{
					bSlotFound = true;
				}
			}
			// Add node to the slot or end if the list only had 1 item
			newPerson = new Person;
			newPerson->LName = sLastName;
			newPerson->FName = sFirstName;
			newPerson->Next = tempPerson->Next;
			tempPerson->Next = newPerson;
		}
	}
	else
	{	// Empty list so add a new node and make it the head
		newPerson = new Person;
		newPerson->LName = sLastName;
		newPerson->FName = sFirstName;
		newPerson->Next = NULL;
		pHead = newPerson;
	}
}

// Simple loop to display the contents of the singly linked list.
void DisplayList(Person* pHead)
{
	Person* pTemp = pHead;
	while (pTemp != NULL)
	{
		cout << "Last Name: " << pTemp->LName << endl;
		cout << "First Name: " << pTemp->FName << endl;
		pTemp = pTemp->Next;
	}

}

int main()
{
	// Add first person to the list.
	Person* headPerson;
	Person* tempPerson;
	Person* nPerson = new Person;

	nPerson->FName = "Larry";
	nPerson->LName = "Lilley";
	nPerson->Next = NULL;

	headPerson = nPerson;
	tempPerson = nPerson;
	
	// Show how the pointers work.
	cout << nPerson->FName << endl;
	cout << headPerson->LName << endl;

	// Add second person to list.
	nPerson = new Person;
	nPerson->FName = "Terri";
	nPerson->LName = "Thompson";
	tempPerson->Next = nPerson;
	nPerson->Next = NULL;
	tempPerson = nPerson;

	// Show how the pointers work with passing through a node.
	cout << nPerson->FName << endl;
	cout << headPerson->Next->LName << endl;

	cout << endl << endl;

	string sLastName = "";
	string sFirstName = "";

	// Get a name from the user.
	cout << "Enter a name to insert into the list" << endl;
	cout << "Enter the Last Name: ";
	cin >> sLastName;
	cout << endl << "Enter the First Name: ";
	cin >> sFirstName;

	// Insert the node in position.
	InsertNodeIntoList(headPerson, sLastName, sFirstName);
	
	// Display the list to show that it inserted in the correct spot.
	DisplayList(headPerson);

	    return 0;
}

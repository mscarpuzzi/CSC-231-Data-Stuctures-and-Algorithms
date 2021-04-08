/*
Michael Scarpuzzi
09/03/2019
CSC 231

This file is my class implentation for the CatList class defined in Catlist.h
*/

#include "CatList.h"
#include <iostream>


// Constructors. Only default constructor is needed for new empty list. 
CatList::CatList()
{
    head = NULL;
    tail = NULL;
};

// Destructor deletes object and code removes garbage.
CatList::~CatList()
{
	while (!empty())
	{
		removeFront();
	}
}

// Is list empty?
bool CatList::empty() const
{
	return (head == NULL);
}

// Get front node.
const Cat& CatList::front() const
{
	return head-> cat;
}

// Get back node.
const Cat& CatList::back() const
{
	return tail->cat;
}

// Add node to front.
void CatList::addFront(const Cat& e)
{
	CatNode* temp = new CatNode;			// Create new node.
	temp->cat = e;					// Store data.
	temp->next = head;				// Current head is now next of our new node.
	head = temp;					// Our new node is now the new head.
	if (!tail)
	{
		tail = temp;
	}

	cout << "Cat Added!\n\n";
}

// Remove node from front.
void CatList::removeFront()
{
	if (!empty())
	{
		CatNode* temp = head;				// temp saves the current head.
		head = temp->next;				// Our new head is the old head's next. 
		delete temp;					// Delete the previous head.
	}
}

// Remove node from back.
void CatList::removeBack()
{
	if (!empty())
	{
		CatNode* temp = tail;				// temp saves the current head.
		tail = temp->prev;
		tail->next = NULL;				// Our new head is the old head's next. 
		delete temp;					// Delete the previous head.
	}
}

//Add to the back of list(not used)
void CatList::addBack(const Cat& e)
{  
	CatNode* temp = new CatNode;
	temp->cat = e;

	
	if (this->head == NULL)
	{
		head = temp;
		tail = temp;
	
	}

	if (tail)
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		
	}
	temp->next = NULL;
	temp->prev = tail;

	cout << "Cat Added!\n\n";
	
	
}

//Search the list
void CatList::searchList(string type, int size, int age)
{
	CatNode* temp = head;

	while (temp)
	{
		if (temp->cat.getType() == type && temp->cat.getSize() == size && temp->cat.getSize() == age)
		{
			cout << "Found cat: Type: " << type << ", Size: " << size << ", Age: " << age;
			temp = temp->next;
			break;
		}
		else
		{
			cout << "Sorry, no cats are in the list!\n";
			break;
		}
		if (empty())
		{
			cout << "Sorry, no cats are in the list!\n";
			break;

		}
		
	}
}

//Edit an Cat object from the list 
void CatList::edit(string type, int size, int age)
{
	CatNode* temp = head;

	bool found = false;

	while (temp && !found)
	{
		if (temp->cat.getType() == type && temp->cat.getSize() == size && temp->cat.getSize() == age)

			found = true;
		else
			temp = temp->next;

	
	if (!found)
	{
		cin.ignore();
		cout << "Sorry, no cats that have those parameters are in the list!" << endl;
		break;
	}
	else
	{
		char pick = ' ';
		bool(keepgoing) = true;

		while (keepgoing)
		{
			cout << endl
				<< "---------------------------------------------------------------------\n"
				<< " Select an option from the menu below\n"
				<< " by entering the number of the choice\n"
				<< "---------------------------------------------------------------------\n"
				<< "This is the type currently " << temp->cat.getType() << endl
				<< "This is the size currently " << temp->cat.getSize() << endl
				<< "This is the age currently " << temp->cat.getAge() << endl
				<< "---------------------------------------------------------------------\n\n"
				<< "Enter what you would like to change: \n\n"
				<< "\t1 for type " << endl
				<< "\t2 for size " << endl
				<< "\t3 for age" << endl
				<< "---------------------------------------------------------------------\n";
				

			cin.ignore();

			pick = getchar();



			string inputstr = "";
			int inputnum = 0;

			switch (pick)
			{
			case '1':
			{
				cout << "Change type to ";
				cin.ignore();
				getline(cin, inputstr);
				temp->cat.setType(inputstr);
				cout << "Done! Change type to " << temp->cat.getType();
				break;

			}
			case '2':
			{
				cout << "Change size to ";
				cin.ignore();
				cin >> inputnum;
				temp->cat.setSize(inputnum);
				cout << "Done! Change size to " << temp->cat.getSize();
				break;

			}
			case '3':
			{
				cout << "Change age to ";
				cin.ignore();
				cin >> inputnum;
				temp->cat.setAge(inputnum);
				cout << "Done! Change age to " << temp->cat.getAge();
				break;

			}
			break;

			}
			break;
		}
	}
	}

	
}

//Remove a Catnode
void CatList::removeFrom(string type, int size, int age) 
{
	CatNode* temp = head;
	
	bool found = false;

	while (temp && !found)
	{
		if (temp->cat.getType().compare(type) == 0 && temp->cat.getSize() != NULL && temp->cat.getAge() != NULL)
		{
			temp = head;
			head = head->next =
			head->prev = NULL;
			delete temp;
			cout << "Cat removed!";
			found = true;
			break;
		}
		    

		
		else
			temp = temp->next;
	}

	if (!found)
	{

		cout << type << "Sorry, no cats that have those parameters are in the list!" << endl;
	}


}

//Display all
void CatList::displayList() const
{
	if (!empty())

	{
		cout << "The following cats are in this list:\n";
		CatNode* temp = head;
		
		while (temp)	// temp evaluates to true if it is not NULL.
		{
			cout << temp-> cat << endl;
			temp = temp->next;	// Move to the next node, which if it's NULL
		}						// will cause the loop to terminate.	   
		cout << endl;
	}
	else
	{
		cout << "There are no cats in this list.\n";
	}
}
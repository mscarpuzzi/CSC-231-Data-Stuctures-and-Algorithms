/*
The purpose of this program is to demonstrate the use of pointers. 
*/

#include <iostream>		// Used for input and output.
#include <string>
#include <conio.h>		// Used for getch().

using namespace std;

struct Car				// Data of the Car struct are public by default here.
{						// If this were a class, the default access type would be private. 
	string make;
	string model;
	int year;
	double mileage;
};

// Forward function declarations.
void pressAnyKey();

int main()
{
	// Demo 1.
	int int1, int2;				// Declare two ints.
	int *pointer1, *pointer2;	// Declare two int pointers.
	pointer1 = &int1;			// The value of pointer1 is the address of int1.
	*pointer1 = 100;			// This sets the value of int1 to 100.

	cout << "Demo 1:" << endl;
	cout << "int1 = " << int1 << endl;
	cout << "pointer1 = " << pointer1 << " - which is the address of int1 in memory" << endl;
	cout << "*pointer1= " << *pointer1 << " - which is the value of int1" << endl << endl;
	pressAnyKey();

	// Demo 2.
	pointer1 = &int2;			// Now pointer1 has the value of the address of int2.
	*pointer1 = 200;			// Now int2 has the value of 200.

	cout << "Demo 2:" << endl;
	cout << "int1 = " << int1 << "- int1 did not change" << endl;
	cout << "int2 = " << int2 << " - int2 received the value given to *pointer1" << endl;
	cout << "pointer1 = " << pointer1 << " - which is the address of int2 in memory" << endl;
	cout << "*pointer1 = " << *pointer1 << " - which is the value of int2" << endl;
	cout << "&int1 = " << &int1 << endl;
	cout << "&int2 = " << &int2 << endl << endl;
	pressAnyKey();

	// Demo 3.
	pointer2 = pointer1;		// The value (address) of pointer1 is now also the value of pointer2.
								// pointer2 now points to int2.
	pointer1 = &int1;			// The value of pointer1 is now the address of int1. pointer1 points to int1.
	*pointer2 = *pointer1 * int1;	// int2 should now be equal to the square of int1.
	
	cout << "Demo 3:" << endl;
	cout << "int1 = " << int1 << endl;
	cout << "int2 = " << int2 << endl;
	cout << "pointer1 = " << pointer1 << endl;
	cout << "*pointer1 = " << *pointer1 << endl;
	cout << "pointer2 = " << pointer1 << endl;
	cout << "*pointer2 = " << *pointer1 << endl;
	cout << "&int1 = " << &int1 << endl;
	cout << "&int2 = " << &int2 << endl << endl;
	pressAnyKey();

	// Demo 4:
	int int3;
	*pointer1 = *pointer2;		// The value of pointer2 is now the value (address) of pointer1.
								// Meaning that int1 and int2 now equal 10,000.
	pointer1 = new int(42);
	cout << "Demo 4:" << endl;
	cout << "int1 = " << int1 << endl;
	cout << "int2 = " << int2 << endl;	
	cout << "pointer1 = " << pointer1 << endl;
	cout << "*pointer1 = " << *pointer1 << endl;
	cout << "pointer2 = " << pointer1 << endl;
	cout << "*pointer2 = " << *pointer1 << endl;
	cout << "&int1 = " << &int1 << endl;
	cout << "&int2 = " << &int2 << endl;
	cout << "&int3 = " << &int3 << endl;
	cout << "*&int1 = " << *&int1 << endl;
	cout << "*&int2 = " << *&int2 << endl << endl;
	pressAnyKey();
	
	// Demo 5:	
	delete pointer1;									// Remove garbage (the 42) from heap. Do before next line.
	pointer1 = &int3;
	cout << "Demo 5:" << endl;
	cout << "*pointer1: " << *pointer1 << endl;			// Random data.
	cout << "*&int3 = " << *&int3 << endl << endl;		// The same random data.
	pressAnyKey();

	// Demo 6:#include "SinglyLinkedList.h"

// This class is based on the definition on page 118
// in our textbook.

// Constructors. Only default constructor is needed for new empty list. 
  SinglyLinkedList::SinglyLinkedList()
	: head(NULL) { }
  

  // Destructor deletes object and code removes garbage.
  SinglyLinkedList::~SinglyLinkedList()
  { 
	  while (!empty()) 
	  {
			removeFront(); 
	  }
  }

  // Is list empty?
  bool SinglyLinkedList::empty() const			
  { 
	  return (head == NULL); 
  }

  // Get front node.
  const Book& SinglyLinkedList::front() const		
  { 
	  return head->book; 
  }

  // Add node to front.
  void SinglyLinkedList::addFront(const Book& e) 
  {	
    Node* temp = new Node;			// Create new node.
    temp->book = e;					// Store data.
    temp->next = head;				// Current head is now next of our new node.
    head = temp;					// Our new node is now the new head.
  }

	// Remove node from front.
   void SinglyLinkedList::removeFront() 
   {
	   if ( !empty() ) 
	   {
			Node* temp = head;				// temp saves the current head.
			head = temp->next;				// Our new head is the old head's next. 
			delete temp;					// Delete the previous head.
	   }
   }

   void SinglyLinkedList#include "SinglyLinkedList.h"

// This class is based on the definition on page 118
// in our textbook.

// Constructors. Only default constructor is needed for new empty list. 
  SinglyLinkedList::SinglyLinkedList()
	: head(NULL) { }
  

  // Destructor deletes object and code removes garbage.
  SinglyLinkedList::~SinglyLinkedList()
  { 
	  while (!empty()) 
	  {
			removeFront(); 
	  }
  }

  // Is list empty?
  bool SinglyLinkedList::empty() const			
  { 
	  return (head == NULL); 
  }

  // Get front node.
  const Book& SinglyLinkedList::front() const		
  { 
	  return head->book; 
  }

  // Add node to front.
  void SinglyLinkedList::addFront(const Book& e) 
  {	
    Node* temp = new Node;			// Create new node.
    temp->book = e;					// Store data.
    temp->next = head;				// Current head is now next of our new node.
    head = temp;					// Our new node is now the new head.
  }

	// Remove node from front.
   void SinglyLinkedList::removeFront() 
   {
	   if ( !empty() ) 
	   {
			Node* temp = head;				// temp saves the current head.
			head = temp->next;				// Our new head is the old head's next. 
			delete temp;					// Delete the previous head.
	   }
   }

   void SinglyLinkedList::displayList() const
   {
	   if ( !empty() )
	   {
		   cout << "The following books are in this list:\n";
		   Node* temp = head;	   
		   while (temp)	// temp evaluates to true if it is not NULL.
		   {
			   cout << temp->book << endl;
			   temp = temp->next;	// Move to the next node, which if it's NULL
		   }						// will cause the loop to terminate.	   
		   cout << endl;
	   }
	   else
	   {
		   cout << "There are no books in this list.\n";
	   }
   }::displayList() const
   {
	   if ( !empty() )
	   {
		   cout << "The following books are in this list:\n";
		   Node* temp = head;	   
		   while (temp)	// temp evaluates to true if it is not NULL.
		   {
			   cout << temp->book << endl;
			   temp = temp->next;	// Move to the next node, which if it's NULL
		   }						// will cause the loop to terminate.	   
		   cout << endl;
	   }
	   else
	   {
		   cout << "There are no books in this list.\n";
	   }
   }
	Car car1 = { "Buick", "Century", 1995, 15678.3 };
	Car *carPointer1 = &car1;
	cout << "The make of car1 is " << car1.make << endl;
	// The member access operator for regular variables is . while -> is the member access operator for pointers.
	cout << "The make of car1 (via carPointer1) is " << carPointer1->make << endl;		// Short form of next line.
	cout << "The make of car1 (via carPointer1) is " << (*carPointer1).make << endl;	// Equivalent to preceding line.
	cout << "Juan is driving the " << car1.make << endl;
	pressAnyKey();

	return 0;	// End program.
}

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl << endl;
	_getch();					// Waits and gets next character entered.		
}
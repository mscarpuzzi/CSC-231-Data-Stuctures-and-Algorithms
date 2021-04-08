/*
Michael Scarpuzzi
09/03/2019
CSC 231

This file is my class implentation for the Cat class defined in Cat.h
*/

#include "Cat.h"		


// Function definitions.	

// Default constructor.
Cat::Cat()		
{					
					
	/*
	title = "";
	author = "";
	year = 0;
			We don't use the above code in order to maintain full control
			over the data in our class. It also greatly simplifies
			the work of testing and debugging.
	*/

	setType("");
	setSize(0);
	setAge(0);
}

// Another constructor. (Overloading)
Cat::Cat(string theType, int theSize, int theAge)
{
	setType(theType);
	setSize(theSize);
	setAge(theAge);
}

// Get and set methods.

string Cat::getType() const	
{								
	return type ;				
}								
								

int Cat::getSize() const
{
	return size;
}

int Cat::getAge() const
{
	return age;
}

void Cat::setType(string theType)
{
	type = theType;
}

void Cat::setSize(int theSize)
{
	size = theSize;
}

// Control data and flag bad data with default value.
void Cat::setAge(int theAge)
{
	if (theAge < 0)
	{
		age = 0;
	}
	else
	{
		age = theAge;
	}
}

// Utility member functions.
void Cat::print()
{
	cout << "Type: " << type << ", Size: "  << size << ", Age: " << age;
}

ostream &operator << (ostream& out, const Cat& theCat)
{
	out << "Type: " << theCat.type << ", Size: "  << theCat.size <<  ", Age: "  << theCat.age;
	return out;
}
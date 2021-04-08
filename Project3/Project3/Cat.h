/*
Michael Scarpuzzi
09/03/2019
CSC 231

This file is my class declaration for the Cat class.
*/
#include <iostream>		// Used for input and output.
#include <string>


using namespace std;

// Preprocessing directives that prevents multiple definitions.
#ifndef Cat_H
#define Cat_H

class Cat
{

	// Declaring friends (friends have access to private data and operations).
	friend ostream &operator << (ostream& out, const Cat& theCat);

	// Member methods (generally public).
public:				// Access modifier = available to other programs.
	// Default constructor.
	Cat();										// Declared but not defined - needs semi-colon.
	// Other constructors.
	Cat(string theType, int theSize, int theAge);

	// Get and set methods or member functions(accessor and mutator functions)
	string getType() const;
	int getSize() const;
	int getAge() const;
	void setType(string theType);
	void setSize(int theSize);
	void setAge(int theAge);

	// Utility member functions.
	void print();

	// Member attributes (generally private).
private:			// Access modifier = not available to other programs.
	string type;
	int size;
	int age;

};	

#endif
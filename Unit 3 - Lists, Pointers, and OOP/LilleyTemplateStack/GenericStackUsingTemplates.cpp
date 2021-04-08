// Use of a stack program that we built in class.
// The stack is built so that it can support native and user defined data types.


#include "stdafx.h"
#include "TemplateStack.h"
//****PLEASE NOTE THE FOLLOWING INCLUDE -- MANY ERRORS WITHOUT
#include "TemplateStack.cpp"


#include <string>

using namespace std;



int main()
{
	TemplateStack<int> myGenericStack;
	
	// Show that the stack is empty.
	cout << "The stack is size: " << myGenericStack.size() << endl;
	if (myGenericStack.isEmpty())
	{
		cout << "The stack is empty!" << endl;
	}
	else
	{
		cout << "The stack is not empty!" << endl;
	}

	// Push an item on the stack.
	myGenericStack.push(9);
	cout << "The stack is size: " << myGenericStack.size() << endl;
	if (myGenericStack.isEmpty())
	{
		cout << "The stack is empty!" << endl;
	}
	else
	{
		cout << "The stack is not empty!" << endl;
	}

	// Push multiple items on the stack.
	myGenericStack.push(0);
	myGenericStack.push(3);

	myGenericStack.push(5);
	myGenericStack.push(7);


	myGenericStack.push(6);
	myGenericStack.push(8);

	// Demonstrate the peek function.
	cout << "The head item is: " << myGenericStack.peek() << endl;
	cout << endl << endl << endl;


	cout << "Jenny?" << endl;

	while (!myGenericStack.isEmpty())
	{
		cout << myGenericStack.pop() << endl;
	}
	if (myGenericStack.isEmpty())
	{
		cout << "The stack is empty!" << endl;
	}
	else
	{
		cout << "The stack is not empty!" << endl;
	}
	
	myGenericStack.~TemplateStack();
	
	cout << endl << endl << endl;

	// Demonstrate the stack working with char type as opposed to integers
	TemplateStack<char> myCharStack;

	myCharStack.push('h');
	myCharStack.push('7');
	myCharStack.push('7');
	myCharStack.push('3');
	myCharStack.push('4');
	myCharStack.push('5');

	cout << "The stack size is: " << myCharStack.size() << endl;

	while (!myCharStack.isEmpty())
	{
		cout << myCharStack.pop() << endl;
	}

	myCharStack.~TemplateStack();

	return 0;
}
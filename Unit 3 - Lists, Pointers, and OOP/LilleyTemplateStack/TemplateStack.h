// Basic stack header file that we created in class.
// This is a "template" stack as opposed to the stack of integers that we created.

#pragma once
#include <iostream>

using namespace std;

#ifndef TemplateStack_h
#define TemplateStack_h

//*********See template code line below*********
// This is different than the class definition for the basic stack of integers
template <class ElemClass> 
class TemplateStack
{
public:
	//***Constructor - used as TemplateStack<DataType> VariableName
	TemplateStack();

	//***Destructor - Deallocate the heap storage
	~TemplateStack();

	//Returns the number of elements in the stack
	int size();

	//Returns true if the stack is empty and false if the stack has 1 or more elements
	bool isEmpty();

	//Removes all elements from the stack
	void clear();

	//***Note the parameter here - it is of type ElemClass - Generic
	void push(ElemClass elem);

	//***Note the return value type here - ElemClass - Generic
	ElemClass pop();

	//***Note the return value type here - ElemClass - Generic
	ElemClass peek();


private:
	//***Note the struct block - generic with ElemClass
	struct GenericNode
	{
		ElemClass NodeData;
		GenericNode* Next;
	};

	int iCount;
	GenericNode* GenericStack;

};



#endif
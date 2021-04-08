// This is a template stack cpp file that includes the TemplateStack.h file.
// This is the template stack that we created in class.
#include "stdafx.h"
#include "TemplateStack.h"

//***Note the template code here to make the constructor generic
template <class ElemClass> 
TemplateStack<ElemClass>::TemplateStack()
{
	iCount = 0;
	GenericStack = NULL;
}

//***Note the template code here to make the destructor generic
template <class ElemClass>
TemplateStack<ElemClass>::~TemplateStack()
{
	clear();
}

//***Note the template code here to make the function call generic
template <class ElemClass>
int TemplateStack<ElemClass>::size()
{
	return iCount;
}

//***Note the template code here to make the function call generic
template <class ElemClass>
bool TemplateStack<ElemClass>::isEmpty()
{
	return iCount == 0;
}

//***Note the template code here to make the procedure call generic
template <class ElemClass>
void TemplateStack<ElemClass>::clear()
{
	while (iCount > 0)
	{
		pop();	// Since pop decrements iCount we don't need to here.
	}
}

//***Note the template code here to make the procedure call generic
template <class ElemClass>
void TemplateStack<ElemClass>::push(ElemClass elem)
{
// create a new node and add to the head of the list
	GenericNode* TempNode = new GenericNode;
	TempNode->NodeData = elem;
	TempNode->Next = GenericStack;
	GenericStack = TempNode;
	iCount++;
}

//***Note the template code here to make the function call generic
template <class ElemClass>
ElemClass TemplateStack<ElemClass>::pop()
{
	//return the element data value from the head of the list.
	//reset the head to the next item in the list.
	//delete the popped off node.
	if (!isEmpty())
	{
		GenericNode* TempNode = GenericStack;
		ElemClass ReturnValue = TempNode->NodeData;
		GenericStack = GenericStack->Next;
		iCount--;
		delete TempNode;
		return ReturnValue;
	}
}

//***Note the template code here to make the function call generic
template <class ElemClass>
ElemClass TemplateStack<ElemClass>::peek()
{
	if (!isEmpty())
	{
		return GenericStack->NodeData;
	}
}

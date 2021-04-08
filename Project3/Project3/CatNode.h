/*
Michael Scarpuzzi
09/03/2019
CSC 231

This file is my class declaration for the CatNode class with access to Cat.h. 
*/
#include "Cat.h"

#ifndef CatNode_H
#define CatNode_H
class CatNode					
{
private:
	CatNode* next;
	CatNode* prev; 
	Cat cat;

	
	// Access is provided by friend declaration.
	friend class CatList;
};
#endif
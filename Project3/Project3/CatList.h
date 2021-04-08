/*
Michael Scarpuzzi
09/03/2019
CSC 231

This file is my class declaration for the CatList class
*/

#include "CatNode.h"
#ifndef CatList_H
#define CatList_H
class CatList
{

public:
	CatList();				// Empty list constructor.
	~CatList();			// Destructor.
	bool empty() const;				// Is list empty?
	const Cat& front() const;		// Get front element in list
	const Cat& back() const;
    void removeBack();
	void addFront(const Cat& e);	// Add to front of list
	void addBack(const Cat& e);	
	void removeFront();
	void removeFrom(string type, int size, int age);
	void displayList() const;
	void searchList(string type, int size, int age);// Display list of cats
	void edit(string type, int size, int age);
private:
	CatNode* head;
	CatNode* tail;
};
#endif

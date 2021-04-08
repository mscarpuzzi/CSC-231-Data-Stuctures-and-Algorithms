/*
Michael Scarpuzzi
10/29/2019
CSC 231

This file is my class implentation for the Tree class defined in glossaryTree.h
*/

#include <iostream>
#include <fstream>
#include <queue> //for push();
#include "glossaryTree.h"



using namespace std;



glossaryTree::glossaryTree() //Default constructor
{
	root = NULL;
}

glossaryTree::~glossaryTree() //Destructor

{
	postOrderDeletion(root);
}

void glossaryTree::postOrderDeletion(treeNode* node)
{
	if (node)
	{
		postOrderDeletion(node->left);
		postOrderDeletion(node->right);
		delete node;
	}
}

void glossaryTree::addNode(string theTerm, string theDefinition)
{
	if (isEmpty())
	{
		treeNode* node = new treeNode();
		node->term = theTerm;
		node->definition = theDefinition;
		root = node;
	}
	else
	{
		addNode(theTerm, theDefinition, root);
	}
}


void glossaryTree::addNode(string theTerm, string theDefinition, treeNode* node)
{
	if (theTerm <= node->term)
	{
		if (node->left)
		{
			addNode(theTerm, theDefinition, node->left);
		}
		else
		{
			treeNode* newNode = new treeNode();
			newNode->term = theTerm;
			newNode->definition = theDefinition;
			node->left = newNode;
		}
	}
	else
	{
		if (node->right)
		{
			addNode(theTerm, theDefinition, node->right);
		}
		else
		{
			treeNode* newNode = new treeNode();
			newNode->term = theTerm;
			newNode->definition = theDefinition;
			node->right = newNode;
		}
	}
}

void glossaryTree::levelOrder(treeNode* node)
{
	queue<treeNode*> termQueue;

	termQueue.push(node);

	while (!termQueue.empty())
	{
		treeNode* visitNode = termQueue.front();
		termQueue.pop();

		cout << visitNode->term << endl;

		if (visitNode->left)
		{
			termQueue.push(visitNode->left);
		}

		if (visitNode->right)
		{
			termQueue.push(visitNode->right);
		}
	}
}

void glossaryTree::preOrder(treeNode* node)
{
	if (node)
	{
		std::cout << node->term << endl;
		preOrder(node->left);
		preOrder(node->right);
	}
}

void glossaryTree::inOrder(treeNode* node)
{
	if (node)
	{
		inOrder(node->left);
		cout << node->term << endl;
		inOrder(node->right);
	}
}

void glossaryTree::postOrder(treeNode* node)
{
	if (node)
	{
		postOrder(node->left);
		postOrder(node->right);
		cout << node->term << endl;
	}
}

void glossaryTree::inOrderTreeDisplay(treeNode *node)
{
	if (node)
	{
		inOrderTreeDisplay(node->left);
		cout << node->term << ": " << node->definition << endl;
		if (node->left)
		{
			cout << " : left child -> " << node->left->term;
		}
		if (node->right)
		{
			cout << " : rightchild -> " << node -> right->term;
		}
		cout << endl;
		inOrderTreeDisplay(node->right);
	}
}

void glossaryTree::deleteNode(treeNode* node, string theTerm)
{
	if (!node)
	{
		cout << "The tree is empty." << endl;
	}
	else
	{
		treeNode* current = node, *parent = NULL;
		bool found = false;
		while ((current) && (!found))
		{
			if (current->term == theTerm)
			{
				found = true;
			}
			else
			{
				parent = current;
				if (theTerm > (current->term))
				{
					current = current->right;
				}
				else
				{
					current = current->left;
				}
			}
		}
		if (!found)
		{
			cout << theTerm << " is not in the tree." << endl;
		}
		else if ((!current->left) && (!current->right))
		{
			if ((parent) && (parent->left == current))
			{
				parent->left = NULL;
			}
			else if (parent)
			{
				parent->right = NULL;
			}
			delete current;
		}
		else if (((current->left) && (!current->right)) || ((!current->left) && (current->right)))
		{
			treeNode* child;
			if (current->left)
			{
				child = current->left;
			}
			else
			{
				child = current->right;
			}
			if (parent->left == current)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
			delete current;
		}
		
	}
}

void glossaryTree::searchNode(treeNode* node, string theTerm) //Searches for a node in the tree by the term included.
{
	if (!node)
	{
		cout << "Cannot find node." << endl;
	}
	else
	{
		treeNode* current = node, *parent = NULL;
		bool found = false;
		while ((current) && (!found))
		{
			if (current->term == theTerm)
			{
				found = true;
			}
			else
			{
				parent = current;
				if (theTerm > (current->term))
				{
					current = current->right;
				}
				else
				{
					current = current->left;
				}
			}
		}
		if (!found)
		{
			cout << theTerm <<  " is not in the tree. Was the term capitalize?" << endl;
		}
		else
		{
			cout << theTerm << " was found! Definition: " << current->definition << endl;
		}
	}
}

bool glossaryTree::nodeSearch(treeNode* node, string theTerm) //Checks to see if a node exists
{
	if (node == NULL)
	{
		return false;
	}
	else if (node->term == theTerm)
	{
		return true;
	}
	else if (theTerm <= node->term)
	{
		return nodeSearch(node->left, theTerm);
	}
	else
	{
		return nodeSearch(node->right, theTerm);
	}
}


void glossaryTree::stringSearch(treeNode* node, string theString) //Searches for a string within the Term and Definition of a node. If found, it displays them.
{
	if (node)
	{
		stringSearch(node->left, theString);
		if ((node->term.find(theString) <= 1000) || (node->definition.find(theString) <= 1000)) 
		{
			cout << node->term << endl;
			cout << node->definition << endl << endl;
		}
		stringSearch(node->right, theString);
	}
}

void glossaryTree::preOrderFlashcards(treeNode* node) //Flashcard function with preorder traversal.
{
	if (node)
	{
		string input;

		cout << node->term << endl << endl;
		cout << "\nPress any key to see the definition." << endl << endl;
		cout << node->definition << endl << endl;
		cout << "Press e (followed by enter) to exit or any of other key (followed by enter) to continue." << endl;

		cin >> input;

		if (input == "e")
		{
			return;
		}
		else if (input != "e")
		{
			preOrderFlashcards(node->left);
			preOrderFlashcards(node->right);
		}
	}
}

void glossaryTree::postOrderFlashcards(treeNode* node) //Flashcards with post order traversal.
{
	if (node)
	{

		postOrderFlashcards(node->left);
		postOrderFlashcards(node->right);
		cout << node->term << endl << endl;
		cout << "\nPress any key to see the definition." << endl << endl;
		cout << node->definition << endl << endl;

	}
}

void glossaryTree::inOrderFlashcards(treeNode* node) //Flash cards with in order traversal.
{
	string input;

	if (input == "e")
	{
		return;
	}
	else if (input != "e")
	{
		postOrderFlashcards(node->left);
	}
	cout << node->term << endl << endl;
	cout << "\nPress any key to see the definition." << endl << endl;
	cout << node->definition << endl << endl;
	cout << "Press e (followed by enter) to exit or any of other key (followed by enter) to continue." << endl;

	cin >> input;

	if (input != "e")
	{
		postOrderFlashcards(node->right);
	}
}

void glossaryTree::levelOrderFlashcards(treeNode* node) //Flash cards with level order traversal.
{
	queue<treeNode*> termQueue;

	termQueue.push(node);

	while (!termQueue.empty())
	{
		treeNode* visitNode = termQueue.front();
		termQueue.pop();

		cout << visitNode->term << endl << endl;
		cout << "\nPress any key to see the definition." << endl << endl;
		cout << visitNode->definition << endl << endl;


		if (visitNode->left)
		{
			termQueue.push(visitNode->left);
		}

		if (visitNode->right)
		{
			termQueue.push(visitNode->right);
		}
	}
}

void glossaryTree::writeToText(treeNode* node, ofstream &treeTextFile) //A save function for the file.
{
	if (node)
	{

		if (!treeTextFile)
		{
			cerr << "File is not here." << endl;
			exit(1);
		}
		else
		{
			treeTextFile << node->term << '\t'
				<< node->definition << '\n';
			writeToText(node->left, treeTextFile);
			writeToText(node->right, treeTextFile);
		}


	}
}
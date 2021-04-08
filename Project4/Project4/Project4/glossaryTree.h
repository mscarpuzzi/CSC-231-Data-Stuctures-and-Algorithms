/*
Michael Scarpuzzi
10/29/2019
CSC 231

This file is my class declaration for the glossaryTree class.
*/
#include <string>
#include "treeNode.h"


using namespace std;

class glossaryTree
{
	treeNode* root;
public:
	glossaryTree();
	~glossaryTree();
	treeNode* getRoot() { return root; } //Returns the root pointer.
	bool isEmpty() { return (root == NULL); } //Checks to see if there is anything in the tree.
	void addNode(string theTerm, string theDefinition);
	void deleteNode(treeNode* node, string theTerm);
	void searchNode(treeNode* node, string theTerm);
	bool nodeSearch(treeNode* node, string theTerm);
	void stringSearch(treeNode* node, string theString);
	void writeToText(treeNode* node, ofstream &treeTextFile);
	//Basic traversals of the tree.
	void levelOrder(treeNode* node);
	void inOrder(treeNode* node);
	void postOrder(treeNode* node);
	void preOrder(treeNode* node);
	void preOrder() { preOrder(root); }

	//Flashcards...
	void levelOrderFlashcards(treeNode* node);
	void inOrderFlashcards(treeNode* node);
	void postOrderFlashcards(treeNode* node);
	void preOrderFlashcards(treeNode* node);

	void inOrderTreeDisplay(treeNode *node);

private:
	void addNode(string theTerm, string theDefinition, treeNode* node);
	void postOrderDeletion(treeNode* node);
};

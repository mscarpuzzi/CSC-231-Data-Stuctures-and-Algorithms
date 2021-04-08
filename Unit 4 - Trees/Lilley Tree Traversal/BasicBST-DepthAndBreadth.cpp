// BasicBST-DepthAndBreadth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <queue>	//Using built in queue as opposed to one that we have built - Push and Pop vs. Enqueue and Dequeue
#include <string>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	char data;
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in tree
BstNode* GetNewNode(char data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root, char data) {
	if (root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is less than root, insert in left subtree. 
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

//To search an element in BST, returns true if element is found
bool Search(BstNode* root, char data) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
	}
	else if (data < root->data) {
		return Search(root->left, data);
	}
	else {
		return Search(root->right, data);
	}
}

//PreOrder prints the root first then the left child then the right child
void PreOrder(BstNode* rootPtr)
{
	if (rootPtr != NULL)
	{
		cout << rootPtr->data << " ";
		PreOrder(rootPtr->left);
		PreOrder(rootPtr->right);
	}
}

//InOrder prints the left child first then the root then the right child
void InOrder(BstNode* rootPtr)
{
	if (rootPtr != NULL)
	{
		InOrder(rootPtr->left);
		cout << rootPtr->data << " ";
		InOrder(rootPtr->right);
	}
}

//PostOrder prints the left child first then the right child then the root
void PostOrder(BstNode* rootPtr)
{
	if (rootPtr != NULL)
	{
		PostOrder(rootPtr->left);
		PostOrder(rootPtr->right);
		cout << rootPtr->data << " ";
	}
}

//LevelOrder is a breadth first print as opposed to depth first. It prints the 
//BST from top to bottom and from left to right 
void LevelOrder(BstNode* rootPtr)
{
	if (rootPtr != NULL)
	{
		queue<BstNode*> qLevel;	//Use a queue to traverse the tree breadth first
		qLevel.push(rootPtr);	//Push is Enqueue with standard C++ queue
		while (!qLevel.empty())
		{
			BstNode* tmpPtr = qLevel.front();
			cout << tmpPtr->data << " ";
			if (tmpPtr->left != NULL)
			{
				qLevel.push(tmpPtr->left);	//Push is enqueue
			}
			if (tmpPtr->right != NULL)
			{
				qLevel.push(tmpPtr->right);	//Push is enqueue
			}
			qLevel.pop();	//Pop is dequeue (remove front)
		}
	}

}

int main() {
	BstNode* root = NULL;  // Creating an empty tree
						   //Code to test the logic
	root = Insert(root, 'F');
	root = Insert(root, 'D');
	root = Insert(root, 'B');
	root = Insert(root, 'E');
	root = Insert(root, 'A');
	root = Insert(root, 'C');
	root = Insert(root, 'J');
	root = Insert(root, 'G');
	root = Insert(root, 'K');
	root = Insert(root, 'I');
	root = Insert(root, 'H');


	// Ask user to enter a number.
	char chLookup;
	cout << "Enter upper case character to be searched\n";
	cin >> chLookup;
	//If character is found, print "FOUND"
	if (Search(root, chLookup) == true) cout << "Found\n";
	else cout << "Not Found\n";


	//Depth First - Preorder - root first then left child then right child
	cout << endl << "PreOrder: ";
	PreOrder(root);

	//Depth First - Inorder	- left child first then root then right child
	cout << endl << "In Order: ";
	InOrder(root);

	//Depth First - Postorder - left child first then right child then root
	cout << endl << "PostOrder: ";
	PostOrder(root);

	//Breadth First - Level Order - left to right, top to bottom, uses a queue
	cout << endl << "Level Order: ";
	LevelOrder(root);

	cout << endl;


}


/*
Michael Scarpuzzi
10/29/2019
CSC 231

This file is my class declaration for the treeNode class.
*/
#include <string>

using namespace std;
class treeNode
{
private:

	string term;
	string definition;
	treeNode* left;
	treeNode* right;

	friend class glossaryTree;
public:
	treeNode() { term = "~"; definition = "~"; left = right = NULL; }; //inline function
};

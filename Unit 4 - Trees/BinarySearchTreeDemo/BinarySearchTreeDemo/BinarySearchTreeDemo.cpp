// Basic demo for binary search tree. 

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Node class.
class Node
{
	string letterData;	// In this demo, the key and the data are the same for simplicity. Single letters are used.
	Node* left;			// The left and right children of the node.
	Node* right;
	friend class Tree;
public:
	Node() { letterData = "~"; left = right = NULL; };		// Inline function.
};

// Tree class
class Tree
{
	Node* root;									// The root of the tree.
public:
	Tree();										// Default constructor.
	~Tree();									// Destructor.
	// Basic public tree operations.
	Node* getRoot() { return root; };			// Another inline function.
	bool isEmpty() { return (root == NULL); }
	void addNode(string theLetterData);			// Add a node. A helper function.
	void deleteNode(Node* node, string theLetterData);	// Delete a node from tree.
	// Basic traversals.
	void levelOrder(Node* node);
	void inorder(Node* node);
	void postorder(Node* node);
	void preorder(Node* node);
	void preorder() { preorder(root); }			// Another helper function. Similar helper functions could be defined for all the above traversals.
	// Other utility functions.
	void inOrderTreeDisplay();					// Another helper function for this display.
	void inOrderTreeDisplay(Node *node);
	Node* findNode(string theLetterData);
	Node* findParent(string theLetterData);
	Node* findMin(Node* node);

private:
	void addNode(string theLetterData, Node* node);		// Add node recursively.
	void postOrderDeletion(Node* node);					// Traversal that deletes nodes of tree, 
														// one leaf at a time until empty.
};

// Constructor
Tree::Tree()
{
	root = NULL;
}

// Destructor.
Tree::~Tree()
{
	postOrderDeletion(root);
}

// Delete the tree, one leaf node at a time until at last the root leaf is deleted. 
void Tree::postOrderDeletion(Node* node)	// This is a post order traversal where the visit is a deletion of the node.
{
	if (node)
	{
		postOrderDeletion(node->left);		// Traverse left.
		postOrderDeletion(node->right);		// Traverse right.
		delete node;						// Visit node (delete it).
	}
}

// Add a node. This is also a helper function for the other addNode function that takes a node parameter.
void Tree::addNode(string theLetterData)
{
	// If tree has no elements. Add to the root position.
	if (isEmpty())
	{
		std::cout << "Add root node ... " << theLetterData << endl;
		Node* node = new Node();				// Create new node to be added.
		node->letterData = theLetterData;		// Place data in new node.
		root = node;							// Set new node as the root of the tree.
	}
	else // Otherwise traverse to the next correct position in tree.
	{
		std::cout << "Add new node ... " << theLetterData << endl;
		addNode(theLetterData, root);
	}
}

// Add a node using recursion.
void Tree::addNode(string theLetterData, Node* node)
{

	if (theLetterData <= node->letterData) // If the key is less than the node key, recursively go left.
	{
		if (node->left)	// Keep searching recursively until empty node position.
		{
			addNode(theLetterData, node->left);
		}
		else							// Add node into empty correct position.
		{
			Node* newNode = new Node();	// Create node.
			newNode->letterData = theLetterData;		// Update the data part with the data to be added.
			node->left = newNode;		// Connect the node to its parent.
		}
	}
	else
	{
		if (node->right)	// Keep searching recursively until empty node position.
		{
			addNode(theLetterData, node->right);
		}
		else						// Add node into empty correct position.
		{
			Node* newNode = new Node();	// Create node, set data, and connect node to tree.
			newNode->letterData = theLetterData;
			node->right = newNode;
		}
	}
}

// Level-order traversal assisted by queue.
void Tree::levelOrder(Node* node)
{
	// Create a queue of node pointers.
	queue<Node*> bookQueue;

	// Enqueue the root of tree/subtree to be traversed. Primes the queue for use in following loop.
	bookQueue.push(node);

	while (!bookQueue.empty())	// Keep traversing until queue is empty.
	{
		// Get front node of queue and remove it from queue.
		Node* visitNode = bookQueue.front();
		bookQueue.pop();

		std::cout << visitNode->letterData << endl;		// The visit: display.

														// Enqueue the visited node's left child if it exists.
		if (visitNode->left)
		{
			bookQueue.push(visitNode->left);
		}

		// Enqueue the visited node's right child if it exists.
		if (visitNode->right)
		{
			bookQueue.push(visitNode->right);
		}
	}
}

// Classic recursive traversals: pre-order, post-order, and in-order.

void Tree::preorder(Node* node)
{
	if (node)									// If node exists ...
	{
		std::cout << node->letterData << endl;		// Visit.
		preorder(node->left);					// Traverse left.
		preorder(node->right);					// Traverse right.
	}
}

void Tree::inorder(Node* node)
{
	if (node)
	{
		inorder(node->left);					// Traverse left.
		std::cout << node->letterData << endl;		// Visit.
		inorder(node->right);					// Traverse right.
	}
}

void Tree::postorder(Node* node)
{
	if (node)
	{
		postorder(node->left);					// Recursively traverse left.
		postorder(node->right);					// Recursively traverse right.
		std::cout << node->letterData << endl;  // Visit: display.
	}
}


// Function to find minimum element in a sub-tree.
Node* Tree::findMin(Node* node)
{
	while (node->left)
	{
		node = node->left;
	}
	return node;
}

void Tree::inOrderTreeDisplay()
{
	if (!isEmpty())
	{
		inOrderTreeDisplay(getRoot());
	}
	else
	{
		std::cout << "The data set is empty.\n";
	}
}

void Tree::inOrderTreeDisplay(Node *node)
{
	if (node)
	{
		inOrderTreeDisplay(node->left);		// Recurse left.

		// Visit: display node and children.
		std::cout << node->letterData;
		if (node == root)	// If the node is the root, identify it as the root.
		{
			std::cout << "(root)";
		}
		if (node->left)
		{
			std::cout << ": left child-> " << node->left->letterData;
		}
		if (node->right)
		{
			std::cout << "  right child-> " << node->right->letterData;
		}
		std::cout << endl;

		inOrderTreeDisplay(node->right);	// Recurse right.
	}
}

Node* Tree::findNode(string theLetterData)
{
	// Beginning at the root, try to find the node. If found, return it.
	Node* current = root;
	while (current)
	{
		if (current->letterData == theLetterData)		// If the data is found, return the found node.
		{
			return current; 
		}
		else
		{
			if (theLetterData > (current->letterData))
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}
	}
	return NULL;		// Return null if the node is not found.
}

Node* Tree::findParent(string theLetterData)
{
	// Beginning at the root, try to find the node. If found, return it.
	Node* current = root;
	while ((current) && ((current->left) || (current->right)))
	{
		if (((current->left) && (current->left->letterData == theLetterData))		// If the data is found, return the found node.
			|| ((current->right) && (current->right->letterData == theLetterData)))
		{
			return current;
		}
		else
		{
			if (theLetterData > (current->letterData))
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}
	}
	return NULL;
}

// Delete the node that matches the passed letter data in the parameter node's subtree.
void Tree::deleteNode(Node* node, string theLetterData)
{
	// Unfound case 1: There are no nodes to be searched. 
	if (!node)
	{
		std::cout << "The data \"" << theLetterData << "\" was not found (because the data set is empty).\n";
	}
	else
	{
		// Try to find the node to be deleted and if it exists, the parent of the node as well.	
		Node* current = findNode(theLetterData);
		Node* parent = findParent(theLetterData);

		// Unfound case 2: The item was not found, provide message and exit function.
		if (!current)
		{
			std::cout << theLetterData << " not in the data set (the tree)." << endl;
		}
		// Found case 1: The node found is a leaf node
		else if ((!current->left) && (!current->right))
		{
			if ((parent) && (parent->left == current))	// If current is not the root, and current is the left child ...
			{
				parent->left = NULL;					// ... null the parent link.
			}
			else if (parent)							// Or if current is not the root, and current is the right child ...
			{
				parent->right = NULL;					// ... null the parent link.
			}
			else if (current == root)					// Or if the current is the root, then null the root. 
			{
				root = NULL;							// The tree's root must be set to NULL because the tree is now empty.
			}
			delete current;								// Deallocate/delete the found node.
			std::cout << "\"" << theLetterData << "\" has been removed from the Tree." << endl;
		}
		// Found case 2: The node found has a single child.
		else if (((current->left) && (!current->right)) || ((!current->left) && (current->right)))
		{
			Node* child;
			if (current->left)					// Get lone child node of the node to be deleted.
			{
				child = current->left;
			}
			else
			{
				child = current->right;
			}
			if (current == root)				// Current is the root and thus has no parent.
			{
				root = child;					// The current node to be deleted is the root so we need to make the 
			}									// root's lone child the new root.
			else if (parent->left == current)	// There is a parent and so attach child node to parent node.
			{
				parent->left = child;
			}
			else if (parent)					// Or if there is a parent whose
			{
				parent->right = child;
			}
			delete current;						// Deallocate/delete the found node.
			std::cout << "\"" << theLetterData << "\" has been removed from the Tree." << endl;
		}
		// Found case 3: Node has two children (final possibility).		
		else	// Over-write the data (practically speaking delete) with appropriate data.
		{
			Node *minRight = findMin(current->right);				// Get the minimum value from the right sub-tree
			string tempLetterData = minRight->letterData;			// Save the minRight value.
			deleteNode(current->right, minRight->letterData);		// Delete the minRight node.
			current->letterData = tempLetterData;					// Over-write minRight's original data into the node that has been "deleted."
			std::cout << "\"" << theLetterData << "\" has been over-written (deleted).\n";	// Display removal message of node to be deleted.
			std::cout << "A copy of \"" << tempLetterData << "\" was put in the place of \"" << theLetterData << "\".\n";
		}																// used for the copy value from the tree.
	} // End else - there are nodes to be searched and processed.
}


// Test main program
int main()
{
	Tree tree = Tree();		// Create tree and add nodes.
	tree.addNode("M");
	tree.addNode("E");
	tree.addNode("S");
	tree.addNode("J");
	tree.addNode("P");
	tree.addNode("B");
	tree.addNode("A");
	tree.addNode("W");
	tree.addNode("H");
	tree.addNode("Z");

	// Show traversals.

	cout << "\nLevel order traversal" << endl;
	tree.levelOrder(tree.getRoot());
	cout << endl;
	system("pause");

	cout << "\nPre order traversal" << endl;
	tree.preorder();
	cout << endl;
	system("pause");

	cout << "\nIn order traversal" << endl;
	tree.inorder(tree.getRoot());
	cout << endl;
	system("pause");

	cout << "\nPost order traversal" << endl;
	tree.postorder(tree.getRoot());
	cout << endl;
	system("pause");

	// Test deletion cases:

	cout << "Show tree:\n\n";
	tree.inOrderTreeDisplay();	// Show current tree for comparison.

	cout << "\nDeleting \"H\" - leaf:\n\n";
	tree.deleteNode(tree.getRoot(), "H");		// Test deleting a leaf.	
	tree.inOrderTreeDisplay();
	system("pause");

	cout << "\nDeleting \"B\" - node with left child only:\n\n";
	tree.deleteNode(tree.getRoot(), "B");		// Test deleting a node with only a left child.
	tree.inOrderTreeDisplay();
	system("pause");

	cout << "\nDeleting \"W\" - node with right child only:\n\n";
	tree.deleteNode(tree.getRoot(), "W");		// Test deleting a right child.
	tree.inOrderTreeDisplay();
	system("pause");

	cout << "\nDeleting \"M\" - node/root with two children\n\n";
	tree.deleteNode(tree.getRoot(), "M");		// Test delete a node with two children.
	tree.inOrderTreeDisplay();
	system("pause");

	cout << "\nDeleting \"P\" - root with two children\n\n";
	tree.deleteNode(tree.getRoot(), "P");		// Test delete a root with two children.
	tree.inOrderTreeDisplay();
	system("pause");

	cout << "\nDeleting \"Q\" - non-existent node from non-empty tree\n\n";
	tree.deleteNode(tree.getRoot(), "Q");		// Test delete a root with two children.
	tree.inOrderTreeDisplay();
	system("pause");

	cout << "\nDeleting \"E\" - node with two children\n\n";
	tree.deleteNode(tree.getRoot(), "E");		
	tree.inOrderTreeDisplay();
	system("pause");
	
	cout << "\nDeleting \"J\" - node with one child\n\n";
	tree.deleteNode(tree.getRoot(), "J");
	tree.inOrderTreeDisplay();
	system("pause");

	cout << "\nDeleting \"A\" - node with no children\n\n";
	tree.deleteNode(tree.getRoot(), "A");
	tree.inOrderTreeDisplay();
	system("pause");

	cout << "\nDeleting \"S\" - root with one child\n\n";
	tree.deleteNode(tree.getRoot(), "S");		// Test delete a root with one child.
	tree.inOrderTreeDisplay();
	system("pause");

	cout << "\nDeleting \"Z\" - root with no children\n\n";
	tree.deleteNode(tree.getRoot(), "Z");		// Test delete a root with no children.
	tree.inOrderTreeDisplay();
	system("pause");

	cout << "\nDeleting \"Q\" - non-existent node from empty tree\n\n";
	tree.deleteNode(tree.getRoot(), "Q");		// Test delete a root with two children.
	tree.inOrderTreeDisplay();
	system("pause");
}
/*
Michael Scarpuzzi
10/29/2019
CSC 231

This file is my driver for the glossaryTree.cpp

***The project NEEDS revision***
*/

#include <iostream>
#include <string>
#include <fstream>
#include "glossaryTree.h"

using namespace std;

glossaryTree tree = glossaryTree();


void pressAnyKey()
{
	cout << "\nPress any key to continue" << endl;
	
}

void readTermsFile()
{
	ifstream termsFile("Terms.txt", ios::in);
	string theWord, theDefinition;

	if (!termsFile)
	{
		cerr << "Incorrect file type!" << endl;
		exit(1);
	}

	while (!termsFile.eof())
	{
		getline(termsFile, theWord, '\t');
		getline(termsFile, theDefinition, '\n');
		tree.addNode(theWord, theDefinition);
	}
}

void writeTermsFile()
{
	ofstream treeTextFile("Terms.txt", ios::out);

	tree.writeToText(tree.getRoot(), treeTextFile);

}

int menuDisplay()
{
	int userChoice; //to store the users choice from the menu.

	//Menu display information
	cout << "SELECT FROM THE FOLLOWING\n";
	cout << "1: Add a term and it's meaning.\n";
	cout << "2: Edit a term.\n";
	cout << "3: Find and display a term.\n";
	cout << "4: View all the terms in a list.\n";
	cout << "5: Show flashcards.\n";
	cout << "6: Delete a term.\n";
	cout << "7: Search for text within a term or it's definition.\n";
	cout << "8: Exit the program.\n";
	cout << endl;
	cout << "Please enter a selection: ";

	cin >> userChoice;
	return userChoice;
}

void addTerm()
{
	string theTerm, theDefinition;
	cout << "Please enter a term to add: " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, theTerm);
	cout << "Enter the definition for that term: " << endl;
	getline(cin, theDefinition);
	
	tree.addNode(theTerm, theDefinition);

	cout << "Term was added!" << endl;
}

void editTerm()
{

	string theTerm, tempTerm, tempDefinition;
	bool found;

	cout << "Enter the term to be modified: " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, theTerm);
	found = tree.nodeSearch(tree.getRoot(), theTerm);
	if (found)
	{
		tree.deleteNode(tree.getRoot(), theTerm);

		cout << "Enter the new term: " << endl;
		getline(cin, tempTerm);

		cout << "Enter the new definition for that term: " << endl;
		getline(cin, tempDefinition);

		tree.addNode(tempTerm, tempDefinition);

		cout << "Term was edited!" << endl;
	}
	else
	{
		cout << "Error: There is no such term!" << endl;
	}
}

void displayTerm()
{
	string theTerm;
	cout << "Enter a term to have it's definition displayed: " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, theTerm);
	tree.searchNode(tree.getRoot(), theTerm);
}

void listAllTerms()
{
	tree.inOrder(tree.getRoot());
}

void flashcards()
{
	int choice;

	//Menu display for the various traversals available.
	cout << "Choose a type of traversal to view the flashcards in:" << endl;
	cout << "1. PreOrder Traversal" << endl;
	cout << "2. InOrder Traversal" << endl;
	cout << "3. PostOrder Traversal" << endl;
	cout << "4. LevelOrder Traversal" << endl;

	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		tree.preOrderFlashcards(tree.getRoot());
		break;
	}
	case 2:
	{
		tree.inOrderFlashcards(tree.getRoot());
		break;
	}
	case 3:
	{
		tree.postOrderFlashcards(tree.getRoot());
		break;
	}
	case 4:
	{
		tree.levelOrderFlashcards(tree.getRoot());
		break;
	}
	default:
		cout << "I'm sorry, but that is not a valid selection. It must be 1 through 4." << endl;
		break;
	}
}

void deleteTerm()
{
	string theTerm;
	cout << "Enter a term to be deleted: " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, theTerm);
	if (tree.nodeSearch(tree.getRoot(), theTerm) == true)
	{
		cout << "Term was deleted!" << endl;
	}
	tree.deleteNode(tree.getRoot(), theTerm);

}

void stringSearch()
{
	string theString;
	cout << "Enter what you wish to search for: " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, theString);

	tree.stringSearch(tree.getRoot(), theString);
}

int main() 
{
	tree.addNode("six", "6");
	tree.addNode("two", "2");
	tree.addNode("four", "4");
	tree.addNode("one", "1");
	tree.addNode("five", "5");
	tree.addNode("three", "3");
	tree.addNode("seven", "7");
	//Declare variables
	int userChoice;
	bool running = true;

	readTermsFile();
	while (running) {
		userChoice = menuDisplay();
		switch (userChoice) {
		case 1: //Add a term and it's meaning.
		{
			cout << "/Adding a term/" << endl;
			addTerm();
			pressAnyKey();
			break;
		}
		case 2: //Edit a term.
		{
			cout << "/Editing a term/" << endl;
			editTerm();
			pressAnyKey();
			break;
		}
		case 3: //Find and display a term and it's definition.
		{
			cout << "/Viewing a term/" << endl;
			displayTerm();
			pressAnyKey();
			break;
		}
		case 4: //View all terms in a list.
		{
			cout << "/Viewing all terms/" << endl;
			listAllTerms();
			pressAnyKey();
			break;
		}
		case 5: //Show flashcards.
		{
			//cout << "Showing Flashcards.";
			flashcards();
			pressAnyKey();
			break;
		}
		case 6: //Delete a term.
		{
			//cout << "Deleting a term.";
			deleteTerm();
			pressAnyKey();
			break;
		}
		case 7: // Show all entries containing a search string.
		{
			cout << "/Searching for a string/" << endl;
			stringSearch();
			pressAnyKey();
			break;
		}
		case 8: //Exit.
		{
			cout << "Exiting.";
			writeTermsFile();
			running = false;
			break;
		}
		userChoice = NULL;
		}
	}
}
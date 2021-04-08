#include <iostream>		// Used for input and output.
#include <conio.h>		// Used for getch().
#include <string>		// String library.

using namespace std;

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl;
	_getch();					// Waits and gets next character entered.	
}

int main()
{
	string bookTitle[] = { "Today is Really Yesterday", "Oranges are Just Oranges", "The Ancients are Really Young" };
	string searchString = "Real";

	// The find function returns the integer index of the first occurance of "is" in each bookTitle.
	string output = "";
	for (int i = 0; i < 3; i++)
	{
		if (bookTitle[i].find(searchString) != string::npos) // Find returns npos (an integer constant) 
		{													 // if the search string is not found.
			output += "\"" + searchString + "\" is found in " + bookTitle[i] + "\n";		
		}
		else
		{
			output += "\"" + searchString + "\" is not found in " + bookTitle[i] + "\n";
		}
	}
	cout << output << endl;				

	pressAnyKey();

	return 0;
}
/*
This program demonstrates simple recursion.
1. A recursive function is a function which calls itself.
2. The recursive call must be place in a condition that is not always true. 
3. Each recursive call must contribute to the completion of the task.
4. A recursive function must have an exit condition and base case which completes the task.
*/

#include <iostream>		// Used for input and output.
#include <conio.h>		// Used for getch().

using namespace std;

// Press any key to continue.
void pressAnyKey()
{
	cout << "Press any key to continue" << endl;
	_getch();							// Waits and gets next character entered.	
}

// A traditional example of simple recursion.
int factorial(int x)
{
    if (x == 1)							// Base case where recursive calls cease.
    {
        return 1;						
    } 
	else								// Recursive call.
    {
        return x * factorial(x - 1);
    }
}

// A traditional example of simple recursion.
// Exponent must be non-negative to give accurate results. 
int power(int base, int exponent)
{
	if (exponent <= 0)
	{
		return 1;
	}
	else if (exponent == 1)
	{
        return base;
	}    
    else
	{
        return base * power(base, exponent - 1);
	}
}

int main()
{
	cout << "4! " << factorial(4) << endl;
	pressAnyKey();

	cout << "5 cubed is " << power(5, 3) << endl;
	pressAnyKey();

	return 0;	// Program ends normally. 
}
/*
Michael Scarpuzzi
11/17/2019
CSC 231

This file is my class declaration for the whoopingCrane class.
*/
#include <iostream>

using namespace std;

#ifndef whoopingCrane_H
#define whoopingCrane_H

class whoopingCrane
{
	//member variables
	int ID;
	char location[80];
	double age;
	char gender[50];

	friend ostream &operator << (ostream& out, const whoopingCrane& theCrane); 
public:
	//Constructors
	whoopingCrane();
	whoopingCrane(int theID, char *theLocation, double theAge, char *theGender);

	//Accessors and Mutators
	int getID() const;
	string getLocation() const;
	double getAge() const;
	string getGender() const;
	void setID(int theID);
	void setLocation(char *theLocation);
	void setAge(double theAge);
	void setGender(char *theGender);


	//Helpers
	void print();

};

#endif

/*
Michael Scarpuzzi
11/17/2019
CSC 231

This file is my class implentation for the whoopingCrane class defined in whoopingCrane.h
*/
#include <iostream>
#include <fstream>

#include "whoopingCrane.h"

using namespace std;

//Constructors
whoopingCrane::whoopingCrane()
{
	setID(0);
	setLocation((char *)"");
	setAge(0);
	setGender((char *)"");
}

whoopingCrane::whoopingCrane(int theID, char *theLocation, double theAge, char *theGender)
{
	setID(theID);
	setLocation(theLocation);
	setAge(theAge);
	setGender(theGender);
}

//Accessor and Mutator functions.

int whoopingCrane::getID() const
{
	return ID;
}

string whoopingCrane::getLocation() const
{
	return location;
}

double whoopingCrane::getAge() const
{
	return age;
}

string whoopingCrane::getGender() const
{
	return gender;
}

void whoopingCrane::setID(int theID)
{
	if (theID < 111111)
	{
		ID = 000000;
	}
	else
	{
		ID = theID;
	}
}

void whoopingCrane::setLocation(char *theLocation)
{
	strcpy_s(location, theLocation);
}

void whoopingCrane::setAge(double theAge)
{
	if (theAge < 0.0)
	{
		age = 0.0;
	}
	else
	{
		age = theAge;
	}
}

void whoopingCrane::setGender(char *theGender)
{
	strcpy_s(gender, theGender);
}

void whoopingCrane::print()
{
	cout << ID << " is located at: " << location << " and is a " << age
		<< " year old " << gender;
}

ostream & operator<<(ostream & out, const whoopingCrane & theCrane)
{
	out << theCrane.ID << " is located at: " << theCrane.location << " and is a " << theCrane.age
		<< " year old " << theCrane.gender;
	return out;
}
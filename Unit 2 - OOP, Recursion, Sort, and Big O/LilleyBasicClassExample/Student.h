#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

#ifndef Student_H
#define Student_H

class Student
{
public:
	// Basic constructor
	Student();

	// Basic overloaded constructor
	Student(string StudFName, string StudLName, char StudMI, string StudDBO, long StudID);

	// Basid destructor
	~Student();

	// Public accessor functions -  note the const as we are not changing values - just returning
	string getFirstName() const;
	string getLastName() const;
	char getMiddleInitial() const;
	string getStudentDOB() const;
	long getStudentID() const;
	
	// Public mutator functions - note the void as we are not returning anything
	void setFirstName(string FName);
	void setLastName(string LName);
	void setMiddleInitial(char MI);
	void setStudentDOB(string DOB);
	void setStudentID(long StudID);



private:

	// Basic attributes about a student
	// These are private so we will only manipulate them from within the class
	string StudentFirstName;
	string StudentLastName;
	char StudentMI;
	string StudentDOB;
	long StudentID;

};



#endif // !Student_H
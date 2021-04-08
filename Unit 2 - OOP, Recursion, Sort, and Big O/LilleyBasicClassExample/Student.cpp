#include "stdafx.h"
#include "Student.h"

// Constructor without parameters - calling the mutator functions as opposed to just
// setting the values to empty strings, NULL, and 0
Student::Student()
{
	setFirstName("");
	setLastName("");
	setMiddleInitial(NULL); 
	setStudentDOB("");
	setStudentID(0);
}

// Overloaded constructor with parameters - again calling the mutator fucntions as 
// opposed to just setting the values based on the parameters
Student::Student(string FName, string LName, char MI, string DOB, long StudID)
{
	setFirstName(FName);
	setLastName(LName);
	setMiddleInitial(MI);
	setStudentDOB(DOB);
	setStudentID(StudID);
}

Student::~Student()
{

}

// Accessor functions returning values as opposed to changing values - note the const.
string Student::getFirstName() const
{
	return StudentFirstName;
}

string Student::getLastName() const
{
	return StudentLastName;
}

char Student::getMiddleInitial() const
{
	return StudentMI;
}

string Student::getStudentDOB() const
{
	return StudentDOB;
}

long Student::getStudentID() const
{
	return StudentID;
}


// Mutator functions/procedures without return values
void Student::setFirstName(string FName)
{
	StudentFirstName = FName;
}

void Student::setLastName(string LName)
{
	StudentLastName = LName;
}

void Student::setMiddleInitial(char MI)
{
	StudentMI = MI;
}

void Student::setStudentDOB(string DOB)
{
	StudentDOB = DOB;
}
	
void Student::setStudentID(long StudID)
{
	StudentID = StudID;
}
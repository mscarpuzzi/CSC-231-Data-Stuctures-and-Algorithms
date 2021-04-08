// VectorOfStudents.cpp : Defines the entry point for the console application.
// This is a very basic program that fills a vector with students of class Student.
// We include the Student.h file as it is the header file for our Student class.
// The Student class contains 5 attributes per object and is simply used to demonstate
// the procedure of building a class and then instantiating objects of that class and
// storing them in a container class - vector.

#include "stdafx.h"
#include <vector>
#include <string>

#include <iostream>

#include "Student.h"

using namespace std;

// Function Prototypes
void GetStudents(vector<Student> & vStudents);
void DisplayStudents(vector<Student> & vStudents);

int main()
{
	vector<Student> vStudents;

	GetStudents(vStudents);
	DisplayStudents(vStudents);

    return 0;
}

// Simple procedure to display the contents of the vector of students to the screen. It
// uses accessor functions of class Student to retrieve the attributes for display to the
// console.
void DisplayStudents(vector<Student> & vStudents)
{
	cout << endl;
	cout << "You entered the following students:" << endl;
	int iVectorSize = vStudents.size();
	int i = 0;
	for (i = 0; i < iVectorSize; i++)
	{
		cout << "Last Name: " << vStudents[i].getLastName() << endl
			<< "First Name: " << vStudents[i].getFirstName() << endl
			<< "Middle Init: " << vStudents[i].getMiddleInitial() << endl
			<< "DOB: " << vStudents[i].getStudentDOB() << endl
			<< "Student ID: " << vStudents[i].getStudentID() << endl;
	}

}

// Simple procedure to prompt the user on the number of students he/she wants to enter.
// Then the procedure creates that many objects of type/class Student, gets the attributes
// from the user, sets the attributes in the objects using mutator functions, and adds
// the Students to a vector.
void GetStudents(vector<Student> & vStudents)
{
	int iNumStudents = 0;
	string sTempString = "";
	char cTempChar;
	long lTempLong;

	cout << "How many students do you want to enter? ";
	cin >> iNumStudents;

	Student studNewStudent;
	int i = 0;
	for (i = 0; i < iNumStudents; i++)
	{
		cout << endl;
		cout << "Enter First Name: ";
		cin >> sTempString;

		studNewStudent.setFirstName(sTempString);

		cout << endl;
		cout << "Enter Last Name: ";
		cin >> sTempString;

		studNewStudent.setLastName(sTempString);

		cout << endl;
		cout << "Enter Middle Initial: ";
		cin >> cTempChar;

		studNewStudent.setMiddleInitial(cTempChar);

		cout << endl;
		cout << "Enter DOB: ";
		cin >> sTempString;

		studNewStudent.setStudentDOB(sTempString);

		cout << endl;
		cout << "Enter Student ID: ";
		cin >> lTempLong;

		studNewStudent.setStudentID(lTempLong);

		vStudents.push_back(studNewStudent);
	}

}

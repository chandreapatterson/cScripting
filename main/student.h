#pragma once
#include "degree.h"
#include <iostream>
#include <string>

using namespace std;


// For Student class, variables are privately scoped and functions are globally scoped
class Student {

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int daysComp[3];
	DegreeProgram degreeProgram;

public:

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getStudentAge();
	int* getDaysComp();
	DegreeProgram getDegreeProgram();

	void setStudentID(string x);
	void setFirstName(string x);
	void setLastName(string x);
	void setEmailAddress(string x);
	void setStudentAge(int x);
	void setDaysComp(int daysComp1, int daysComp2, int daysComp3);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void printStudentID();
	void printFirstName();
	void printLastName();
	void printEmailAddress();
	void printStudentAge();
	void printDaysComp();
	void printDegreeProgram();
	void print();

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysComp[], DegreeProgram degreeProgram);

};


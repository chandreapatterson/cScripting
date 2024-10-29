#pragma once
#include "student.h"
#include <iostream>
#include <string>

using namespace std;


// Defines Roster class with functions
class Roster {

public:

	Student* classRosterArray[5];


	void parse(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysComp1, int daysComp2, int daysComp3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	string GetStudentID(int indexSpot);

	// Sets integer variables for object parsing
	int arrayLimit;
	int startIndex;
	Roster(int arrayLimit);

	~Roster();

};

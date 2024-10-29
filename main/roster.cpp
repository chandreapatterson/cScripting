#include "degree.h"
#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>

using namespace std;


// Defines parse function for separating data records from main file
void Roster::parse(string studentData) {

	string studentID, firstname, lastname, emailAddress;

	int studentAge, daysComp1, daysComp2, daysComp3;

	// If statement starts with conditional to check if starting value is less than length of array
	if (startIndex < arrayLimit) {

		// Sets classRosterArray to a new object in Student class
		classRosterArray[startIndex] = new Student();

		// Searches for next comma
		int toNext = studentData.find(",");
		studentID = studentData.substr(0, toNext);
		classRosterArray[startIndex]->setStudentID(studentID);

		// Sets pointer variable by finding comma index values and using integer difference

		int delimitFrom = toNext + 1;
		toNext = studentData.find(",", delimitFrom);
		firstname = studentData.substr(delimitFrom, toNext - delimitFrom);
		classRosterArray[startIndex]->setFirstName(firstname);

		delimitFrom = toNext + 1;
		toNext = studentData.find(",", delimitFrom);
		lastname = studentData.substr(delimitFrom, toNext - delimitFrom);
		classRosterArray[startIndex]->setLastName(lastname);

		delimitFrom = toNext + 1;
		toNext = studentData.find(",", delimitFrom);
		emailAddress = studentData.substr(delimitFrom, toNext - delimitFrom);
		classRosterArray[startIndex]->setEmailAddress(emailAddress);

		delimitFrom = toNext + 1;
		toNext = studentData.find(",", delimitFrom);
		studentAge = stoi(studentData.substr(delimitFrom, toNext - delimitFrom));
		classRosterArray[startIndex]->setStudentAge(studentAge);

		delimitFrom = toNext + 1;
		toNext = studentData.find(",", delimitFrom);
		daysComp1 = stoi(studentData.substr(delimitFrom, toNext - delimitFrom));

		delimitFrom = toNext + 1;
		toNext = studentData.find(",", delimitFrom);
		daysComp2 = stoi(studentData.substr(delimitFrom, toNext - delimitFrom));

		delimitFrom = toNext + 1;
		toNext = studentData.find(",", delimitFrom);
		daysComp3 = stoi(studentData.substr(delimitFrom, toNext - delimitFrom));
		classRosterArray[startIndex]->setDaysComp(daysComp1, daysComp2, daysComp3);

		delimitFrom = toNext + 1;
		toNext = studentData.find(",", delimitFrom);
		string outputDegree = studentData.substr(delimitFrom, toNext - delimitFrom);

		if (outputDegree == "SOFTWARE") {
			classRosterArray[startIndex]->setDegreeProgram(SOFTWARE);
		}
		else if (outputDegree == "SECURITY") {
			classRosterArray[startIndex]->setDegreeProgram(SECURITY);
		}
		else if (outputDegree == "NETWORK") {
			classRosterArray[startIndex]->setDegreeProgram(NETWORK);
		}

		startIndex++;
	}

	return;
}

// Sets arguments for add method
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysComp1, int daysComp2, int daysComp3, DegreeProgram degreeProgram) {

	int daysComp[3] = { daysComp1, daysComp2, daysComp3 };

	classRosterArray[arrayLimit] = new Student(studentID, firstName, lastName, emailAddress, studentAge, daysComp, degreeProgram);
};


// Calls remove function
void Roster::remove(string id) {

	// Sets boolean variable to assign value to classRosterArray if null while iterating
	bool studentExists = false;
	for (int i = 0; i < arrayLimit; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (id == classRosterArray[i]->getStudentID()) {
			classRosterArray[i] = nullptr;
			studentExists = true;
			break;
		}
	}

	// Displays message based on boolean value of if-else
	if (studentExists == false) {
		cout << "Message: Student ID "
			<< id
			<< " does not return a record."
			<< endl;
	}
	else if (studentExists == true) {
		cout << "Removed: Student ID "
			<< id
			<< endl;
	}

	return;
}


// Loops through array to print all records
void Roster::printAll() {

	for (int i = 0; i < arrayLimit; i++) {
		if (classRosterArray[i] == nullptr)
		{
			continue;
		}
		else {
			classRosterArray[i]->print();
		}
	}

	cout << endl;

	return;
}


// Loops through array to print record for average course days
void Roster::printAverageDaysInCourse(string id) {

	for (int i = 0; i < arrayLimit; i++) {
		if (id == classRosterArray[i]->getStudentID()) {
			cout << "Average days in course: "
				<< id
				<< " - "
				<< ((classRosterArray[i]->getDaysComp()[0] + classRosterArray[i]->getDaysComp()[1] + classRosterArray[i]->getDaysComp()[2]) / 3)
				<< endl;
		}
	}

	return;
}


// Loops through array to print invalid email by using if-statement to look for blank space as invalid character
void Roster::printInvalidEmails() {

	for (int i = 0; i < arrayLimit; ++i) {
		string checkEmailValidity = classRosterArray[i]->getEmailAddress();
		if ((checkEmailValidity.find('@') == string::npos) || (checkEmailValidity.find(' ') != string::npos) || (checkEmailValidity.find('.') == string::npos)) {
			cout << "Invalid email address: "
				<< classRosterArray[i]->getStudentID()
				<< " - "
				<< checkEmailValidity
				<< endl;
		}
	}
	cout << endl;

	return;
}


// Sets string value to print enumerated variable
void Roster::printByDegreeProgram(DegreeProgram x) {
	string enumToString;
	if (x == SECURITY) {
		enumToString = "SECURITY";
	}
	else if (x == NETWORK) {
		enumToString = "NETWORK";
	}
	else if (x == SOFTWARE) {
		enumToString = "SOFTWARE";
	}

	cout << "Has software degree: "
		<< endl;

	int studentTotal = 0;

	for (int i = 0; i < arrayLimit; i++) {
		if (classRosterArray[i]->getDegreeProgram() == x) {
			classRosterArray[i]->print();
			++studentTotal;
		}
	}

	return;
}


// Sets starting value for variables used to parse
Roster::Roster(int arrayLimit) {
	this->arrayLimit = arrayLimit;
	this->startIndex = 0;

	for (int i = 0; i < arrayLimit; i++) {
		this->classRosterArray[i] = new Student;
	}

	return;
}


// Calls accessor function
string Roster::GetStudentID(int indexSpot) {

	string studentID = classRosterArray[indexSpot]->getStudentID();

	return studentID;
}


// Loops through array pointer to set to null
Roster::~Roster() {

	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	};


}



#include "student.h"
#include <iostream>

using namespace std;

// Accessors and mutators for each record category (i.e. first name, last name, etc...)
// Pointers used to return mutated objects with "this->"
string Student::getStudentID() {
	return studentID;
}
void Student::setStudentID(string x) {
	this->studentID = x;
	return;
}
void Student::printStudentID() {
	cout << studentID;
}



string Student::getFirstName() {
	return firstName;
}
void Student::setFirstName(string x) {
	this->firstName = x;
	return;
}
void Student::printFirstName() {
	cout << firstName;
}




string Student::getLastName() {
	return lastName;
}
void Student::setLastName(string x) {
	this->lastName = x;
	return;
}
void Student::printLastName() {
	cout << lastName;
}




string Student::getEmailAddress() {
	return emailAddress;
}
void Student::setEmailAddress(string x) {
	this->emailAddress = x;
	return;
}
void Student::printEmailAddress() {
	cout << emailAddress;
}




int Student::getStudentAge() {
	return studentAge;
}
void Student::setStudentAge(int x) {
	this->studentAge = x;
	return;
}
void Student::printStudentAge() {
	cout << studentAge;
}



// Loop with this-> allows variable to iterate to appropriate object
int* Student::getDaysComp() {
	return daysComp;
}
void Student::setDaysComp(int daysComp1, int daysComp2, int daysComp3) {

	for (int i = 0; i < 3; i++)
		this->daysComp[0] = daysComp1;
	this->daysComp[1] = daysComp2;
	this->daysComp[2] = daysComp3;

	return;
}
void Student::printDaysComp() {
	cout << daysComp[0]
		<< ", "
		<< daysComp[1]
		<< ", "
		<< daysComp[2];
}



// Program enumerator set in interdependent file
// If statement to assign string making enumerator printable
DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}
void Student::setDegreeProgram(DegreeProgram x) {
	this->degreeProgram = x;
	return;
}
void Student::printDegreeProgram() {

	string printDegree;

	if (degreeProgram == SECURITY) {
		printDegree = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		printDegree = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		printDegree = "SOFTWARE";
	}

	cout << printDegree;

	return;
}


// Creates new record with sample information using pointers
Student::Student() {
	this->studentID = "A0";
	this->firstName = "Sample";
	this->lastName = "Samplington";
	this->emailAddress = "sample@domain.com";
	this->studentAge = 34;
	this->daysComp[0] = 55;
	this->daysComp[1] = 38;
	this->daysComp[2] = 11;
	this->degreeProgram = NETWORK;
}


// Makes each object in Student class nonstatic
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysComp[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	this->daysComp[0] = daysComp[0];
	this->daysComp[1] = daysComp[1];
	this->daysComp[2] = daysComp[2];
	this->degreeProgram = degreeProgram;
}



void Student::print() {

	string printDegree;

	// If-else statement to assign string making enumerator printable
	if (degreeProgram == SECURITY) {
		printDegree = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		printDegree = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		printDegree = "SOFTWARE";
	}

	// Set string values and print
	cout << studentID
		<< "     First Name: "
		<< getFirstName()
		<< "     Last Name: "
		<< getLastName()
		<< "     Age: "
		<< getStudentAge()
		<< "     daysInCourse: {"
		<< getDaysComp()[0]
		<< ", "
		<< getDaysComp()[1]
		<< ", "
		<< getDaysComp()[2]
		<< "} Degree Program: "
		<< printDegree
		<< endl;

	return;
}
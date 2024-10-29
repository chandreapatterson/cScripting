// Import libraries and links to interdependent C++ files
#include "degree.h"
#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>

// Uses standard library
using namespace std;

int main()
{
    // Project title
    cout << "        ||||                                 ||||"
        << endl
        << "        ||||         Scripting Practice      ||||"
        << endl
        << "        ||||              in C++             ||||"
        << endl
        << "        ||||                                 ||||"
        << endl
        << "        ||||        Chandrea Patterson       ||||"
        << endl
        << "        ||||                                 ||||"
        << endl
        << "        |||||||||||||||||||||||||||||||||||||||||"
        << endl
        << endl
        << endl
        << endl;


    // Main data used to print and update including ID, first name, last name, email, etc...
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Sample,Lastname,sample@sample.com,23,45,25,15,SOFTWARE"
    };


    // Refers to Roster class initiated in roster.h file with loop through parsed objects
    Roster* classRoster = new Roster(5);
    for (int i = 0; i < 5; i++) {

        classRoster->parse(studentData[i]);
    };





    // The below functions print or remove sections of parsed objects based on their given C++ class

    classRoster->printAll();
    cout << endl
        << endl;




    classRoster->printInvalidEmails();
    cout << endl
        << endl;


    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->GetStudentID(i));
    }
    cout << endl
        << endl
        << endl;



    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl
        << endl
        << endl;



    classRoster->remove("A3");
    cout << endl
        << endl
        << endl;



    classRoster->printAll();
    cout << endl
        << endl;



    classRoster->remove("A3");
    cout << endl
        << endl;
}


#include "roster.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Roster::parse(string studentDataTable)
{
	int rhs = studentDataTable.find(",");
	string studentID = studentDataTable.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentDataTable.find(",", lhs);
	string firstName = studentDataTable.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentDataTable.find(",", lhs);
	string lastName = studentDataTable.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentDataTable.find(",", lhs);
	string emailAddress = studentDataTable.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentDataTable.find(",", lhs);
	int age = stoi(studentDataTable.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentDataTable.find(",", lhs);
	int daysInCourse1 = stoi(studentDataTable.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentDataTable.find(",", lhs);
	int daysInCourse2 = stoi(studentDataTable.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentDataTable.find(",", lhs);
	int daysInCourse3 = stoi(studentDataTable.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentDataTable.find(",", lhs);
	string degree = studentDataTable.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram;

	if (degree == "SECURITY") {
	degreeProgram = SECURITY;
}

	else if (degree == "NETWORK")
{
	degreeProgram = NETWORK;
}

	else if (degree == "SOFTWARE") 
{
	degreeProgram = SOFTWARE;
}

	else 
{
	cout << "Error: Invalid Degree";
}


add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysinCourse2, int daysinCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1, daysinCourse2, daysinCourse3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}


void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student * temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << "Student ID: " << studentID << " removed from roster." << std::endl << std::endl;
		this->printAll();
	}
	else cout << "Student ID: " << studentID << " not in roster." << std::endl << std::endl;
}


void Roster::printAll()
{	
	cout << left;

	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << setw(5) << classRosterArray[i]->getID();
		cout << setw(12) << "First Name: " << setw(10) << classRosterArray[i]->getFirstName();
		cout << setw(11) << "Last Name: " << setw(10) << classRosterArray[i]->getLastName();
		cout << setw(7) << "Email: " << setw(25) << classRosterArray[i]->getEmailAddress();
		cout << setw(5) << "Age: " << setw(5) << classRosterArray[i]->getAge();
		cout << setw(16) << "Days In Course: " << "{" << classRosterArray[i]->getDaysInCourse()[0] << ", " << classRosterArray[i]->getDaysInCourse()[1] << ", " << classRosterArray[i]->getDaysInCourse()[2] << setw(5) << "}";
		cout << setw(16) << "Degree Program: " << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}	
}



void Roster::printAverageDaysInCourse(string studentID)
{	
	for (int i = 0; i <= Roster::lastIndex; i++)
	{	
		if (classRosterArray[i]->getID() == studentID)
		{	
			cout << "Student " << classRosterArray[i]->getID() << " average days in course: ";
			cout << (classRosterArray[i]->getDaysInCourse()[0]
				+ classRosterArray[i]->getDaysInCourse()[1]
				+ classRosterArray[i]->getDaysInCourse()[2]) / 3.0;
		}
	}
	cout << std::endl;
}


void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string emailAddress = classRosterArray[i]->getEmailAddress();
		if (emailAddress.find(' ') != string::npos ||
			emailAddress.find('@') == string::npos ||
			emailAddress.find('.') == string::npos)
		{
			any = true;
			cout << "Invalid email: " << emailAddress << endl;
		}
	}
	if (!any) cout << "No invalid emails." << std::endl;
}



void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			cout << setw(5) << classRosterArray[i]->getID();
			cout << setw(12) << "First Name: " << setw(10) << classRosterArray[i]->getFirstName();
			cout << setw(11) << "Last Name: " << setw(10) << classRosterArray[i]->getLastName();
			cout << setw(7) << "Email: " << setw(25) << classRosterArray[i]->getEmailAddress();
			cout << setw(5) << "Age: " << setw(5) << classRosterArray[i]->getAge();
			cout << setw(16) << "Days In Course: " << "{" << classRosterArray[i]->getDaysInCourse()[0] << ", " << classRosterArray[i]->getDaysInCourse()[1] << ", " << classRosterArray[i]->getDaysInCourse()[2] << setw(5) << "}";
			cout << setw(16) << "Degree Program: " << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
		}
	}
	cout << std::endl;
}


Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];
	}
}


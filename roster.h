#pragma once
#include "student.h"
using namespace std;

class Roster
{
public:
	int lastIndex = -1;

	const static int numStudents = 5;

	Student* classRosterArray[numStudents];

	void parse(string studentData);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	void printAll();

	void printByDegreeProgram(DegreeProgram degreeProgram);

	void printInvalidEmails();

	void printAverageDaysInCourse(string StudentID);

	void remove(string studentID);

	~Roster();
};
#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;


class Student
{
public:
	const static int daysInCourseArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[daysInCourseArraySize];
	DegreeProgram degreeProgram;

public:
	Student();
	Student(string StudentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
	~Student();


	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();


	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int Age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();
};

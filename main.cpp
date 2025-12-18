#include "roster.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	cout << "C867 - Scripting and Programming Applications" << endl;
	cout << "Language Used: C++" << endl;
	cout << endl;

	const int numStudents = 5;
	Roster classRoster;

	const string studentData[] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Epic,Gamerz,EGz@ritogames.com,25,10,20,30,SOFTWARE"
	};

	for (int i = 0; i < numStudents; i++)
	{
		classRoster.parse(studentData[i]);
	};

	cout << "Showing all students: " << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Showing all students with invalid emails: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	cout << "Calculating student's average days in course: " << endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
	}
	cout << endl;

	cout << "Students in software degree program: " << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Removing student with ID A3: " << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "Showing all students: " << endl;
	classRoster.printAll();
	cout << endl;
	
	cout << "Removing student with ID A3: " << endl;
	classRoster.remove("A3");
	cout << endl;
	

	system("pause");
	return 0;
}






#include "roster.h"
int main()
{
	const string studentData[] =
	{
		"A1,   John  Smith   ,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,   Suzan Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,   Jack  Napoli  ,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,   Erin  Black   ,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,   Alex  McCarthy,amcca01@wgu.edu	,33,10,20,35,SOFTWARE"
	};

	const int numStudents = 5;
	Roster roster;
	Student student;

	cout << "Scripting and Programming Applications, C++, 001472622, Alex McCarthy" << std::endl;
	cout << std::endl;

	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "Displaying all students: " << std::endl;
	cout << std::endl;
	roster.printAll();
	cout << std::endl;

	cout << "Displaying invalid email addresses: " << std::endl;
	cout << std::endl;
	roster.printInvalidEmails();
	cout << std::endl;

	cout << "Average days to complete course: " << std::endl;
	cout << std::endl;
	roster.printAverageDaysInCourse("A2");

	cout << "Displaying student by degree program: " << degreeProgramStrings[SOFTWARE] << std::endl;
	cout << std::endl;
	roster.printByDegreeProgram((SOFTWARE));
	cout << std::endl;

	cout << "Removing student with ID A3" << std::endl;
	cout << std::endl;
	roster.removeStudentByID("A3");
	cout << std::endl;

	roster.printAll();
	cout << std::endl;

	cout << "Removing student with ID A3" << std::endl;
	cout << std::endl;
	roster.removeStudentByID("A3");
	cout << std::endl;

	system("pause");
	return 0;


}
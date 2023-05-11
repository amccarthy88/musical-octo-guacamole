#pragma once
#include "student.h"
class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string row);

	void add(string studentID, 
		string firstName, 
		string lastName, 
		string emailAddress, 
		int age, 
		double sDTC1, 
		double sDTC2, 
		double sDTC3, 
		DegreeProgram dp);
	void printAll();
	void printByDegreeProgram(DegreeProgram dp);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void removeStudentByID(string studentID);
	~Roster();
};
#include "roster.h"
void Roster::parse(string studentData)
{
	DegreeProgram dp = SECURITY;
	if (studentData.back() == 'Y') dp = SECURITY;
	else if (studentData.back() == 'K') dp = NETWORK;
	else if (studentData.back() == 'E') dp = SOFTWARE;

	int rhs = studentData.find(",");
	string sID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string fn = studentData.substr(lhs, rhs = lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string ln = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string ea = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int ag = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double d1 = stod(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double d2 = stod(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double d3 = stod(studentData.substr(lhs, rhs - lhs));

	add(sID, fn, ln, ea, ag, d1, d2, d3, dp);
}

void Roster::add(string studentID, 
				string firstName, 
				string lastName, 
				string emailAddress, 
				int ag, 
				double sDTC1, 
				double sDTC2, 
				double sDTC3, 
				DegreeProgram dp)
{
	double darr[3] = { sDTC1, sDTC2, sDTC3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, ag, darr, dp);
}

void Roster::printAll()
{
	
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		classRosterArray[i]->print();

	}
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegree() == dp) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string ea = (classRosterArray[i]->getEmail());
		if ((ea.find('@') == string::npos || ea.find('.') == string::npos) || (ea.find(' ') != string::npos))
		{
			any = true;
			cout << ea << std::endl;
		}	
		
	}
	
	if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getID() == studentID)
		{
			cout << classRosterArray[i]->getID() << ": ";
			cout << (classRosterArray[i]->getDaysToComplete()[0]
				+ classRosterArray[i]->getDaysToComplete()[1]
				+ classRosterArray[i]->getDaysToComplete()[2]) / 3.0 << std::endl;
		}
	}
	cout << std::endl;
}

void Roster::removeStudentByID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << "Student " << studentID << " removed from roster." << std::endl << std::endl;
	}
	else cout << "Student with ID:" << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster()
{
	cout << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
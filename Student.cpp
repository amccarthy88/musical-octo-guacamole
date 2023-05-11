#include "student.h"
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysToCompleteArraySize; i++) this->daysToComplete[i] = 0;
	this->degreeProgam = DegreeProgram::SECURITY;
}

Student::Student(string studentID, 
				string firstName, 
				string lastName, 
				string emailAddress, 
				int age, 
				double daysToComplete[], 
				DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysToCompleteArraySize; i++) this->daysToComplete[i] = daysToComplete[i];
	this->degreeProgam = degreeProgram;
}

Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName;  }
string Student::getEmail() { return this->emailAddress;  }
int Student::getAge() { return this->age;  }
double* Student::getDaysToComplete() { return this->daysToComplete; }
DegreeProgram Student::getDegree() { return this->degreeProgam; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstName) { this->firstName = firstName;  }
void Student::setLastName(string lastName) { this->lastName = lastName;  }
void Student::setEmail(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysToComplete(double daysToComplete[])
{
	for (int i = 0; i < daysToCompleteArraySize; i++) this->daysToComplete[i] = daysToComplete[i];
}
void Student::setDegree(DegreeProgram dp) { this->degreeProgam = dp;  }

void Student::printHeader()
{
	cout << "Output format: " << std::endl;
	cout << "ID | First Name | Last Name | Email Address | Age | Days to Complete a Class | Type" << std::endl;
	cout << std::endl;
}
void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysToComplete()[0] << ',';
	cout << this->getDaysToComplete()[1] << ',';
	cout << this->getDaysToComplete()[2] << '\t';
	cout << degreeProgramStrings[this->getDegree()] << '\n';
}

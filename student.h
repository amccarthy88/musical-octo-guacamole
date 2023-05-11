#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
	const static int daysToCompleteArraySize = 3;
	private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double daysToComplete[daysToCompleteArraySize];
	DegreeProgram degreeProgam;
public: 
	Student();
	Student(string studentID, 
		string firstName, 
		string lastName, 
		string emailAddress, 
		int age, 
		double daysToComplete[], 
		DegreeProgram degreeProgram);
	~Student();

	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	double* getDaysToComplete();
	DegreeProgram getDegree();

	void setID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string emailAddress);
	void setAge(int age);
	void setDaysToComplete(double daysToComplete[]);
	void setDegree(DegreeProgram degreeProgram);

	static void printHeader();

	void print();
};
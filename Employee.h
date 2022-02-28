#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>

using namespace std;

class Employee
{
	public:
		string BranchNumber, EmployeeNumber;
		Employee();
		void Input();
		void Display();
};

#endif

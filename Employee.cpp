#include <iostream>
#include <string>
#include "Employee.h"

Employee::Employee()
{
	BranchNumber = "";
	EmployeeNumber = "";
}

void Employee::Input()
{
	string branchnumber, employeenumber;
	cout << "Please input the Branch's number: ";
	cin >> branchnumber;
	cout << "Please input the Employee's number: ";
	cin >> employeenumber;
	BranchNumber = branchnumber, EmployeeNumber = employeenumber; 
}

void Employee::Display()
{
	cout << "Branch's number: " << BranchNumber << endl;
	cout << "Employee's number: " << EmployeeNumber << endl;
}

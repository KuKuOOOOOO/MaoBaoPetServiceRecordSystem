#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;

Customer::Customer()
{
	Name = "";
	PhoneNumber = ""; 
}

void Customer::CustomerInput()
{
	string name, phonenumber;
	cout << "Please input the customer's name: ";
	cin >> name;
	cout << "Please input the customer's phone number: ";
	cin >> phonenumber;
	Name = name, PhoneNumber = phonenumber;
}

void Customer::CustomerDisplay()
{
	cout << "The customer's name: " << Name << endl;
	cout << "The customer's phone number: " << PhoneNumber << endl;
}

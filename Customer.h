#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

using namespace std;

class Customer
{
	public:
		string Name, PhoneNumber;
		Customer();
		void CustomerInput();
		void CustomerDisplay();
};

#endif

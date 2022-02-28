#ifndef PET_H
#define PET_H
#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;

class Pet: public Customer
{
	public:
		string PetClass, PetName;
		int Service;
		Pet();
		void PetInput();
		void PetDisplay();
};

#endif

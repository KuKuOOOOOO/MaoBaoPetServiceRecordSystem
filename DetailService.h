#ifndef DETAILSERVICE_H
#define DETAILSERVICE_H
#include <iostream>
#include <string>
#include "Pet.h"

using namespace std;

class DetailService: public Pet
{
	public:
		string ServiceDate;
		int ServiceCost, Option;
		DetailService();
		void ServiceInput();
		void ServiceDisplay();
};

#endif


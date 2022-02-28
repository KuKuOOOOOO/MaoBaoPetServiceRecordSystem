#include <iostream>
#include <string>
#include "Pet.h"

using namespace std;

Pet::Pet()
{
	PetClass = "";
	PetName = "";
	Service = 0;
}

void Pet::PetInput()
{
	CustomerInput();
	string petclass, petname;
	int service;
	cout << "Please input the pet's class(cat, dog or rabbit...): ";
	cin >> petclass;
	cout << "Please input the pet's name: ";
	cin >> petname;
	while(1)
	{
		cout << "Please input the service number(1. Beauty or 2. Medical): ";
		cin >> service;
		if(!cin || service < 0 || service > 2)
		{
			cin.clear();
			cin.ignore();
			cout << "Please input again. You can only input 1 or 2" << endl;
			continue;
		}
		break;
	} 
	PetClass = petclass, PetName = petname, Service = service;
}

void Pet::PetDisplay()
{
	CustomerDisplay();
	cout <<  Name << "'s pet's class: " << PetClass << endl;
	cout <<  Name << "'s pet's name: " << PetName << endl;
	if(Service == 1)
		cout << PetName << "'s service: Beauty" << endl;
	else
		cout << PetName << "'s service: Medical" << endl;
}

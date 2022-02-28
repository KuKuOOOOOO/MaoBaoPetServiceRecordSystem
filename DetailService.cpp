#include <iostream>
#include <string>
#include "DetailService.h"

DetailService::DetailService()
{
	ServiceDate = "";
	ServiceCost = 0;
	Option = 0;
} 

void DetailService::ServiceInput()
{
	PetInput();
	string servicedate;
	int servicecost, option;
	if(Service == 1)
	{
		cout << "Please input the beauty option: " << endl;
		cout << "1. Take a bath. " << endl;
		cout << "2. Trim pet's hair. " << endl;
		cout << "3. Take a bath and trim pet's hair. " << endl;
		cout << "Your input: ";
		while(1)
		{
			cin >> option;
			if(!cin || option < 0 || option > 3)
			{
				cin.clear();
				cin.ignore();
				cout << "Please input again. You can only input 1, 2 or 3. " << endl;
				continue;
			} 
			break;
		}
	}
	else
	{
		cout << "Please input the medical option: " << endl;
		cout << "1. Cold medical. " << endl;
		cout << "2. Surgery. " << endl;
		cout << "Your input: ";
		while(1)
		{
			cin >> option;
			if(!cin || option < 0 || option > 2)
			{
				cin.clear();
				cin.ignore();
				cout << "Please input again. You can only input 1 or 2. " << endl;
				continue;
			}
			break;
		}
	}
	cout << "Please input the service total cost: ";
	while(1)
	{
		cin >> servicecost;
		if(!cin || servicecost < 0)
		{
			cin.clear();
			cin.ignore();
			cout << "Please input again. You can only input the positive number. " << endl;
			continue;
		} 
		break;
	}
	cout << "Please input the service date(March, 5:0305): ";
	cin >> servicedate;
	ServiceDate = servicedate, ServiceCost = servicecost, Option = option;
}

void DetailService::ServiceDisplay()
{
	PetDisplay();
	if(Service == 1)
	{
		cout << "The beauty option: ";
		if(Option == 1)
			cout << "1. Take a bath. " << endl;
		else if(Option == 2)
			cout << "2. Trim pet's hair. " << endl;
		else
			cout << "3. Take a bath and trim pet's hair. " << endl;
	}
	else
	{
		cout << "The medical option: ";
		if(Option == 1)
			cout << "1. Cold medical. " << endl;
		else
			cout << "2. Surgery. " << endl;
	}
	cout << "The service total cost: " << ServiceCost << endl;
	cout << "The service date: " << ServiceDate << endl;
}

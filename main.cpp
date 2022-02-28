#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>
#include "Employee.h"
#include "DetailService.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Record
{
	char CustomerName[50];
	char CustomerPhone[50];
	char PetClass[50];
	char PetName[50];
	int Service;
	int ServiceOption;
	char BranchNumber[50];
	char ServiceDate[50];
	char EmployeeNumber[50];
	int ServiceCost;
};

int main(int argc, char** argv) 
{
	string FileName, EmployeeFile;
	Employee employee;
	while(1)
	{
		bool isFound = false;
		EmployeeFile = "EmployeeList.txt";
		vector<string> EmployeeNumbers;
		ifstream ifs(EmployeeFile.c_str(), ios::in);
		if(!ifs.is_open())
		{
			cout << "Failed to open " << EmployeeFile << ". Please check again. " << endl;
			continue;
		}
		else
		{
			employee.Input();
			string EmployeeNumber;
			while(ifs >> EmployeeNumber && isFound == false)
			{
				EmployeeNumbers.push_back(EmployeeNumber);
				if(employee.EmployeeNumber == EmployeeNumber)
				{
					isFound = true;
					ifs.close();
				}
			}
			if(isFound == false)
			{
				cout << "Input employee number is error. Please input again. " << endl;
				continue;
			}
			break;
		}
	}
	while(1)
	{
		FileName = "list.txt";
		fstream File(FileName.c_str(), ios::out | ios::in | ios::binary);
		if(!File)
		{
			cout << "Error opening file. Please check and enter again. " << endl;
			return 0;
		}
		else
		{
			cout << "Hello " << employee.EmployeeNumber << "!!" << endl;
			cout << "Welcome to MaoBao Pet Service Record System!!" << endl;
			File.close();
			break;
		}
	} 
	while(1)
	{
		int Option;
		fstream File(FileName.c_str(), ios::out | ios::in | ios::binary);
		cout << "Please choose one service: " << endl;
		cout << "1. Add new records to the file. " << endl;
		cout << "2. Display any records in the file. " << endl;
		cout << "3. Change any records in the file. " << endl;
		cout << "4. Delete any records in the file. " << endl;
		cout << "5. Leave this system. " << endl;
		cout << "Your option: ";
		while(1)
		{
			cin >> Option;
			if(!cin || Option < 1 || Option > 5)
			{
				cout << "Please input again. You can only input 1, 2, 3, 4 or 5" << endl;
				cout << "Your option: ";
				cin.clear();
				cin.ignore();
				continue;
			}
			break;
		}
		// 加入新資料
		if( Option == 1)
		{
			Record record;
			DetailService detailservice;
			cout << "-------------------------------------------------------------" << endl;
			detailservice.ServiceInput();
			cout << "-------------------------------------------------------------" << endl;
			employee.Display();
			detailservice.ServiceDisplay();
			cout << "Input success!!" << endl;
			cout << "-------------------------------------------------------------" << endl;
			strcpy(record.BranchNumber, employee.BranchNumber.c_str());
			strcpy(record.ServiceDate, detailservice.ServiceDate.c_str());
			strcpy(record.EmployeeNumber, employee.EmployeeNumber.c_str());
			record.ServiceCost = detailservice.ServiceCost;
			strcpy(record.CustomerName, detailservice.Name.c_str());
			strcpy(record.CustomerPhone, detailservice.PhoneNumber.c_str());
			strcpy(record.PetClass, detailservice.PetClass.c_str());
			strcpy(record.PetName, detailservice.PetName.c_str());
			record.Service = detailservice.Service;
			record.ServiceOption = detailservice.Option;
			File.clear();
			File.seekp(0, ios::end);
			File.write(reinterpret_cast<char *>(&record), sizeof(record));
		}
		// 顯示資料
		else if(Option == 2)
		{
			string PhoneNumber;	
			Record record;
			cout << "Which record do you want to display(Please input the customer's phone number)? " << endl;
			cout << "Customer's phone number: ";
			cin >> PhoneNumber;
			File.clear();
			File.seekg(0, ios::beg);
			bool isFound = false;
			while(File.read(reinterpret_cast<char *>(&record), sizeof(record)))
			{	
				if(record.CustomerPhone == PhoneNumber && isFound == false)
				{
					cout << "-------------------------------------------------------------" << endl;
					cout << "Branch's number: " << record.BranchNumber << endl;
					cout << "Service Date: " << record.ServiceDate << endl;
					cout << "Employee's number: " << record.EmployeeNumber << endl;
					cout << "The Serivce's total cost: " << record.ServiceCost << endl;
					cout << "The customer's name: " << record.CustomerName << endl;
					cout << "The customer's phone number: " << record.CustomerPhone << endl;
					cout << "The pet's class: " << record.PetClass << endl;
					cout << "The pet's name: " << record.PetName << endl;
					if(record.Service == 1)
					{
						cout << "The service: 1. Beauty. " << endl;
						if(record.ServiceOption == 1)
							cout << "The service option: 1. Take a bath. " << endl;
						else if(record.ServiceOption == 2)
							cout << "The service option: 2. Trim pet's hair. " << endl;
						else
							cout << "The service option: 3. Take a bath and trim pet's hair. " << endl;
					}
					else
					{
						cout << "The service: 2. Medical. " << endl;
						if(record.ServiceOption == 1)
							cout << "The service option: 1. Cold medical. " << endl;
						else
							cout << "The service option: 2. Surgery. " << endl;
						
					}
					cout << "-------------------------------------------------------------" << endl;
					isFound = true;
					break;
				}
			}
			if(isFound == false)
			{
				cout << "-------------------------------------------------------------" << endl;
				cout << "No data. " << endl;
				cout << "-------------------------------------------------------------" << endl;
			}
		}
		// 修正資料
		else if(Option == 3)
		{
			string PhoneNumber;	
			Record record;
			DetailService detailservice;
			cout << "Which record do you want to display(Please input the customer's phone number)? " << endl;
			cout << "Customer's phone number: ";
			cin >> PhoneNumber;
			File.clear();
			File.seekg(0, ios::beg);
			bool isFound = false;
			while(File.read(reinterpret_cast<char *>(&record), sizeof(record)))
			{
				if(record.CustomerPhone == PhoneNumber && isFound == false)
				{
					// 顯示修改前資料 
					cout << "-------------------------------------------------------------" << endl;
					cout << "Branch's number: " << record.BranchNumber << endl;
					cout << "Service Date: " << record.ServiceDate << endl;
					cout << "Employee's number: " << record.EmployeeNumber << endl;
					cout << "The Serivce's total cost: " << record.ServiceCost << endl;
					cout << "The customer's name: " << record.CustomerName << endl;
					cout << "The customer's phone number: " << record.CustomerPhone << endl;
					cout << "The pet's class: " << record.PetClass << endl;
					cout << "The pet's name: " << record.PetName << endl;
					if(record.Service == 1)
					{
						cout << "The service: 1. Beauty. " << endl;
						if(record.ServiceOption == 1)
							cout << "The service option: 1. Take a bath. " << endl;
						else if(record.ServiceOption == 2)
							cout << "The service option: 2. Trim pet's hair. " << endl;
						else
							cout << "The service option: 3. Take a bath and trim pet's hair. " << endl;
					}
					else
					{
						cout << "The service: 2. Medical. " << endl;
						if(record.ServiceOption == 1)
							cout << "The service option: 1. Cold medical. " << endl;
						else
							cout << "The service option: 2. Surgery. " << endl;
						
					}
					cout << "-------------------------------------------------------------" << endl;
					// 修改顯示的資料 
					detailservice.ServiceInput();
					cout << "-------------------------------------------------------------" << endl;
					employee.Display();
					detailservice.ServiceDisplay();
					cout << "Edit success!!" <<endl; 
					cout << "-------------------------------------------------------------" << endl;
					strcpy(record.BranchNumber, employee.BranchNumber.c_str());
					strcpy(record.ServiceDate, detailservice.ServiceDate.c_str());
					strcpy(record.EmployeeNumber, employee.EmployeeNumber.c_str());
					record.ServiceCost = detailservice.ServiceCost;
					strcpy(record.CustomerName, detailservice.Name.c_str());
					strcpy(record.CustomerPhone, detailservice.PhoneNumber.c_str());
					strcpy(record.PetClass, detailservice.PetClass.c_str());
					strcpy(record.PetName, detailservice.PetName.c_str());
					record.Service = detailservice.Service;
					record.ServiceOption = detailservice.Option;
					File.clear();
					File.seekp(File.tellg() - streamoff(sizeof(record)), ios::beg);
					File.write(reinterpret_cast<char *>(&record), sizeof(record));
					isFound = true;
					break;
				}
			}
			if(isFound == false)
			{
				cout << "-------------------------------------------------------------" << endl;
				cout << "No data. " << endl;
				cout << "-------------------------------------------------------------" << endl;
			}
		}
		else if(Option == 4)
		{
			string PhoneNumber;
			Record record;
			cout << "Which record do you want to display(Please input the customer's phone number)? " << endl;
			cout << "Customer's phone number: ";
			cin >> PhoneNumber;
			File.clear();
			File.seekg(0, ios::beg);
			ofstream FileOut("temp.dat", ios::binary);
			bool isFound = false;
			while(File.read(reinterpret_cast<char *>(&record), sizeof(record)))
			{
				if(record.CustomerPhone == PhoneNumber && isFound == false)
				{
					char YesorNo;
					isFound = true;
					// 顯示修改前資料 
					cout << "-------------------------------------------------------------" << endl;
					cout << "Branch's number: " << record.BranchNumber << endl;
					cout << "Service Date: " << record.ServiceDate << endl;
					cout << "Employee's number: " << record.EmployeeNumber << endl;
					cout << "The Serivce's total cost: " << record.ServiceCost << endl;
					cout << "The customer's name: " << record.CustomerName << endl;
					cout << "The customer's phone number: " << record.CustomerPhone << endl;
					cout << "The pet's class: " << record.PetClass << endl;
					cout << "The pet's name: " << record.PetName << endl;
					if(record.Service == 1)
					{
						cout << "The service: 1. Beauty. " << endl;
						if(record.ServiceOption == 1)
							cout << "The service option: 1. Take a bath. " << endl;
						else if(record.ServiceOption == 2)
							cout << "The service option: 2. Trim pet's hair. " << endl;
						else
							cout << "The service option: 3. Take a bath and trim pet's hair. " << endl;
					}
					else
					{
						cout << "The service: 2. Medical. " << endl;
						if(record.ServiceOption == 1)
							cout << "The service option: 1. Cold medical. " << endl;
						else
							cout << "The service option: 2. Surgery. " << endl;
						
					}
					cout << "-------------------------------------------------------------" << endl;
					cout << "Do you want to delete this record(Y/N)? ";
					cin >> YesorNo;
					if(YesorNo == 'Y' || YesorNo == 'y')
					{
						File.clear();
						File.seekg(0, ios::beg);
						while(File.read(reinterpret_cast<char *>(&record), sizeof(record)))
							if(record.CustomerPhone != PhoneNumber)
								FileOut.write(reinterpret_cast<char *>(&record), sizeof(record));
						File.close();
						FileOut.close();
						remove("list.txt");
						rename("temp.dat", "list.txt");
					}
					else
						continue;
					cout << "This record is deleted!!" << endl;
					break;
				}
			}
			if(isFound == false)
			{
				cout << "-------------------------------------------------------------" << endl;
				cout << "No data. " << endl;
				cout << "-------------------------------------------------------------" << endl;
			}
		}
		else
		{
			cout << "OK!! See you next time. " << endl; 
			cout << "End this program. " << endl;
			File.close();
			break;
		}
		
	}
	return 0;
}

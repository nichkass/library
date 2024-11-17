#include <iostream>
#include "Person.h"
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;


Person::Person( int id,  string* name,  string* NumberPhone,  string* email) : id(id), name(name), NumberPhone(NumberPhone), email(email)
{
	file.open("take_list.txt", fstream::out | fstream::in | fstream::app);
	if (file.is_open()) { 
		cout << "File sucessful open" << endl;
		file << id << ' ';
		file << name << ' ';
		file << NumberPhone << ' ';
		file << email << endl;
	}
	else cout << "File is not open" << endl;
	file.close();
}

int Person::GetId() { return this->id; }
string* Person::GetName() { return this->name; }
string* Person::GetNumberPhone() { return this->NumberPhone; }
string* Person::GetEmail() { return this->email; }


void Person::SetId(int& id) { this->id = id; }
void Person::SetName(string*& name) { this->name = name; }
void Person::SetNumberPhone(string*& NumberPhone) { this->NumberPhone = NumberPhone; }
void Person::SetEmail(string*& email) { this->email = email; }

Person::~Person()
{
	delete[] name;
	delete[] NumberPhone;
	delete[]email;
}



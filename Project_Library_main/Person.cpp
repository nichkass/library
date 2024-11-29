#pragma once
#include <iostream>
#include "Person.h"
#include <fstream>
//#include <filesystem>
#include <string>

using namespace std;
//namespace fs = std::filesystem;

Person::Person() {}
Person::Person(const string& id, const string& name, const string& NumberPhone, const  string& email)
{
	this->id = new string(id);
	this->name = new string(name);
	this->NumberPhone = new string(NumberPhone);
	this->email = new string(email);
	file.open("take_list.txt", fstream::out | fstream::in | fstream::app);
	if (file.is_open()) {
		cout << "File sucessful open" << endl;
		file << id << ' ';
		file << name << ' ';
		file << NumberPhone << ' ';
		file << email << endl;
		file.close();
	}
	else cout << "File is not open" << endl;
	
}
Person::Person(const Person& person)
{
	this->id = person.id;
	this->name = person.name;
	this->NumberPhone = person.NumberPhone;
	this->email = person.email;
}
string* Person::GetId() { return this->id; }
string* Person::GetName() { return this->name; }
string* Person::GetNumberPhone() { return this->NumberPhone; }
string* Person::GetEmail() { return this->email; }


void Person::SetId(string& id) { this->id = new string(id); }
void Person::SetName(string& name) { this->name = new string(name); }
void Person::SetNumberPhone(string& NumberPhone) { this->NumberPhone = new string(NumberPhone); }
void Person::SetEmail(string& email) { this->email = new string(email); }

Person::~Person()
{
	delete[] name;
	delete[] NumberPhone;
	delete[]email;
	delete[] id;
}



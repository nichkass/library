#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

class Person
{
public:
	fstream file;
	Person( int id,  string* name,  string* NumberPhone,  string* email);

	int GetId();
	string* GetName();
	string* GetNumberPhone();
	string* GetEmail();


	void SetId(int& id);
	void SetName(string*& name);
	void SetNumberPhone(string*& NumberPhone);
	void SetEmail(string*& email);

	~Person();
private:
	int id;
	string* name;
	string* NumberPhone;
	string* email;
	
};
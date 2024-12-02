#pragma once
#include <iostream>
#include <fstream>
//#include <filesystem>
#include <string>
#include "Book.h"

using namespace std;
//namespace fs = std::filesystem;

class Person
{
public:
	Person();
	 fstream file;
	Person(const string& id, const string& name, const  string& NumberPhone, const  string& email);
	Person(const Person& person);
	 string* GetId();
	 string* GetName();
	 string* GetNumberPhone();
	 string* GetEmail();
	 Book* GetMyBook();

	 void SetId(string& id);
	 void SetName(string& name);
	 void SetNumberPhone(string& NumberPhone);
	 void SetEmail(string& email);
	 void TakeBook(Book& book);
	 void GiveBook(Book& book);
	 
	~Person();
private:
	 string* id;
	 string* name;
	 string* NumberPhone;
	 string* email;
	 Book* MyBook;
};
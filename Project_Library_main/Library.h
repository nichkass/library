#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include "Person.h"
#include <fstream>
#include "windows.h"
//#include <filesystem>

using namespace std;
//namespace fs = std::filesystem;


class Library
{
public:
	 fstream file_lib;
	 fstream file_lib2;

	 fstream file_for_person;

	 fstream file_admin;

	 Library();

	  void AddBook(Book& book);

	  void DeleteBook(Book& book);
	  void DeletePerson(Person& person);

	  void PrintList();
	  void PrintListPersons();

	  void PrintListBookForPerson();
	  void PrintOneBook(Book& book);

	  bool Check_admin(string &name, string &password);

	  Book* SearchBook(string* NameBook);
	  Person* SearchPerson(string* name, string* number);

	  vector<Book*> books;
	  vector<Person*> persons;
	  vector<Book*> persons_book;
};
#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include "Person.h"
#include <fstream>
//#include <filesystem>

using namespace std;
//namespace fs = std::filesystem;


class Library
{
public:
	 fstream file_lib;
	 fstream file_lib2;

	 fstream file_for_person;

	Library();

	  void AddBook(Book& book);

	  void DeleteBook(Book& book);
	  void DeletePerson(Person& person);

	  void PrintList();
	  void PrintListPersons();

	  void PrintListBookForPerson();
	  void PrintOneBook(Book& book);

	  Book* SearchBook(string* NameBook);

	  vector<Book*> books;
	  vector<Person*> persons;
};
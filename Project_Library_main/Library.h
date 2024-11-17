#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include "Person.h"
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Library
{
public:
	Library(const string& filenamebook, const string& filenameperson);

	void AddBook(Book& book);
	
	//void DeleteBook(Book book);

	void PrintList();

	void SearchBook(string* NameBook);

	vector<Book> books;
	vector<Person> persons;
};
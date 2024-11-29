#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Book.h"
#include "Library.h"

using namespace std;

class Admin
{
public:
	Admin();

	void PrintListBooks();

	void PrintListPersons();

	void AddNewBook(Book& book);

	void DeleteBook(Book &book);

	void SearchBook(string* NameBook);
};


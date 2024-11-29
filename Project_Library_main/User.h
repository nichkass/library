#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Book.h"
#include "Library.h"

using namespace std;

class User
{
public:
	User();

	void PrintListBooks();

	void SearchBook(string* NameBook);

	void SetMyBook(Book& book);

	Book GetMyBook();
private:
	Book MyBook;

};


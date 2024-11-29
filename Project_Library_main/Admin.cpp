#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Book.h"
#include "Library.h"
#include "Admin.h"

using namespace std;

Admin::Admin()
{
	Library lib;
}
void Admin::PrintListBooks()
{
	Library lib;
	lib.PrintList();
}

void Admin::PrintListPersons()
{
	Library lib;
	lib.PrintListPersons();
}

void Admin::AddNewBook(Book& book)
{
	Library lib;
	lib.AddBook(book);
}

void Admin::DeleteBook(Book &book)
{
	Library lib;
	lib.DeleteBook(book);
}

void Admin::SearchBook(string* NameBook)
{
	Library lib;
	lib.SearchBook(NameBook);
}

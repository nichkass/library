#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Book.h"
#include "Library.h"
#include "User.h"

using namespace std;

User::User()
{
	Library lib;
}
void User::PrintListBooks()
{
	Library lib;
	lib.PrintList();
}

void User::SearchBook(string* NameBook)
{
	Library lib;
	lib.SearchBook(NameBook);
}

void User::SetMyBook(Book& book)
{
	this->MyBook = book;
}

Book User::GetMyBook()
{
	return MyBook;
}
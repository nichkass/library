#pragma once
#include <iostream>
#include "Book.h"
#include <fstream>
#include <filesystem>
#include <string>
#include "windows.h"

using namespace std;
namespace fs = std::filesystem;

Book::Book() { this->takes = true; }
Book& Book::operator=(const Book& book)
{

	//Book newbook(book);
	this->author = book.author;
	this->name = book.name;
	this->genre = book.genre;
	this->date = book.date;
	return *this;
}

Book::Book(const string& genre, const string& author, const string& name, const string& date)
{
	
	this->author = new string(author);
	this->name = new string(name);
	this->genre = new string(genre);
	this->date = new string(date);
	string namefile = name + ".txt";
	file_book.open(namefile, fstream::out | fstream::in | fstream::app);
	if (file_book.is_open()) {
		file_book.close();
	}
	else cout << "Error: File is not open" << endl;
	
}
Book::Book(const Book&book)
{

	this->author = new string(*book.author);
	this->name = new string(*book.name);
	this->genre = new string(*book.genre);
	this->date = new string(*book.date);
}

void Book::New_Book()
{
	string namefile = *this->name + ".txt";
	file_book.open(namefile, fstream::out | fstream::in | fstream::app);
	if (file_book.is_open()) {
		file_book.close();
	}
	else cout << "Error: File is not open" << endl;
	
}
string* Book::GetAuthor() { return this->author; }
string* Book::GetName() { return this->name; }
string* Book::GetGenre() { return this->genre; }
string* Book::GetDate() { return this->date; }
bool Book::GetPrivate() { return this->takes; }

void Book::SetAuthor(string& author) { this->author = new string(author); }
void Book::SetName(string& name) { this->name = new string(name); }
void Book::SetGenre(string& genre) { this->genre = new string(genre); }
void Book::SetDate(string& date) { this->date = new string(date); }
void Book::SetPrivate() { this->takes = false; }
void Book::ChangePrivate() { this->takes = true;}

void Book::Print_one_book(Book& book)
{
	cout << *book.GetGenre() << ' ' << *book.GetAuthor() << ' ' << *book.GetName() << ' ' << *book.GetDate() << endl;
}

Book::~Book()
{
	delete author;
	delete name;
	delete genre;
	delete date;
}
#pragma once
#include <iostream>
#include "Book.h"
#include <fstream>
//#include <filesystem>
#include <string>

using namespace std;
//namespace fs = std::filesystem;
Book& Book::operator=(const Book& book)
{

	//Book newbook(book);
	this->author = book.author;
	this->name = book.name;
	this->genre = book.genre;
	this->date = book.date;
	return *this;
}

Book::Book(const string& author, const string& name, const string& genre, const string& date)
{
	
	this->author = new string(author);
	this->name = new string(name);
	this->genre = new string(genre);
	this->date = new string(date);
	string namefile = name + ".txt";
	file_book.open(namefile, fstream::out | fstream::in | fstream::app);
	if (file_book.is_open()) {
		cout << "File sucessful open" << endl;
		file_book << author << ' ';
		file_book << genre << ' ';
		file_book << name << ' ';
		file_book << date << std::endl;
	}
	else cout << "File is not open" << endl;
	file_book.close();
}
Book::Book(const Book&book)
{
	delete[] author;
	delete[] name;
	delete[] genre;
	delete[] date;

	this->author = new string(*book.author);
	this->name = new string(*book.name);
	this->genre = new string(*book.genre);
	this->date = new string(*book.date);
}
string* Book::GetAuthor() { return this->author; }
string* Book::GetName() { return this->name; }
string* Book::GetGenre() { return this->genre; }
string* Book::GetDate() { return this->date; }

void Book::SetAuthor(string& author) { this->author = new string(author); }
void Book::SetName(string& name) { this->name = new string(name); }
void Book::SetGenre(string& genre) { this->genre = new string(genre); }
void Book::SetDate(string& date) { this->date = new string(date); }

Book::~Book()
{
	delete[]author;
	delete[]name;
	delete[]genre;
	delete[]date;
}
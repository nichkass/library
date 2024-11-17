#include <iostream>
#include "Book.h"
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

Book::Book( string*genre,  string* author,  string* name,  int date) : genre(genre), author(author), name(name), date(date)
{
	string namefile = *name + ".txt"; 
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

string* Book::GetAuthor() { return this->author; }
string* Book::GetName() { return this->name; }
string* Book::GetGenre() { return this->genre; }
int Book::GetDate() { return this->date; }

void Book::SetAuthor(string*& author) { this->author = author; }
void Book::SetName(string*& name) { this->name = name; }
void Book::SetGenre(string*& genre) { this->genre = genre; }
void Book::SetDate(int& date) { this->date = date; }

Book::~Book() 
{
	delete[]author;
	delete[]name;
	delete[]genre;
}
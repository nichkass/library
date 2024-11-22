#pragma once
#include <iostream>
#include <fstream>
//#include <filesystem>
#include <string>

using namespace std;
//namespace fs = std::filesystem;

class Book
{
public:
	Book& operator=(const Book& book);

	fstream file_book;
	Book(const string& author, const string& name, const string& genre, const string& date);
	Book(const Book&book);
	string* GetAuthor();
	string* GetName();
	string* GetGenre();
	string* GetDate();

	void SetAuthor(string& author);
	void SetName(string& name);
	void SetGenre(string& genre);
	void SetDate(string& date);

	~Book();

private:
	string* author;
	string* name;
	string* genre;
	string* date; 
};
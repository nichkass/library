#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

class Book
{
public:

	fstream file_book;
	Book( string* genre,  string* author,  string* name,  int date);

	string* GetAuthor();
	string* GetName();
	string* GetGenre();
	int GetDate();

	void SetAuthor(string*& author);
	void SetName(string*& name);
	void SetGenre(string*& genre);
	void SetDate(int& date);

	~Book();

private:
	string* author;
	string* name; 
	string* genre;
	int date;
};
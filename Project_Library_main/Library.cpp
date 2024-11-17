#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Person.h"
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

Library::Library(const string& filenamebook, const string& filenameperson)
{
    ifstream file(filenamebook);

    if (file.is_open())
    { 
        string line; 
        string genre; string author; string name;
        string year;
        while (getline(file, line, ' ')) 
        {
            genre = line;
            author = line;
            name = line;
            year = line;
        }
        books.emplace_back(genre, author, name, year);
        file.close();
    }
    else 
    {
        std::cerr << "Unable to open file with books" << std::endl; 
    }

    ifstream file1(filenameperson);

    if (file1.is_open()) 
    {
        string line; 
        string id; string name; string NumberPhone;
        string email;
        while (getline(file1, line, ' '))
        {
            id = line;  
            name = line;  
            NumberPhone = line;  
            email = line;
        }
        persons.emplace_back(id, name, NumberPhone, email);   
        file1.close(); 
    }
    else
    {
        std::cerr << "Unable to open file with persons" << std::endl;
    }
}

void Library::AddBook(Book& book) 
{
	books.push_back(book);
}

//void Library::DeleteBook(Book book)
//{
//	books.erase(find(books.begin(), books.end(), book));
//}

void Library::PrintList()
{
	for (int i = 0; i < books.size(); i++)
	{
		cout << books[i].GetAuthor() << ' ' << books[i].GetGenre() << ' ' << books[i].GetName() << ' ' << books[i].GetDate() << endl;
	}
}

void Library::SearchBook(string* NameBook)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].GetName() == NameBook) cout << books[i].GetAuthor() << ' ' << books[i].GetGenre() << ' ' << books[i].GetName() << ' ' << books[i].GetDate() << endl; 
	}
}



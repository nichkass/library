#pragma once
#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Person.h"
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;



Library::Library() {}

void Library::AddBook(Book& book)
{
    file_lib.open("Library_books.txt", fstream::out | fstream::in | fstream::app);
    books.push_back(book);
    if (file_lib.is_open())
    {
        for (int i = 0; i < books.size(); i++)
        {
            file_lib << *books[i].GetGenre() << ' ' << *books[i].GetAuthor() << ' ' << *books[i].GetName() << ' ' << *books[i].GetDate() << endl;
        }
    }
    else cout << "File lib_books is not open to write" << endl;
    file_lib.close();
}

void Library::DeleteBook(Book& book)
{
    file_lib.open("Library_books.txt", fstream::out | fstream::in | fstream::app); 

    for (auto i = books.begin() ; i < books.end(); i++)
    {
        if (i->GetName() == book.GetName() && i->GetGenre() == book.GetGenre() && i->GetDate() == book.GetDate() && i->GetAuthor() == book.GetAuthor())
        {
            books.erase(i);
            book.~Book();
        }
    }

    if (file_lib.is_open())
    {
        for (int i = 0; i < books.size(); i++)
        {
            file_lib << books[i].GetGenre() << ' ' << books[i].GetAuthor() << ' ' << books[i].GetName() << ' ' << books[i].GetDate() << endl;
        }
        file_lib.close();
    }
    else cout << "File lib_books is not open to write" << endl;
}

void Library::PrintList()
{
    for (int i = 0; i < books.size(); i++)
    {
        cout << *books[i].GetAuthor() << ' ' << *books[i].GetGenre() << ' ' << *books[i].GetName() << ' ' << *books[i].GetDate() << endl;
    }
}

void Library::PrintListPersons()
{
    for (int i = 0; i < persons.size(); i++)
    {
        cout << *persons[i].GetId() << ' ' << *persons[i].GetName() << ' ' << *persons[i].GetNumberPhone() << ' ' << *persons[i].GetEmail() << endl;
    }
}

Book Library::SearchBook(string* NameBook)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].GetName() == NameBook) return books[i];
    }
}



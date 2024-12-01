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
    file_lib.open("Library_books.txt", fstream::out);
    books.push_back(&book);
    if (file_lib.is_open())
    {
        for (int i = 0; i < books.size(); i++)
        {
            file_lib << *books[i]->GetGenre() << ' ' << *books[i]->GetAuthor() << ' ' << *books[i]->GetName() << ' ' << *books[i]->GetDate() << endl;
        }
        file_lib.close();
    }
    else cout << "File lib_books is not open to write" << endl;
    
}

void Library::DeleteBook(Book& book)
{
    fs::path p = fs::current_path() / (*(book.GetName()) + ".txt");
    

    bool flag = false;
    auto i = books.begin();
    for ( ; i < books.end(); i++)
    {
        if (*(*i)->GetName() == *book.GetName())
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        (*i)->~Book();
        books.erase(i);
    }
    
    if (fs::exists(p))
    {
        fs::remove(p);
    }
    file_lib.open("Library_books.txt", fstream::out);
    if (file_lib.is_open())
    {
        for (int i = 0; i < books.size(); i++)
        {
            file_lib << *books[i]->GetGenre() << ' ' << *books[i]->GetAuthor() << ' ' << *books[i]->GetName() << ' ' << *books[i]->GetDate() << endl;
        }
        file_lib.close();
    }
    else cout << "File lib_books is not open to write" << endl;

}

void Library::PrintList()
{
    for (int i = 0; i < books.size(); i++)
    {
        cout << *books[i]->GetGenre() << ' ' << *books[i]->GetAuthor() << ' ' << *books[i]->GetName() << ' ' << *books[i]->GetDate() << endl;
    }
}

void Library::PrintListPersons()
{
    for (int i = 0; i < persons.size(); i++)
    {
        cout << *persons[i]->GetId() << ' ' << *persons[i]->GetName() << ' ' << *persons[i]->GetNumberPhone() << ' ' << *persons[i]->GetEmail() << endl;
    }
}


Book* Library::SearchBook(string* NameBook)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (*books[i]->GetName() == *NameBook) return books[i];
    }
}



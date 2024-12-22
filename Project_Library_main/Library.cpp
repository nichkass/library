#pragma once
#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Person.h"
#include <fstream>
#include <filesystem>
#include <string>
#include "windows.h"

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

void Library::DeletePerson(Person& person)
{
    bool flag = false;
    auto i = persons.begin();
    for (; i < persons.end(); i++)
    {
        if (*(*i)->GetName() == *person.GetName())
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        persons.erase(i);
    }
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
        cout << *persons[i]->GetId() << ' ' << *persons[i]->GetName() << ' ' << *persons[i]->GetNumberPhone() << ' ' << *persons[i]->GetEmail() << endl;;
        cout << *persons_book[i]->GetGenre() << ' ' << *persons_book[i]->GetAuthor() << ' ' << *persons_book[i]->GetName() << ' ' << *persons_book[i]->GetDate() << endl;
    }
}

void Library::PrintListBookForPerson()
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i]->GetPrivate() == true)
        {
            cout << *books[i]->GetGenre() << ' ' << *books[i]->GetAuthor() << ' ' << *books[i]->GetName() << ' ' << *books[i]->GetDate() << endl;
        }
    }
}

void Library::PrintOneBook(Book& book)
{
    cout << *(book.GetGenre()) << ' ' << *(book.GetAuthor()) << ' ' << *(book.GetName()) << ' ' << *(book.GetDate()) << endl;
}

Book* Library::SearchBook(string* NameBook)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (*books[i]->GetName() == *NameBook) return books[i];
    }
    return nullptr;
}

Person* Library::SearchPerson(string* name, string* number)
{
    for (int i = 0; i < persons.size(); i++)
    {
        if (*persons[i]->GetName() == *name && *persons[i]->GetNumberPhone() == *number) return persons[i];
    }
    return nullptr;
}
bool Library::Check_admin(string& name, string& password)
{
    file_admin.open("Library_admin.txt", fstream::in);

    if (file_admin.is_open())
    {
        string name1, password1;
        bool res = false;
        while (getline(file_admin, name1, ' ') && getline(file_admin, password1))
        {
            if (name1 == name && password1 == password) { res = true; }
        }
        file_admin.close();
        if (res) { return res; }
        else return false;
    }
    else cout << "File_admin is not open to read" << endl;
}

#include <iostream>
#include <string>
#include "Person.h"
#include "Book.h"
#include "Library.h"
#include "Admin.h"
#include "User.h"

using namespace std;

int main()
{
    bool flag = false;
    Book book;
    int action;
    do {
        cout << "Chouse 1. Admin  2. User" << endl;
        int person;
        
        
        Library lib;


        //
        lib.file_lib.open("Library_books.txt", fstream::out | fstream::in | fstream::app);
        lib.file_lib2.open("Library_persons.txt", fstream::out | fstream::in | fstream::app);

        //Чтение книги
        if (lib.file_lib.is_open())
        {
            string line;
            string genre, author, name, year;
            Book new_book;
            while (getline(lib.file_lib, line, ' '))
            {
                genre = line[0];
                author = line[1];
                name = line[2];
                year = line[3];
                new_book.SetGenre(genre);
                new_book.SetAuthor(author);
                new_book.SetName(name);
                new_book.SetDate(year);
                lib.books.push_back(new_book);
            }
            
        }
        else cout << "File lib_book is not open to read" << endl;
        lib.file_lib.close();

        //Чтение пользователей
        if (lib.file_lib2.is_open())
        {
            string line;
            string id, name, number, email;
            Person person;
            while (getline(lib.file_lib2, line, ' '))
            {
                id = line[0];
                name = line[1];
                number = line[2];
                email = line[3];
                person.SetId(id);
                person.SetName(name);
                person.SetNumberPhone(number);
                person.SetEmail(email);
                lib.persons.push_back(person);
            }
            
        }
        else cout << "File lib_persons is not open to read" << endl;
        lib.file_lib2.close();



        lib.file_lib.open("Library_books.txt", fstream::out | fstream::in | fstream::app); 
        lib.file_lib2.open("Library_persons.txt", fstream::out | fstream::in | fstream::app);

        //Запись из вектор книг
        if (lib.file_lib.is_open())
        {
            for (int i = 0; i < lib.books.size(); i++)
            {
                lib.file_lib << lib.books[i].GetGenre() << ' ' << lib.books[i].GetAuthor() << ' ' << lib.books[i].GetName() << ' ' << lib.books[i].GetDate() << endl;
            }
            
        }
        else cout << "File lib_books is not open to write" << endl;
        lib.file_lib.close();

        //запись из вектор пользователей
        if (lib.file_lib2.is_open()) {
            for (int i = 0; i < lib.persons.size(); i++)
            {
                lib.file_lib2 << lib.persons[i].GetId() << ' ' << lib.persons[i].GetName() << ' ' << lib.persons[i].GetNumberPhone() << ' ' << lib.persons[i].GetEmail() << endl;
            }
            
        }
        else cout << "File lib_persons is not open to write" << endl;
        lib.file_lib2.close();


        //



        cin >> person;
        if (person == 1)
        {
            cout << "1. List_Books  2. List_Persons  3. Add_New_Book  4. Delete_Book  5. Search_Book" << endl;
            cin >> action;
            do {
                if (action == 1)
                {
                    cout << "Books: " << endl;
                    cout << endl;
                    lib.PrintList();
                }
                else if (action == 2)
                {
                    cout << "Persons: " << endl;
                    cout << endl;
                    lib.PrintListPersons();

                }
                else if (action == 3)
                {
                    string genre, author, name, date;

                    cout << "Write: genre, author, name, date" << endl;
                    cin.ignore();
                    cout << "Genre: "; getline(cin, genre);
                    cout << "Author "; getline(cin, author);
                    cout << "Name: "; getline(cin, name);
                    cout << "Date: "; getline(cin, date);
                    Book boooook;
                    boooook.SetGenre(genre);
                    boooook.SetAuthor(author);
                    boooook.SetName(name);
                    boooook.SetDate(date);
                    book.New_Book(boooook);
                    lib.AddBook(book);
                    cout << "Your book add" << endl;
                }
                else if (action == 4)
                {
                    string name;

                    cout << "Write: name" << endl;
                    cin.ignore();
                    cout << "Name: "; getline(cin, name);
                    string* str = &name;
                    Book book = lib.SearchBook(str);
                    lib.DeleteBook(book);
                    cout << "Your book deleted" << endl;

                    //Запись из вектор книг
                    if (lib.file_lib.is_open())
                    {
                        for (int i = 0; i < lib.books.size(); i++)
                        {
                            lib.file_lib << lib.books[i].GetGenre() << ' ' << lib.books[i].GetAuthor() << ' ' << lib.books[i].GetName() << ' ' << lib.books[i].GetDate() << endl;
                        }

                    }
                    else cout << "File lib_books is not open to write" << endl;
                    lib.file_lib.close();
                }
                else if (action == 5)
                {
                    string name;

                    cout << "Write: name" << endl;
                    cin.ignore();
                    cout << "Name: "; getline(cin, name);
                    string* str = &name;
                    Book book = lib.SearchBook(str);
                    book.Print_one_book(book);
                }
                cout << "1. List_Books  2. List_Persons  3. Add_New_Book  4. Delete_Book  5. Search_Book" << endl;
                cin >> action;


            } while (action != 0);
        }
        else if (person == 2)
        {

        }
        else
        {
            cout << "Error you dont chose your person" << endl;
        }


        
    } while (action != 0);

    
}

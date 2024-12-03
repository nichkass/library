#include <iostream>
#include <string>
#include "Person.h"
#include "Book.h"
#include "Library.h"
#include <fstream>
#include <filesystem>
#include <random>

using namespace std;

random_device dev;
mt19937 rng(dev());
uniform_int_distribution<> dist(100000, 1000000);

int main()
{
    bool flag = false;
    bool Flag = false;
    int action = -1;
    int action2 = -1;
    Library lib;

    lib.file_lib.open("Library_books.txt", fstream::in);
    lib.file_lib2.open("Library_persons.txt", fstream::in);

    //Чтение книги
    if (lib.file_lib.is_open())
    {
        string line;
        string genre, author, name, year;
        Book* new_book = new Book();
        while (getline(lib.file_lib, genre, ' ') && getline(lib.file_lib, author, ' ')
            && getline(lib.file_lib, name, ' ')
            && getline(lib.file_lib, year, ' '))
        {
            new_book->SetGenre(genre);
            new_book->SetAuthor(author);
            new_book->SetName(name);
            new_book->SetDate(year);
            lib.books.push_back(new_book);
            lib.file_lib.close();
        }
    }
    else cout << "File lib_book is not open to read" << endl;


    //Чтение пользователей
    if (lib.file_lib2.is_open())
    {
        string line;
        string id, name, number, email;
        Person* person = new Person();
        while (getline(lib.file_lib2, id, ' ') && getline(lib.file_lib2, name, ' ')
            && getline(lib.file_lib2, number, ' ') && getline(lib.file_lib2, email, ' '))
        {
            person->SetId(id);
            person->SetName(name);
            person->SetNumberPhone(number);
            person->SetEmail(email);
            lib.persons.push_back(person);
        }
    }
    else cout << "File lib_persons is not open to read" << endl;
    lib.file_lib2.close();

    lib.file_lib.open("Library_books.txt", fstream::out);
    lib.file_lib2.open("Library_persons.txt", fstream::out);


    //Запись из векторa книг в файл
    if (lib.file_lib.is_open())
    {
        for (int i = 0; i < lib.books.size(); i++)
        {
            lib.file_lib << *lib.books[i]->GetGenre() << ' ' << *lib.books[i]->GetAuthor() << ' ' << *lib.books[i]->GetName() << ' ' << *lib.books[i]->GetDate() << endl;
        }

    }
    else cout << "File lib_books is not open to write" << endl;
    lib.file_lib.close();

    //запись из вектора пользователей в файл
    if (lib.file_lib2.is_open()) {
        for (int i = 0; i < lib.persons.size(); i++)
        {
            lib.file_lib2 << *lib.persons[i]->GetId() << ' ' << *lib.persons[i]->GetName() << ' ' << *lib.persons[i]->GetNumberPhone() << ' ' << *lib.persons[i]->GetEmail() << endl;
        }

    }
    else cout << "File lib_persons is not open to write" << endl;
    lib.file_lib2.close();

    //



    do {
        cout << "Chouse 1. Admin  2. User" << endl;
        string pers; int person = -1;
        getline(cin, pers);
        
        do
        {
            try { person = stoi(pers); }
            catch (...)
            {
                cout << "Write number please" << endl;
                cout << "Chouse 1. Admin  2. User" << endl;
                getline(cin, pers);
            }
        } while (person != 1 && person != 2);

        if (person == 1)
        {
            cout << "Write: nickname, password" << endl;
            string password, nickname;
            cout << "Nickname: ";
            cin.ignore();
            getline(cin, nickname);
            cout << "Pssword: ";
            cin.ignore();
            getline(cin, password); //создать файл с админами и проверять админа
            //Добавить функцию поиск у какого пользователя книга
            // найти книгу в файле с пользователями и вывести пользователя
            cout << "1. List_Books  2. List_Persons  3. Add_New_Book  4. Delete_Book  5. Search_Book 0. Exit" << endl;
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
                    cout << "Author: "; getline(cin, author);
                    cout << "Name: "; getline(cin, name);
                    cout << "Date: "; getline(cin, date);
                    Book* book = new Book();
                    book->SetGenre(genre);
                    book->SetAuthor(author);
                    book->SetName(name);
                    book->SetDate(date);
                    book->New_Book();
                    lib.AddBook(*book);
                    cout << "Your book add" << endl;
                }
                else if (action == 4)
                {
                    string name;

                    cout << "Write name book" << endl;
                    cin.ignore();
                    cout << "Name: "; getline(cin, name);
                    string* str = &name;
                    Book* book = lib.SearchBook(str);
                    lib.DeleteBook(*book);
                    cout << "Your book deleted" << endl;
                }
                else if (action == 5)
                {
                    string name;

                    cout << "Write name book" << endl;
                    cin.ignore();
                    cout << "Name: "; getline(cin, name);
                    string* str = &name;
                    Book* book = lib.SearchBook(str);
                    book->Print_one_book(*book);
                }

                cout << "1. List_Books  2. List_Persons  3. Add_New_Book  4. Delete_Book  5. Search_Book 0. Exit" << endl;
                cin >> action;


            } while (action != 0);
        }

        else if (person == 2)
        {
            Person* user = new Person();
            string name, number, email;
            cout << "Write your name, number phone, email" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Number phone: ";
            cin.ignore();
            getline(cin, number);
            cout << "Email: ";
            cin.ignore();
            getline(cin, email);

            int Id = dist(rng);
            string id = to_string(Id);
            user->SetName(name);
            user->SetEmail(email);
            user->SetId(id);
            user->SetNumberPhone(number);

            cout << "1. List_Books 2. Search_Book 3. Take_book 4. Give_book 5. Get_MyBook 0. Exit" << endl;
            cin >> action2;

            do
            {
                if (action2 == 1)
                {
                    cout << "Books: " << endl;
                    cout << endl;
                    lib.PrintListBookForPerson();
                }
                else if (action2 == 2)
                {
                    string name;
                    cout << "Write name book" << endl;
                    cin.ignore();
                    cout << "Name: "; getline(cin, name);
                    string* str = &name;
                    Book* book = lib.SearchBook(str);
                    if (book->GetPrivate() == true)
                        book->Print_one_book(*book);
                    else cout << "This book is already taken" << endl;
                }
                else if (action2 == 3)
                {
                    string name;
                    cout << "Write name book" << endl;
                    cin.ignore();
                    cout << "Name: "; getline(cin, name);
                    string* str = &name;
                    Book* book = lib.SearchBook(str);
                    if (book->GetPrivate() == true)
                        user->TakeBook(*book);
                    else cout << "This book is already taken" << endl;

                    lib.persons.push_back(user);

                    lib.file_lib2.open("Library_persons.txt", fstream::out);
                    if (lib.file_lib2.is_open())
                    {
                        for (int i = 0; i < lib.persons.size(); i++)
                        {
                            lib.file_lib2 << *(lib.persons[i]->GetId()) << ' ' << *(lib.persons[i]->GetName()) << ' ' << *(lib.persons[i]->GetNumberPhone()) << ' ' << *(lib.persons[i]->GetEmail()) << ' ' << endl;
                        }
                    }
                    lib.file_lib2.close();

                    Flag = true;
                }
                else if (action2 == 4)
                {
                    user->GiveBook(*(user->GetMyBook()));
                    cout << "You gave the book away" << endl;
                    lib.DeletePerson(*user);
                    Flag = false;
                }
                else if (action2 == 5)
                {
                    if (user->GetMyBook() != nullptr)
                        lib.PrintOneBook(*(user->GetMyBook()));
                    else cout << "You dont have any books" << endl;
                }

                if (action2 == 0 && Flag == true)
                {
                    cout << "you have not returned the book, please return the book to the library" << endl;
                }
                cout << "1. List_Books 2. Search_Book 3. Take_book 4. Give_book 5. Get_MyBook 0. Exit" << endl;
                cin >> action2;

            } while (Flag != false);
        }
        else
        {
            cout << "Error: you dont chose your person" << endl;
        }



    } while (action == 0 && Flag == false);


}

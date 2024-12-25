#include <iostream>
#include <string>
#include "Person.h"
#include "Book.h"
#include "Library.h"
#include <fstream>
#include <filesystem>
#include <random>
#include "windows.h"

using namespace std;

random_device dev;
mt19937 rng(dev());
uniform_int_distribution<> dist(100000, 1000000);

void Loading()
{
    for (int i = 0; i < 3; i++)
    {
        Sleep(300);
        system("cls");
        cout << "..." << endl;
        Sleep(300);
        system("cls");
        cout << ".." << endl;
    }
    system("cls");
}

int main()
{
    bool flag = false;
    bool Flag = false;
    string action = "";
    string action2 = "";
    Library lib;

    lib.file_lib.open("Library_books.txt", fstream::in);
    lib.file_lib2.open("Library_persons.txt", fstream::in);

    //Reading file with all books
    if (lib.file_lib.is_open())
    {
        string genre, author, name, year;
        while (getline(lib.file_lib, genre, ' ') && getline(lib.file_lib, author, ' ')
            && getline(lib.file_lib, name, ' ')
            && getline(lib.file_lib, year))
        {

            Book* new_book = new Book();

            new_book->SetGenre(genre);
            new_book->SetAuthor(author);
            new_book->SetName(name);
            new_book->SetDate(year);
            lib.books.push_back(new_book);

        }
        lib.file_lib.close();
    }
    else cout << "File lib_book is not open to read" << endl;

    //Reading file with all user
    if (lib.file_lib2.is_open())
    {
        string id, name, number, email, genre, author, name2, year;
        while (getline(lib.file_lib2, id, ' ') && getline(lib.file_lib2, name, ' ') && getline(lib.file_lib2, number, ' ')
            && getline(lib.file_lib2, email, ' ') && getline(lib.file_lib2, genre, ' ') && getline(lib.file_lib2, author, ' ')
            && getline(lib.file_lib2, name2, ' ') && getline(lib.file_lib2, year))
        {
            Person* person = new Person();
            person->SetId(id);
            person->SetName(name);
            person->SetNumberPhone(number);
            person->SetEmail(email);
            lib.persons.push_back(person);

            Book* new_book = new Book();

            new_book->SetGenre(genre);
            new_book->SetAuthor(author);
            new_book->SetName(name2);
            new_book->SetDate(year);
            lib.persons_book.push_back(new_book);
        }
        lib.file_lib2.close();
    }
    else cout << "File lib_persons is not open to read" << endl;



    bool exit = false;

    do {
        cout << "Chouse 1. Admin  2. User" << endl;
        string pers; int person = -1;
        cout << "Write '1' or '2': ";
        getline(cin, pers);

        //Checking for input
        do
        {
            try {

                person = stoi(pers);
                if (person != 1 && person != 2)
                {
                    cout << "Please write 1 or 2" << endl;
                    cout << "Chouse 1. Admin  2. User" << endl;
                    getline(cin, pers);
                }
            }
            catch (...)
            {
                cout << "Write number please" << endl;
                cout << "Chouse 1. Admin  2. User" << endl;
                cout << "Write '1' or '2': ";
                getline(cin, pers);
            }
        } while (person != 1 && person != 2);

        if (person == 1)
        {
            cout << "Write: nickname, password" << endl;
            string password, nickname;
            cout << "Nickname: ";
            getline(cin, nickname);
            cout << "Password: ";
            getline(cin, password);
            Sleep(1000);
            system("cls");
            Loading();
            if (lib.Check_admin(nickname, password)) {
                cout << "The correct password" << endl;
                Sleep(500);
                system("cls");
                cout << "1. List_Books  2. List_Users  3. Add_New_Book  4. Delete_Book  5. Search_Book 6. Search_User's_book 0. Exit" << endl;
                cout << "Your choice: ";
                getline(cin, action);
                do {
                    Loading();
                    if (action == "1" || action == "2" || action == "3" || action == "4" || action == "5" || action == "6") {
                        if (action == "1")
                        {
                            cout << "Books in the our library" << endl;
                            cout << endl;
                            lib.PrintList();
                        }
                        else if (action == "2")
                        {
                            cout << "Users" << endl;
                            cout << endl;
                            lib.PrintListPersons();
                        }
                        else if (action == "3")
                        {
                            string genre, author, name, date;
                            bool len = false; // To check the length
                            bool num = false; // To check the number in the name

                            bool check = false;

                            vector<char> numbers = { '1','2','3','4','5','6','7','8','9','0' };
                            cout << "Write information about book" << endl;
                            do {
                                cout << "Genre: "; 
                                getline(cin, genre);
                                for (int i = 0; i < genre.size(); i++)
                                {
                                    for (int j = 0; j < numbers.size(); j++)
                                    {
                                        if (numbers[j] == genre[i]) { num = true; }
                                    }
                                }
                                if (genre.size() > 20) { len = true; }
                                if (len) {
                                    cout << "Long genre!!" << endl;
                                }
                                if (num)
                                {
                                    cout << "There are numbers in the record" << endl;
                                }

                                if (num == true && len == true) check = true;
                                if (num == false && len == true) check = true;
                                if (num == true && len == false) check = true;
                                if (num == false && len == false) check = false;

                                num = false;
                                len = false;
                            } while (check != false);

                            do {
                                cout << "Author: "; getline(cin, author);
                                for (int i = 0; i < author.size(); i++)
                                {
                                    for (int j = 0; j < numbers.size(); j++)
                                    {
                                        if (numbers[j] == author[i]) { num = true; }
                                    }
                                }
                                if (author.size() > 30) { len = true; }
                                if (len) {
                                    cout << "Long author name!!" << endl;
                                }
                                if (num)
                                {
                                    cout << "There are numbers in the record" << endl;
                                }

                                if (num == true && len == true) check = true;
                                if (num == false && len == true) check = true;
                                if (num == true && len == false) check = true;
                                if (num == false && len == false) check = false;

                                num = false;
                                len = false;
                            } while (check != false);

                            do {
                                cout << "Name: "; getline(cin, name);
                                if (name.size() > 30) { len = true; }
                                if (len) {
                                    cout << "Long name!!" << endl;
                                }
                                if (len == true) check = true;
                                else check = false;

                                num = false;
                                len = false;
                            } while (check != false);

                            do {
                                cout << "Date: "; getline(cin, date);
                                vector<char> symbols = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
                                for (int i = 0; i < date.size(); i++)
                                {
                                    for (int j = 0; j < symbols.size(); j++)
                                    {
                                        if (symbols[j] == date[i]) { num = true; }
                                    }
                                }
                                if (date.size() > 4) { len = true; }
                                if (len) {
                                    cout << "Long date!!" << endl;
                                }
                                if (num)
                                {
                                    cout << "There are letters in the record" << endl;
                                }

                                if (num == true && len == true) check = true;
                                if (num == false && len == true) check = true;
                                if (num == true && len == false) check = true;
                                if (num == false && len == false) check = false;

                                num = false;
                                len = false;
                            } while (check != false);


                            Book* book = new Book();
                            book->SetGenre(genre);
                            book->SetAuthor(author);
                            book->SetName(name);
                            book->SetDate(date);
                            book->New_Book();
                            lib.AddBook(*book);
                            cout << "This book add" << endl;
                        }
                        else if (action == "4")
                        {
                            string name;

                            cout << "Write the name of the book to delete" << endl;
                            cout << "Name: "; getline(cin, name);
                            string* str = &name;
                            Book* book = lib.SearchBook(str);
                            if (book != nullptr) {
                                lib.DeleteBook(*book);
                                cout << "Your book deleted" << endl;
                            }
                            else cout << "This book is not in the library" << endl;
                        }
                        else if (action == "5")
                        {
                            string name;

                            cout << "Write the name of the book you want to find" << endl;
                            cout << "Name: ";
                            getline(cin, name);
                            string* str = &name;
                            Book* book = lib.SearchBook(str);
                            if (book != nullptr) { book->Print_one_book(*book); }
                            else cout << "This book is not in the library" << endl;
                        }
                        else if (action == "6")
                        {
                            string name, number;
                            cout << "Please write user's data" << endl;
                            cout << "Name: "; getline(cin, name);
                            cout << "Number: "; getline(cin, number);
                            string* s1 = &name; string* s2 = &number; 
                            Person* pers = lib.SearchPerson(s1, s2);
                            if (pers != nullptr)
                            {
                                for (int i = 0; i < lib.persons.size(); i++)
                                {
                                    if (*pers->GetId() == *lib.persons[i]->GetId())
                                    {
                                        cout << "The book that the user had: ";
                                        lib.PrintOneBook(*(lib.persons_book[i]));
                                    }
                                }
                            }
                            else cout << "Error: There is no such user" << endl;
                        }
                    }
                    else cout << "Error: There is no such choice " << endl;

                    cout << "1. List_Books  2. List_Users  3. Add_New_Book  4. Delete_Book  5. Search_Book 6. Search_User's_book 0. Exit" << endl;
                    cout << "Your choice: ";
                    getline(cin, action);


                } while (action != "0");
            }
            else
            {
                action = "0";
                cout << "Wrong password!" << endl;
                Sleep(500);
                system("cls");
            }
        }

        else if (person == 2)
        {
            Person* user = new Person();
            cout << "1. Authorization 2. Identification" << endl;
            string choice = "";
            bool for_authorization = true;
            bool check_info = false;
            cout << "Write '1' if you want to log in, or write '2' if you have already been logged in: ";
            getline(cin, choice);
            if (choice == "1")
            {
                string name, number, email;
                
                cout << "Write your name, number phone, email, please" << endl;

                do
                {
                    cout << "Name: ";
                    getline(cin, name);
                    if (name.size() > 30) { cout << "Long name!!" << endl; check_info = true; }
                    else { check_info = false; }
                } while (check_info != false);

                do {
                    bool numb = false;
                    bool len_num = false;


                    cout << "Number phone: ";
                    getline(cin, number);
                    
                    string num2 = number;
                    if (number[0] == '+')
                    {
                        string n = "";
                        for (int i = 1; i < number.size(); i++)
                        {
                             n += number[i];
                        }
                        number = n;
                    }
                    vector<char> figure = { '1','2','3','4','5','6','7','8','9','0'};
                    bool f = true;
                    for (int i = 0; i < number.size(); i++)
                    {
                        f = true;
                        for (int j = 0; j < figure.size(); j++)
                        {
                            if (number[i] == figure[j]) { f = false; break; }
                        }
                        if (f)
                        {
                            numb = true;
                            cout << "Wrong number!!" << endl;
                            break;
                        }
                    } 
                    number = num2;

                    if (number.size() > 13) {
                        cout << "Long number" << endl; len_num = true;
                    }
                    else { len_num = false; }

                    if (numb == true && len_num == false) check_info = true;
                    if (numb == false && len_num == true) check_info = true;
                    if (numb == true && len_num == true) check_info = true;
                    if (numb == false && len_num == false) check_info = false;
                } while (check_info != false);
                
                do {
                    cout << "Email: ";
                    getline(cin, email);
                    bool sobaka = true;
                    bool len_email = false;
                    int k = 0;
                    for (int i = 0; i < email.size(); i++)
                    {
                        if (email[i] == '@') { k++; }
                    }
                    if (k == 1) { sobaka = false; }
                    string str_expansion = "";
                    vector<string> expansion = { "@yandex.ru", "@mail.ru", "@inbox.ru", "@bk.ru", "@hotmail.com", "@live.com", "@xakep.ru", "@furmail.ru"};
                    if (!sobaka) {
                        for (int i = 0; i < email.size(); i++)
                        {
                            int j = i;
                            if (email[i] == '@')
                            {
                                while (i != email.size())
                                {
                                    str_expansion += email[i];
                                    i++;
                                }
                                i = j;
                            }


                        }
                        sobaka = true;
                    }
                    for (int i = 0; i < expansion.size(); i++)
                    {
                        if (str_expansion == expansion[i]) { sobaka = false; }
                    }
                    if (sobaka) { cout << "Wrong email" << endl; }
                    if (email.size() > 50) { cout << "Long email" << endl; len_email = true; }

                    if (sobaka == true && len_email == true) check_info = true;
                    if (sobaka == true && len_email == false) check_info = true;
                    if (sobaka == false && len_email == true) check_info = true;
                    if (sobaka == false && len_email == false) check_info = false;
                } while (check_info != false);
                int Id = dist(rng);
                string id = to_string(Id);
                user->SetId(id);
                user->SetName(name);
                user->SetEmail(email);
                user->SetNumberPhone(number);
            }
            else if (choice == "2")
            {
                string name, number;
                
                cout << "Please write your name, number phone, please" << endl;
                do {
                    cout << "Name: "; getline(cin, name);
                    cout << "Number: "; getline(cin, number);
                    string* s1 = &name; string* s2 = &number;
                    user = lib.SearchPerson(s1, s2);
                    if (user == nullptr) cout << "Wrong data" << endl;
                } while (user == nullptr);
                    
            }
            else {
                cout << "Error: There is no such choice " << endl; break;
            }
            

            cout << "1. List_Books 2. Search_Book 3. Take_book 4. Give_book 5. Get_MyBook 0. Exit" << endl;
            cout << "Your choice: ";
            getline(cin, action2);

            do
            {
                Loading();
                if (action2 == "1" || action2 == "2" || action2 == "3" || action2 == "4" || action2 == "5" || action2 == "0") {
                    if (action2 == "1")
                    {
                        cout << "Books in the library" << endl;
                        cout << endl;
                        lib.PrintListBookForPerson();
                    }
                    else if (action2 == "2")
                    {
                        string name;
                        cout << "Write name book" << endl;
                        cout << "Name: "; getline(cin, name);
                        string* str = &name;
                        Book* book = lib.SearchBook(str);
                        if (book != nullptr) {
                            if (book->GetPrivate() == true)
                                book->Print_one_book(*book);
                            else cout << "This book is already taken" << endl;
                        }
                        else cout << "This book is not in the library" << endl;
                    }
                    else if (action2 == "3")
                    {
                        string name;
                        cout << "Write the name of the book you want to take" << endl;
                        cout << "Name: "; getline(cin, name);
                        string* str = &name;
                        Book* book = lib.SearchBook(str);
                        if (book != nullptr) {
                            if (user->GetMyBook() == nullptr) {
                                if (book->GetPrivate() == true)
                                    user->TakeBook(*book);
                                else cout << "This book is already taken" << endl;
                                lib.persons.push_back(user);
                                lib.persons_book.push_back(book);
                                lib.file_lib2.open("Library_persons.txt", fstream::out);
                                if (lib.file_lib2.is_open())
                                {
                                    for (int i = 0; i < lib.persons.size(); i++)
                                    {
                                        lib.file_lib2 << *lib.persons[i]->GetId() << ' ' << *lib.persons[i]->GetName() << ' ' << *lib.persons[i]->GetNumberPhone() << ' ' << *lib.persons[i]->GetEmail() << ' ' << *book->GetGenre() << ' ' << *book->GetAuthor() << ' ' << *book->GetName() << ' ' << *book->GetDate() << endl;
                                    }
                                }
                                lib.file_lib2.close();

                                Flag = true;
                                cout << "You take this book" << endl;

                            }
                            else cout << "You already taken book, please give book in library" << endl;
                        }
                        else cout << "This book is not in the library" << endl;
                    }
                    else if (action2 == "4")
                    {
                        if (user->GetMyBook() != nullptr) {
                            user->GiveBook(*(user->GetMyBook()));
                            cout << "You gave the book away" << endl;
                            Flag = false;
                        }
                        else cout << "You dont have any book" << endl;
                    }
                    else if (action2 == "5")
                    {
                        cout << "Your book: ";
                        if (user->GetMyBook() != nullptr)
                            lib.PrintOneBook(*(user->GetMyBook()));
                        else cout << "You dont have any books" << endl;
                    }
                }
                else {
                    cout << "Error: There is no such choice " << endl;
                    action2 = "0";
                }
                if (action2 == "0" && Flag == true)
                {
                    cout << "you have not returned the book, please return the book to the library" << endl;
                }

                cout << "1. List_Books 2. Search_Book 3. Take_book 4. Give_book 5. Get_MyBook 0. Exit" << endl;
                cout << "Your choice: ";
                getline(cin, action2);

                if (action2 == "0" && Flag == false)
                {
                    for_authorization = false;
                }

            } while (for_authorization != false);

        }


        if (action == "0" || action2 == "0")
        {
            exit = true;
        }

    } while (exit != true);


    lib.file_lib.open("Library_books.txt", fstream::out);
    lib.file_lib2.open("Library_persons.txt", fstream::out);

    //Writing books
    if (lib.file_lib.is_open())
    {
        for (int i = 0; i < lib.books.size(); i++)
        {
            lib.file_lib << *lib.books[i]->GetGenre() << ' ' << *lib.books[i]->GetAuthor() << ' ' << *lib.books[i]->GetName() << ' ' << *lib.books[i]->GetDate() << endl;
        }

    }
    else cout << "File lib_books is not open to write" << endl;
    lib.file_lib.close();

    //Writing users
    if (lib.file_lib2.is_open()) {
        for (int i = 0; i < lib.persons.size(); i++)
        {
            lib.file_lib2 << *lib.persons[i]->GetId() << ' ' << *lib.persons[i]->GetName() << ' ' << *lib.persons[i]->GetNumberPhone() << ' ' << *lib.persons[i]->GetEmail() 
                << ' ' << *lib.persons_book[i]->GetGenre() << ' ' << *lib.persons_book[i]->GetAuthor() << ' ' 
                << *lib.persons_book[i]->GetName() << ' ' << *lib.persons_book[i]->GetDate() << endl;
        }
    }
    else cout << "File lib_persons is not open to write" << endl;
    lib.file_lib2.close();


}

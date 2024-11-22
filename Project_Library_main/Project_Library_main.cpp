#include <iostream>
#include "Person.h"
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{
    Person person("3254261", "name", "+7275269", "email");
    cout << "Person" << endl;
    Book book("genre", "aut", "namebook", "455616");
    cout << "Book" << endl;
    Library lib("aut.txt", "take_list.txt");
    cout << "Lib" << endl;
    lib.AddBook(book);
    cout << "Add" << endl;
    lib.PrintList();
    cout << endl;
    cout << "Print" << endl;
    lib.DeleteBook(book);
    cout << endl;
    cout << "Del" << endl;
    lib.PrintList();
    
}

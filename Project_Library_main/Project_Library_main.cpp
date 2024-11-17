#include <iostream>
#include "Person.h"
#include "Book.h"

using namespace std; 

int main() 
{
    int a = 1;
    string n = "name";
    string* n1 = &n;
    string num = "+23522636";
    string* num1 = &num;
    string em = "email";
    string* em1 = &em;
    Person person(a, n1, num1, em1); 
    cout << person.GetId() << endl; 
    string gen = "gen";
    string* gen1 = &gen;
    string aut = "author";
    string* aut1 = &aut;
    string name = "namebook";
    string* name1 = &name;
    int aa = 315;
    Book book(gen1, aut1, name1, aa);
    cout << book.GetName() << endl;

}

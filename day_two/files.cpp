// files.cpp : Nithin
// Desc: A program to illustrate the use of files, file opening in c++

#include <iostream>
#include <fstream> // we use this lib to work with files

using namespace std;

int main()
{
    char first_name[30], last_name[30];
    int age;
    char file_name[20];
    char choice[20] = "y";

    cout << "Enter file name: ";
    cin >> file_name;

    // create an ofstream called People.
    ofstream People(file_name, ios::out);

    while (true)
    {
        cout << "Enter first name: ";
        cin >> first_name;

        cout << "Enter last name: ";
        cin >> last_name;

        cout << "Enter age: ";
        cin >> age;

        // write the inputs to the file using the stream

        People << first_name << endl
               << last_name << endl
               << age << endl;

        cout << "Continue? (Y/n): ";
        cin >> choice;

        if (choice[0] == 'n' || choice[0] == 'N')
        {
            break;
        }
    }

    People.close();

    // create an ifstream to read the file
    ifstream People_read(file_name, ios::in);

    while (true)
    {
        People_read >> first_name >> last_name >> age;

        if (People_read.eof())
        {
            break;
        }

        cout << endl
             << "First name: " << first_name << endl;
        cout << "Last name: " << last_name << endl;
        cout << "Age: " << age << endl;
    }

    People_read.close();

    return 0;
}
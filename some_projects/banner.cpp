// banner.cpp : Nithin
// Desc : a program that prints english characters as banners

/*
4.
Suppose we wanted to print a banner for the following:
'FREEZY BREEZE MAKES THREE TREES FREEZE'

We want the letters to be pretty big since this is a banner:


FFFFF
F
FFF
F
F

EEEEE
E
EEE
E
EEEEE
etc.
Being a good problem decomposer, you probably noticed that rather than put all the cout's in the main function, it would be far more efficient to put them in functions. So we could have a 'printE' function and a 'printZ' function and so on.

Write a program with functions that creates a banner of a word or phrase with lots of repeated letters. Some possibilities:


FREEZY BREEZE MAKES FLEAS
SNEEZE TWEETLE BEETLE PADDLE BATTLE
SIX SICK CHICKS KICK
SUE SEWS SUE'S SOCKS
BEN BENDS BIM'S BROOM
*/

/*

Author comments

-   I hate this
-   I can not think of a way to do this rather than brute forcing it!
-   Start:      5:34pm 02-01-2024
-   End:        6:52pm 02-01-2024 (!? yes this took more than an hour.)

*/

#include <iostream>
#include <functional>
#include <map>
#include <limits>

// we use this library to use maps in c++ :')

using namespace std;

using pfunc = void (*)(char, int); // defining a function type

const int kLongDashLength = 5;
const int kMidDashLength = 4;
const int kShortDashLength = 3;

const int kMaxInputCharacters = 20;

void print(const char &character)
{
    cout << character;
    return;
}

void printDash(const char &c, int dashLength)
{
    for (int i = 0; i < dashLength; i++)
    {
        print(c);
    }
    print('\n');
}

void printEndChars(const char &c, int dashLength)
{
    for (int i = 0; i < dashLength; i++)
    {
        if (i == 0 || i == dashLength - 1)
        {
            print(c);
        }
        else
        {
            print(' ');
        }
    }
    print('\n');
}

void printF()
{
    const char c = 'F';
    print('\n');
    printDash(c, kLongDashLength);
    print(c);
    print('\n');
    printDash(c, kLongDashLength);
    print(c);
    print('\n');
    print(c);
    print('\n');
    return;
}

void printE()
{
    const char c = 'E';
    print('\n');
    printDash(c, kLongDashLength);
    print(c);
    print('\n');
    printDash(c, kShortDashLength);
    print(c);
    print('\n');
    printDash(c, kLongDashLength);
    return;
}

void printB()
{
    const char c = 'B';
    print('\n');
    printDash(c, kMidDashLength);
    printEndChars(c, kLongDashLength);
    printDash(c, kMidDashLength);
    printEndChars(c, kLongDashLength);
    printDash(c, kMidDashLength);
}

int main()
{
    // create a character : function map
    std::map<char, std::function<void()>> character_function_map; // this is an ordered map as opposed to unordered_map, which is basically hash_map

    // this is one way to add key value pairs to a predefined map
    character_function_map['F'] = printF;
    character_function_map['E'] = printE;
    character_function_map['B'] = printB;

    char input[kMaxInputCharacters];

    while (true)
    {
        cout << "\nEnter the string: ";
        if (!(cin >> input))
        {
            cout << "You did something wrong nigga" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else
        {
            cout << "Your input: " << input << endl;
            break;
        }
    };

    for (int i = 0; i < kMaxInputCharacters; i++)
    {
        char current_char = toupper(input[i]);

        if (character_function_map.count(current_char) == 1)
        {
            character_function_map[current_char]();
        }
        else
        {
            continue;
        }
    }

    return 0;
}
// random_numbers.cpp: Nithin
// Desc: a small, simple game to allow users to guess the random nunmber generated by the program.

#include <iostream>
#include <cstdlib>
#include <limits>
#include <time.h>

// cstdlib: various utility functions, including random number generation, memory allocation, process control, etc.

using namespace std;

int main()
{

    // we use the `srand()` function to seed the random number generator.
    srand((unsigned)time(NULL));

    int random_number = rand() % 100 + 1; // generates a random number between 1 and 100

    int guess = 0;

    do
    {
        cout << "Enter your guess (-1 to exit): ";

        if (!(cin >> guess))
        {
            cout << "Please enter a number." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (guess == -1)
        {
            cout << "You entered -1. Exiting..." << endl;
            break;
        }

        if (guess > random_number)
        {
            cout << "Too high! Guess again." << endl;
        }
        else if (guess < random_number)
        {
            cout << "Too low! Guess again." << endl;
        }
        else
        {
            cout << "You guessed it! The number was " << random_number << endl;
        }

    } while (guess != random_number);

    return 0;
}
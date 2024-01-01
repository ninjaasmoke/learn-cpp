// inputs.cpp: Nithin
// Desc: using `cin` to get user inputs

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int input_var = 0; // the lergest value this can store is "2147483647"

    // we enter a `do while` loop and stay inside till the user enters -1 or a non integer input.
    do
    {
        /* code */
        cout << "Enter a number (-1 = quit): ";

        // `cin` returns false if the input operation fails. In this case, it fails if the user enters a non numeric value, since it expects an integer.
        if (!(cin >> input_var))
        {
            // cout << "You entered a non-numeric. Exiting..." << endl;
            // break;

            // we can also clear the error flag and ignore the rest of the input buffer.
            cout << "Please enter a number." << endl;
            cin.clear();
            // we ignore the max number of characters that can be stored in the input buffer till we encounter a newline character or we can ignore upto a specific number of characters.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (input_var == -1)
        {
            cout << "You entered -1. Exiting..." << endl;
            break;
        }

        if (input_var != -1)
        {
            cout << "You entered " << input_var << endl;
        }
    } while (input_var != -1);

    cout << "All done." << endl;

    return 0;
}
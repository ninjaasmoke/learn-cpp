// magic_number.cpp: Nithin
// Desc: a program that does manipulation of 3 digit integers.

/*
5.
Here is a "magic number" problem: Ask a user to enter a three-digit number whose first digit is greater than its last.
Your program will reverse the number, and subtract the reversal from the original number.
Finally, reverse the resulting number, and add it to its unreversed form. Output the final result.
The original number that the user enters must be of integer type (not three chars).
Think about how to write a function that takes an integer as input and returns the reverse of that number.

Example:

input number: 901
reverse it: 109
subtract: 901 - 109 = 792
reverse it: 297
add: 297 + 792 = 1089
*/

/*
Authors comments

-   seems ez
-   start:  7:11pm 02-01-2024
-   end:    7:48pm 02-01-2024
*/

#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

bool ParseThreeDigitNumber(int number)
{
    const int first_digit = ((number % 1000) - (number % 100)) / 100;
    const int last_digit = (number % 10);
    if (first_digit < last_digit)
    {
        cout << "Please enter a number where the first digit is greater than the third:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

// int ReverseNumber(int number)
// {
//     int n = number;
//     int reverse = 0;
//     while (n > 0)
//     {
//         const int last_digit = n % 10;
//         reverse = (reverse * 10) + last_digit;
//         n = n / 10;
//     }

//     return reverse;
// }

int ReverseNumber(int n, int reverse = 0)
{
    if (n == 0)
        return reverse;

    const int last_digit = n % 10;
    reverse = (reverse * 10) + last_digit;
    return ReverseNumber(n / 10, reverse);
}

int main()
{
    int number;

    cout << "Enter a 3 digit integer where the first digit is greater than the third digit:" << endl;

    while (true)
    {

        if (!(cin >> number) || number < 99 || number > 999)
        {
            cout << "Please enter a number between 100 and 999" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else
        {
            const bool parsed_digits = ParseThreeDigitNumber(number);
            if (!parsed_digits)
                continue;
            break;
        }
    }

    const int reverse_number = ReverseNumber(number);
    const int subtract = number - reverse_number;
    const int reverse_subtract = ReverseNumber(subtract);
    const int final_number = reverse_subtract + subtract;

    cout << "Final number: " << final_number << endl;

    return 0;
}
// card_trick.cpp : Nithin
// Desc : A program to implement a card trick

/*
7.
This is a number analogy to a famous card trick.

Ask the user to enter a three-digit number.
Think of the number as ABC (where A, B, C are the three digits of the number).
Now, find the remainders of the numbers formed by ABC, BCA, and CAB when divided by 11.

We will call these remainders X, Y, Z.
Add them up as X+Y, Y+Z, Z+X.

If any of the sums are odd, increase or decrease it by 11
(whichever operation results in a positive number less than 20; note if the sum is 9, just report this and stop the process).
Finally, divide each of the sums in half. The resulting digits are A, B, C.

Write a program that implements this algorithm.
*/

/*
Author Comments:

-   start:      7:40pm 03-01-2024
-   end:        8:59pm 03-01-2024
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

const int kMagicNumberCheck = 9;
const int kMagicNumberDivider = 11;

vector<int> GetDigitsFromNumber(int n)
{
    vector<int> digits;

    while (n != 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }

    reverse(digits.begin(), digits.end());

    return digits;
}

int GetNumberFromDigits(vector<int> digits)
{
    int number = 0;
    int size = digits.size();

    for (int i = 0; i < size; i++)
    {
        int digit = digits[i];
        int power = size - 1 - i;
        int tens = pow(10, power);
        number += (digit * tens);
        // cout << "\ndigit: " << digit << endl;
        // cout << "size - 1 - i: " << power << endl;
        // cout << "pow: " << tens << endl;
        // cout << "number: " << number << endl;
    }

    return number;
}

int CardTrickNumber(int n)
{
    if (n % 2 == 0)
    {
        return n;
    }
    if (n > kMagicNumberCheck)
    {
        return n - 11;
    }
    return n + 11;
}

int main()
{
    int number;

    cout << "Enter a 3 digit number: ";
    if (!(cin >> number))
    {
        cout << "Please enter a number!" << endl;
        exit(1);
    }
    else
    {
        if (number < 100 || number > 999)
        {
            cout << "Please enter a 3 digit number!" << endl;
            exit(1);
        }
    }

    vector<int> digits = GetDigitsFromNumber(number);

    const int A = digits[0];
    const int B = digits[1];
    const int C = digits[2];

    int ABC = GetNumberFromDigits({A, B, C});
    int BCA = GetNumberFromDigits({B, C, A});
    int CAB = GetNumberFromDigits({C, A, B});

    int X = ABC % 11; // ABCRemainer
    int Y = BCA % 11; // BCARemainer
    int Z = CAB % 11; // CABRemainer

    int sumXY = X + Y;
    int sumYZ = Y + Z;
    int sumZX = Z + X;

    if (sumXY == kMagicNumberCheck || sumYZ == kMagicNumberCheck || sumZX == kMagicNumberCheck)
    {
        cout << "The magic trick does not work with: " << number << endl;
        exit(1);
    }

    sumXY = CardTrickNumber(sumXY) / 2;
    sumYZ = CardTrickNumber(sumYZ) / 2;
    sumZX = CardTrickNumber(sumZX) / 2;

    cout << "First digit: " << sumXY << endl;
    cout << "Second digit: " << sumYZ << endl;
    cout << "Third digit: " << sumZX << endl;

    return 0;
}
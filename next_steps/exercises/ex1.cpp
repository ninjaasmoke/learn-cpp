// ex1.cpp : Nithin
// Desc : a program to find numbers that are perfect squares but also the sum of digits

/*
Exercise 1
The integer 36 has a peculiar property: it is a perfect square, and is also the sum of the integers from 1 through 8.
The next such number is 1225 which is 352, and the sum of the integers from 1 through 49.
Find the next number that is a perfect square and also the sum of a series 1...n.
This next number may be greater than 32767. You may use library functions that you know of, (or mathematical formulas) to make your program run faster.
It is also possible to write this program using for-loops to determine if a number is a perfect square or a sum of a series.
(Note: depending on your machine and your program, it can take quite a while to find this number.)
*/

#include <iostream>
#include <cmath>
#include <unordered_map>
#include <chrono>

using namespace std;

const int kValidNumbers = 4;
const unsigned long long int kUpperProcessLimit = 100000;

unsigned long long int GetSquare(unsigned long long int n)
{
    return (n * n);
}

unsigned long long int GetSumUpto(unsigned long long int n)
{
    return (n * (n + 1) / 2);
}

void PrepareSquares(std::unordered_map<unsigned long long int, unsigned long long int> &square_map)
{
    for (unsigned long long int i = 1; i <= kUpperProcessLimit; i++)
    {
        square_map.insert({GetSquare(i), i});
    }
    return;
}

void PrepareSums(std::unordered_map<unsigned long long int, unsigned long long int> &sum_map)
{
    for (unsigned long long int i = 1; i <= kUpperProcessLimit; i++)
    {
        unsigned long long int sum = GetSumUpto(i);
        sum_map.insert({sum, i});
    }
}

int main()
{
    auto start = std::chrono::system_clock::now();
    std::unordered_map<unsigned long long int, unsigned long long int> square_map;
    std::unordered_map<unsigned long long int, unsigned long long int> sum_map;

    PrepareSquares(square_map);
    PrepareSums(sum_map);

    int valid_numbers = kValidNumbers;
    unsigned long long int i = 1;

    while (true)
    {
        if (valid_numbers == 0)
        {
            break;
        }

        unsigned long long int square = GetSquare(i);

        if (sum_map.find(square) != sum_map.end())
        {
            cout << "\n-----------------\n";
            cout << "Found it!" << endl;
            cout << "Sum: " << square << endl;
            cout << "Sum from 1 to: " << sum_map[square] << endl;
            cout << "Square: " << square << endl;
            cout << "Root: " << square_map[square] << endl;
            cout << "\n-----------------\n";
            valid_numbers--;
        }

        i++;
    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "\nExecution time: " << elapsed.count() << " ms\n";
    return 0;
}
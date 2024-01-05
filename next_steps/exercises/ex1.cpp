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
using LongIntType = unsigned long long int;

const int kValidNumbers = 6;
const LongIntType kUpperProcessLimit = 100000;

LongIntType GetSquare(LongIntType n)
{
    return (n * n);
}

LongIntType GetSumUpto(LongIntType n)
{
    return (n * (n + 1) / 2);
}

void PrepareSquares(std::unordered_map<LongIntType, LongIntType> &square_map)
{
    for (LongIntType i = 1; i <= kUpperProcessLimit; i++)
    {
        square_map.insert({GetSquare(i), i});
    }
    return;
}

void PrepareSums(std::unordered_map<LongIntType, LongIntType> &sum_map)
{
    for (LongIntType i = 1; i <= kUpperProcessLimit; i++)
    {
        LongIntType sum = GetSumUpto(i);
        sum_map.insert({sum, i});
    }
}

int main()
{
    auto start = std::chrono::system_clock::now();
    std::unordered_map<LongIntType, LongIntType> square_map;
    std::unordered_map<LongIntType, LongIntType> sum_map;

    PrepareSquares(square_map);
    PrepareSums(sum_map);

    int valid_numbers = kValidNumbers;
    LongIntType i = 1;

    while (true)
    {
        if (valid_numbers == 0)
        {
            break;
        }

        LongIntType square = GetSquare(i);

        if (sum_map.find(square) != sum_map.end())
        {
            std::cout << "\n-----------------\n";
            std::cout << "Found it!" << std::endl;
            std::cout << "Sum: " << square << std::endl;
            std::cout << "Sum from 1 to: " << sum_map[square] << std::endl;
            std::cout << "Square: " << square << std::endl;
            std::cout << "Root: " << square_map[square] << std::endl;
            std::cout << "\n-----------------\n";
            valid_numbers--;
        }

        i++;
    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "\nExecution time: " << elapsed.count() << " ms\n";
    return 0;
}
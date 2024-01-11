// 01knapsack.cpp : Nithin
// desc : a recursive approach to solve kansack with memoization

#include <iostream>
#include <cstring>
#include <cmath>

const size_t kMaxSize = 1002;
const size_t kMaxWeight = 1002;

int static T[kMaxSize][kMaxWeight]; // memoization cache

int knapsack(const int wt[], const int val[], int c, int n)
{
    if (c == 0 || n == 0)
    {
        return 0;
    }

    if (T[n][c] != -1)
    {
        return T[n][c];
    }

    int result;

    if (wt[n - 1] <= c)
    {
        result = std::max((val[n - 1] + knapsack(wt, val, c - wt[n - 1], n - 1)), knapsack(wt, val, c, n - 1));
    }
    else
    {
        result = knapsack(wt, val, c, n - 1);
    }
    T[n][c] = result;
    return result;
}

int main()
{
    std::memset(T, -1, sizeof(T));

    const int wt[4] = {1, 3, 4, 6};
    const int val[4] = {3, 5, 7, 9};
    const int cap = 7;
    const int size = sizeof(wt) / sizeof(wt[0]);

    const int bestPrice = knapsack(wt, val, cap, size);

    std::cout << "Best price: " << bestPrice << std::endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << T[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}

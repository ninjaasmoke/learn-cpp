// knapsackTD.cpp : Nithin
// desc : a top down approach to solve knapsack.

#include <iostream>
#include <cmath>

const int kMaxSize = 1002;
const int kMaxWeight = 1002;

static int T[kMaxSize][kMaxWeight]; // by default filled with zero

int knapsackTD(const int wt[], const int val[], int W, int N)
{
    // initialization of the cache/matrix
    for (int i = 0; i < kMaxSize; i++)
        for (int j = 0; j < kMaxWeight; j++)
            T[i][j] = 0;

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                T[i][j] = std::max(val[i - 1] + T[i - 1][j - wt[i - 1]], T[i - 1][j]);
            }
            else
            {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    return T[N][W];
}

int main()
{
    const int wt[4] = {1, 3, 4, 6};
    const int val[4] = {3, 5, 7, 9};
    const int cap = 7;
    const int size = sizeof(wt) / sizeof(wt[0]);

    const int bestPrice = knapsackTD(wt, val, cap, size);

    std::cout << "Best price: " << bestPrice << std::endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << T[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
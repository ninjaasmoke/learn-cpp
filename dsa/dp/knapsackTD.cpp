// knapsackTD.cpp : Nithin
// desc : a top down approach to solve knapsack.

#include <iostream>
#include <cmath>

const int kMaxSize = 102;
const int kMaxWeight = 102;

static int T[kMaxSize][kMaxWeight]; // auto initialised to 0! (since static)

int knapsack(const int wt[], const int val[], int W, int N);

int main()
{
    // const int wt[4] = {1, 3, 4, 7};
    // const int val[4] = {1, 4, 5, 9};

    // const int cap = 9;
    // const int size = sizeof(wt) / sizeof(wt[0]);

    const int wt[4] = {1, 3, 4, 6};
    const int val[4] = {3, 5, 7, 9};
    const int cap = 7;
    const int size = sizeof(wt) / sizeof(wt[0]);

    const int bestPrice = knapsack(wt, val, cap, size);

    std::cout << "Best Price: " << bestPrice << std::endl;

    return 0;
}

int knapsack(const int wt[], const int val[], int W, int N)
{
    // init T to 0 matrix
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < W; j++)
    //         T[i][j] = 0;

    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < W + 1; j++)
            if (wt[i - 1] <= j)
            {
                T[i][j] = std::max((val[i - 1] + T[i - 1][j - wt[i - 1]]), T[i - 1][j]);
            }
            else
            {
                T[i][j] = T[i - 1][j];
            }
    return T[N][W];
}
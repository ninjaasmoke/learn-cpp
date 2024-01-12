// subsetSum.cpp : Nithin
// desc : a variation of the knapsack problem. given an array and a sum, is it possible to get the sum by adding any elements of the attay?

#include <iostream>
#include <cstring>

const int kMaxSize = 101;
const int kMaxSum = 1001;

static bool T[kMaxSize][kMaxSum]; // initialised to 0

bool subsetSumBU(const int arr[], int sum, int n)
{
    // initialization
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sum; j++)
        {
            if (i == 0)
            {
                T[i][j] = false;
            }
            if (j == 0)
            {
                T[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                T[i][j] = T[i - 1][j - arr[i - 1]] || T[i - 1][j];
            }
            else
            {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    return T[n][sum];
}

bool subsetSumTD(const int arr[], int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }

    if (n == 0 && sum != 0)
    {
        return false;
    }

    if (arr[n - 1] <= sum)
    {
        return subsetSumTD(arr, sum - arr[n - 1], n - 1) || subsetSumTD(arr, sum, n - 1);
    }
    else
    {
        return subsetSumTD(arr, sum, n - 1);
    }
}

int main()
{

    const int arr[] = {2, 3, 7, 8, 10};

    const int sum = 11;

    const int size = sizeof(arr) / sizeof(arr[0]);

    bool possible = subsetSumBU(arr, sum, size);
    std::cout << "possible: " << possible << std::endl;

    possible = subsetSumTD(arr, sum, size);
    std::cout << "possible: " << possible << std::endl;

    return 0;
}
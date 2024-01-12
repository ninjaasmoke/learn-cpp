// coinChange.cpp : Nithin
// desc :
//  given an integer array that represents coin denominations,
//  determine the fewest number of coins you need to achieve a total given amount.

// assumption:
//  the arr is sorted in ascending order!

/*
    arr = [1, 5, 6, 9]
    amt = 6

    T:  i   i   i   i   i   i
    0   1   2   3   4   5   6
    0   1
*/

#include <iostream>
#include <cstdint>

const int kMaxSize = 102;
const int kMaxAmount = 1002;

static int T[kMaxAmount]; // automatically initialised to all 0

/**
 * CoinChange
 * @param arr: array of coins
 * @param amt: value of amount
 * @param n:   size of array
 */
int CoinChange(int arr[], int amt, int n)
{
    if (amt < 1)
    {
        return 0;
    }

    for (int i = 1; i <= amt; i++)
    {
        T[i] = INT32_MAX; // ideally infinity

        for (int j = 0; j < n; j++)
        {
            int coin = arr[j];
            // if (coin <= i && T[i - coin] != INT32_MAX) // an optimisation for array of just 1 element
            if (coin <= i)
            {
                T[i] = std::min(T[i], 1 + T[i - coin]);
            }
        }
    }

    if (T[amt] == INT32_MAX)
    {
        return -1;
    }
    return T[amt];
}

int main()
{
    int n = 1;
    int arr[n] = {9};
    int amt = 11;

    int coinChange = CoinChange(arr, amt, n);

    std::cout << "Coinchange: " << coinChange << std::endl;

    return 0;
}
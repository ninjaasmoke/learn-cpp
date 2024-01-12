// equalSumPartition.cpp : Nithin
// desc : a program to check if an array can be divided into 2 sub arrays, where the sum of the sub arrays are equal
// assumption : the array only has integers.

#include <iostream>

const int kMaxSize = 102;
const int kMaxSum = 1002;

static int T[kMaxSize][kMaxSum];

bool SubsetSumTD(const int arr[], const int sum, const int size)
{
    if (sum == 0)
        return true;

    if (sum != 0 && size == 0)
        return false;

    if (arr[size - 1] <= sum)
        return SubsetSumTD(arr, sum - arr[size - 1], size - 1) || SubsetSumTD(arr, sum, size - 1);
    return SubsetSumTD(arr, sum, size - 1);
}

bool CanPartition(const int arr[], const int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
        return false;

    return SubsetSumTD(arr, sum / 2, size);
}

int main()
{
    const int arr[] = {1, 5, 11, 5};
    const int size = sizeof(arr) / sizeof(arr[0]);

    bool canPart = CanPartition(arr, size);
    std::cout << "CanPart: " << canPart << std::endl;

    return 0;
}
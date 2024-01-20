// climbingStairs.cpp : Nithin
// desc : n stairs. can climb k at a time. how many ways to climb?? return the vector of ways

#include <iostream>
#include <vector>

void ClimbStairsHelper(int n, int k, std::vector<int> &seq, std::vector<std::vector<int>> &res)
{
    if (n == 0)
    {
        res.push_back(seq);
        return;
    }

    for (int i = 1; i <= k && i <= n; ++i)
    {
        seq.push_back(i);
        ClimbStairsHelper(n - i, k, seq, res);
        seq.pop_back();
    }
}

std::vector<std::vector<int>> ClimbStairs(int n, int k)
{
    std::vector<std::vector<int>> res;
    std::vector<int> currentSequence;

    ClimbStairsHelper(n, k, currentSequence, res);

    return res;
}

int NumWaysToClimbStairs(int n, int k)
{
    if (n == 0)
    {
        return 1;
    }

    int numWays = 0;
    for (int i = 1; i <= k && i <= n; ++i)
    {
        numWays += NumWaysToClimbStairs(n - i, k);
    }

    return numWays;
}

int main()
{
    int n = 6, k = 2;

    std::vector<std::vector<int>> waysToClimb = ClimbStairs(n, k);

    for (size_t i = 0; i < waysToClimb.size(); i++)
    {
        for (size_t j = 0; j < waysToClimb[i].size(); j++)
        {
            std::cout << waysToClimb[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nNumber of ways to climb: " << NumWaysToClimbStairs(n, k) << std::endl;

    return 0;
}
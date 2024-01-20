// smallestRange.cpp : Nithin
// desc :

/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.



Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<int> smallestRange(vector<vector<int>> &nums)
{
    int k = nums.size();

    // Create a min heap of pairs (value, list index, index in list)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

    // Initialize the heap with the first element from each list and the index in the list
    for (int i = 0; i < k; ++i)
    {
        if (!nums[i].empty())
        {
            minHeap.push({nums[i][0], {i, 0}});
        }
    }

    // Initialize the range variables
    int rangeStart = numeric_limits<int>::min();
    int rangeEnd = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();

    // Process the heap until one of the lists is exhausted
    while (minHeap.size() == k)
    {
        auto top = minHeap.top();
        minHeap.pop();

        int val = top.first;
        int listIndex = top.second.first;
        int indexInList = top.second.second;

        // Update the range
        if (val > maxVal)
        {
            maxVal = val;
        }

        // Check if the current range is smaller
        if (maxVal - minHeap.top().first < rangeEnd - rangeStart)
        {
            rangeStart = minHeap.top().first;
            rangeEnd = maxVal;
        }

        // Move to the next element in the same list
        if (indexInList + 1 < nums[listIndex].size())
        {
            minHeap.push({nums[listIndex][indexInList + 1], {listIndex, indexInList + 1}});
        }
    }

    return {rangeStart, rangeEnd};
}

int main()
{
    vector<vector<int>> nums1 = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> result1 = smallestRange(nums1);
    cout << "Output 1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<vector<int>> nums2 = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    vector<int> result2 = smallestRange(nums2);
    cout << "Output 2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}

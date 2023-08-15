// Subset Sum: Given an array of integers and a target sum, find if there exists a subset of the array whose sum is equal to the target using recursion.

#include <bits/stdc++.h>
using namespace std;

bool subsetSumRecursive(const vector<int> &arr, int target, int index, int currentSum, vector<int> &subset)
{
    // Base case: If the current sum is equal to the target, we found a subset.
    if (currentSum == target)
    {
        return true;
    }

    // Base case: If we have exhausted all elements in the array.
    if (index >= arr.size())
    {
        return false;
    }

    // Include the current element and explore further.
    subset.push_back(arr[index]);
    bool includeCurrent = subsetSumRecursive(arr, target, index + 1, currentSum + arr[index], subset);

    if (includeCurrent)
    {
        return true; // If we found a valid subset in the "include" branch, return true.
    }

    // Exclude the current element and explore further.
    subset.pop_back(); // If the "include" branch didn't find a subset, backtrack and try the "exclude" branch.
    bool excludeCurrent = subsetSumRecursive(arr, target, index + 1, currentSum, subset);

    return excludeCurrent;
}

bool hasSubsetSum(const vector<int> &arr, int target, vector<int> &subset)
{
    // Start the recursive function from the first index with an initial sum of 0 and an empty subset.
    return subsetSumRecursive(arr, target, 0, 0, subset);
}

int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(34);
    arr.push_back(4);
    arr.push_back(12);
    arr.push_back(5);
    arr.push_back(2);
    int target = 9;
    vector<int> subset;

    if (hasSubsetSum(arr, target, subset))
    {
        cout << "exists a subset with the target sum" << endl;
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "no subset found with the target sum " << endl;
    }
    return 0;
}
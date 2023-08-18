#include <bits/stdc++.h>
using namespace std;

// Recursive method

int binarySearch(const vector<int> &arr, int target, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            return binarySearch(arr, target, mid + 1, high);
        }
        else
        {
            return binarySearch(arr, target, low, mid - 1);
        }
    }
    return -1;
}

// Iterative method

int bsearch(const vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
    int target = 7;
    int index = binarySearch(arr, target, 0, arr.size() - 1);
    cout << index << endl;
    
    return 0;
}
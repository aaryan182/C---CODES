// Check if an array is sorted in non-decreasing order.

#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {2, 3, 9, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    bool sorted = isSorted(arr, size);

    if (sorted)
    {
        cout << "array is sorted in non decreasing order " << endl;
    }
    else
    {
        cout << "array is not sorted  in non decreasing order " << endl;
    }

    return 0;
}
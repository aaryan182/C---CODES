//  Find the maximum and minimum element in an array.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 10, 3, 8, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Maximum element of the array  is : " << max << endl;
    cout << "Minimum element of the array  is : " << min << endl;

    return 0;
}

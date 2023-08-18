#include <bits/stdc++.h>
using namespace std;

int peakElement(int arr[] ,int n){
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return end;
}

int main()
{  
   int arr[6] = {2,6,9,4,3};
//    int size = sizeof(arr)/sizeof(arr[0]);
   cout<<"peak element is: "<<peakElement(arr , 6);
   return 0;
}
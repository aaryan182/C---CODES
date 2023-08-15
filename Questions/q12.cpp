// Calculate the sum of all elements in an array.


#include <bits/stdc++.h>
using namespace std;

int main()
{  
   int arr[] = {5, 10, 3, 8, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = 0 ;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    cout<<"sum of the given array is : "<<sum<<endl;
     
   return 0;
}
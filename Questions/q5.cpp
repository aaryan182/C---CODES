// Write a C++ program to calculate the sum of the digits of a positive integer.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n >= 0)
    {
        int sum = 0;
        int originalNumber = n;

        while (n > 0)
        {
            int digit = n % 10;
            sum += digit;
            n /= 10;
        }
        cout << "sum of digits " << originalNumber << " is: " << sum << endl;
    }
    else
    {
        cout<<"number is not positive"<<endl;
    }
    
    return 0;
}
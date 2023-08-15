// Write a recursive function to calculate the sum of the first n natural numbers.

#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n * (n + 1)) / 2;
    }
}

int main()
{
    int n;
    cin >> n;

    int result = sum(n);
    cout << "Sum of first " << n << " natural numbers is : " << result << endl;
    return 0;
}
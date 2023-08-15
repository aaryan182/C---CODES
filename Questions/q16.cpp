// Write a recursive function to calculate the factorial of a given non-negative integer n

#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    int result = fact(n);
    cout << "factorial of the number " << n << " is : " << result << endl;
    return 0;
}
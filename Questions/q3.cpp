// Implement a C++ class for a simple calculator that can perform addition, subtraction, multiplication, and division.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n1, n2;
    cin >> n1 >> n2;

    cout << "calculator processing starts : " << endl;
    cout << "Addition of entered numbers " << n1 << " & " << n2 << " is: " << n1 + n2 << endl;
    cout << "Subtraction of entered numbers " << n1 << " & " << n2 << " is: " << n1 - n2 << endl;
    cout << "Multiplication  of entered numbers " << n1 << " & " << n2 << " is: " << n1 * n2 << endl;
    cout << "Division of entered numbers " << n1 << " & " << n2 << " is: " << n1 / n2 << endl;
    cout << "calculator processing over !!!" << endl;
    return 0;
}
// Write a recursive function to print numbers from start to end in increasing order.

#include <bits/stdc++.h>
using namespace std;

void printno(int start, int end)
{
    if (start > end)
    {
        return;
    }
    cout << start << ' ';
    printno(start + 1, end);
}

int main()
{
    int start, end;
    cin >> start >> end;

    cout << "numbers from " << start << " to " << end << " are: " << endl;
    printno(start, end);
    return 0;
}
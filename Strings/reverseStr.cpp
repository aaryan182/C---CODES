#include <bits/stdc++.h>
using namespace std;

string reverseStr(string s) {
    int n = s.length();
    int i = 0;
    int j = n - 1;
    while (i < j) {
        swap(s[i++], s[j--]);
    }
    return s;
}

int main()
{  
    string s;
    cin>>s;
    cout<<reverseStr(s);
   return 0;
}
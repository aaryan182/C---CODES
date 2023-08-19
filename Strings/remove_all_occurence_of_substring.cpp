#include <bits/stdc++.h>
using namespace std;

string removeOccurence(string s , string part) {
    while(s.length()!=0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{  
   string s, part;
   getline(cin, s);
   getline(cin, part);
   cout<<"Removed string is : "<<removeOccurence(s,part)<<endl;
   return 0;
}

// This code defines a function called `removeOccurence` that takes in two strings as parameters: `s` and `part`. The purpose of this function is to remove all occurrences of the string `part` from the string `s`.
// The function uses a while loop to repeatedly check if the length of the string `s` is not equal to 0 and if the string `part` is found within the string `s`. The condition `s.find(part) < s.length()` checks if the index of the first occurrence of `part` in `s` is less than the length of `s`. If this condition is true, it means that `part` is found in `s`.
// Inside the while loop, the function uses the `erase` method to remove the occurrence of `part` from `s`. The `erase` method takes in two parameters: the starting index of the substring to be erased and the length of the substring to be erased. In this case, `s.find(part)` is used to find the starting index of the first occurrence of `part` in `s`, and `part.length()` is used to determine the length of `part`. This effectively removes the occurrence of `part` from `s`.
// After the while loop finishes, the function returns the modified string `s`. This means that all occurrences of `part` have been removed from `s`, and the modified string is returned as the result of the function.
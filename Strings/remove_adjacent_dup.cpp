#include <bits/stdc++.h>
using namespace std;

string removeAdjacent(string s)
{
   string result;
    for (auto c : s)
    {
        if (!result.empty() && result.back() == c)
        {
            result.pop_back();
        }
        else
        {
            result.push_back(c);
        }
    }
    return result;
}

int main()
{
    string s;
    getline(cin, s);
    cout << removeAdjacent(s) << endl;
    return 0;
}

// This code defines a function called `removeAdjacent` that takes a string as input and returns a modified version of the string. 
// The function uses a loop to iterate over each character in the input string. 
// Inside the loop, there is an `if` statement that checks if the `result` string is not empty and if the last character of the `result` string is the same as the current character being iterated. 
// If the condition is true, it means that the current character is adjacent to the previous character in the `result` string. In this case, the code removes the last character from the `result` string using the `pop_back` function. 
// If the condition is false, it means that the current character is not adjacent to the previous character. In this case, the code adds the current character to the `result` string using the `push_back` function. 
// After the loop finishes iterating over all the characters in the input string, the modified `result` string is returned as the output of the function.
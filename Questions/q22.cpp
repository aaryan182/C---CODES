// Palindrome Check: Write a recursive function to check if a given string is a palindrome (reads the same forwards and backwards).

#include <bits/stdc++.h>
using namespace std;

string cleanString(const string &str)
{
    string cleanStr;
    for (char c : str)
    {
        if (isalnum(c))
        {
            cleanStr.push_back(tolower(c));
        }
    }
    return cleanStr;
}

bool isPalindrome(const string &str, int left, int right)
{
    if (left >= right)
    {
        return true;
    }
    if (str[left] != str[right])
    {
        return false;
    }
    return isPalindrome(str, left + 1, right - 1);
}

bool isPalindrome(const string &str)
{
    string cleanStr = cleanString(str);
    return isPalindrome(cleanStr, 0, cleanStr.size() - 1);
}

int main()
{
    string input;
    cout << "enter a string ";
    getline(cin, input);
    if (isPalindrome(input))
    {
        cout << "string is a palindrome" << endl;
    }
    else
    {
        cout << "string is not a palindrome" << endl;
    }
    return 0;
}
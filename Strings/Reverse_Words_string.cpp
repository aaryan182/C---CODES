// The `reverseWords` function takes a string `s` as input and modifies it in-place to reverse the order of words. It uses two pointers, `start` and `end`, to keep track of the current word being processed.
// The function starts by initializing `start` and `end` to 0. It then enters a while loop that continues until `end` reaches the end of the string.
// Inside the loop, the code checks if the character at index `end` is a space character. If it is, it means that a word has been found. In this case, the code uses the `reverse` function to reverse the characters between `start` and `end-1` (excluding the space character). This effectively reverses the word.
// After reversing the word, the code updates `start` to be `end + 1`, which points to the start of the next word.
// Finally, after the loop ends, the code uses the `reverse` function again to reverse the last word (from `start` to the end of the string).



#include <bits/stdc++.h>
using namespace std;

void reverseWords(string &s)
{
    int start = 0;
    int end = 0;

    while (end < s.size())
    {
        if (s[end] == ' ')
        {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        end++;
    }
    reverse(s.begin() + start, s.end());
}

int main()
{
    string s;
    getline(cin, s);
    reverseWords(s);
    cout << s << endl;
    return 0;
}

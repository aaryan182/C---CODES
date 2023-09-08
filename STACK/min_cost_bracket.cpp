#include <bits/stdc++.h>
using namespace std;
int findMinimumCost(string str)
{

    // odd condition
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
            s.push(ch);
        else
        {
            // ch is closed brace
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    // stack contains invalid expression
    int a = 0, b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int minimumCost = findMinimumCost(input);
    cout << "Minimum cost: " << minimumCost << endl;

    return 0;
}

// Suppose we have the input string str = "}{{}}{{{". The goal is to find the minimum cost required to balance the string by removing some braces.
// The function first checks if the length of the string is odd. If it is, the function returns -1 because it is impossible to balance the string with an odd length.
// Next, the function uses a stack to process each character of the string. If the character is an opening brace ('{'), it is pushed onto the stack. If it is a closing brace ('}'), the function checks if the stack is empty or if the top of the stack is an opening brace. If either condition is true, it means the braces are balanced, so the opening brace is popped from the stack. Otherwise, the closing brace is pushed onto the stack.
// After processing all the characters, the function checks the remaining braces in the stack. If the top of the stack is an opening brace ('{'), it means there are unmatched opening braces, so the count b is incremented. Otherwise, if the top of the stack is a closing brace ('}'), it means there are unmatched closing braces, so the count a is incremented. The stack is then popped until it becomes empty.
// Finally, the minimum cost is calculated as (a+1)/2 + (b+1)/2. This formula ensures that the cost is minimized by pairing unmatched braces together. The function returns the minimum cost.
// In our example, the function will return 3 because there are 3 unmatched opening braces ('{') and no unmatched closing braces ('}'). The minimum cost is calculated as (0+1)/2 + (3+1)/2 = 2.
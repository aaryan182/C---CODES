#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string expression;

    // Taking input for the expression
    cout << "Enter the expression: ";
    cin >> expression;

    // Checking if the expression has valid parentheses
    if (isValidParenthesis(expression))
    {
        cout << "The expression has valid parentheses." << endl;
    }
    else
    {
        cout << "The expression does not have valid parentheses." << endl;
    }

    return 0;
}

// This code is a function that checks if a given string contains valid parentheses. It uses a stack data structure to keep track of opening parentheses and ensures that they are closed in the correct order.

// 1. The function takes a string `s` as input and returns a boolean value indicating whether the parentheses in the string are valid or not.

// 2. It initializes an empty stack `st` to store opening parentheses.

// 3. It iterates over each character in the string using a for loop.

// 4. For each character `ch`, it checks if it is an opening parenthesis ('(', '{', or '['). If it is, it pushes it onto the stack.

// 5. If the character is not an opening parenthesis, it checks if the stack is empty. If it is not empty, it retrieves the top element of the stack using the `top()` function and assigns it to the variable `top`.

// 6. It then checks if the current character `ch` is a closing parenthesis (')', '}', or ']'). If it is, it compares it with the top element of the stack to ensure that they form a valid pair. If they do, it pops the top element from the stack using the `pop()` function.

// 7. If the current character `ch` is not a closing parenthesis or if it does not form a valid pair with the top element of the stack, the function returns `false` indicating that the parentheses are not valid.

// 8. After iterating over all characters in the string, the function checks if the stack is empty. If it is, it means that all opening parentheses have been closed in the correct order, so it returns `true`. Otherwise, it returns `false`.

// In summary, the function uses a stack to keep track of opening parentheses and ensures that they are closed in the correct order. It returns `true` if the parentheses are valid and `false` otherwise.
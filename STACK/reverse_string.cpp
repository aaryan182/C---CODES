#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "aaryan";
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }
    string ans = "";
    while (!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout << ans<<endl;

    return 0;
}


// This code is written in C++ and it demonstrates how to reverse a string using a stack.

// First, a string variable named "str" is declared and initialized with the value "aaryan". 

// Then, a stack of characters named "s" is declared. A stack is a data structure that follows the Last-In-First-Out (LIFO) principle, meaning that the last element added to the stack will be the first one to be removed.

// Next, a for loop is used to iterate over each character in the string "str". The loop starts from index 0 and continues until the length of the string. 

// Inside the loop, the current character at index "i" is stored in a variable named "ch". Then, the character is pushed onto the stack "s" using the push() function. This means that the characters of the string will be added to the stack in reverse order.

// After the loop finishes, an empty string variable named "ans" is declared. This variable will store the reversed string.

// Then, a while loop is used to iterate until the stack "s" becomes empty. Inside the loop, the top character of the stack is retrieved using the top() function and stored in the variable "ch". The top() function returns the element at the top of the stack without removing it.

// The character "ch" is then appended to the end of the string "ans" using the push_back() function. This function adds the character to the end of the string.

// Finally, the top character is removed from the stack using the pop() function. This function removes the element at the top of the stack.

// Once the while loop finishes, the reversed string "ans" is printed to the console using the cout statement.

// The main function then returns 0, indicating successful execution of the program.
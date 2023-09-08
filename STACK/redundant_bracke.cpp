#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else
        {
            // ch is either ')' or a lowercase letter 
            if(ch == ')'){
                bool isRedundant = true;
                
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;    
}

int main()
{
    string expression = "((a+b))";
    if(findRedundantBrackets(expression))
        cout << "Redundant brackets are present." << endl;
    else
        cout << "No redundant brackets found." << endl;
    
    return 0;
}


// Explanation:
// The findRedundantBrackets function takes a string s as input, which represents a mathematical expression.
// It uses a stack (st) to keep track of opening brackets and operators encountered.
// It iterates through each character of the expression.
// If the character is an opening bracket (() or an operator (+, -, *, /), it is pushed onto the stack.
// If the character is a closing bracket ()), it checks for redundant brackets.
// It sets a boolean variable isRedundant to true initially.
// It pops elements from the stack until it encounters the corresponding opening bracket (().
// During this process, if it encounters any operator, it sets isRedundant to false.
// If isRedundant remains true after popping all elements until the opening bracket, it means there are redundant brackets.
// Finally, it returns true if redundant brackets are found, otherwise false.
// In the main function, an example expression ((a+b)) is passed to findRedundantBrackets to check for redundant brackets.
// If redundant brackets are found, it prints "Redundant brackets are present." Otherwise, it prints "No redundant brackets found."    
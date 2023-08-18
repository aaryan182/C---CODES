// This code checks whether a given string is a palindrome or not. 
// A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward. For example, "madam" and "racecar" are palindromes.
// The code uses a two-pointer approach to compare characters from the beginning and end of the string. 
// First, the code initializes two pointers, `left` and `right`, to the start and end of the string respectively. 
// Then, it enters a while loop that continues until the `left` pointer is less than the `right` pointer. 
// Inside the loop, there are two inner while loops. The first inner while loop increments the `left` pointer until it reaches a alphanumeric character (a letter or a digit). The second inner while loop decrements the `right` pointer until it reaches a alphanumeric character. 
// After both inner while loops finish, the code compares the characters at the `left` and `right` pointers using the `tolower` function to convert both characters to lowercase. If the characters are not equal, the function returns 0, indicating that the string is not a palindrome. 
// If the characters are equal, the `left` pointer is incremented and the `right` pointer is decremented. This process continues until the `left` pointer is no longer less than the `right` pointer. 
// Finally, if the while loop completes without returning 0, the function returns 1, indicating that the string is a palindrome. 
// In the `main` function, a test string "A man, a plan, a canal, Panama!" is defined. The `isPalindrome` function is called with this test string as an argument, and the result is stored in the `result` variable. 
// Then, an if-else statement checks the value of `result`. If it is 1, the code prints "It's a palindrome." If it is not 1, the code prints "It's not a palindrome." 
// Finally, the `main` function returns 0, indicating successful execution of the program.

#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string A)
{
    // two pointer approach
    int left = 0;
    int right = A.length() - 1;

    while (left < right)
    {
        while (left < right && !isalnum(A[left]))
            left++;
        while (left < right && !isalnum(A[right]))
            right--;

        if (tolower(A[left++]) != tolower(A[right--]))
            return 0;
    }

    return 1;
}
int main()
{
    string testString = "A man, a plan, a canal, Panama!";
    int result = isPalindrome(testString);

    if (result == 1)
    {
        cout << "It's a palindrome." << endl;
    }
    else
    {
        cout << "It's not a palindrome." << endl;
    }

    return 0;
}

// another approach



// int isPalindrome(string A)
// {
//     // Convert the string to lowercase
//     for (int i = 0; i < A.length(); i++)
//     {
//         A[i] = tolower(A[i]);
//     }

//     // Create a new string with only alphanumeric characters
//     string cleanString = "";
//     for (char c : A)
//     {
//         if (isalnum(c))
//         {
//             cleanString += c;
//         }
//     }

//     // Check if the cleanString is a palindrome
//     int left = 0;
//     int right = cleanString.length() - 1;
//     while (left < right)
//     {
//         if (cleanString[left] != cleanString[right])
//         {
//             return 0; // Not a palindrome
//         }
//         left++;
//         right--;
//     }

//     return 1; // It's a palindrome
// }
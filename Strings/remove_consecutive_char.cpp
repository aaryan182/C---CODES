#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string removeConsecutiveSame(string A, int B) {
    string result = "";
    int count = 1;

    for (int i = 1; i < A.length(); i++) {
        if (A[i] == A[i - 1]) {
            count++;
        } else {
            // If consecutive count is not equal to B, add to result
            if (count != B) {
                result += A.substr(i - count, count);
            }
            // Reset count for the new character sequence
            count = 1;
        }
    }

    // Handle the last character sequence
    if (count != B) {
        result += A.substr(A.length() - count, count);
    }

    return result;
}

int main()
{
    string A;
    int B;

    cout << "Enter string A: ";
    cin >> A;

    cout << "Enter integer B: ";
    cin >> B;

    string output = removeConsecutiveSame(A, B);
    cout << "Output: " << output << endl;

    return 0;
}

// This code is a function that takes in a string `A` and an integer `B` as input and returns a modified version of the string.
// The function starts by initializing an empty string `result` and a counter variable `count` to 1.
// Then, it enters a for loop that iterates over each character in the string `A`, starting from the second character (index 1). 
// Inside the loop, it checks if the current character is equal to the previous character. If they are equal, it increments the `count` variable by 1. This is done to keep track of the number of consecutive characters that are the same.
// If the current character is not equal to the previous character, it means that the consecutive sequence of characters has ended. In this case, it checks if the count is not equal to `B`. If it is not equal, it means that the consecutive sequence of characters is not of length `B`, so it appends the substring of `A` from the start of the consecutive sequence (i - count) to the end of the consecutive sequence (count) to the `result` string.
// After appending the substring, it resets the `count` variable to 1, as a new consecutive sequence of characters has started.
// Once the loop is finished, it checks if the last consecutive sequence of characters is not of length `B`. If it is not, it appends the substring of `A` from the start of the last consecutive sequence (A.length() - count) to the end of the last consecutive sequence (count) to the `result` string.
// Finally, it returns the `result` string, which contains the modified version of the input string `A`.
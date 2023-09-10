#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string A) {
        unordered_map<char, int> count;
        deque<char> q;

        string ans = "";

        for (char ch : A) {
            count[ch]++;
            q.push_back(ch);

            while (!q.empty() && count[q.front()] > 1) {
                q.pop_front();
            }

            if (q.empty()) {
                ans.push_back('#');
            } else {
                ans.push_back(q.front());
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Example usage
    string input = "aabbcd";
    string result = solution.FirstNonRepeating(input);

    cout << "First non-repeating characters: " << result << endl;

    return 0;
}


// This code is a function that takes a string as input and returns a new string. The purpose of the function is to find the first non-repeating character in the input string.

// To achieve this, the code uses two data structures: an unordered map and a deque.

// The unordered map, named "count", is used to keep track of the count of each character in the input string. The key of the map is the character itself, and the value is the count of that character.

// The deque, named "q", is used to store the characters in the order they appear in the input string. The deque is used as a queue, where characters are added to the back and removed from the front.

// The code initializes an empty string named "ans" to store the result.

// The code then iterates over each character in the input string. For each character, it increments the count in the unordered map and adds the character to the back of the deque.

// After adding the character to the deque, the code enters a while loop. This loop checks if the deque is not empty and if the count of the character at the front of the deque is greater than 1. If both conditions are true, it means that the character at the front of the deque is repeating, so it is removed from the front of the deque. This process continues until either the deque is empty or the character at the front of the deque is non-repeating.

// After the while loop, the code checks if the deque is empty. If it is empty, it means that there are no non-repeating characters in the deque, so the code appends a '#' character to the "ans" string. Otherwise, it appends the character at the front of the deque to the "ans" string.

// Finally, after iterating over all the characters in the input string, the code returns the "ans" string, which contains the first non-repeating character for each position in the input string.
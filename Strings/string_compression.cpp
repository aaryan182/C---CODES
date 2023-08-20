#include <bits/stdc++.h>
using namespace std;

void compressString(vector<string> &input)
{
    // Create a map to store the count of each unique string.
    map<string, int> charCount;

    // Loop through each string in the input vector.
    for (const string &s : input)
    {
        // Increment the count of the current string in the map.
        charCount[s]++;
    }

    // Loop through each entry (string and count) in the charCount map.

    for (const auto &entry : charCount)
    {
        // Print the current string.
        cout << entry.first << " ";
        // Print the count.
        if (entry.second > 1)
        {
            // Print the count.
            cout << entry.second << " ";
        }
    }
    cout << endl;
}

int main()
{
    vector<string> input = {"a", "a", "b", "b", "c", "c", "d"};
    compressString(input);
    return 0;
}

// This code is a function that takes a vector of strings as input and compresses the strings by counting the occurrences of each string.
// First, the code declares a map called `charCount` which will store the count of each string.
// Then, it loops through each string in the input vector using a range-based for loop. Inside the loop, it increments the count of the current string in the `charCount` map using the `++` operator.
// After the loop, it loops through each entry in the `charCount` map using a range-based for loop with the `auto` keyword. Inside the loop, it prints the key (the string) and the value (the count) of each entry using `cout`.
// Finally, it prints a newline character to separate the output from any other output that may come after.
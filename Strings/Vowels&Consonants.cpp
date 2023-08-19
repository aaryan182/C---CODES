// This code calculates the number of substrings in a given string that start with a vowel and end with a consonant, or vice versa.
// The code starts by defining a constant variable `MOD` with a value of 1000000007. This variable is used to take the modulo of the final count to prevent overflow.
// The `isVowel` function is defined to check if a given character is a vowel. It returns `true` if the character is 'a', 'e', 'i', 'o', or 'u', and `false` otherwise.
// The `solve` function takes a string `A` as input and returns the count of substrings that start with a vowel and end with a consonant, or vice versa. It initializes two variables `vowelCount` and `consonantCount` to keep track of the number of vowels and consonants in the string, respectively.
// The function then iterates over each character in the string using a for loop. If the current character is a vowel, the `vowelCount` variable is incremented. Otherwise, the `consonantCount` variable is incremented.
// After the loop, the function calculates the count of substrings by multiplying the `vowelCount` and `consonantCount` variables and taking the modulo of the result with `MOD`. This is done to prevent overflow in case the count is very large.


#include <iostream>
using namespace std;

const int MOD = 1000000007;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int solve(string A) {
    int n = A.length();
    long long vowelCount = 0, consonantCount = 0;
    
    for (int i = 0; i < n; ++i) {
        if (isVowel(A[i])) {
            vowelCount++;
        } else {
            consonantCount++;
        }
    }

    long long count = (vowelCount * consonantCount) % MOD;

    return count;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = solve(input);
    cout << "Number of substrings starting with a vowel and ending with a consonant, or vice versa: " << result << endl;

    return 0;
}


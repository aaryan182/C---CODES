#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        return false;
    }

    vector<int> count1(26, 0), count2(26, 0);

    // Count the frequency of characters in s1 and the first window of s2
    for (int i = 0; i < s1.length(); i++)
    {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    int left = 0;
    int right = s1.length();

    while (right < s2.length())
    {
        // Check if the two arrays are equal
        if (count1 == count2)
        {
            return true;
        }
 
        // Move the window's right boundary
        count2[s2[right] - 'a']++;
        count2[s2[left] - 'a']--;
        left++;
        right++;
    }

    // Check if the two arrays are equal for the last window
    if (count1 == count2)
    {
        return true;
    }

    return false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    bool result = checkInclusion(s1, s2);

    cout << (result ? "true" : "false") << endl;

    return 0;
}


// This code checks if one string, `s1`, is a permutation of another string, `s2`. 
// First, it checks if the length of `s1` is greater than the length of `s2`. If it is, then `s1` cannot be a permutation of `s2`, so the function returns `false`.
// Next, two vectors, `count1` and `count2`, are created. These vectors are used to count the frequency of each character in `s1` and the first window of `s2`. The vectors are initialized with 26 elements, each set to 0. This is because there are 26 lowercase letters in the English alphabet.
// Then, a loop is used to iterate through each character in `s1` and the first window of `s2`. For each character, the corresponding element in `count1` and `count2` is incremented by 1.
// After that, two variables, `left` and `right`, are initialized. `left` represents the left boundary of the window, and `right` represents the right boundary of the window. The initial values of `left` and `right` are set to 0 and the length of `s1`, respectively.
// A while loop is used to slide the window through `s2`. In each iteration of the loop, the code checks if `count1` is equal to `count2`. If they are equal, it means that `s1` is a permutation of the current window of `s2`, so the function returns `true`.
// Then, the code updates `count2` by incrementing the count of the character at the right boundary of the window and decrementing the count of the character at the left boundary of the window. The left boundary is then moved one position to the right, and the right boundary is moved one position to the right as well.
// This process continues until the right boundary reaches the end of `s2`.
// Finally, after the while loop ends, the code checks if `count1` is equal to `count2` for the last window. If they are equal, it means that `s1` is a permutation of the last window of `s2`, so the function returns `true`. Otherwise, it returns `false`.
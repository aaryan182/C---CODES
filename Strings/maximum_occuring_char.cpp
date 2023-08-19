// The `getMaxOccuringChar` function takes a string `str` as input and returns a character. This function is responsible for finding the character that occurs the most in the given string.
// Inside the `getMaxOccuringChar` function, an array `count` of size 26 is declared and initialized with all zeros. This array will be used to store the count of each character in the string.
// A `for` loop is used to iterate through each character of the string. The loop starts from 0 and goes up to the length of the string. Inside the loop, the count of the current character is incremented by 1 in the `count` array. The expression `str[i]-'a'` is used to convert the character to its corresponding index in the `count` array. This is done by subtracting the ASCII value of 'a' from the ASCII value of the current character.
// After the first loop, the `count` array will contain the count of each character in the string.
// Two variables `max` and `ans` are declared. `max` is initialized with 0 and `ans` is initialized with the character 'a'. These variables will be used to keep track of the character that occurs the most and its count.
// Another `for` loop is used to iterate through each index of the `count` array. The loop starts from 0 and goes up to 25 (since there are 26 alphabets). Inside the loop, the current count is compared with the current maximum count. If the current count is greater than the current maximum count, then the maximum count is updated and the corresponding character is updated in the `ans` variable. The expression `i+'a'` is used to convert the index back to its corresponding character by adding the ASCII value of 'a' to the index.
// After the second loop, the `ans` variable will contain the character that occurs the most in the string.
// The `getMaxOccuringChar` function returns the character stored in the `ans` variable.

#include <bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(string str){
    int count[26] = {0};
    for(int i=0; i<str.length(); i++){
        count[str[i]-'a']++;
    }
    int max = 0;
    char ans = 'a';
    for(int i=0; i<26; i++){
        if(max < count[i]){
            max = count[i];
            ans = i+'a';
        }
    }
    return ans;
}

int main()
{  
   string s;
   cin>>s;
   cout<<getMaxOccuringChar(s); 
   return 0;
}
#include <bits/stdc++.h>
using namespace std;

string replaceSpaces(string &s) {
    string ans = "";
    int n = s.length();
    for(int i=0; i<n; i++){
        if(s[i] == ' '){
            ans.push_back('%');
            ans.push_back('2');
            ans.push_back('0');
        }
        else{
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main()
{  
   string s;
   getline(cin, s);
   cout << "Replaced string is: " << replaceSpaces(s) << endl; 
   return 0;
}

// without making new string


// void replaceSpaces(string& s) {
//     int n = s.length();
//     int spaceCount = 0;
//     for (int i = 0; i < n; i++) {
//         if (s[i] == ' ') {
//             spaceCount++;
//         }
//     }

//     int newLength = n + 2 * spaceCount;
//     s.resize(newLength);

//     for (int i = n - 1; i >= 0; i--) {
//         if (s[i] == ' ') {
//             s[newLength - 1] = '0'; 
//             s[newLength - 2] = '2';
//             s[newLength - 3] = '%';
//             newLength -= 3;
//         } else {
//             s[newLength - 1] = s[i];
//             newLength--;
//         }
//     }
// }

// explanation for the above code 
// This code is a function called `replaceSpaces` that takes a string `s` as input and replaces all spaces in the string with "%20". 
// The function first calculates the length of the input string `s` and initializes a variable `spaceCount` to keep track of the number of spaces in the string. 
// Then, it iterates through each character in the string using a for loop. If the current character is a space, the `spaceCount` variable is incremented. 
// After counting the number of spaces, the function calculates the new length of the string after replacing the spaces with "%20". This is done by adding 2 times the `spaceCount` to the original length of the string. 
// The `resize` function is then used to resize the string to the new length. This ensures that the string has enough space to accommodate the additional characters. 
// Next, the function iterates through the original string in reverse order using another for loop. If the current character is a space, the function replaces it with "%20" by assigning the appropriate characters to the last three positions of the resized string. The `newLength` variable is then decremented by 3 to account for the additional characters. 
// If the current character is not a space, it is simply copied to the last position of the resized string and the `newLength` variable is decremented by 1. 
// Finally, the function returns and the input string `s` is modified in place with the spaces replaced by "%20".

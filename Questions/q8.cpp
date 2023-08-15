// Write a C++ program to check if a given string is a palindrome (reads the same forwards and backwards).

#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string &str){
    string reversedStr = str;
    reverse(reversedStr.begin(),reversedStr.end());

    return (str == reversedStr);
}

int main()
{  
   string str;
   cout<<"enter a string " <<endl;
   getline(cin,str);

   if(isPallindrome(str)){
    cout<<"string is pallindrome  "<<endl;
   }
   else
   {
    cout<<"string is not pallindrome "<<endl;
   }
   
   return 0;
}
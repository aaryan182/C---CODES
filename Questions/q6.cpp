// Write a C++ program to check if a given character is a vowel or consonant.

#include <bits/stdc++.h>
using namespace std;

int main()
{  
   char ch;
   cin>>ch;

   ch = tolower(ch);

   if (ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u')
   {
    cout<<"Entered charachter "<<ch<<" is : vowel"<<endl;
   }
   else
   {
        cout<<"Entered charachter "<<ch<<" is : consonant"<<endl;
   }
    
   return 0;
}
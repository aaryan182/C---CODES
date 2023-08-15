// Write a recursive function to count the number of digits in a positive integer n.

#include <bits/stdc++.h>
using namespace std;

int countDig(int n){
    if (n < 10)
    {
        return  1;
    }
    else
    {
        return 1 + countDig(n/10);
    }
    
    
}

int main()
{  
   int n;
   cin>>n;

   int numDigits = countDig(n) ;

   cout<<"number of digits in : "<<n<<" is : "<< numDigits<<endl;
   return 0;
}

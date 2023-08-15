// Write a recursive function to generate the nth Fibonacci number in the sequence.


#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1 || n== 2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main()
{  
   int n;
   cin>>n;

   int result = fib(n) ;
   cout<<"the "<<n<<"th fibonacci number is : "<<result<<endl;
   return 0;
}
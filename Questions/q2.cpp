// Write a C++ function to calculate the factorial of a given number using recursion.

#include <bits/stdc++.h>
using namespace std;

unsigned long long factorial(int n){
    if(n==0 || n==1){
        return 1;
    }

    return n*factorial(n-1);
}

int main()
{  
    int n;
    cin>>n;

    unsigned long long result =  factorial(n);
    cout<<"factorial of : "<<n<<" is: "<<result<<endl;
   return 0;
}
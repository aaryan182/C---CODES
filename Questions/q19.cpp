// Write a recursive function to calculate the value of base raised to the power of exponent.

#include <bits/stdc++.h>
using namespace std;

double power(double base ,int exponent){
    if (exponent == 0) {
        return 1;
    }

    // Recursive case: If the exponent is positive, calculate the power recursively.
    if (exponent > 0) {
        return base * power(base, exponent - 1);
    }
    // If the exponent is negative, calculate the reciprocal of the power recursively.
    else {
        return 1 / (base * power(base, -exponent - 1));
    }
}

int main()
{  
   double base ;
   int exponent;

   cin>>base>>exponent;

   double result = power(base , exponent) ;
   cout<<base<<" raised to the power of : "<<exponent<<" is : "<<result<<endl;
   return 0;
}
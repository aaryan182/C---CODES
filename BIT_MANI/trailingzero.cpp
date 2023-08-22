#include <bits/stdc++.h>
using namespace std;

int trailzero(int n){
    int count = 0;

        while ((n & 1) == 0 && n != 0) {
            count++;
            n >>= 1;
        }

        return count;
}

int main()
{  
   int input = 120;
   cout<<"number of trailing zeros present in "<<input<<" is : "<<trailzero(input)<<endl;
   return 0;
}
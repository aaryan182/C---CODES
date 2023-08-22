#include <bits/stdc++.h>
using namespace std;

int numSetBits(unsigned int A) {
        int count = 0;
        while (A > 0) {
            if (A & 1) {
                count++;
            }
            A >>= 1;
        }
        return count;
    }


int main()
{  
   unsigned int input = 345;
   cout<<"Number of 1 bits present in "<<input<<" is : "<<numSetBits(input)<<endl; 
   return 0;
}

// This code is a function that takes an unsigned integer as input and returns the number of set bits in its binary representation.
// The function starts by initializing a variable called `count` to 0. This variable will keep track of the number of set bits.
// Then, it enters a while loop that continues as long as the input number `A` is greater than 0. Inside the loop, it checks if the least significant bit of `A` is set (i.e., equal to 1) using the bitwise AND operator (`&`). If the bit is set, it increments the `count` variable by 1.
// After that, it right shifts the value of `A` by 1 position using the `>>=` operator. This operation effectively divides `A` by 2, discarding the least significant bit. This step is necessary to move to the next bit in the binary representation of `A`.
// The loop continues until all bits of `A` have been processed, and then the function returns the final value of `count`, which represents the number of set bits in the binary representation of the input number.
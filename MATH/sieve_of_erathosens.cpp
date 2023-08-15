// This code snippet implements the Sieve of Eratosthenes algorithm to find all prime numbers up to a given limit N. The function sieve takes an integer N as input and returns a vector of prime numbers. It initializes a boolean vector isPrime of size N+1, where isPrime[i] is initially set to true for all i. Then, it iterates over the numbers from 2 to the square root of N, and for each prime number p, it marks all its multiples as non-prime by setting isPrime[i] to false. Finally, it collects all the prime numbers by iterating over the range from 2 to N and adding the numbers for which isPrime[i] is true to the primes vector.

// This code is an implementation of the Sieve of Eratosthenes algorithm, which is used to find all prime numbers up to a given number N.

// The code starts by including the necessary libraries for input/output, vector manipulation, and mathematical operations.

// The `sieve` function takes an integer N as input and returns a vector of integers representing all prime numbers up to N. 

// Inside the `sieve` function, a vector called `primes` is initialized to store the prime numbers. If N is less than 2, the function returns an empty vector since there are no prime numbers less than 2.

// A vector called `isPrime` is then initialized with N+1 elements, all set to true. The first two elements, isPrime[0] and isPrime[1], are set to false since 0 and 1 are not prime numbers.

// The algorithm then iterates from p = 2 to the square root of N. For each value of p, if isPrime[p] is true, it means that p is a prime number. The algorithm then marks all multiples of p as non-prime by setting isPrime[i] to false, where i starts from p*p and increments by p in each iteration.

// After the inner loop finishes, the algorithm iterates from 2 to N and checks if each number is prime by checking the value of isPrime[i]. If isPrime[i] is true, it means that i is a prime number and it is added to the `primes` vector.

// Finally, the `primes` vector is returned.

// In the `main` function, an integer N is initialized to 30. The `sieve` function is called with N as the input, and the resulting vector of prime numbers is stored in the `primes` vector.

// The code then prints a message indicating the prime numbers up to N, followed by a loop that prints each prime number separated by a space.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve(int N) {
    vector<int> primes;
    if (N < 2) {
        return primes;
    }

    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p <= sqrt(N); ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    int N = 30;
    vector<int> primes = sieve(N);

    cout << "Prime numbers up to " << N << ": ";
    for (int prime : primes) {
        cout << prime << " ";
    }

    return 0;
}


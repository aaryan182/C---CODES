#include <bits/stdc++.h>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
public:
    int tour(petrolPump p[], int n) {
        int start = 0; // Starting point
        int balance = 0; // Keeps track of the current balance
        int deficit = 0; // Keeps track of the total deficit

        for (int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;

            if (balance < 0) {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        return (deficit + balance >= 0) ? start : -1;
    }
};

int main() {
    Solution solution;

    // Example usage
    petrolPump pumps[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int n = sizeof(pumps) / sizeof(pumps[0]);

    int start = solution.tour(pumps, n);

    if (start != -1) {
        cout << "Starting point: " << start << endl;
    } else {
        cout << "No valid starting point found." << endl;
    }

    return 0;
}



// This code is a solution to a problem that involves finding the starting point of a circular tour of petrol pumps. The problem is that there are N petrol pumps arranged in a circular route, and each petrol pump has a certain amount of petrol and a certain distance to the next petrol pump. The goal is to find a starting point from where we can complete the tour by visiting all the petrol pumps, without running out of petrol.

// The code is written in C++ and defines a class called Solution. Inside the class, there is a public method called tour, which takes an array of petrolPump objects and the number of petrol pumps as input, and returns an integer representing the starting point.

// The method starts by initializing three variables: start, balance, and deficit. The start variable keeps track of the starting point, the balance variable keeps track of the current balance of petrol, and the deficit variable keeps track of the total deficit of petrol.

// Then, the method enters a for loop that iterates over each petrol pump. Inside the loop, the balance variable is updated by adding the difference between the petrol and distance of the current petrol pump.

// If the balance becomes negative, it means that we have run out of petrol at some point. In this case, the deficit variable is updated by adding the negative balance, the start variable is updated to the next petrol pump index, and the balance is reset to 0.

// After the loop ends, the method checks if the total deficit plus the final balance is greater than or equal to 0. If it is, it means that we can complete the tour without running out of petrol, so the method returns the starting point. Otherwise, it returns -1 to indicate that it is not possible to complete the tour.

// In summary, this code uses a simple algorithm to find the starting point of a circular tour of petrol pumps. It keeps track of the balance and deficit of petrol while iterating over the petrol pumps, and returns the starting point if it is possible to complete the tour.
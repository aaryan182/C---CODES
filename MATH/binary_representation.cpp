#include <iostream>
#include <string>

using namespace std;

string Solution::findDigitsInBinary(int A) {
    if (A == 0)
        return "0";

    string binaryRepresentation = "";
    
    while (A != 0) {
        int i = A % 2;
        binaryRepresentation = to_string(i) + binaryRepresentation;
        A /= 2;
    }

    return binaryRepresentation;
}

int main() {
    int N;
    cin >> N;

    Solution solution;
    string binary = solution.findDigitsInBinary(N);
    cout << "Binary representation: " << binary << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Function to calculate sum of two integers
int calculate(int a, int b) {
    return a + b;
}

// Function to calculate product of two floats
float calculate(float x, float y) {
    return x * y;
}

// Function to calculate average of three integers and return as float
float calculate(int a, int b, int c) {
    return (a + b + c) / 3.0f;
}

int main() {
    // Test all three versions

    int sum = calculate(10, 20); // Calls int version
    float product = calculate(3.5f, 2.0f); // Calls float version
    float avg = calculate(10, 20, 30); // Calls 3-int version

    // Display results
    cout << "Sum of 10 and 20 = " << sum << endl;
    cout << "Product of 3.5 and 2.0 = " << product << endl;
    cout << "Average of 10, 20, 30 = " << avg << endl;

    return 0;
}
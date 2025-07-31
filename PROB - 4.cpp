#include <iostream>
using namespace std;

// Function that takes array pointer and returns sum
int sumArray(int* ptr, int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += *(ptr + i); // Pointer arithmetic
    }
    return total;
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // Pointer to the array
    int* p = arr;

    // Sum using pointer in main (without function)
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += *(p + i); // Using pointer arithmetic
    }

    cout << "Sum using pointer in main: " << sum << endl;

    // Sum using function
    int result = sumArray(arr, 5);
    cout << "Sum using function with pointer: " << result << endl;

    return 0;
}
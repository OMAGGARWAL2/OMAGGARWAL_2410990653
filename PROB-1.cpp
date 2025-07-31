#include <iostream>
using namespace std;

// Function to find the pointer to the largest value
int* findLargest(int* x, int* y, int* z) {
    if (*x >= *y && *x >= *z)
        return x;
    else if (*y >= *x && *y >= *z)
        return y;
    else
        return z;
}

// Function to swap two integers using pointers
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    // Declare and initialize variables
    int a = 10, b = 20, c = 30;

    // Create pointers
    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;

    // Print original addresses and values
    cout << "Original values and addresses:\n";
    cout << "a = " << *p1 << ", Address = " << p1 << endl;
    cout << "b = " << *p2 << ", Address = " << p2 << endl;
    cout << "c = " << *p3 << ", Address = " << p3 << endl;

    // Swapping values using pointers
    swap(p1, p2); // Swap a and b
    swap(p2, p3); // Swap b and c

    // Print values after swapping
    cout << "\nValues after swapping using pointers:\n";
    cout << "a = " << *p1 << ", b = " << *p2 << ", c = " << *p3 << endl;

    // Find and modify the largest
    int* largest = findLargest(p1, p2, p3);
    *largest = 100;

    // Print final values
    cout << "\nValues after modifying the largest to 100:\n";
    cout << "a = " << *p1 << ", b = " << *p2 << ", c = " << *p3 << endl;

    return 0;
}
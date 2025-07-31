#include <iostream>
using namespace std;

// Function using Call by Value
void doubleByValue(int x) {
    x = x * 2;
    cout << "Inside doubleByValue: x = " << x << endl;
}

// Function using Call by Reference
void doubleByReference(int &x) {
    x = x * 2;
    cout << "Inside doubleByReference: x = " << x << endl;
}

int main() {
    int a = 5, b = 5;

    cout << "Before doubleByValue: a = " << a << endl;
    doubleByValue(a);  // Value won't change
    cout << "After doubleByValue: a = " << a << endl;

    cout << "\nBefore doubleByReference: b = " << b << endl;
    doubleByReference(b);  // Value will change
    cout << "After doubleByReference: b = " << b << endl;

    return 0;
}
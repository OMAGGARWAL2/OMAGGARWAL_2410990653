#include<iostream>
#include<memory>
using namespace std;
int main () {
    int *ptr1;
    ptr1 = new int(612);
    int *ptr2 = ptr1;
    cout << "POINTER 1 IS"<< ptr1;
    delete ptr1;
    delete ptr2;
}
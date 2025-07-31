#include <iostream>
#include <memory> 
using namespace std;
unique_ptr<int> createPointer(int value) {
    unique_ptr<int> ptr = make_unique<int>(value);
    return ptr;
}
int main() {
    unique_ptr<int> myPtr = createPointer(100);
    cout << "Value stored in smart pointer: " << *myPtr << endl;
    return 0;
}
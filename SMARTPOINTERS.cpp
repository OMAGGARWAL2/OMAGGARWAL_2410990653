#include<iostream>
#include<memory>
using namespace std;
int main () {
    std :: unique_ptr<int> x(new int (12));
    return 0;
}
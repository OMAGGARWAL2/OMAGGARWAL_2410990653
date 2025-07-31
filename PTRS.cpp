#include<iostream>
using namespace std;
int main ()
{
    int *ptr = new int;
    cout << "ENTER THE POINTER:- ";
    cin >> *ptr;
    cout << "YOU ENTERED THE PTR:-"<< *ptr; 
    return 0;
}
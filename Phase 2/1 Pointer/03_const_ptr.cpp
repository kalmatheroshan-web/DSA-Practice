#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 200;

    // makes value only readable
    const int *p = &a;

    // *p = 100;  //error
    // pointer can be change but value can't
    cout << *p << endl;
    p = &b;
    cout << *p << endl;

    // const pointer
    int *const ptr = &b;

    // ptr = &a; //error
    cout << ptr << endl;

    *ptr = 500; //value can change
    cout << *ptr << endl;
}
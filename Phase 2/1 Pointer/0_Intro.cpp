#include <iostream>
using namespace std;
/*
    For 32-bit compiler:
        sizeof(pointer) = 4 bytes

    For 64-bit compiler:
        sizeof(pointer) = 8 bytes

    data_type *pointer;

       - "data_type" tells how much memory should be fetched when dereferencing
       - A pointer is also a variable, but it stores an address
*/

int main()
{
    int a = 10;
    cout << "Address of a: " << &a << endl;

    int *ptr = &a;
    cout << "Value of ptr (address): " << ptr << endl;
    cout << "Value present at that address: " << *ptr << endl;

    int b = 200;
    ptr = &b; // it's variable so can be updated
    cout << "Pointer now points to b, value = " << *ptr << endl;

    int value = 100;
    cout << (*&value) << endl;         // prints 100
    cout << (*&*&*&*&*&value) << endl; // still prints 100

    // pointer in array
    int arr[] = {10, 20, 30, 40, 50};

    // arr == &arr[0]
    // &arr == address of entire array

    // arr[i] == *(arr+i) == i[arr]

    cout << *arr << endl;
    cout << arr[2] << " or " << *(arr + 2) << endl;
    cout << "0[arr] " << 0 [arr] << endl;

    cout << endl;

    cout << "Values " << endl;

    // Print the value using addr
    for (int i = 0; i < 5; i++)
        cout << *(arr + i) << " ";

    cout << endl;
    
    for (int *ptr = arr; ptr < arr + 5; ptr++)
        cout << *ptr << " ";

    cout << endl;
    cout << endl;

    cout << "Address " << endl;
    // Print the addresses
    for (int i = 0; i < 5; i++)
        cout << (arr + i) << " ";
    cout << endl;

    // some pointer arithmetic
    int x = 500;
    int *p = &x;

    cout << "\nPointer arithmetic with int:" << endl;
    cout << "Base address: " << p << endl;
    cout << "p + 1: " << p + 1 << endl;
    cout << "p - 1: " << p - 1 << endl;

    bool check = false;
    bool *pt = &check;

    cout << "\nPointer arithmetic with bool:" << endl;
    cout << "Base address: " << pt << endl;
    cout << "pt + 1: " << pt + 1 << endl;
    cout << "pt - 1: " << pt - 1 << endl;

    return 0;
}

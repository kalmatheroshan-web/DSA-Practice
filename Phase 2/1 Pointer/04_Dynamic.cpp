#include <iostream>
#include <vector>
using namespace std;
/*
    for dynamic memory allocation use
        new keyword

    Note :
     - Default value is garbage
     - There is no memory management done by the compiler here
     - so use delete keyword here

*/

int main()
{
    // for variables
    int *p = new int;
    cout << "Garbage : " << *p << endl;
    *p = 100;

    *p = 100001;
    cout << *p << endl;
    cout << endl;


    int n;
    cout << "enter the value of n" << endl;
    cin >> n;

    // for array
    float *ar = new float[n];

    for (int i = 0; i < n; i++)
        ar[i] = i + 1;

    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << endl;

    delete p;
    delete[] ar;

    cout << endl;
    cout << "After delete " << *p << endl;
}
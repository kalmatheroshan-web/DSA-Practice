#include <iostream>
using namespace std;

void fun(int **p1) { *p1 += 1; }

int main()
{
    int n = 100;
    int *p = &n;
    int **ptr = &p;

    cout << n << endl;
    cout << *p << endl;
    cout << **ptr << endl;

    cout << "Address" << endl;

    cout << p << endl;
    cout << *ptr << endl;

    int a = 10;
    int *p1 = &a;
    int **ptr1 = &p1;

    cout << p1 << endl;
    fun(ptr1);
    cout << p1 << endl;

    int b = 10;
    int *pt = &b; // Single pointer
    int **pt1 = &pt; // Double pointer
    int ***pt2 = &pt1; // Triple pointer

    ***pt2 += 5;
    cout << b << endl;
}
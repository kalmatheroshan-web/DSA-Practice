#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A() { cout << "A constructor" << endl; }

    void print()
    {
        cout << " A is called .." << endl;
    }
};

class B : public A
{
public:
    B() { cout << "B constructor" << endl; }

    void print()
    {
        cout << "B is called .." << endl;
    }
};

class C : public B
{
public:
    C() { cout << "C constructor" << endl; }

    void print()
    {
        cout << "C is called .." << endl;
    }
};

int main()
{
    A obj;
    B bs; 
    C cs; 

    return 0;
}
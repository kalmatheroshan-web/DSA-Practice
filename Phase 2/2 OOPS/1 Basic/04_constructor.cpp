#include <bits/stdc++.h>
using namespace std;
/*
    Note : whenever you write any contructor defualt will be overwrite
*/

class student
{

public:
    string name;
    char grade;
    int age;
    double d;

    // default constructor
    student() { cout << "mannual contructor called .. " << endl; }

    // Parameterized constuctor
    student(int a)
    {
        age = a;
        cout << "student is there" << endl;
    }
};

class box
{
public:
    int length;
    int height;
    int width;

    box()
    {
        length = 0;
        height = 0;
        width = 0;
    }

    // constructor overloading
    // Constructor overloading means having multiple constructors in the same class, each with a different number or type of parameters.

    // cons with 1 parameter
    box(int length)
    {
        this->length = length;
    }

    // cons with 2 parameter
    box(int length, int height)
    {
        this->length = length;
        this->height = height;
    }

    // cons with 3 parameter
    box(int length, int height, int width)
    {
        this->length = length;
        this->height = height;
        this->width = width;
    }

    void pr()
    {
        cout << "length " << length << endl;
        cout << "height " << height << endl;
        cout << "width " << width << endl;
    }
};

int main()
{
    box b;
    b.pr();

    // if defualt overwrites give error here
    // box *b2 = new box({10, 20, 40});
    // b2->pr();

    cout << endl;

    box c(10, 20);
    c.pr();

    return 0;
}
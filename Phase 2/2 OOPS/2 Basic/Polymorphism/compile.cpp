#include <bits/stdc++.h>
using namespace std;

// compile time polymorphism
// 1 fnx overloading
// 2 operator overloading

// 1 fnx overloading
class math
{
public:
    // fnx overloading .. (name and return type must be same)
    int sum(int a, int b) { return a + b; }
    int sum(int a, double b) { return a; }
    int sum(int a, int b, int c) { return a + b + c; }
};

// 2 operator overloading

class dub
{
public:
    int sum;
    dub(int a) { sum = a; }
    int operator+(dub &obj)
    {
        return this->sum - obj.sum;
    }
};

class Point
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Friend function to overload <<
    friend ostream &operator<<(ostream &os, const Point &p);
    friend istream &operator>>(istream &is, Point &p);
};

ostream &operator<<(ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

istream &operator>>(istream &is, Point &p)
{
    is >> p.x >> p.y;
    return is;
}

int main()
{
    dub alone(10);
    dub blone(100);
    cout << alone + blone << endl;

    Point p(10, 20);

    cout << p << endl;
    cout << "enter the values" << endl;
    
    cin >> p;
    cout << p << endl;

    return 0;
}
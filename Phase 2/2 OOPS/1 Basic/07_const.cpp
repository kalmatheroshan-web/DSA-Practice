#include <bits/stdc++.h>
using namespace std;

class box
{
    int x, y;

public:
    box(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    // setter
    void setx(int x) { this->x = x; }
    void sety(int y) { this->y = y; }

    // getter
    int getx() const { return x; } // inside this can't modified the value of property
    int gety() const { return y; }

    int getxx() const
    {
        int f = 10;
        f = 200;
        f = 5999;
        return x;
    }
};

void print_abc(const box &bx)
{
    // bx is const obj so must access all the const pro & method
    cout << "x " << bx.getx() << ", y " << bx.gety() << ", x " << bx.getxx() << endl;
}

// changing const values
class student
{
    string name;
    mutable int marks;

public:
    student(string name, int marks)
    {
        this->name = name;
        this->marks = marks;
    }

    string getName() const { return name; }
    int getMarks() const
    {
        marks = 100;
        return marks;
    }
    void show()
    {
        cout << "Name " << this->name << endl;
        cout << "Marks " << this->marks << endl;
    }
};

// inlization list
class customer
{
    const string name;
    int *balance;

public:
    // error modifing the const
    customer(string n , int bal){
        // name = n;
        balance = new int(bal);
    }  
};

int main()
{
    box abc(10, 20);
    print_abc(abc);

    student rohit("Rohit", 89);
    rohit.getMarks();
    rohit.show();
}
#include <bits/stdc++.h>
using namespace std;

class exam
{
    int marks;
    char grade;

public:
    // Inline constructor (automatically inline because inside class)
    exam(int mr, char ch) : marks(mr), grade(ch) {}
    void pr()
    {
        cout << "Marks will be " << marks << endl;
        cout << "Grade will be " << grade << endl;
    }
};

// Explicit inline constructor
class Student
{
    string name;
    int age;

public:
    inline Student(string n, int a); // constructor declaration
    void display();
};

// inline constructor definition
inline Student::Student(string n, int a) : name(n), age(a) {}

// inline function
inline void Student::display()
{
    cout << "Name: " << name << ", Age: " << age << endl;
}

int main()
{

    exam eg(110, 'A');
    eg.pr();

    Student rohit("Rohit", 12);
    
    cout << endl;
    rohit.display();

        
}

#include <bits/stdc++.h>
using namespace std;

// shallow -- serface level
// deep -- Dettail oriented work

class Person
{
public:
    int id;
    string *name;

    // Default constructor
    Person()
    {
        this->id = 0;
        this->name = nullptr;
    }

    // Parameterized constructor
    Person(int id, string name)
    {
        this->id = id;
        this->name = new string(name);
    }

    // Shallow copy constructor
    // Person(const Person &other)
    // {
    //     this->id = other.id;
    //     this->name = other.name; // shallow copy (same pointer)
    //     cout << "Custom shallow copy constructor called..." << endl;
    // }

    // Deep copy constructor
    Person(const Person &other)
    {
        this->id = other.id;
        this->name = new string(*other.name);
        cout << "Custom Deep copy constructor called..." << endl;
    }

    // Destructor
    ~Person()
    {
        delete name;
        name = nullptr;
        cout << "Destructor called for id " << id << endl;
    }
};

int main()
{
    Person p1(10, "Roshan");
    Person p2(p1); // Shallow copy

    cout << "p2.id: " << p2.id << endl;
    cout << "p2.name: " << *(p2.name) << endl;

    // Modify original
    p1.id = 1220;
    *p1.name = "Khello";

    cout << "\nAfter modifying p1:" << endl;
    cout << "p1.id: " << p1.id << ", p1.name: " << *(p1.name) << endl;
    cout << "p2.id: " << p2.id << ", p2.name: " << *(p2.name) << endl;

    return 0;
}

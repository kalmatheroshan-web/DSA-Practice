#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    string name;
    char grade;
    int age;
};

int main()
{

    student *p = new student;
    (*p).name = "Rohan";
    (*p).grade = 'A';
    (*p).age = 22;

    // Arrow operator (*). == ->
    cout << p->name << endl;
    cout << p->grade << endl;
    cout << p->age << endl;

    // another way to assign
    student *ptr = new student({"Mohan", 'A', 122});

    cout << endl;
    cout << "The elements are " << endl;

    cout << ptr->name << endl;
    cout << ptr->grade << endl;
    cout << ptr->age << endl;

    student *p_value = new student;
    cout << p_value->name << endl;  // (empty string)
    cout << p_value->grade << endl; // garbage
    cout << p_value->age << endl;   // garbage

    return 0;
}
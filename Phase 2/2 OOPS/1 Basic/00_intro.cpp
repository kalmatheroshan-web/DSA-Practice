#include <iostream>
using namespace std;

// with packing exact size will be getting
// #pragma pack(1);

// padding
struct student
{
    string name;
    float age;
    char b;
    float roll_no;
    char grade;
};

class intro
{
public:
    string name;
    float age;
    char b;
    float roll_no;
    char grade;
};

int main()
{

    // cout << sizeof(student) << endl;
    // cout << sizeof(string) << endl;

    // student rohan = {"Roshan", 203, 'a', 123.12, 'A'};
    // cout << rohan.grade << endl;
    // cout << rohan.age << endl;

    cout << sizeof(intro) << endl;
}
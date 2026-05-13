#include <bits/stdc++.h>
using namespace std;
/*
    By defualt all the member and function are private
    
*/


class student
{
public:
    string name;
    char grade;
    int age;
};

void print(student &s)
{
    cout << "Elements are ... " << endl;

    cout << "Name " << s.name << endl;
    cout << "Grade " << s.grade << endl;
    cout << "Age " << s.age << endl;

    cout << endl;
}

class box
{
    int length;
    int height;
    int width;

public:
    // setter
    void setLen(int l) { length = l; }
    void setHei(int h) { height = h; }
    void setWid(int w) { width = w; }

    // getter
    int getLen() { return length; }
    int getHei() { return height; }
    int getWid() { return width; }
};

int main()
{
    student rohu = {"rohan", 'A', 23};
    cout << "Name " << rohu.name << endl;
    cout << "Grade " << rohu.grade << endl;
    cout << "Age " << rohu.age << endl;

    cout << endl;

    student ar[2] = {{"Maratha", 'A', 22}, {"Omkar", 'A', 20}};
    cout << ar[0].name << endl;
    cout << ar[1].name << endl;

    cout << endl;

    student mohan = {"Mohan", 'D', 24};
    print(mohan);

    box bb;
    bb.setLen(100);
    cout << "Box length " << bb.getLen() << endl;

    bb.setWid(200);
    cout << "Box width " << bb.getWid() << endl;

    bb.setHei(300);
    cout << "Box height " << bb.getHei() << endl;

    return 0;
}
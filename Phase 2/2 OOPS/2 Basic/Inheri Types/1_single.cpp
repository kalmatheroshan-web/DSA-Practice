#include <bits/stdc++.h>
using namespace std;

class animal
{
protected:
    int age;

public:
    animal()
    {
        cout << "Animal constructor .. " << endl;
    }
    void see()
    {
        cout << "Animal can see" << endl;
    }
};

class dog : protected animal
{
public:
    void bark()
    {
        cout << "barking .." << endl;
        see();
    }
};

int main()
{

    dog d1;
    d1.bark();

    return 0;
}
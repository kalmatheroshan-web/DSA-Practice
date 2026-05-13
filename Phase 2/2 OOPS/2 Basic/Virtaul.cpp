#include <bits/stdc++.h>
using namespace std;
class Animal
{
public:
    // pure virtual fnx
    virtual void speak() = 0;
};

/*
override tells the compiler:

    “This function is meant to override a virtual function from the base class.”
*/

class dog : public Animal
{
public:
    void speak() override
    {
        cout << "speak somethng " << endl;
    }
};

int main()
{

    // Animal obj; //error : abstract class
    dog obj;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*

Note :
    without virtual always right side fnx called

*/

class Animal
{
public:
    virtual void speak()
    {
        cout << "Hu Hu" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak() 
    {
        cout << "bark" << endl;
    }

    void walk()
    {
        cout << "walking.." << endl;
    }
};
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Mi Mu" << endl;
    }

    void walk()
    {
        cout << "walking.." << endl;
    }
};

int main()
{
    // Upcasting ..
    Animal *ani = new Dog();

    // Downcasting ..
    // Dog *ani = new Animal(); // error
    Dog *dg = (Dog *)new Animal();
    dg->speak();

    // ani->speak();
    // ani->walk(); //error

    // Animal *p;
    // vector<Animal *> animals;
    // animals.push_back(new Dog());
    // animals.push_back(new Cat());
    // animals.push_back(new Animal());

    // animals.push_back(new Dog());
    // animals.push_back(new Cat());
    // animals.push_back(new Animal());

    // for (auto val : animals)
    // {
    //     val->speak();
    // }

    /*

    parent *a = new parent;
    chilc *b = new child;

    parent *a = new child;
    child *a = new parent;

    ----- ----- 
    w/o virtual right side
    with virtual left side

    */

    return 0;
}

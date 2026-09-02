#include <bits/stdc++.h>
using namespace std;

// 1. Abstract Base Class: cannot be instantiated directly
class Animal
{
public:
    // Pure virtual function: forces derived classes to implement speak()
    virtual void speak() = 0;

    // Standard virtual function: provides a default implementation that can be overridden
    virtual void move()
    {
        cout << "Animal moves." << endl;
    }

    // Virtual Destructor: ensures proper cleanup of derived objects via base pointers
    virtual ~Animal()
    {
        cout << "Animal destroyed." << endl;
    }
};

// 2. Concrete Derived Class
class Dog : public Animal
{
public:
    // 'override' ensures this matches a base virtual function exactly
    void speak() override
    {
        cout << "Woof! Woof!" << endl;
    }

    // Overriding standard virtual function
    void move() override
    {
        cout << "Dog runs on four legs." << endl;
    }

    ~Dog() override
    {
        cout << "Dog destroyed." << endl;
    }
};

// 3. Derived Class preventing further overriding using 'final'
class Cat final : public Animal
{
public:
    void speak() override final // 'final' prevents further derived classes from overriding speak()
    {
        cout << "Meow!" << endl;
    }

    ~Cat() override
    {
        cout << "Cat destroyed." << endl;
    }
};

int main()
{
    // Animal baseObj; // Error: cannot instantiate abstract class

    // Direct object creation
    Dog myDog;
    myDog.speak();

    cout << "--- Polymorphism via Base Pointer (Late Binding) ---" << endl;

    // Base class pointers holding derived objects
    Animal *p1 = new Dog();
    Animal *p2 = new Cat();

    // Calls derived implementations dynamically at runtime
    p1->speak(); // Woof! Woof!
    p1->move();  // Dog runs on four legs.
    p2->speak(); // Meow!

    cout << "--- Cleanup via Virtual Destructors ---" << endl;

    // Invokes derived destructor first, then base destructor
    delete p1;
    delete p2;

    return 0;
}
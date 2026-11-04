/*
   NAMESPACES IN C++
   ===================

   Namespaces prevent name collisions in large projects by grouping
   identifiers (variables, functions, classes) under named scopes.

   Topics covered:
     1. Basic Namespace Declaration
     2. Scope Resolution Operator (::)
     3. Global Scope Resolution (::var)
     4. Nested Namespaces (C++17 syntax included)
     5. Namespace Aliases
     6. Anonymous (Unnamed) Namespaces
*/

#include <iostream>
using namespace std;

// 1. BASIC NAMESPACES
namespace Physics
{
    int marks = 90;
    void display()
    {
        cout << "Physics marksue: " << marks << endl;
    }
}

namespace Chemistry
{
    int marks = 85;
    void display()
    {
        cout << "Chemistry marksue: " << marks << endl;
    }
}

// 2. GLOBAL SCOPE VS LOCAL SCOPE
int globalmarks = 500; // Global scope variable

// 3. NESTED NAMESPACES
namespace Outer
{
    namespace Inner
    {
        void test()
        {
            cout << "Inside Outer::Inner namespace" << endl;
        }
    }
}

// C++17 Direct Nested Namespace Syntax
namespace Org::Department::Team
{
    void info()
    {
        cout << "C++17 Nested Namespace: Org::Department::Team" << endl;
    }
}

// 4. UNNAMED / ANONYMOUS NAMESPACE
// Restricts visibility to THIS FILE ONLY (replaces C-style static globals)
namespace
{
    void secret_function()
    {
        cout << "File-private function called" << endl;
    }
}

int main()
{
    cout << "--- 1. Avoiding Conflicts with Scope Resolution (::) ---" << endl;
    Physics::display();
    Chemistry::display();
    cout << "Physics marks: " << Physics::marks << " | Chemistry marks: " << Chemistry::marks << endl
         << endl;

    cout << "--- 2. Global Scope Resolution ---" << endl;
    int globalmarks = 50; // Shadows global variable
    cout << "Local globalmarks: " << globalmarks << endl;
    cout << "Global ::globalmarks: " << ::globalmarks << endl
         << endl; // Access global scope

    cout << "--- 3. Using-Declarations ---" << endl;
    {
        using Physics::marks; // Brings only Physics::marks into this local block scope
        cout << "Unqualified marks: " << marks << endl;
    }
    cout << endl;

    cout << "--- 4. Nested Namespaces & Aliases ---" << endl;
    Outer::Inner::test();
    Org::Department::Team::info();

    // Namespace Alias (useful for deeply nested or long names)
    namespace DevTeam = Org::Department::Team;
    DevTeam::info();
    cout << endl;

    cout << "--- 5. Anonymous Namespace ---" << endl;
    secret_function(); // Callable directly within this translation unit

    return 0;
}

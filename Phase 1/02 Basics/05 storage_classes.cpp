/*

    STORAGE CLASSES IN C++
    =========================

   Storage classes define the lifetime, scope, and visibility of
   variables and functions.

   Types covered:
     1. auto            - Default local variable storage (stack allocated)
     2. static          - Preserves value across function calls / internal linkage
     3. register        - Suggests CPU register storage for fast access
     4. extern          - Declares global variable defined in another file
     5. mutable         - Allows modification inside const member functions
     6. thread_local    - Unique variable copy per thread
   ====================================================================
*/

#include <iostream>
using namespace std;

// 1. GLOBAL & EXTERN SCOPE
int global_var = 100; // Global variable (static duration, external linkage)

// Declares that 'external_var' is defined elsewhere (e.g., another .cpp file)
extern int external_var;

// 2. STATIC STORAGE CLASS
void demonstrate_static()
{
    int normal_count = 0;        // Re-initialized every function call
    static int static_count = 0; // Initialized ONLY ONCE, retains value across calls

    normal_count++;
    static_count++;

    cout << "Normal Count: " << normal_count
         << " | Static Count: " << static_count << endl;
}

// 3. MUTABLE STORAGE CLASS (Used inside classes)
class TestMutable
{
private:
    int id;
    mutable int call_count; // Can be modified even inside const member functions

public:
    TestMutable(int i) : id(i), call_count(0) {}

    void print_id() const // Marked as const
    {
        call_count++; // Allowed because call_count is 'mutable'
        cout << "ID: " << id << " (Called " << call_count << " times)" << endl;
    }
};

// MAIN FUNCTION
int main()
{
    cout << "--- 1. Auto & Register ---" << endl;
    auto x = 10;                   // Local variable, stack lifetime
    register int fast_counter = 0; // Hint to compiler to use CPU register
    cout << "Auto x: " << x << ", Register counter: " << fast_counter << endl
         << endl;

    cout << "--- 2. Static Storage Class ---" << endl;
    demonstrate_static(); // Normal: 1 | Static: 1
    demonstrate_static(); // Normal: 1 | Static: 2
    demonstrate_static(); // Normal: 1 | Static: 3
    cout << endl;

    cout << "--- 3. Mutable Storage Class ---" << endl;
    const TestMutable obj(101);
    obj.print_id(); // Mutates internal counter despite const object
    obj.print_id();
    cout << endl;

    return 0;
}
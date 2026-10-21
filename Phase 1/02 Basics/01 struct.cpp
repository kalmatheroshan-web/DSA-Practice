#include <iostream>
using namespace std;

/*
    // Structure Declaration
    struct name {
        type1 mem1;
        type2 mem2;
        ...
    };

    members are stored in contiguous memory 
    // Structure Declaration + Definition
    struct name {
        type1 mem1;
        type2 mem2;
        ...
    } var1, var2;

    // ❌ This fails in older C++ versions (initialization inside struct)
    struct Point {
        int x = 0;
        int y = 0;
    };

    // Access and Modify Members
    var_name.member_name;
    var_name.member_name = new_val;

    // Member Functions
    struct Point {
        int x, y;

        // Member function
        int sum() {
            return x + y;
        }
    };

    // Call member function using (.) operator
    cout << s.sum();

    // Nested Structure
    struct Inner {
        int a, b;
    };

    struct Outer {
        Inner in;
        int x, y;
    };

    ---- OR ----
    struct Outer {
        struct Inner {
            int a, b;
        } in;

        void hello() { cout << "Hello, World!" << endl; }
        int sum(int a, int b) { return a + b; }
    };
*/

// Structure with functions
struct name
{
    int x, y;

    void hello() { cout << "Namaste Roshan" << endl; }

    int sum(int a, int b) { return a + b; }
};

struct outer
{
    struct inner
    {
        int x, y;
    } in;
    int ok;
    void hello() { cout << "Hello World !!" << endl; }
    int mul(int a, int b) { return a * b; }
};

int main()
{
    name var;

    var.x = 100;
    var.y = 200;

    cout << "x = " << var.x << endl;
    cout << "y = " << var.y << endl;

    var.hello();
    cout << "Sum(10, 20) = " << var.sum(10, 20) << endl;

    // nested
    outer out = {{12, 22}, 30};
    out.hello();
    cout << "Multiplication = " << out.mul(10, 20) << endl;

    return 0;
}

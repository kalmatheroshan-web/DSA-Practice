#include <iostream>
using namespace std;

class line_a
{
public:
    int physics = 90;
    int chemistry = 85;

    void print()
    {
        cout << "line a" << endl;
    }
};

class line_b
{
public:
    int chemistry = 95;

    void print()
    {
        cout << "line b" << endl;
    }
};

class line_c : public line_a, public line_b
{
public:
    // Resolves default 'chemistry' member ambiguity
    using line_a::chemistry; 

    // Resolves 'print()' method ambiguity
    void print()
    {
        line_a::print();
        line_b::print();
    }
};

int main()
{
    line_c obj;

    // Accesses line_a::chemistry via using-declaration
    cout << "Chemistry (from line_a): " << obj.chemistry << endl;

    // Accesses line_b::chemistry via scope resolution
    cout << "Chemistry (from line_b): " << obj.line_b::chemistry << endl;

    // Calls line_c's print method
    obj.print();

    return 0;
}
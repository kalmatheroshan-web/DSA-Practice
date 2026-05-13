#include <bits/stdc++.h>
using namespace std;

// diamond problem
class line_a
{
public:
    int physics;
    int chemistry;
    void print()
    {
        cout << "line a" << endl;
    }
};

class line_b
{
public:
    int chemistry;
    void print()
    {
        cout << "line b" << endl;
    }
};

class line_c : public line_a, public line_b
{
public:
};

int main()
{
    line_c obj;
    cout << obj.line_a::chemistry << endl;
    obj.line_a::print();
    obj.line_b::print();
}
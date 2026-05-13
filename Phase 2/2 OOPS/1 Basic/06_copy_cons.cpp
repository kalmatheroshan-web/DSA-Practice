#include <bits/stdc++.h>
using namespace std;

class customer
{
public:
    string name;
    int ac;
                                // data mem(vari)
    customer(string nm, int ac) : name(nm), ac(ac) {}

    // custom copy constructor
    customer(const customer &B)
    {
        this->name = B.name;
        this->ac = B.ac;
        cout << "custom copy constructor called .." << endl;
    }

    void pr()
    {
        cout << "Name " << name << endl;
        cout << "Account " << ac << endl;
    }
};

int main()
{
    customer rohit("Rohit", 2103);

    // default copy constuctor
    customer neetu(rohit);
    neetu.name = "keval";

    rohit.pr();

    cout << endl;
    cout << endl;

    neetu.pr();

    return 0;
}
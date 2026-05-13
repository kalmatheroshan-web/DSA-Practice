#include <bits/stdc++.h>
using namespace std;

class customer
{
    string name;
    int *balance;

public:
    customer()
    {
        name = "Unique";
        balance = new int(0);

        cout << "constuctor " << this->name << endl;
    }

    // inlization list
    customer(string n, int bal) : name(n), balance(new int(bal))
    {
        cout << "constuctor " << this->name << endl;
    }

    void pr()
    {
        cout << "Name " << this->name << endl;
        cout << "Balance " << *this->balance << endl;
    }

    // it can't handle dynamic obj
    ~customer()
    {
        delete balance;
        cout << "Destructor of " << this->name << endl;
    }
};

class test
{
private:
    int fir, sec;

public:
    test()
    {
        this->fir = 0;
        this->sec = 0;
    }

    test(int a, int b) : sec(a + b), fir(a) {};

    friend int main();
};

int main()
{

    customer obj("Roshan", 12000);
    // obj.pr();
    cout << endl;

    customer a1("1", 1000);
    customer a2("2", 2000);
    customer a3("3", 3000);

    customer *a4 = new customer;
    delete a4;

    // test objett(10, 20);
    // cout << objett.fir << endl;
    // cout << objett.sec << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
    static member are common for all the objects
    static function only can access the static variables
*/

class saving_ac
{
    string name;
    int balance;
    int ac_num;
    static int total_cus;
    static int total_bal;

public:
    saving_ac(string n, int bal, int ac)
    {
        name = n;
        balance = bal;
        ac_num = ac;
        total_cus++;
        total_bal += bal;
    }

    void display()
    {
        cout << "Ac " << ac_num << endl;
        cout << "Name " << name << endl;
        cout << "Balance " << balance << endl;
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            total_bal += amount;
        }
    }

    void widrawal(int amount)
    {
        if (balance - amount >= 0)
        {
            balance -= amount;
            total_bal -= amount;
        }
    }

    static int getTotal() { return total_cus; }
    static int getTotalBal() { return total_bal; }

    static void hello()
    {
        // cout << total_cus << endl;

         // no this pointer allowed
        // error : non static var ,all member must be static
        // cout << name << endl;

        cout << "Hello world !!" << endl;
    }
};

// why this? bcoz it get memory
int saving_ac::total_cus = 0;
int saving_ac::total_bal = 0;

int main()
{
    saving_ac rohan("Rohan", 1000, 1);
    saving_ac mohan("Mohan", 2000, 2);
    cout << saving_ac::getTotal() << endl;
    cout << saving_ac::getTotalBal() << endl;

    saving_ac::hello();

    mohan.hello();

    return 0;
}
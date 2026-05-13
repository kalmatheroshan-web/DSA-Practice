#include <bits/stdc++.h>
using namespace std;

/*
    data hiding , means here we are wraping the data member and
    member funx into class

    so every class is eg of encapulation , but in strict encap we
    are trying to make all the data member as private
*/

class customer
{
    string name;
    int age, balance;
    static int total_amount;

public:
    customer(string name, int age, int balance)
    {
        this->name = name;
        this->age = age;
        this->balance = balance;
        total_amount += balance;
    }

    void deposite(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            total_amount += amount;
        }
    }

    void widrawal(int amount)
    {
        if (balance - amount >= 0)
        {
            balance -= amount;
            total_amount -= amount;
        }
        else
            cout << "Balance is not sufficient" << endl;
    }

    void changeAge(int age)
    {
        if (0 < age && age <= 100)
            this->age = age;
        else
            cout << "Invalid age" << endl;
    }

    void display()
    {
        cout << "Name " << this->name << endl;
        cout << "Age " << this->age << endl;
        cout << "Balance " << this->balance << endl;
        cout << "Total amount " << this->total_amount << endl;
    }
};

int customer::total_amount = 0;

int main()
{

    customer rohan("Rohan", 12, 1000);
    rohan.deposite(1000);
    rohan.deposite(1000);
    rohan.display();

    // widrawal
    rohan.widrawal(1000);
    rohan.widrawal(1000);
    rohan.widrawal(1000);
    rohan.widrawal(1000);
    rohan.display();

    return 0;
}